(* Encyclopedia of Parentheses *)
(* n <= 20 => 2^n <= 10^6 *)

let chars_of_string s = List.of_seq (String.to_seq s)
let string_of_chars cs = String.of_seq (List.to_seq cs)

(* 文字列が正しいカッコ列か *)
let valid (ls: char list): bool =
  let rec aux l r ls =
    if r > l then false else
    match ls with
    | [] -> l = r
    | '(' :: t -> aux (l + 1) r t
    | ')' :: t -> aux l (r + 1) t
    | c :: t -> failwith @@ "Invalid character " ^ (Char.escaped c) in
  aux 0 0 ls

let solve n : string list =
  let rec strs n : char list list =
    if n = 1 then ['('] :: [')'] :: [] else
      let s = strs (n - 1) in
      (List.map (fun s -> '(' :: s) s) @ (List.map (fun s -> ')' :: s) s) in
  strs n |> List.filter valid |> List.map string_of_chars

let () =
  let n = read_line () |> int_of_string in
  solve n |> List.iter print_endline
