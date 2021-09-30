let letter = [%sedlex.regexp? 'a' .. 'z' | 'A' .. 'Z'];
let digit = [%sedlex.regexp? '0' .. '9'];

let identifier_start = [%sedlex.regexp? letter | '_'];
let identifier_continue = [%sedlex.regexp? identifier_start | digit];
let identifier = [%sedlex.regexp?
  (identifier_start, Star(identifier_continue))
];

exception Unexpected(string);

let rec token = lexbuf => {
  open Tokens;
  open Sedlexing.Utf8;
  switch%sedlex (lexbuf) {
  | white_space => token(lexbuf)
  | "nil" => NilLiteral
  | "true" => BooleanLiteral(true)
  | "false" => BooleanLiteral(false)
  | "end" => End
  | "if" => If
  | "then" => Then
  | "else" => Else
  | "while" => While
  | "do" => Do
  | "(" => ParenLeft
  | ")" => ParenRight
  | "=" => Equal
  | "+" => Plus
  | "-" => Minus
  | "*" => Star
  | "//" => DoubleSlash
  | "==" => EqualEqual
  | "~=" => TildeEqual
  | "<=" => LessEqual
  | "<" => Less
  | ">=" => GreaterEqual
  | ">" => Greater
  | identifier => Identifier(lexeme(lexbuf))
  | eof => EOF
  | _ => raise(Unexpected(lexeme(lexbuf)))
  };
};
