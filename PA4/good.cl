-- Utilizamos o TP 1 como molde para um programa bem escrito
class A2I {

     c2i(char : String) : Int {
	if char = "0" then 0 else
	if char = "1" then 1 else
	if char = "2" then 2 else
        if char = "3" then 3 else
        if char = "4" then 4 else
        if char = "5" then 5 else
        if char = "6" then 6 else
        if char = "7" then 7 else
        if char = "8" then 8 else
        if char = "9" then 9 else
        { abort(); 0; }  -- the 0 is needed to satisfy the typchecker
        fi fi fi fi fi fi fi fi fi fi
     };

(*
   i2c is the inverse of c2i.
*)
     i2c(i : Int) : String {
	if i = 0 then "0" else
	if i = 1 then "1" else
	if i = 2 then "2" else
	if i = 3 then "3" else
	if i = 4 then "4" else
	if i = 5 then "5" else
	if i = 6 then "6" else
	if i = 7 then "7" else
	if i = 8 then "8" else
	if i = 9 then "9" else
	{ abort(); ""; }  -- the "" is needed to satisfy the typchecker
        fi fi fi fi fi fi fi fi fi fi
     };

(*
   a2i converts an ASCII string into an integer.  The empty string
is converted to 0.  Signed and unsigned strings are handled.  The
method aborts if the string does not represent an integer.  Very
long strings of digits produce strange answers because of arithmetic 
overflow.

*)
     a2i(s : String) : Int {
        if s.length() = 0 then 0 else
	if s.substr(0,1) = "-" then ~a2i_aux(s.substr(1,s.length()-1)) else
        if s.substr(0,1) = "+" then a2i_aux(s.substr(1,s.length()-1)) else
           a2i_aux(s)
        fi fi fi
     };

(*
  a2i_aux converts the usigned portion of the string.  As a programming
example, this method is written iteratively.
*)
     a2i_aux(s : String) : Int {
	(let int : Int <- 0 in	
           {	
               (let j : Int <- s.length() in
	          (let i : Int <- 0 in
		    while i < j loop
			{
			    int <- int * 10 + c2i(s.substr(i,1));
			    i <- i + 1;
			}
		    pool
		  )
	       );
              int;
	    }
        )
     };

(*
    i2a converts an integer to a string.  Positive and negative 
numbers are handled correctly.  
*)
    i2a(i : Int) : String {
	if i = 0 then "0" else 
        if 0 < i then i2a_aux(i) else
          "-".concat(i2a_aux(i * ~1)) 
        fi fi
    };
	
(*
    i2a_aux is an example using recursion.
*)		
    i2a_aux(i : Int) : String {
        if i = 0 then "" else 
	    (let next : Int <- i / 10 in
		i2a_aux(next).concat(i2c(i - next * 10))
	    )
        fi
    };

};

class Stack{
    isNil(): Bool { true};
    head(): String { { abort(); ""; } };

    tail(): Stack { { abort(); self; } };

    push(i : String) : Stack {
        (new StackImpl).init(i, self)
    };

};

class StackImpl inherits Stack{
    head: String <- "";
    next: Stack;
    
    init(i: String, s: Stack): StackImpl{
        {
            head <- i;
            next <- s;
            self;
        }
    };
    isNil(): Bool {false};

    head(): String{ head };
    tail(): Stack { next };

};

class StackCommand{

    command :String <- "";
    
    interpretCommand(c: String, stack: Stack): Stack{
        {
            new Stack;
        }
    };
};

class StackCommandShow inherits StackCommand{
    interpretCommand(c: String, stack: Stack): Stack{
        {
            
            while (not stack.isNil()) loop
                {
                (new IO).out_string(stack.head());
                (new IO).out_string("\n");
                stack <- stack.tail();

                }
            pool;
            

            stack;
            
        }
    };
 };

class StackCommandStack inherits StackCommand{

    interpretCommand(c: String, stack: Stack): Stack{
        {
            stack.push(c);
        }
    };
};

 class StackCommandEvaluate inherits StackCommand{
    op: String <- "";
    op1: String;
    op2:String;
    
    interpretCommand(c: String, stack: Stack): Stack{
        {
            if (not stack.isNil()) then
            op <- stack.head()
            else false
            fi;

            if(op = "+") then
            {
                stack <- stack.tail();

                op1 <- stack.head();
                
                stack <- stack.tail();

                op2 <- stack.head();
                
                stack <- stack.tail();

                stack <- stack.push(sum(op1, op2));
            }
            else if(op = "s") then
            {
                stack <- stack.tail();
                op1 <- stack.head();
                stack <- stack.tail();
                op2 <- stack.head();
                stack <- stack.tail();
                stack <- stack.push(op1);
                stack <- stack.push(op2);
            }
            else false
            fi fi;

            stack;
        }
    
    };

    sum(op1:String, op2: String): String{
        {
            (new A2I).i2a((new A2I).a2i(op1) + (new A2I).a2i(op2));
        }
    };

 };


class Main inherits IO{
    stack: Stack <- new Stack;
    exec: Bool <- true;
    op: String <- "";
    main(): Object{
        {
        
        while(exec) loop
            {
            out_string(">");

            op <- in_string();

            if(op = "d") 
                then 
                  interpretCommand(new StackCommandShow, stack, op)
            
            else if (op = "x")
                then
                exec <- false
             else if(op = "e")
                 then
                 stack <- interpretCommand(new StackCommandEvaluate, stack, op)

            else stack <- interpretCommand(new StackCommandStack, stack, op)

            fi fi fi;
            
            -- else if(op = "|") 
            --     then stack <- stack.push("|")
            -- fi --fi
            }
        pool;

        out_string("Goodbye!\n");    
        }
    };

    interpretCommand(c:StackCommand, stack: Stack, s: String): Stack{
        c.interpretCommand(s, stack)
    };

};
