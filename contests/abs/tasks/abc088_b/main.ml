open Base
open Stdio

let read_line () = In_channel.input_line_exn In_channel.stdin
let read_intls () =
  read_line () |> String.split ~on:' ' |> List.map ~f:Int.of_string

let () =
  let _ = read_line () in (* n は使わない *)
  let a = read_intls () in
  let sorted = List.sort ~compare:Int.descending a in
  let rec loop alice bob = function
    | [] -> (alice, bob)
    | [a] -> (alice + a, bob)
    | a :: b :: tl -> loop (alice + a) (bob + b) tl in
  let alice, bob = loop 0 0 sorted in
  printf "%d\n" (alice - bob)
