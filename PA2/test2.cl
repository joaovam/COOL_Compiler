(*Inteiros*) F

(*Identificadores de tipo*) A OK

(*Identificadores de objeto*) A OK

(*Identificadores self e SELF_TYPE*) A OK

(*Símbolos sintáticos*) A falta @ e => (vai ser usado no case)

(*Strings com caracteres de escape (\b, \t, \n, \f)*) F

(*Strings com \*) F

(*Strings com nova linha sem caracteres de escape ou \*) F

(*Strings com EOF*) F

(*Strings com null (caracter \0)*) F

(*Strings passando os limites do arquivo (muito longas)*) F

(*Comentários de uma linha*) A OK

(*Comentários aninhados*) A OK

(*Comentários multilinha*) A OK

(*Comentário passando os limites do arquivo (muito longos)*) A OK

(*Palavras-chave (class OK, else OK, false, fi OK, if OK, in, inherits OK, isvoid, let, loop, pool, then OK, while,
case, esac, new, of, not, true)*) F

(*Whitespace*) F

(*Testando palavra-chave "class" e "inherits" e operadores sintáticos "{" e "}"*)
class Main inherits IO {

    -- Testando comentário de uma linha
    -- (*Testando comentário de uma linha
    (*Testando comentários
    multilinha*)
    (* --Testando comentários
    multilinha*)
    (*Testando(*comentários(*ani*)nha*)dos*)
    Testando comentário inválido *)
    (*Testando comentário muito longolongolongolongolongolongolongolongolongolongolongolongolongolongo
    longolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongo
    longolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongo
    longolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongo
    longolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongo
    longolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongo
    longolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongo
    longolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongo
    longolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongo
    longolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongo
    longolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongolongo
    longolongolongolongolongolongo*)

    (*Testando identificadores de tipo e de objeto e operadores sintáticos ":" e ";"*)
    valido : Int;
    va_li_do : Int;
    valido1 : Int;
    Invalido : Int; (*Identificadores de objeto não podem começar com letra maiúscula*)
    _invalido : Int; (*Identificadores de objeto não podem começar com _*)
    1invalido : Int; (*Identificadores de objeto não podem começar com dígito*)
    in-va-li-do : Int; (*Identificadores de objeto não podem ter -*)
    in.va.li.do : Int; (*Identificadores de objeto não podem ter .*)
    invalido : int; (*Identificadores de tipo não podem começar com letra minúscula*)

    (*Testando identificador SELF_TYPE e operadores sintáticos "(" e ")"*)
    main() : SELF_TYPE {
        {
            (*Testando operador de atribuição*)
            valido <- 1;
            va_li_do <- 2;
            valido1 <- 3;

            (*Testando operadores aritméticos*)
            valido <- va_li_do + valido1;
            valido <- va_li_do - valido1;
            valido <- va_li_do * valido1;
            valido <- va_li_do / valido1;
            valido <- ~va_li_do;

            (*Testando operadores lógicos e palavras-chave*)
            if (valido = 0) then 0 else
            if (valido <= 1) then 1 else
            if (valido < 2) then 2 else
            if (valido >= 3) then 3 else (*>= é inválido*)
            if (valido = 3) then valido++ else (*valido++ é inválido*)
            fi fi fi fi fi

            (*Testando identificador self e operador sintático "."*)
            self.out_string("Testando self");
            self;
        }
    };
};