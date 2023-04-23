-- testando classe sem métodos
class A {
};

-- testando método vazio
Class BB__ inherits A {
    empty_feature() : Int {
    };
};

-- testando classe com um método
Class C {
    feature() : Int {
        0
    };
};

-- testando parâmetros formais, vários métodos em uma classe e inicialização de atributos
Class D inherits A {
    c : Int;
    d : Int <- 0;

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

-- testando expressões aritméticas
Class E inherits A {
    c : Int <- 1 * 2;

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

-- testando expressões condicionais e comandos if else, while e case
Class F inherits A {
    c : Int <- 1;

    conditional_if_expression() : Int {
        if (c <= 1) then 0 else
        if (c < 2) then 1 else
        if (c = 2) then 2 else
        if (not(c = 1)) then 3 else false
        fi fi fi fi
    };

    while_expression() : Int {
        {
            while (c < 5) loop 
                {
                        c <- c + 1;
                }
            pool;
            0;
        }
    };

    case_expression() : Int {
        0
        -- FALTANDO!!!
    }
};

-- testando bloco de expressão
Class G inherits A {
    block() : Int {
        {
            c <- 0;
            c <- 1;
        }
    };
};

-- testando expressões let
class H inherits A {
    a : Int <- let b : Int <- 0, c : Int <- 1 in 2;
    d : Int <- let e : Int, f : Int <- 1 in 2;
};