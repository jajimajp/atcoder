open Base
open Stdio

let read_line () = In_channel.input_line_exn In_channel.stdin
let read_int () = read_line () |> Int.of_string

let () =
  let n = read_int () in
  List.range 0 n
  |> List.map ~f:(fun _ -> read_int ())
  |> List.dedup_and_sort ~compare:Int.compare
  |> List.length
  |> printf "%d\n"
