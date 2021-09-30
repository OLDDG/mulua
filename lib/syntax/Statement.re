open Base;

%gen
module rec Statement: {
  [@deriving sexp]
  type t =
    | Assignment(Assignment.t);
} = Statement

and Block: {
  [@deriving sexp]
  type t = list(Statement.t);
} = Block

and Assignment: {
  module AssignmentOperator: {
    [@deriving sexp]
    type t =
      | Assign;
  };

  [@deriving sexp]
  type t = {
    left: Identifier.t,
    operator: AssignmentOperator.t,
    right: Expression.t,
  };
} = Assignment;

include Statement;
