
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <symtab.h>
#include "semant.h"
#include "utilities.h"

extern int semant_debug;
extern char *curr_filename;

//////////////////////////////////////////////////////////////////////
//
// Symbols
//
// For convenience, a large number of symbols are predefined here.
// These symbols include the primitive type and method names, as well
// as fixed names used by the runtime system.
//
//////////////////////////////////////////////////////////////////////
static Symbol 
    arg,
    arg2,
    Bool,
    concat,
    cool_abort,
    copy,
    Int,
    in_int,
    in_string,
    IO,
    length,
    Main,
    main_meth,
    No_class,
    No_type,
    Object,
    out_int,
    out_string,
    prim_slot,
    self,
    SELF_TYPE,
    Str,
    str_field,
    substr,
    type_name,
    val;

//
// Initializing the predefined symbols.
//
static void initialize_constants(void)
{
    arg         = idtable.add_string("arg");
    arg2        = idtable.add_string("arg2");
    Bool        = idtable.add_string("Bool");
    concat      = idtable.add_string("concat");
    cool_abort  = idtable.add_string("abort");
    copy        = idtable.add_string("copy");
    Int         = idtable.add_string("Int");
    in_int      = idtable.add_string("in_int");
    in_string   = idtable.add_string("in_string");
    IO          = idtable.add_string("IO");
    length      = idtable.add_string("length");
    Main        = idtable.add_string("Main");
    main_meth   = idtable.add_string("main");
    //   _no_class is a symbol that can't be the name of any 
    //   user-defined class.
    No_class    = idtable.add_string("_no_class");
    No_type     = idtable.add_string("_no_type");
    Object      = idtable.add_string("Object");
    out_int     = idtable.add_string("out_int");
    out_string  = idtable.add_string("out_string");
    prim_slot   = idtable.add_string("_prim_slot");
    self        = idtable.add_string("self");
    SELF_TYPE   = idtable.add_string("SELF_TYPE");
    Str         = idtable.add_string("String");
    str_field   = idtable.add_string("_str_field");
    substr      = idtable.add_string("substr");
    type_name   = idtable.add_string("type_name");
    val         = idtable.add_string("_val");
}

////////////////////////////////////////////////////////////////////
//                          CLASS TABLE
////////////////////////////////////////////////////////////////////

ClassTable::ClassTable(Classes classes) : semant_errors(0) , error_stream(cerr) {
    install_basic_classes();
}

void ClassTable::install_basic_classes() {

    // The tree package uses these globals to annotate the classes built below.
    //curr_lineno  = 0;
    Symbol filename = stringtable.add_string("<basic class>");
    
    // The following demonstrates how to create dummy parse trees to
    // refer to basic Cool classes.  There's no need for method
    // bodies -- these are already built into the runtime system.
    
    // IMPORTANT: The results of the following expressions are
    // stored in local variables.  You will want to do something
    // with those variables at the end of this method to make this
    // code meaningful.

    // 
    // The Object class has no parent class. Its methods are
    //        abort() : Object    aborts the program
    //        type_name() : Str   returns a string representation of class name
    //        copy() : SELF_TYPE  returns a copy of the object
    //
    // There is no need for method bodies in the basic classes---these
    // are already built in to the runtime system.

    Class_ Object_class =
	class_(Object, 
	       No_class,
	       append_Features(
			       append_Features(
					       single_Features(method(cool_abort, nil_Formals(), Object, no_expr())),
					       single_Features(method(type_name, nil_Formals(), Str, no_expr()))),
			       single_Features(method(copy, nil_Formals(), SELF_TYPE, no_expr()))),
	       filename);

    // 
    // The IO class inherits from Object. Its methods are
    //        out_string(Str) : SELF_TYPE       writes a string to the output
    //        out_int(Int) : SELF_TYPE            "    an int    "  "     "
    //        in_string() : Str                 reads a string from the input
    //        in_int() : Int                      "   an int     "  "     "
    //
    Class_ IO_class = 
	class_(IO, 
	       Object,
	       append_Features(
			       append_Features(
					       append_Features(
							       single_Features(method(out_string, single_Formals(formal(arg, Str)),
										      SELF_TYPE, no_expr())),
							       single_Features(method(out_int, single_Formals(formal(arg, Int)),
										      SELF_TYPE, no_expr()))),
					       single_Features(method(in_string, nil_Formals(), Str, no_expr()))),
			       single_Features(method(in_int, nil_Formals(), Int, no_expr()))),
	       filename);  

    //
    // The Int class has no methods and only a single attribute, the
    // "val" for the integer. 
    //
    Class_ Int_class =
	class_(Int, 
	       Object,
	       single_Features(attr(val, prim_slot, no_expr())),
	       filename);

    //
    // Bool also has only the "val" slot.
    //
    Class_ Bool_class =
	class_(Bool, Object, single_Features(attr(val, prim_slot, no_expr())),filename);

    //
    // The class Str has a number of slots and operations:
    //       val                                  the length of the string
    //       str_field                            the string itself
    //       length() : Int                       returns length of the string
    //       concat(arg: Str) : Str               performs string concatenation
    //       substr(arg: Int, arg2: Int): Str     substring selection
    //       
    Class_ Str_class =
	class_(Str, 
	       Object,
	       append_Features(
			       append_Features(
					       append_Features(
							       append_Features(
									       single_Features(attr(val, Int, no_expr())),
									       single_Features(attr(str_field, prim_slot, no_expr()))),
							       single_Features(method(length, nil_Formals(), Int, no_expr()))),
					       single_Features(method(concat, 
								      single_Formals(formal(arg, Str)),
								      Str, 
								      no_expr()))),
			       single_Features(method(substr, 
						      append_Formals(single_Formals(formal(arg, Int)), 
								     single_Formals(formal(arg2, Int))),
						      Str, 
						      no_expr()))),
	       filename);

    this->class_index[Object] = Object_class;
    this->class_index[IO] = IO_class;
    this->class_index[Int] = Int_class;
    this->class_index[Bool] = Bool_class;
    this->class_index[Str] = Str_class;
}

