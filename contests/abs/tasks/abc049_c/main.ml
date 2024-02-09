open Base
open Stdio

let read_line () = In_channel.input_line_exn In_channel.stdin

(** s を空文字から生成できる *)
let rec generatable s =
  let open String in
  if s = "" then true
  else
    match (suffix s 5, suffix s 6, suffix s 7) with
    | "dream", _, _ -> generatable (drop_suffix s 5)
    | "erase", _, _ -> generatable (drop_suffix s 5)
    | _, "eraser", _ -> generatable (drop_suffix s 6)
    | _, _, "dreamer" -> generatable (drop_suffix s 7)
    | _, _, _ -> false

let () =
  let s = read_line () in
  let ans = if generatable s then "YES" else "NO" in
  printf "%s\n" ans
