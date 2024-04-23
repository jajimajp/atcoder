open Base
open Stdio
open Int64

let tb = Hashtbl.create (module Int64)

let read_line () = In_channel.input_line_exn In_channel.stdin

let rec cnt n =
  let oi = Int64.of_int in
  if n <= one then zero else
  match Hashtbl.find tb n with
    | Some v -> v
    | None ->
  if n % (oi 2) = (oi 0) then
    n + ((oi 2) * cnt (n / (oi 2)))
  else
    n + ((cnt (n / (oi 2))) + cnt (n / (oi 2) + one))

let () =
  let n = read_line () |> Int64.of_string in
  printf "%s\n" (Int64.to_string @@ cnt n)
