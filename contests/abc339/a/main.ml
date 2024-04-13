open Base
open Stdio
let read_line () = In_channel.input_line_exn In_channel.stdin
let () =
  read_line ()
  |> String.rsplit2_exn ~on:'.' |> snd
  |> print_endline