bool ClassTable::install_custom_classes(Classes classes){
    for(int i = classes->first(); classes->more(i); i = classes->next(i)){
        Class_ current = classes->nth(i);
        Symbol class_name = current->get_name();

        //cout << "Passing through class: " << class_name << endl;

        if (class_name == Int || 
        class_name == Bool ||
        class_name == Str ||
        class_name == SELF_TYPE ||
        class_name == Object) {
            semant_error(current) << "Redefinition of " << class_name << " is not allowed. \n";
            return false;
        } else if (this->class_index.find(class_name) != class_index.end()) {
            semant_error(current) << "Class " << class_name <<" is already defined. \n";
            return false;
        } else {
            //cout << "Indexing class: " << class_name << endl;
            this->class_index[class_name] = current;
        }
    }
    return true;
}

bool ClassTable::build_inheritance_graph(){ // builds inheritance graph
    for (auto const& class_map : this->class_index){
        Symbol name = class_map.first; // first position of map;
        if(name != Object){ // class object has no antecessor
            Class_ definition = class_map.second;
            Symbol parent_name = definition->get_parent_name();
            parent_index[name] = parent_name;
            
            if (this->class_index.find(parent_name) ==this->class_index.end()) {
                semant_error(definition) << "Class " << name << " inherits from undefined class " << parent_name << ".\n"; 
                return false;
            } 
            
            if (parent_name == Int || 
            parent_name == Bool ||
            parent_name == Str ||
            parent_name == SELF_TYPE) {
                semant_error(definition) << "Class " << name <<" cannot inherit from primitive class " << parent_name << ".\n";
                return false;
            }

            if (this->inheritance_graph.find(parent_name) == this->inheritance_graph.end()) {
                this->inheritance_graph[parent_name] = std::vector<Symbol>();
            }

            this->inheritance_graph[parent_name].push_back(name);
        }
    }
    return true;
}

enum NodeColor {white, gray, black};
std::map<Symbol, NodeColor> color;

bool ClassTable::search_for_cycle_in_inheritance_graph(){

    color.clear();

    for(auto const& c : this->class_index){
        color[c.first] = white;
        //std::cout << "Class: " << c.first << endl;
    }

    for(auto const& c : this->class_index){
        if(color[c.first] == white)
            if(!this->inheritance_graph_dfs(c.first))
                return false;
    }
    return true;
}

