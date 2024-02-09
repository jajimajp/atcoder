open Base
open Stdio

let read_line () = In_channel.input_line_exn In_channel.stdin
let read_int () = read_line () |> Int.of_string

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

exception Break
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
  (* 座標を中心に近い順に並べ替える *)
  let center = (t.n / 2, t.n / 2) in
  let check_poss = List.sort check_poss
      ~compare:(fun p1 p2 ->
        (dist_p2 p1 center) - (dist_p2 p2 center)) in
  try
    List.iter check_poss
      ~f:(fun (i, j) ->
        printf "q 1 %d %d\n" i j;
        Out_channel.flush Out_channel.stdout;
        let inp = read_int () in
        match inp with
        | 0 -> ()
        | n ->
          v_found := !v_found + n;
          pos := (i, j) :: !pos;
        if !v_found = v_tot then
          raise Break
      )
  with
  | Break -> ();
  let ijstr =
    List.map !pos ~f:(fun (i, j) -> Printf.sprintf "%d %d" i j)
    |> String.concat ~sep:" " in
  printf "a %d %s\n" (List.length !pos) ijstr;
  Out_channel.flush Out_channel.stdout;
  match read_int () with
  | 1 -> ()
  | _ -> failwith "(): got != 1 for answer query. something went wrong."
