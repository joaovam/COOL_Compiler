(*Elementos léxicos da linguagem COOL a serem testados: inteiros, identificadores, símbolos sintáticos, strings, comentários, palavras-chave e whitespace.*)

(*Testando palavras-chave "class" e "inherits" e operadores sintáticos "{" e "}"*)
class ClasseTeste {

    contaAteDez : SELF_TYPE {
    
        (*Testando palavras-chave "let", "in", "while", "loop", "pool" e "new"*)
        (let c : Int <- 1 in {
        
            (*Testando operador sintático <=*)
            while c <= 10 loop {
            
                (new IO).out_int(c);
                c <- c + 1;
            } pool;
            self;
        })
    };
};

class Main inherits IO {

    -- Testando comentário de uma linha
    -- (*Testando comentário de uma linha
    (*Testando comentários
    multilinha*)
    (* --Testando comentários
    multilinha*)
    (*Testando(*comentários(*ani*)nha*)dos*)
    Testando comentário inválido *)
    (*Testando comentário muito longo. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
    Nulla mollis ultricies. Suspendisse scelerisque pharetra risus, id posuere nisi
    placerat quis. Phasellus eu tellus est. Suspendisse vitae vestibulum ex. Morbi dapibus
    placerat mi, porttitor porta ante gravida quis. Nunc fermentum arcu tortor, eu placerat
    magna iaculis nec. Vivamus laoreet egestas nibh sit amet mattis. Nullam euismod nunc a
    pellentesque cursus. Duis metus orci, gravida ac auctor sed, convallis vitae sapien.
    Donec luctus dictum urna. Etiam nec nulla eget justo pretium commodo vel a enim. Nunc
    eros ligula, posuere in tortor vel, laoreet vulputate tellus. In hendrerit eget lectus
    ut mattis. Curabitur non risus ut nibh gravida pretium. Interdum et malesuada fames ac
    ante ipsum primis in faucibus. Nam ac magna vestibulum, tempor nulla in, lobortis lacus.
    Integer ut mauris sed nunc congue posuere blandit sit amet erat. In aliquam magna non risus
    varius, id vestibulum nulla mattis. Cras pretium egestas justo, nec aliquam.*)

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

            (*Testando operadores lógicos e palavras-chave "if", "then", "else" e "fi"*)
            if (valido = 0) then 0 else
            if (valido <= 1) then 1 else
            if (valido < 2) then 2 else
            if (valido >= 3) then 3 else (*>= é inválido*)
            if (valido = 3) then valido++ else
            fi fi fi fi fi
            
            (*Testando valores inteiros*)
            valido <- 1234; (*Valor válido*)
            valido <- 56.78; (*Valor inválido*)
            valido <- ~9012; (*Valor negativo válido*)
            valido <- -3456; (*Valor negativo inválido*)
            
            (*Testando strings (String com EOF na ultima linha)*)
            self.out_string("Esta é uma string normal. Nada errado aqui ");
            self.out_string("Esta string \ntem quebra de linha. ");
            self.out_string("Esta string\b tem um backspace. ");
            self.out_string("Esta string \t tem um tab. ");
            self.out_string("Esta string \f tem um formfeed. ");
            self.out_string("Esta string \
                                tem um escape. ");
            self.out_string("Esta string é inválida,
                        ta faltando escape. ");
            self.out_string("Esta string tem um \0 no meio dela, troca para 0 isso ai. ");
            self.out_string("Esta string é muito longa:\
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

            (*Testando palavras-chave "true" e "false"*)
            varVerdadeira : Bool <- true;
            varVerdadeiraInvalida : Bool <- ture;
            varFalsa : Bool <- false;
            varFalsaInvalida : Bool <- fales;
            
            testeClasse : ClasseTeste <- new ClasseTeste;
            
            (*Testando palavras-chave "not" e "isvoid"*) 
            if not(isvoid(testeClasse)) then {
                testeClasse.contaAteDez();
            } else {} fi;
            
            (*Testando palavras chave "case", "esac" e "of"*)
            case of esac;

            (*Testando identificador self e operador sintático "."*)
            self.out_string("Testando self");
            self;
        }
    };
};

(*Testando string com EOF*)
"Esta string esta com EOF... That's all folks!