bool ClassTable::inheritance_graph_dfs(Symbol symbol){

    //std::cout << "Color of symbol: " << color[symbol] <<std::endl;

    color[symbol] = gray;//visiting the vertex

    for (auto const& current: inheritance_graph[symbol]){

        //std::cout << "Edge between: " << symbol <<" and " <<current << std::endl;
        //std::cout << "Color of Current: " << color[current] <<std::endl;

        if(color[current] == gray){
            semant_error() << "There is a circular inheritance with class " << current << " and " << symbol <<".\n";
            return false;
        }
        
        if(!inheritance_graph_dfs(current)){
            return false;
        }

    }
    color[symbol] = black;
    return true;
    
}

Symbol ClassTable::least_upper_bound(Symbol x, Symbol y){//returns the least commom ancestor from x and y
    std::set<Symbol> ancestors;

    Symbol current = x;

    while(current != Object){
        ancestors.insert(current);
        current = this->parent_index[current];

    }

    current = y;
    while(current != Object){
        if(ancestors.find(current)!= ancestors.end()){
            return current;
        }
        current = this->parent_index[current];
    }
    return Object;
}

bool ClassTable:: is_type_defined(Symbol x){//checks if type x is defined
    return this->class_index.find(x) != this->class_index.end();
}

bool ClassTable::is_primitive(Symbol symbol) {//tells if a class is a primitive
    return symbol == Object ||symbol == IO     ||symbol == Int    ||symbol == Bool   ||symbol == Str;
}

Symbol ClassTable::get_parent(Symbol x){//returns the name of the parent class of class x
    if(this->parent_index.find(x) == this->parent_index.end())
        return No_type;
    
    return this->parent_index[x];
}

bool ClassTable::check_if_classTable_is_ok(){
    if(!this->search_for_cycle_in_inheritance_graph()){
        return false;
    }

    if(! this->is_type_defined(Main)){
            semant_error() << "No definition of Main found. \n";
            return false;
    }
    return true;
}

std::map<Symbol, method_class*> retrieve_methods_from_class(Class_ class_definition){
    std::map<Symbol, method_class*> methods;

    Symbol name = class_definition->get_name();
    Features features = class_definition->get_features();

    for(int i = features->first(); features->more(i); i = features->next(i)){
        Feature f = features->nth(i);
        if(f->is_method()){
            method_class * method = static_cast<method_class*>(f);
            Symbol method_name = method->get_name();

            if(methods.find(method_name) != methods.end()){
                classtable->semant_error(class_definition) << "Method " << method_name << "already defined previously\n";
            }else{
                methods[method_name] = method;
            }
        }
    }
    return methods;
}

std::map<Symbol, attr_class*> retrieve_attrs_from_class(Class_ class_definition){
    std::map<Symbol, attr_class*> attrs;

    Symbol name = class_definition->get_name();
    Features features = class_definition->get_features();

    for(int i = features->first(); features->more(i); i = features->next(i)){
        Feature f = features->nth(i);

        if(f->is_attr()){

            attr_class * attr = static_cast<attr_class*>(f);
            Symbol attr_name = attr->get_name();
            //std::cout << "checking attr: " << attr->get_name() <<endl;

            if(attrs.find(attr_name) != attrs.end()){//checks if attr is already defined, should not stop error recon
                classtable->semant_error(class_definition) << "Attribute " << attr_name << " already defined previously\n";

            }

            //std::cout << "indexing attr: " << attr->get_name() <<endl;
            attrs[attr_name] = attr;
            
        }
    }
    return attrs;
}

method_class* get_class_method(Symbol class_name, Symbol meth_name){
    std::map<Symbol, method_class*> methods = class_methods[class_name];

    if(methods.find(meth_name) == methods.end()){
        return nullptr;
    }
    return methods[meth_name];
}

attr_class* get_class_attr(Symbol class_name, Symbol attr_name){
    std::map<Symbol, attr_class*> attrs = class_attrs[class_name];

    if(attrs.find(attr_name) == attrs.end()){//there is no such attribute specified
        return nullptr;
    }
    return attrs[attr_name];
}

void register_class_methods_and_attrs(Class_ definition){
    class_methods[definition->get_name()] = retrieve_methods_from_class(definition);
    class_attrs[definition->get_name()] = retrieve_attrs_from_class(definition);
}

