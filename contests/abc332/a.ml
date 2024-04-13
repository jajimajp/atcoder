(* Compile command:
eval $(opam env) ocamlfind ocamlopt -O2 -o a.out \
main.ml -linkpkg -thread \
-package str,num,threads,containers,core,iter,batteries
*)

open Base
open Stdio

(** ヘルパー関数群 *)
(** Python の標準に寄せる *)
let input () = In_channel.(input_line_exn stdin)
let split = String.split ~on:' '
let int = Int.of_string
let map f ls = List.map ~f ls
let tup2 = function
  | [a; b] -> (a, b)
  | _ -> failwith "invalid argument"
let tup3 = function
  | [a; b; c] -> (a, b, c)
  | _ -> failwith "invalid argument"

let cl_of_s (s : string) : char list =
  String.(to_list_rev (rev s))

let () =
  let n, s, k = tup3 @@ map int (split (input ())) in
  let rec loop i acc =
    if i < n then
      let p, q = tup2 @@ map int (split (input ())) in
      loop (i + 1) (acc + p * q)
    else acc in
  let price = loop 0 0 in
  let price =
    if price >= s then price else price + k in
  printf "%d\n" price
