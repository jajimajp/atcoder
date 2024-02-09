open Base
open Stdio

let read_line () = In_channel.input_line_exn In_channel.stdin
let read_2int () =
  let l = read_line ()
          |> String.split ~on:' ' |> List.map ~f:Int.of_string in
  match l with
  | [a; b] -> (a, b)
  | _ -> failwith "read_2int: invalid input"

let () =
  let a, b = read_2int () in
  printf "%s\n"
    (match (a * b) % 2 with
    | 0 -> "Even"
    | _ -> "Odd"
    )