////////////////////////////////////////////////////////////////////
//                          TYPECHECKING
////////////////////////////////////////////////////////////////////

// Adiciona cada atributo para o escopo da classe, incluso os herdados
void build_attribute_scopes(Class_ current_class) {
    symbol_table->enterscope();
    symbol_table->addid(self, new Symbol(current_class_definition->get_name()));

    std::map<Symbol, attr_class*> attrs = retrieve_attrs_from_class(current_class);
    for(const auto &x : attrs) {
        attr_class* attr_definition = x.second;
        objects_table->addid(
            attr_definition->get_name(), 
            new Symbol(attr_definition->get_type())
        );
    }

    if(current_class->get_name() == Object)
        return;

    Symbol parent_type = classtable->get_parent(current_class->get_name());
    Class_ parent_definition = classtable->class_index[parent_type];
    build_attribute_scopes(parent_definition);
}

// Checa se atributos existem na classe herdada
void process_attributes(Class_ current_class, attr_class* attr){
    if(get_class_attr(current_class->get_name(), attr->get_name()) != nullptr){
        classtable->semant_error(class_definition) 
            << "Attribute " << attr_name << " already defined on an inherited class.\n";
        error();
    }
    
    Symbol parent_name = classtable->get_parent(current_class->get_name());
    if (parent_name == No_type)
        return;
    Class_ parent_definition = classtable->class_index[parent_name];
    process_attributes(parent_definition, attr);
}

// Checagem de metodos para caso de Override
void process_method(Class_ current_class, method_class* original_method, method_class* parent_method){
    // Verificando se há metodo de mesmo nome na classe pai.
    if (parent_method == nullptr) return;

    Symbol parent_name = classtable->get_parent(current_class->get_name());
    if (parent_name == No_type)
        return;

    // Garatindo que o metodo sobrescrito mantém o mesmo tipo de retorno.
    if (original_method->get_return_type() != parent_method->get_return_type()){
        classtable->semant_error(current_class)
            << "In the method overrided " << original_method->get_name()
            << ", the return type " << original_method->get_return_type()
            << " is different from inherited method type " 
            << parent_method->get_return_type() << ".\n";
    }

    // Garatindo que o numero de argumentos se mantém  
    Formals original_method_args = original_method->get_formals();
    Formals parent_method_args = parent_method->get_formals();

    int n_original_method_args = 0;
    int n_parent_method_args = 0;

    while (original_method_args->more(n_original_method_args)){
        n_original_method_args = original_method_args->next(n_original_method_args);
    }
    while (parent_method_args->more(n_parent_method_args)){
        n_parent_method_args = parent_method_args->next(n_parent_method_args);
    }

    if(n_original_method_args != n_parent_method_args){
        classtable->semant_error(current_class)
            << "In the method overrided " << original_method->get_name()
            << ", the number of arguments " << n_original_method_args
            << " is different from inherited method number of arguments " 
            << "(" << parent_method->get_return_type() << ")" << ".\n";
    }

    // Garatindo que os argumentos são de mesmo tipo
    n_original_method_args = 0;
    n_parent_method_args = 0;
    
    while(
        original_method_args->more(n_original_method_args) &&
        parent_method_args->more(n_parent_method_args))
    {
        Formal original_formal = original_method_args->nth(n_original_method_args);
        Formal parent_formal = parent_method_args->nth(n_parent_method_args);

        if(original_formal->get_type() != parent_formal->get_type()){
            classtable->semant_error(current_class)
                << "In the method overrided " << original_method->get_name()
                << ", the type of argument " << original_formal->get_name()
                << " (" << original_formal->get_type() << ")" 
                << " is different from the corresponding inherited method argument "
                << parent_formal->get_name() << " (" << parent_formal->get_type() << ")" 
                << ".\n";
            }

        n_original_method_args = original_method_args->next(n_original_method_args);
        n_parent_method_args = parent_method_args->next(n_parent_method_args);
    }

    Class_ parent_class_definition = classtable->class_index[parent_name];

    process_method(
        parent_class_definition,
        original_method,
        get_class_method(
            parent_name,
            original_method->get_name()
        )
    )
}

