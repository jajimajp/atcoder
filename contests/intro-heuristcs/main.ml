open Base
open Stdio

let read_line () = In_channel.input_line_exn In_channel.stdin

(* 問題を表す型 *)
type t =
  { d: int; (* D *)
    c: int Array.t; (* c  *)
    s: int Array.t Array.t; (* s *)
  }

(* 出力を表す型 *)
type ans = int list (* 先頭が1日目 *)

let input () : t =
  let d =
    read_line () |> Int.of_string in
  let c = read_line ()
          |> String.split ~on:' '
          |> List.map ~f:Int.of_string
          |> Array.of_list in
  let s = Array.create ~len:d (Array.create ~len:26 0) in
  for i = 0 to d - 1 do
    let row = read_line ()
          |> String.split ~on:' '
          |> List.map ~f:Int.of_string
          |> Array.of_list in
    s.(i) <- row
  done;
  { d; c; s }

(** 問題 t と出力 ans に対する last(d, i) *)
let last t ans d i =
  let d = d - 1 in (* 0-indexed に変換 *)
  let opened = (* d 日以前にコンテストiを開いた日 *)
    List.filter_mapi ans ~f:(fun idx e ->
      if idx <= d && e = i then Some idx else None) in
  match List.last opened with
  | None -> 0
  | Some idx -> idx + 1 (* 1-indexed に変換 *)

let score_for ~day ~prev_score t ans =
  let ans_for_day = List.nth_exn ans (day - 1) in
  let gain = t.s.(day - 1).(ans_for_day - 1) in
  let loss =
    List.init 26 ~f:(fun i ->
      t.c.(i) * (day - (last t ans day (i + 1))))
  |> List.reduce_exn ~f:(+) in
  prev_score + gain - loss

let scores t ans : int list =
  let rec aux day acc_rev =
    if day > t.d then List.tl_exn @@ List.rev acc_rev
    else aux
        (day + 1)
        (score_for ~day ~prev_score:(List.hd_exn acc_rev) t ans :: acc_rev) in
  aux 1 [0]

(* 貪欲法 *)
let decide ~day ~prev_score t ans =
  let ls = List.init 26 ~f:(fun idx ->
    let i = idx + 1 in
    (i, score_for ~day ~prev_score t (ans @ [i]))) in
  List.fold ls ~init:(List.hd_exn ls)
    ~f:(fun (pi, ps) (i, ns) -> if ns > ps then (i, ns) else (pi, ps))
  |> fst

let () =
  let t = input () in
  let rec loop day ans prev_score =
    if day > t.d then ()
    else
      let ti = decide ~day ~prev_score t ans in
      let ans = ans @ [ti] in
      let score = score_for ~day ~prev_score t ans in
      printf "%d\n" ti;
      loop (day + 1) ans score in
  loop 1 [] 0
