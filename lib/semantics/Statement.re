open Base;
open MuLua_syntax.Statement;

let rec eval_block = (~env=Environment.empty) =>
  List.fold(~init=env, ~f=env => eval(~env))

and eval = (~env=Environment.empty) =>
  fun
  | Assignment({left, operator: Assign, right}) =>
    env |> Environment.set(~key=left, ~data=right |> Expression.eval(~env));
