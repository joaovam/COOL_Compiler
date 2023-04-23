
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
 * https://github.com/AgamAgarwal/cool-compiler/blob/master/assignments/3/bad.cl *)

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

--testando método vazio
Class F inherits A {
    (*error: missing ':'*)
    empty_feature()  Int {
        
    };
};

Class G inherits A {
    (*error: int is not a type identifier*)
    empty_feature() : int {
        
    };
};

Class H inherits A {
    (*error: Empty_feature() is not a method identifier*)
    Empty_feature() : Int {
        
    };
};

Class I inherits A {
    (*error: empty_feature is not a method*)
    empty_feature : Int {
        
    };
};

Class J inherits A {
    (*error: type of method return is missing*)
    empty_feature() : {
        
    };
};

-- testando classe com um método
Class K {
    (*error: a is not a Integer*)
    feature() : Int {
        a
    };
};

-- testando parâmetros formais, vários métodos em uma classe e inicialização de atributos
Class L inherits A {
    c : Int;
    d : Int < 0; (*error: attribution should be with <-*)

    no_formals() : Int {
        c <- 1
    };

    one_formal(one : Arg1) : Int {
        1
    };

    two_formals(one : Arg1, two : Arg2) : Int {
        1
    };
};

Class M inherits A {
    c : Int;
    d : Int <- 0; 

    no_formals() : Int {
        (*error: no variable to recieve the value 1*)
         <- 1
    };

    one_formal(one : Arg1) : Int {
        1
    };

    two_formals(one : Arg1, two : Arg2) : Int {
        1
    };
};

Class N inherits A {
    c : Int;
    d : Int <- 0; 

    no_formals() : Int {
        c <- 1
    };

    (*error: type of parameter one is missing*)
    one_formal(one) : Int {
        1
    };

    two_formals(one : Arg1, two : Arg2) : Int {
        1
    };
};

Class O inherits A {
    c : Int;
    d : Int <- 0; 

    no_formals() : Int {
        c <- 1
    };

    one_formal(one : Arg1) : Int {
        1
    };

    (*error: missing , between arguments*)
    two_formals(one : Arg1 two : Arg2) : Int {
        1
    };
};

-- testando expressões aritméticas
Class P inherits A {
    (*error: an operator is missing*)
    c : Int <- 1  2;

    mul_add() : Int {
        c <- 1 + 1 * 2
    };

    add_mul() : Int {
        c <- (1 + 1) * 2 * (3 + (4 + 4))
    };

    add_sub() : Int {
        c <- 1 + 1 - 2
    };

    mul_div(): Int {
        c <- 1 * 2 / 2
    };
};

Class Q inherits A {
    (*error: invalid operator -*)
    c : Int <- -1 * 2;

    mul_add() : Int {
        c <- 1 + 1 * 2
    };

    add_mul() : Int {
        c <- (1 + 1) * 2 * (3 + (4 + 4))
    };

    add_sub() : Int {
        c <- 1 + 1 - 2
    };

    mul_div(): Int {
        c <- 1 * 2 / 2
    };
};

Class R inherits A {
    c : Int <- 1 * 2;

    mul_add() : Int {
        c <- 1 + 1 * 2
    };

    add_mul() : Int {
        (*error: ) is missing*)
        c <- (1 + 1 * 2 * (3 + (4 + 4))
    };

    add_sub() : Int {
        c <- 1 + 1 - 2
    };

    mul_div(): Int {
        c <- 1 * 2 / 2
    };
};

Class S inherits A {
    c : Int <- 1 * 2;

    mul_add() : Int {
        c <- 1 + 1 * 2
    };

    add_mul() : Int {
        (*error: ( is missing*)
        c <- 1 + 1) * 2 * (3 + (4 + 4))
    };

    add_sub() : Int {
        c <- 1 + 1 - 2
    };

    mul_div(): Int {
        c <- 1 * 2 / 2
    };
};

-- testando expressões condicionais e comandos if else, while e case
Class T inherits A {
    c : Int <- 1;

    conditional_if_expression() : Int {
        (*error: invalid operator >=*)
        if (c >= 1) then 0 else
        if (c < 2) then 1 else
        if (c = 2) then 2 else
        if (not(c = 1)) then 3 else
        fi fi fi fi
    }

    while_expression() : Int {
		while c < 5 loop {
			    c <- c + 1;
		} pool
    }

    case_expression() : Int {
        -- FALTANDO!!!
    }
};