void type_check(Class_ next_class) {
    current_class_name = next_class->get_name();
    current_class_definition = next_class;
    current_class_methods = retrieve_methods_from_class(next_class);
    current_class_attrs = retrieve_attrs_from_class(next_class);

    symbol_table = new SymbolTable<Symbol, Symbol>();
    build_attribute_scopes(next_class);
    
    for (const auto &x : current_class_methods) {
        process_method(next_class, x.second, x.second);
    }

    for (const auto &x : current_class_attrs) {
        Symbol parent_name = classtable->get_parent(current_class_name);
        Class_ parent_definition = classtable->class_index[parent_name];
        process_attributes(parent_definition, x.second);
    }

    for (const auto &x : current_class_attrs) {
        x.second->type_check();
    }

    for (const auto &x : current_class_methods) {
        x.second->type_check();
    }
}

Symbol int_const_class::type_check() {
    this->set_type(Int);
    return Int;
}

Symbol bool_const_class::type_check() {
    this->set_type(Bool);
    return Bool;
}

Symbol string_const_class::type_check() {
    this->set_type(Str);
    return Str;
}

Symbol object_class::type_check() {
    if (name == self) {
        this->set_type(SELF_TYPE);
        return SELF_TYPE;
    }

    Symbol* object_type = symbol_table->lookup(name);
    if (object != nullptr){
        this->set_type(*object_type);
        return *object_type;
    }

    this->set_type(Object);
    classtable->semant_error(this)
        << "The object "
        << name
        << " is undefined in this scope.\n";
    return Object;
}

method_class* get_method_def_in_inheritance(Symbol class_name,Symbol method_name){
    if (class_name == No_type)
        return nullptr;

    method_class* def = get_class_method(class_name,method_name);
    if (def)
        return def;

    Symbol parent_name = classtable->get_parent(class_name);
    return get_method_def_in_inheritance(class_name, method_name);
}

method_class* get_method_def(Symbol class_name, Symbol method_name){
    method_class* method = get_method_def_in_inheritance(class_name, method_name);

    if (method)
        return method;

    if (classtable->is_primitive(class_name)){
        return get_class_method(class_name, method_name);
    }
    return nullptr;
}

////////////////////////////////////////////////////////////////////
//
// semant_error is an overloaded function for reporting errors
// during semantic analysis.  There are three versions:
//
//    ostream& ClassTable::semant_error()                
//
//    ostream& ClassTable::semant_error(Class_ c)
//       print line number and filename for `c'
//
//    ostream& ClassTable::semant_error(Symbol filename, tree_node *t)  
//       print a line number and filename
//
///////////////////////////////////////////////////////////////////

ostream& ClassTable::semant_error(Class_ c)
{                                                             
    return semant_error(c->get_filename(),c);
}    

ostream& ClassTable::semant_error(Symbol filename, tree_node *t)
{
    error_stream << filename << ":" << t->get_line_number() << ": ";
    return semant_error();
}

ostream& ClassTable::semant_error()                  
{                                                 
    semant_errors++;                            
    return error_stream;
} 




void error(){
    
    cerr << "Compilation halted due to static semantic errors." << endl;
    exit(1);
}

/*   This is the entry point to the semantic checker.

     Your checker should do the following two things:

     1) Check that the program is semantically correct
     2) Decorate the abstract syntax tree with type information
        by setting the `type' field in each Expression node.
        (see `tree.h')

     You are free to first do 1), make sure you catch all semantic
     errors. Part 2) can be done in a second stage, when you want
     to build mycoolc.
 */
void program_class::semant()
{
    initialize_constants();

    /* ClassTable constructor may do some semantic analysis */
    classtable = new ClassTable(classes);

    /* some semantic analysis code may go here */
    if(!classtable->install_custom_classes(classes)){
        error();
    }
    
    //build the inheritance graph using a map
    if(!classtable->build_inheritance_graph())
        error();

    //checks if the classtable is acyclic and has no inheritance from undefined class
    if(!classtable->check_if_classTable_is_ok())
        error();

    //registering all the methods and attributes on a map indexed by the name of the class
    for(auto const& x : classtable->class_index)
        register_class_methods_and_attrs(x.second);
    
    //typechecking all classes, attributes, methods, expressions, etc.
    for (int i = 0; classes->more(i); i = classes->next(i))
        type_check(classes->nth(i));

    //exits with error in case of semantic problems
    if(classtable->errors())
        error();
    

    
}


