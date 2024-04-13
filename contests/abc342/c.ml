let value_exn = function
  | Some x -> x
  | None -> raise Not_found
let read_line () = In_channel.input_line In_channel.stdin |> value_exn
let read2 () =
  read_line () |> String.split ~on:' '
