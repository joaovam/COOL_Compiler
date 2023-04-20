
(*
 *  execute "coolc bad.cl" to see the error messages that the coolc parser
 *  generates
 *
 *  execute "myparser bad.cl" to see the error messages that your parser
 *  generates
 *)

(* repositorios que podem ajudar:
 * https://github.com/vinceniko/cool-compiler/blob/master/pa3-submission/bad.cl
 * https://github.com/HoussemNasri/CoolCompiler/tree/master/syntax-analysis/tests
 * https://github.com/AgamAgarwal/cool-compiler/blob/master/assignments/3/bad.cl)

(* no error *)
class A {
};

(* error:  b is not a type identifier *)
Class b inherits A {
};

(* error:  a is not a type identifier *)
Class C inherits a {
};

(* error:  keyword inherits is misspelled *)
Class D inherts A {
};

(* error:  closing brace is missing *)
Class E inherits A {
;

