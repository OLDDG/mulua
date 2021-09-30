%{
open MuLua_syntax
%}

%start <Program.t> program

%%

let program :=
  | ~ = block; EOF;
    <>

let block :=
  | ~ = statement*;
    <>

let statement :=
  | ~ = assignment_statement;
    <>

let assignment_statement :=
  | left = assignable; operator = assignment_operator; right = expression;
    {
      Statement.Assignment { left; operator; right; }
    }

let assignable ==
  | ~ = Identifier;
    <>

let assignment_operator ==
  | Equal;
    { Statement.Assignment.AssignmentOperator.Assign }

let expression :=
  | ~ = Identifier;
    <Expression.Identifier>
  | ~ = literal;
    <>

let literal :=
  | NilLiteral;
    {
      Expression.Literal Expression.Literal.Nil
    }
  | value = BooleanLiteral;
    {
      Expression.Literal (Expression.Literal.Boolean value)
    }
  | value = IntegerLiteral;
    {
      Expression.Literal (Expression.Literal.Integer value)
    }
