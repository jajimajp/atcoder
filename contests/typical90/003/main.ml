(* 003 - Longest Circular Road *)

let accum n a b : Hashtbl.t =
  let nbr = Hashtbl.create (2 * n) in
  let rec loop i =
    if i = n then
      nbr
    else
        if Hashtbl.mem a then
          Hashtbl.replace a (b :: Hashtbl.find a) else
          Hashtbl.add a [b];
        if Hashtbl.mem b then
          Hashtbl.replace b (a :: Hashtbl.find b) else
          Hashtbl.add b [a] in
  loop 0;
  nbr

type tree =
  Br of int * tree list

let solve (n: int) (a: int list) (b: int list): int =
  let nbr = accum n a b in
  (* 子方向で取れる長さの最大値 *)
  let rec aux (t : tree) : int = match t with
    | _, [] -> 0
    | _, chds ->
      let lens = List.map aux chds in
      List.fold_left max 0 lens in
