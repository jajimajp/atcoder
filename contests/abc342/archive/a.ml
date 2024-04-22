let value_exn = function
  | Some v -> v
  | None -> failwith "Expected a value, got None"

let read_line () = In_channel.input_line In_channel.stdin |> value_exn

let () =
  let s = read_line () in
  let a, b, c = s.[0], s.[1], s.[2] in
  let idx =
    match a = b, b = c, c = a  with
    | true, true, true ->
      let rec loop i =
        if s.[i] = a then
          loop (i + 1)
        else
          i in
      loop 0
    | false, true, false -> 0
    | false, false, true -> 1
    | true, false, false -> 2 in
  print_endline @@ string_of_int (idx + 1)
