open Base
open Stdio

let read_line () = In_channel.input_line_exn In_channel.stdin
let read_int () = read_line () |> Int.of_string
let read_2int () =
  let l = read_line () |> String.split ~on:' ' |>  List.map ~f:Int.of_string in
  match l with
  | [a;b] -> (a, b)
  | _ -> failwith "err"

let () =
  let n = read_int () in
  let rec aux n =
    if n = 0 then "1" else "10" ^ (aux (n - 1)) in
  printf "%s\n" (aux n)
