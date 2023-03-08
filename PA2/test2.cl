(*Inteiros*) F

(*Identificadores de tipo*) A OK

(*Identificadores de objeto*) A OK

(*Identificadores self e SELF_TYPE*) A OK

(*Símbolos sintáticos*) A

(*Strings com caracteres de escape (\b, \t, \n, \f)*) F

(*Strings com \*) F

(*Strings com nova linha sem caracteres de escape ou \*) F

(*Strings com EOF*) F

(*Strings com null (caracter \0)*) F

(*Strings passando os limites do arquivo (muito longas)*) F

(*Comentários de uma linha*) A OK

(*Comentários aninhados*) A OK

(*Comentários multilinha*) A OK

(*Comentário passando os limites do arquivo (muito longos)*) A

(*Palavras-chave (class, else, false, fi, if, in, inherits, isvoid, let, loop, pool, then, while,
case, esac, new, of, not, true)*) F

(*Whitespace*) F


class Main {
    (*Testando identificadores de tipo e de objeto*)
    this_is_valid : Object;
    this_is_valid1 : Object;
    This_is_not_valid : Object;
    _this_is_not_valid : Object;
    1this_is_not_valid : Object;
    this-is-not-valid : Object;
    this.is.not.valid : Object;
    this_is_not_valid1 : object;

    -- Testando comentário de uma linha
    -- (*Testando comentário de uma linha
    (*Testando comentários
    multilinha*)
    (* --Testando comentários
    multilinha*)
    (*Testando(*comentários(*ani*)nha*)dos*)
    Testando comentário inválido *)

    (*Testando identificador SELF_TYPE*)
    main() : SELF_TYPE {
        {
            (*Testando identificador self*)
            self.out_string("Teste");
            self;
        }
    };
};