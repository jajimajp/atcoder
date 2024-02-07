let solve n l k a =
  (* スコア s を達成できるか *)
  let ok s =
    let rec loop r ki a =
      if ki = k then
        l - r >= s
      else
        let rec lm a = match a with
          | [] -> None
          | hd :: tl ->
            if hd - r >= s then Some (hd, tl) else lm tl
        in match lm a with
        | None -> false
        | Some (newr, a) -> loop newr (ki + 1) a in
    loop 0 0 a in
  let rec bins l r =
    if r <= l + 1 then
      l
    else
      let m = (l + r) / 2 in
      if ok m then
        bins m r
      else
        bins l m
  in bins 0 1000000000

let () =
  let n :: l :: [] = String.split_on_char ' ' (read_line ()) |> List.map int_of_string in
  let k = read_line () |> int_of_string in
  let a = String.split_on_char ' ' (read_line ()) |> List.map int_of_string in
  solve n l k a |> string_of_int |> print_endline
