(*Inteiros*) F OK

(*Identificadores de tipo*) A OK

(*Identificadores de objeto*) A OK

(*Identificadores self e SELF_TYPE*) A OK

(*Símbolos sintáticos*) A falta @ e => (vai ser usado no case)

(*Strings com caracteres de escape (\b, \t, \n, \f)*) F OK

(*Strings com \*) F OK

(*Strings com nova linha sem caracteres de escape ou \*) F OK

(*Strings com EOF*) F OK

(*Strings com null (caracter \0)*) F OK

(*Strings passando os limites do arquivo (muito longas)*) F OK

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
            
            (*Testando valores inteiros*)
            valido <- 1234; -- Valor valido
            valido <- 56.78; -- Valor invalido;
            valido <- ~9012; -- Valor negativo valido
            valido <- -3456; -- Valor negativo invalido
            
            (*Testando strings (String com EOF na ultima linha)*)
            out_string("Esta eh uma string normal. Nada errado aqui ");
            out_string("Esta string \ntem quebra de linha. ");
            out_string("Esta string\b tem um backspace. ");
            out_string("Esta string \t tem um tab. ");
            out_string("Esta string \f tem um formfeed. ");
            out_string("Esta string \ 
                        tem um escape. ");
            out_string("Esta string eh invalida,
                        ta faltando escape. ");
            out_string("Esta string tem um null \0 no meio dela, ta errado isso ai. ");
            out_string("Esta string eh muito longa:\ 
            Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis vestibulum lorem at\
            nulla mollis ultricies. Suspendisse scelerisque pharetra risus, id posuere nisi\
            placerat quis. Phasellus eu tellus est. Suspendisse vitae vestibulum ex. Morbi dapibus\
            placerat mi, porttitor porta ante gravida quis. Nunc fermentum arcu tortor, eu placerat\
            magna iaculis nec. Vivamus laoreet egestas nibh sit amet mattis. Nullam euismod nunc a\
            pellentesque cursus. Duis metus orci, gravida ac auctor sed, convallis vitae sapien.\
            Donec luctus dictum urna. Etiam nec nulla eget justo pretium commodo vel a enim. Nunc\
            eros ligula, posuere in tortor vel, laoreet vulputate tellus. In hendrerit eget lectus\
            ut mattis. Curabitur non risus ut nibh gravida pretium. Interdum et malesuada fames ac\
            ante ipsum primis in faucibus. Nam ac magna vestibulum, tempor nulla in, lobortis lacus.\
            Integer ut mauris sed nunc congue posuere blandit sit amet erat. In aliquam magna non risus\
            varius, id vestibulum nulla mattis. Cras pretium egestas justo, nec aliquam. ");
            

            (*Testando identificador self e operador sintático "."*)
            self.out_string("Testando self");
            self;
        }
    };
};

(*Testando string com EOF*)
"Esta string esta com EOF... That's all folks!
