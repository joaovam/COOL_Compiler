class C {
	a : Int;
	b : Bool;
	init(x : Int, y : Bool) : C {
           {
		a <- x;
		b <- y;
		self;
           }
	};
};

class Main {
	main():C {
	 {
	  (new C).init(1,1);
	  (new C).init(1,true,3);
	  (new C).iinit(1,true);
	  (new C);
	 }
	};
};

--Nao tem como testar todos os erros de classe pois após alguns deles o programa deve finalizar com erro
-- comentar os testes abaixo caso necessário
class T1{
	x:Int;
	x:Int;
};

--Redefinition of class Int
class Int{

};

-- Inherits of primitive class
class Bar inherits Int{

};

-- Inherits not defined class
class X inherits NotDefined{

};


-- Circular inheritance
class Cir inherits Cular{

};

class Foo inherits Cir{

};

class Cular inherits Foo{

};