open Base
open Stdio

let read_line () = In_channel.input_line_exn In_channel.stdin
let read_int () = read_line () |> Int.of_string

(** list のシャッフル *)
let shuffle ls =
  let nd = List.map ~f:(fun c -> (Random.bits (), c)) ls in
  let sond = List.sort ~compare:(fun a b -> Int.compare (fst a) (fst b)) nd in
  List.map ~f:snd sond

(** list の半分ではなく1/4をランダムに選ぶ *)
let rand_pick_half ls =
  let ls = shuffle ls in
  let len = List.length ls in
  List.take ls (len / 4)

type oilfield = int * (int * int) list
type t =
  { n : int;
    m : int;
    e : Float.t;
    ofs : oilfield list;
  }

let input () : t =
  let nme = read_line () |> String.split ~on:' ' in
  let n, m, e = match nme with
  | [n;m;e] ->
    (Int.of_string n, Int.of_string m, Float.of_string e)
  | _ -> failwith "input: invalid input" in
  let input_of () : oilfield =
    let l = read_line () |> String.split ~on:' ' in
    let d = List.hd_exn l |> Int.of_string in
    let ij = List.tl_exn l |> List.map ~f:Int.of_string in
    let rec ijs acc_rev = function
    | [] -> List.rev acc_rev
    | i :: j :: tl ->
      ijs ((i, j) :: acc_rev) tl
    | [_] -> failwith "input_of: invalid input" in
    (d, ijs [] ij) in
  let ofs = List.init m ~f:(fun _ -> input_of ()) in
  { n; m; e; ofs }

(** ２点間の距離の２乗 *)
let dist_p2 (i1, j1) (i2, j2) =
  (i1-i2)*(i1-i2) + (j1-j2)*(j1-j2)

(** ２次元配列 arr の (i, j) 周囲８マスの値を value だけ増加 *)
let set_chance_around t arr i j value =
  for di = -1 to 1 do
    let i' = i + di in
    if i' < 0 || t.n <= i' then ()
    else
      for dj = -1 to 1 do
        if di = 0 && dj = 0 then ()
        else
          let j' = j + dj in
          if j' < 0 || t.n <= j' then ()
          else
            arr.(i').(j') <- arr.(i').(j') + value
      done
  done

(** ２次元配列 arr の指定したマスを value だけ増加 *)
let add_sal_around t arr ijs value =
  List.iter ijs ~f:(fun (i, j) ->
    arr.(i).(j) <- arr.(i).(j) + value)

(** ２次元配列 arr の要素の最大値 *)
let max_sal arr =
  Array.map arr ~f:(fun row ->
    Array.max_elt row ~compare:Int.compare |> Option.value_exn)
  |> Array.max_elt ~compare:Int.compare
  |> Option.value_exn

(** ２次元配列 arr の要素の平均値 *)
let avg_sal arr =
  let sum =
    Array.fold arr ~init:0 ~f:(fun acc row ->
        acc + (Array.reduce_exn row ~f:(+))) in
  let height = Array.length arr in
  sum / (height * height)

(** 期待の２次元配列 arr から、２点の比較関数を返す *)
let compare_points t arr p1 p2 =
  let i1, j1 = p1 in
  let i2, j2 = p2 in
  if arr.(i1).(j1) > arr.(i2).(j2) then
    -1
  else if arr.(i1).(j1) < arr.(i2).(j2) then
    1
  else
    let center = (t.n / 2, t.n / 2) in
    (dist_p2 p1 center) - (dist_p2 p2 center)

(* *** 入出力コマンドのラッパー *** *)
(** 1マス(i, j)を選び、そのマスの地下を掘る *)
let query_dig ~i ~j : int =
  printf "q 1 %d %d\n" i j;
  Out_channel.flush Out_channel.stdout;
  read_int ()

(** d(>=2) マスの集合 S を選び v(S) を占う *)
let query_fortune (ijs : (int * int) list) : int =
  let len = List.length ijs in
  let ijstr =
    List.map ijs ~f:(fun (i, j) -> Printf.sprintf "%d %d" i j)
    |> String.concat ~sep:" " in
  printf "q %d %s\n" len ijstr;
  Out_channel.flush Out_channel.stdout;
  read_int ()

(** v(i, j) > 0 と判断したマスの集合を回答する *)
let guess (ijs : (int * int) list) : unit =
  let len = List.length ijs in
  let ijstr =
    List.map ijs ~f:(fun (i, j) -> Printf.sprintf "%d %d" i j)
    |> String.concat ~sep:" " in
  printf "a %d %s\n" len ijstr;
  Out_channel.flush Out_channel.stdout;
  match read_int () with
  | 1 -> ()
  | _ -> failwith "guess: got != 1. something went wrong"

(** 2次元配列をビジュアライザで色付けるようなコメントを出力する。 *)
let out_colors arr =
  let avg = avg_sal arr in
  let arr = Array.map arr ~f:(fun row ->
    Array.map row ~f:(fun e -> max 0 (e - avg))) in
  let maxval = max_sal arr in
  let color_of_val v =
    let v = 255 * v / maxval in
    Printf.sprintf "#%2X%2X%2X" v v v in
  Array.iteri arr ~f:(fun i row ->
    Array.iteri row ~f:(fun j v ->
        printf "#c %d %d %s\n" i j (color_of_val v);
        Out_channel.flush Out_channel.stdout));
  (* デバッグ用 *)
  printf "# sal00 %d\n" arr.(0).(0)

let () =
  let t = input () in
  let pos = ref [] in (* 油田のある座標 *)
  let v_tot = (* 石油の全埋蔵量 *)
    t.ofs |> List.map ~f:fst |> List.reduce_exn ~f:(+) in
  let v_found = ref 0 in (* これまでの石油埋蔵量 *)
  let check_poss = (* 確認する座標の一覧 *)
    List.Cartesian_product.map2
      (List.range 0 t.n) (List.range 0 t.n)
      ~f:(fun a b -> (a, b)) in
  (* マスの期待値を表す *)
  let chance = Array.make_matrix ~dimx:t.n ~dimy:t.n 0 in
  (* 座標を中心に近い順に並べ替える *)
  let center = (t.n / 2, t.n / 2) in
  let check_poss = List.sort check_poss
      ~compare:(fun p1 p2 ->
        (dist_p2 p1 center) - (dist_p2 p2 center)) in
  let rec loop = function
    | [] -> ()
    | (i, j) :: tl ->
      let inp = query_dig ~i ~j in
      begin match inp with
      | 0 -> ()
      | n ->
          v_found := !v_found + n;
          set_chance_around t chance i j n;
          pos := (i, j) :: !pos
      end;
      if !v_found = v_tot then () (* 探索完了 *)
      else
        let compare = compare_points t chance in
        loop (List.sort tl ~compare) in
  let () = loop check_poss in
  let answer = !pos in
  (* 答えはすでにわかっている。これから saliency のテストをやる。 *)
  let saliency = Array.make_matrix ~dimx:t.n ~dimy:t.n 0 in
  let check_poss = (* 確認する座標の一覧を再度出す。 *)
    List.Cartesian_product.map2
      (List.range 0 t.n) (List.range 0 t.n)
      ~f:(fun a b -> (a, b)) in
  for i = 1 to (t.n * t.n) do
    let checks = rand_pick_half check_poss in
    let conf = query_fortune checks in
    add_sal_around t saliency checks conf;
    out_colors saliency
  done;
  (* チェックのビジュアルが邪魔なので、左上を一回みる *)
  let _ = query_dig 0 0 in
  guess answer
