open Base
open Stdio

let read_line () = In_channel.input_line_exn In_channel.stdin
let read_int () = read_line () |> Int.of_string

type oilfield = int * (int * int) list
type t =
  { n : int;
    m : int;
    e : Float.t;
    ofs : oilfield list;
  }

let input () : t =
  let nme = read_line () |> String.split ~on:' ' in
  let n, m, e = match nme with
  | [n;m;e] ->
    (Int.of_string n, Int.of_string m, Float.of_string e)
  | _ -> failwith "input: invalid input" in
  let input_of () : oilfield =
    let l = read_line () |> String.split ~on:' ' in
    let d = List.hd_exn l |> Int.of_string in
    let ij = List.tl_exn l |> List.map ~f:Int.of_string in
    let rec ijs acc_rev = function
    | [] -> List.rev acc_rev
    | i :: j :: tl ->
      ijs ((i, j) :: acc_rev) tl
    | [_] -> failwith "input_of: invalid input" in
    (d, ijs [] ij) in
  let ofs = List.init m ~f:(fun _ -> input_of ()) in
  { n; m; e; ofs }

let () =
  let t = input () in
  let pos = ref [] in (* 油田のある座標 *)
  for i = 0 to t.n - 1 do
    for j = 0 to t.n - 1 do
      printf "q 1 %d %d\n" i j;
      Out_channel.flush Out_channel.stdout;
      let inp = read_int () in
      match inp with
      | 0 -> ()
      | _ -> pos := (i, j) :: !pos
    done
  done;
  let ijstr =
    List.map !pos ~f:(fun (i, j) -> Printf.sprintf "%d %d" i j)
    |> String.concat ~sep:" " in
  printf "a %d %s\n" (List.length !pos) ijstr;
  Out_channel.flush Out_channel.stdout;
  match read_int () with
  | 1 -> ()
  | _ -> failwith "(): got != 1 for answer query. something went wrong."
