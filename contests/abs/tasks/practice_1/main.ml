open Base
open Stdio

let read_line () = In_channel.input_line_exn In_channel.stdin
let read_int () = read_line () |> Int.of_string
let read_2int () =
  let l = read_line () |> String.split ~on:' ' |> List.map ~f:Int.of_string in
  match l with
  | [a; b] -> (a, b)
  | _ -> failwith "read_2int: invalid input. expected 2 int in a line."

let () =
  let a = read_int () in
  let b, c = read_2int () in
  let s = read_line () in
  printf "%d %s\n" (a + b + c) s
