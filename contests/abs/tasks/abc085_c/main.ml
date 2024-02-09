open Base
open Stdio

let read_line () = In_channel.input_line_exn In_channel.stdin
let read_2int () =
  let l = read_line ()
          |> String.split ~on:' ' |> List.map ~f:Int.of_string in
  match l with
  | [a;b] -> (a,b)
  | _ -> failwith "read_2int: invalid input"

let () =
  let n, ly = read_2int () in
  let ans = ref (-1, -1, -1) in
  for x = 0 to n do
    for y = 0 to n - x do
      let z = n - x - y in
      if 10000*x + 5000*y + 1000*z = ly then
        ans := (x, y, z)
    done
  done;
  let x, y, z = !ans in
  printf "%d %d %d\n" x y z
