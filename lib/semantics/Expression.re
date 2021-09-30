open MuLua_syntax.Expression;

module Literal = {
  let eval: Literal.t => Value.t =
    fun
    | Nil => Nil
    | Boolean(x) => Boolean(x)
    | Integer(x) => Integer(x);
};

let eval = (~env=Environment.empty) =>
  fun
  | Literal(x) => x |> Literal.eval
  | Identifier(x) => x |> Environment.get(env)
  | _ => failwith("TODO");
