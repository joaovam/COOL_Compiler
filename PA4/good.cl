-- Utilizamos o TP 1 como molde para um programa bem escrito
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
