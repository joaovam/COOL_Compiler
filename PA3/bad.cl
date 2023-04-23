
(*
 *  execute "coolc bad.cl" to see the error messages that the coolc parser
 *  generates
 *
 *  execute "myparser bad.cl" to see the error messages that your parser
 *  generates
 *)

(* sem erro *)
class A {
};

(* erro: b não é um identificador de tipo *)
Class b inherits A {
};

(* erro: a não é um identificador de tipo *)
Class C inherits a {
};

(* erro: palavra-chave inherits escrita errada *)
Class D inherts A {
};

(* erro: faltando chave de fechamento *)
Class E inherits A {
;

-- testando método vazio
Class F inherits A {
    (* erro: faltando : *)
    empty_feature()  Int {
        
    };
};

Class G inherits A {
    (* erro: int não é um identificador de tipo *)
    empty_feature() : int {
        
    };
};

Class H inherits A {
    (* erro: Empty_feature() não é um identificador de método *)
    Empty_feature() : Int {
        
    };
};

Class I inherits A {
    (* erro: empty_feature não é um método *)
    empty_feature : Int {
        
    };
};

Class J inherits A {
    (* erro: tipo do return está faltando *)
    empty_feature() : {
        
    };
};

-- testando classe com um método
Class K {
    (* erro: a não é inteiro *)
    feature() : Int {
        a
    };
};

-- testando parâmetros formais, vários métodos em uma classe e inicialização de atributos
Class L inherits A {
    c : Int;
    d : Int < 0; (* erro: atribuição deveria ser com <- *)

    no_formals() : Int {
        <- 1 (* erro: nenhuma variável para receber 1 *)
    };

    (* erro: faltando o tipo do parâmetro "one" *)
    one_formal(one) : Int {
        1
    };

    (* erro: faltando , entre os argumentos *)
    two_formals(one : Arg1 two : Arg2) : Int {
        1
    };
};

-- testando expressões aritméticas
Class M inherits A {
    (* erro: faltando operador *)
    c : Int <- 1  2;

    (* erro: operador inválido - *)
    d : Int <- -1 * 2;

    mul_add() : Int {
        c <- 1 + 1 * 2
    };

    add_mul() : Int {
        (* erro: faltando ) *)
        c <- (1 + 1 * 2 * (3 + (4 + 4))
        (* erro: faltando ( *)
        d <- 1 + 1) * 2 * (3 + (4 + 4))
    };

    add_sub() : Int {
        c <- 1 + 1 - 2
    };

    mul_div(): Int {
        c <- 1 * 2 / 2
    };
};

-- testando expressões condicionais e comandos if else, while e case
Class N inherits A {
    c : Int <- 1;

    conditional_if_expression() : Int {
        (* erro: operador inválido >= *)
        if (c >= 1) then 0 else

        (* erro: palavra-chave then está faltando *)
        if (c < 2) 1 else

        (* erro: palavra-chave if está faltando *)
        (c = 2) then 2 else

        (* erro: no não é uma palavra-chave *)
        if (no(c = 1)) 3 else false 

        fi fi fi (* erro: palavra-chave fi está faltando *)
    }

    while_expression() : Int {
        {
            (* erro: palavra-chave while está faltando *)
            (c < 5) loop 
                {
                        c <- c + 1;
                }
            pool;

            (* erro: palavra-chave loop está faltando *)
            while (c < 5) 
                {
                        c <- c + 1;
                }
            (* erro: palavra-chave pool está faltando *)

            0;
        }
    };

    case_expression() : Int {
        (* erro: palavra-chave of está faltando *)
        case (c = 1)
            c : Int => 1;
            d : Int => 2;
        esac

        (* erro: palavra-chave case está faltando *)
        case (c = 1)
            (* erro: faltando tipo*)
            a : => 1
            (* erro: faltando > *)
            c : Int = 1;
            (* erro: faltando : *)
            d Int => 2;
        esac
        0
    };
};

-- testando bloco de expressão
Class O inherits A {
    
    block() : Int {
        (* erro: faltando { *)
            c <- 0;
            c <- 1;
        (* erro: faltando } *)
    };
};

-- testando expressões let
class P inherits A {
    a : Int <- b : Int <- 0, c : Int <- 1 in 2; (* erro: palavra-chave let está faltando *)
    d : Int <- let e : Int, f : Int <- 1 2; (* erro: palavra-chave in está faltando *)
};
