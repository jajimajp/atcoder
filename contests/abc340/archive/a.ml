open Base
open Stdio

let read_line () = In_channel.input_line_exn In_channel.stdin

let read_3int () =
  let l = read_line () |> String.split ~on:' ' |> List.map ~f:Int.of_string in
  match l with
  | [a;b;c] -> (a, b, c)
  | _ -> failwith "e"

let () =
  let a, b, d = read_3int () in
  let rec loop a =
    if a = b then [b]
    else a :: (loop (a+d)) in
  let l = loop a in
l |> List.map ~f:(fun i -> Printf.sprintf "%d" i) |> String.concat ~sep:" "
|> printf "%s\n"
