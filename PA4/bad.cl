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
class T1{
	x:Int;
	x:Int;
};


-- class Bar inherits Int{

-- };

-- class X inherits NotDefined{

-- };



-- class Cir inherits Cular{

-- };

-- class Foo inherits Cir{

-- };

-- class Cular inherits Foo{

-- };