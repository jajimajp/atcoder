open Base
open Stdio

let read_line () = In_channel.input_line_exn In_channel.stdin

let () =
  read_line ()
    |> String.fold ~init:0 ~f:(fun acc c ->
      match c with
      | '0' -> acc
      | _ -> acc + 1
      )
    |> printf "%d\n"
