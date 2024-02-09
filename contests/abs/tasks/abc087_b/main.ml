open Base
open Stdio

let read_line () = In_channel.input_line_exn In_channel.stdin
let read_int () = read_line () |> Int.of_string

let () =
  let a = read_int () in
  let b = read_int () in
  let c = read_int () in
  let x = read_int () in
  let zton n = List.range ~stop:`inclusive 0 n in
  List.Cartesian_product.map3
    (zton a) (zton b) (zton c)
    ~f:(fun a b c ->
      if 500*a + 100*b + 50*c = x then 1 else 0)
  |> List.reduce_exn ~f:(+)
  |> printf "%d\n"
