open Base
open Stdio

let read_line () = In_channel.input_line_exn In_channel.stdin
let read_int () = read_line () |> Int.of_string
let read_intls () =
  read_line () |> String.split ~on:' ' |> List.map ~f:Int.of_string

(** n を 2 で割り切れる回数 *)
let times_for n =
  let rec loop acc n =
    match n % 2 with
    | 0 -> loop (acc + 1) (n / 2)
    | _ -> acc in
  loop 0 n

let () =
  let _ = read_int () in
  let a = read_intls () in
  List.map ~f:times_for a
  |> List.reduce_exn ~f:min
  |> printf "%d\n"
