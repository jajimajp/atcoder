open Base
open Stdio

let read_line () = In_channel.input_line_exn In_channel.stdin
let read_3int () =
  let l = read_line ()
          |> String.split ~on:' ' |> List.map ~f:Int.of_string in
  match l with
  | [a;b;c] -> (a,b,c)
  | _ -> failwith "read_3int: invalid input"

(** 10 進法での各桁の和 *)
let sum_digits n =
  let rec loop acc = function
    | 0 -> acc
    | n -> loop (acc + (n % 10)) (n / 10) in
  loop 0 n

let () =
  let n, a, b = read_3int () in
  List.range ~stop:`inclusive 1 n
  |> List.filter ~f:(fun n ->
      let sd = sum_digits n in
      a <= sd && sd <= b)
  |> List.reduce_exn ~f:(+)
  |> printf "%d\n"
