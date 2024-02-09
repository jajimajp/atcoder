open Base
open Stdio

let read_line () = In_channel.input_line_exn In_channel.stdin
let read_int () = read_line () |> Int.of_string
let read_3int () =
  let l = read_line ()
          |> String.split ~on:' ' |> List.map ~f:Int.of_string in
  match l with
  | [a;b;c] -> (a,b,c)
  | _ -> failwith "read_3int: invalid input"

(** prev_t から next_t への移動が可能か *)
let possible
    (prev_t, prev_x, prev_y)
    (next_t, next_x, next_y)
  =
    (* マンハッタン距離 *)
    let dist = abs (prev_x - next_x) + abs (prev_y - next_y) in
    (* 最短距離で next に到達後にあまる時間 *)
    let overtime = (next_t - prev_t) - dist in
    overtime >= 0 && overtime % 2 = 0

let () =
  let n = read_int () in
  let ls = (* t_i, x_i, y_i *)
    List.range 0 n
    |> List.map ~f:(fun _ -> read_3int ()) in
  let ls = (0, 0, 0) :: ls in (* 時刻 0 に点 (0, 0) を出発 *)
  let rec aux = function
  | [] | [_] -> true
  | prev :: (next :: _ as tl) ->
    if possible prev next then aux tl else false in
  match aux ls with
  | true -> printf "Yes\n"
  | false -> printf "No\n"
