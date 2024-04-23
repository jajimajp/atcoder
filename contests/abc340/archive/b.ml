open Base
open Stdio

let read_line () = In_channel.input_line_exn In_channel.stdin

let read_2int () =
  let l = read_line () |> String.split ~on:' ' |> List.map ~f:Int.of_string in
  match l with
  | [a;b] -> (a, b)
  | _ -> failwith "e"

let () =
  let q = read_line () |> Int.of_string in
  let rec loop i acc =
    if i >= q then ()
    else
      match read_2int () with
      | 1, x ->
        loop (i + 1) (x :: acc)
      | 2, k ->
        printf "%d\n" (List.nth_exn acc (k - 1));
        loop (i + 1) acc in
  loop 0 []