Class U inherits A {
    c : Int <- 1;

    conditional_if_expression() : Int {
        (*error: keyword if is missing*)
         (c >= 1) then 0 else
        if (c < 2) then 1 else
        if (c = 2) then 2 else
        if (not(c = 1)) then 3 else
        fi fi fi fi
    }

    while_expression() : Int {
		while c < 5 loop {
			    c <- c + 1;
		} pool
    }

    case_expression() : Int {
        -- FALTANDO!!!
    }
};

Class V inherits A {
    c : Int <- 1;

    conditional_if_expression() : Int {
        (*error: keyword then is missing*)
        if (c >= 1)  0 else
        if (c < 2) then 1 else
        if (c = 2) then 2 else
        if (not(c = 1)) then 3 else
        fi fi fi fi
    }

    while_expression() : Int {
		while c < 5 loop {
			    c <- c + 1;
		} pool
    }

    case_expression() : Int {
        -- FALTANDO!!!
    }
};

Class V inherits A {
    c : Int <- 1;

    conditional_if_expression() : Int {
        if (c >= 1) then 0 else
        if (c < 2) then 1 else
        if (c = 2) then 2 else
        if (not(c = 1)) then 3 else
        fi fi fi (*error: keyword fi is missing*)
    }

    while_expression() : Int {
		while c < 5 loop {
			    c <- c + 1;
		} pool
    }

    case_expression() : Int {
        -- FALTANDO!!!
    }
};

Class W inherits A {
    c : Int <- 1;

    conditional_if_expression() : Int {
        if (c >= 1) then 0 else
        if (c < 2) then 1 else
        if (c = 2) then 2 else
        if (no(c = 1)) then 3 else (*error: no is not a keyword*)
        fi fi fi fi
    }

    while_expression() : Int {
		while c < 5 loop {
			    c <- c + 1;
		} pool
    }

    case_expression() : Int {
        -- FALTANDO!!!
    }
};

Class X inherits A {
    c : Int <- 1;

    conditional_if_expression() : Int {
        if (c >= 1) then 0 else
        if (c < 2) then 1 else
        if (c = 2) then 2 else
        if (not(c = 1)) then 3 else 
        fi fi fi fi
    }

    while_expression() : Int {
		(*error: keyword while is missing*)
      c < 5 loop {
			    c <- c + 1;
		} pool
    }

    case_expression() : Int {
        -- FALTANDO!!!
    }
};

Class Y inherits A {
    c : Int <- 1;

    conditional_if_expression() : Int {
        if (c >= 1) then 0 else
        if (c < 2) then 1 else
        if (c = 2) then 2 else
        if (not(c = 1)) then 3 else 
        fi fi fi fi
    }

    while_expression() : Int {
		(*error: keyword loop is missing*)
    while c < 5  {
			    c <- c + 1;
		} pool
    }

    case_expression() : Int {
        -- FALTANDO!!!
    }
};

Class Z inherits A {
    c : Int <- 1;

    conditional_if_expression() : Int {
        if (c >= 1) then 0 else
        if (c < 2) then 1 else
        if (c = 2) then 2 else
        if (not(c = 1)) then 3 else 
        fi fi fi fi
    }

    while_expression() : Int {
		while c < 5 loop {
			    c <- c + 1;
		} (*error: keyword pool is missing*)
    }

    case_expression() : Int {
        -- FALTANDO!!!
    }
};

-- testando bloco de expressão
Class AA inherits A {
    
    block() : Int {
        
            c <- 0;
            c <- 1;
        } (*error: missing symbol {*)
    };
};

Class AB inherits A {
    
    block() : Int {
        {
            c <- 0;
            c <- 1;
        (*error: missing symbol }*)
    };
};

-- testando expressões let
class AC inherits A {
    a : Int <- b : Int <- 0, c : Int <- 1 in 2; (*error: keyword let is missing*)
    d : Int <- let e : Int, f : Int <- 1 in 2;
};

class AD inherits A {
    a : Int <- let b : Int <- 0, c : Int <- 1  2; (*error: keyword in is missing*)
    d : Int <- let e : Int, f : Int <- 1 in 2;
};
