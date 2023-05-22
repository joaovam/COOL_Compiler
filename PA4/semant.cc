
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <symtab.h>
#include "semant.h"
#include "utilities.h"

extern int semant_debug;
extern char *curr_filename;

// ------------------ SÍMBOLOS ------------------
// Por conveniência, um grande número de símbolos é predefinido aqui.
// Esses símbolos incluem o tipo primitivo e os nomes dos métodos, bem como
// como nomes fixos usados ​​pelo sistema de tempo de execução.
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

static void initialize_constants(void){ // Inicializando símbolos pré-definidos
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
    // _no_class é um símbolo que não pode ser o nome de nenhuma classe definida pelo usuário.
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


// ------------------ TABELA DE CLASSES ------------------

ClassTable::ClassTable(Classes classes) : semant_errors(0) , error_stream(cerr){
    install_basic_classes();
}

void ClassTable::install_basic_classes(){

    // O pacote tree usa esses globais para anotar as classes construídas abaixo.
    Symbol filename = stringtable.add_string("<basic class>");

    // A seguir é demonstrado como criar árvores parse para as classes básicas do Cool.
    // Os resultados das seguintes expressões são armazenados em variáveis ​​locais.

    // A classe Object não tem classe pai. Seus métodos são:
    // abort() : Object - aborta o programa
    // type_name() : Str - retorna uma string representando o nome da classe
    // copy() : SELF_TYPE - retorna uma cópia do objeto
    Class_ Object_class =
	class_(Object, 
	       No_class,
	       append_Features(
			       append_Features(
					       single_Features(method(cool_abort, nil_Formals(), Object, no_expr())),
					       single_Features(method(type_name, nil_Formals(), Str, no_expr()))),
			       single_Features(method(copy, nil_Formals(), SELF_TYPE, no_expr()))),
	       filename);

    // A classe IO herda da classe Object. Seus métodos são:
    // out_string(Str) : SELF_TYPE - escreve uma string para a saída
    // out_int(Int) : SELF_TYPE - escreve um inteiro para a saída
    // in_string() : Str - lê uma string da saída
    // in_int() : Int - lê um inteiro da saída
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

    // A classe Int não tem métodos e tem apenas o atributo "val" para o inteiro.
    Class_ Int_class =
	class_(Int, 
	       Object,
	       single_Features(attr(val, prim_slot, no_expr())),
	       filename);

    // A classe Bool também tem apenas o atributo "val".
    Class_ Bool_class =
	class_(Bool, Object, single_Features(attr(val, prim_slot, no_expr())),filename);

    // A classe Str tem os seguintes atributos e métodos:
    // val - tamanho da string
    // str_field - a string
    // length() : Int - retorna o tamanho da string
    // concat(arg: Str) : Str - concatenação de string
    // substr(arg: Int, arg2: Int): Str - seleção de substring
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

        if (class_name == Int || 
        class_name == Bool ||
        class_name == Str ||
        class_name == SELF_TYPE ||
        class_name == Object) {
            semant_error(current) << "Redefinição de " << class_name << " não é permitida. \n";
            return false;
        } else if (this->class_index.find(class_name) != class_index.end()) {
            semant_error(current) << "Classe " << class_name <<" já está definida. \n";
            return false;
        } else this->class_index[class_name] = current;
    }
    return true;
}

bool ClassTable::build_inheritance_graph(){ // Constrói grafo de herança
    for (auto const& class_map : this->class_index){
        Symbol name = class_map.first; // Primeira posição do map
        if(name != Object){ // Classe Object não tem antecessor
            Class_ definition = class_map.second;
            Symbol parent_name = definition->get_parent_name();
            parent_index[name] = parent_name;
            
            if (this->class_index.find(parent_name) ==this->class_index.end()) {
                semant_error(definition) << "Classe " << name << " herda de classe indefinida " << parent_name << ".\n"; 
                return false;
            } 
            
            if (parent_name == Int || 
            parent_name == Bool ||
            parent_name == Str ||
            parent_name == SELF_TYPE) {
                semant_error(definition) << "Classe " << name <<" não herda da classe primitiva" << parent_name << ".\n";
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
    }

    for(auto const& c : this->class_index){
        if(color[c.first] == white)
            if(!this->inheritance_graph_dfs(c.first))
                return false;
    }
    return true;
}

bool ClassTable::inheritance_graph_dfs(Symbol symbol){
    color[symbol] = gray; // Visitando o vértice

    for (auto const& current: inheritance_graph[symbol]){
        if(color[current] == gray){
            semant_error() << "Há uma herança circular com as classes " << current << " e " << symbol <<".\n";
            return false;
        }
        
        if(!inheritance_graph_dfs(current)){
            return false;
        }
    }
    color[symbol] = black;
    return true;
}

bool ClassTable::is_subtype(Symbol x, Symbol y){
    if(x == No_type){
        return true;
    }

    if(x == SELF_TYPE){
        if(y == SELF_TYPE){
            return true;
        }
        else
            x = current_class_name;
    }

    Symbol current = x;

    while(current != Object && current != y){
        current = parent_index[current];
    }

    return current == y;
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

bool ClassTable:: is_type_defined(Symbol x){ // Checa se o tipo x já foi definido
    return this->class_index.find(x) != this->class_index.end();
}

bool ClassTable::is_primitive(Symbol symbol) { // Checa se uma classe é primitiva
    return symbol == Object ||symbol == IO     ||symbol == Int    ||symbol == Bool   ||symbol == Str;
}

Symbol ClassTable::get_parent(Symbol x){ // Retorna o nome da classe pai da classe x
    if(this->parent_index.find(x) == this->parent_index.end())
        return No_type;
    
    return this->parent_index[x];
}

bool ClassTable::check_if_classTable_is_ok(){
    if(!this->search_for_cycle_in_inheritance_graph()){
        return false;
    }

    if(! this->is_type_defined(Main)){
            semant_error() << "Nenhuma definição de Main encontrada. \n";
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

            if(methods.find(method_name) != methods.end()){ // Checa se o método já foi definido
                classtable->semant_error(class_definition) << "Método " << method_name << "já foi definido.\n";
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

            if(attrs.find(attr_name) != attrs.end()){ // Checa se o atributo já foi definido
                classtable->semant_error(class_definition) << "Atributo " << attr_name << " já foi definido.y\n";

            }
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

    if(attrs.find(attr_name) == attrs.end()){
        return nullptr;
    }
    return attrs[attr_name];
}

void register_class_methods_and_attrs(Class_ definition){
    class_methods[definition->get_name()] = retrieve_methods_from_class(definition);
    class_attrs[definition->get_name()] = retrieve_attrs_from_class(definition);
}


// ------------------ CHECAGEM DE TIPO ------------------

void build_attribute_scopes(Class_ current_class){ // Adiciona cada atributo para o escopo da classe, incluindo os herdados
    symbol_table->enterscope();
    symbol_table->addid(self, new Symbol(current_class_definition->get_name()));

    std::map<Symbol, attr_class*> attrs = retrieve_attrs_from_class(current_class);
    for(const auto &x : attrs) {
        attr_class* attr_definition = x.second;
        symbol_table->addid(
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

void process_attributes(Class_ current_class, attr_class* attr){ // Checa se atributos existem na classe herdada
    if(get_class_attr(current_class->get_name(), attr->get_name()) != nullptr){
        classtable->semant_error(current_class_definition) 
            << "Atributo " << attr->get_name() << " já definido na classe herdada.\n";
        error();
    }
    
    Symbol parent_name = classtable->get_parent(current_class->get_name());
    if (parent_name == No_type)
        return;
    Class_ parent_definition = classtable->class_index[parent_name];
    process_attributes(parent_definition, attr);
}

void process_method(Class_ current_class, method_class* original_method, method_class* parent_method){ // Checagem de metodos para caso de Override
    // Verificando se há metodo de mesmo nome na classe pai.
    if (parent_method == nullptr) return;

    Symbol parent_name = classtable->get_parent(current_class->get_name());
    if (parent_name == No_type)
        return;

    // Garatindo que o metodo sobrescrito mantém o mesmo tipo de retorno.
    if (original_method->get_return_type() != parent_method->get_return_type()){
        classtable->semant_error(current_class)
            << "No método " << original_method->get_name()
            << ", o tipo do retorno " << original_method->get_return_type()
            << " é diferente do tipo do método herdado " 
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
            << "No método " << original_method->get_name()
            << ", o número de argumentos " << n_original_method_args
            << " é diferente do número de argumentos do método herdado " 
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
                << "No método " << original_method->get_name()
                << ", o tipo do argumento " << original_formal->get_name()
                << " (" << original_formal->get_type() << ")" 
                << " é diferente do método herdado correspondente "
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
    );
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
        << "O objeto "
        << name
        << " é indefinido nesse escopo.\n";
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

Symbol no_expr_class::type_check() {
    this->set_type(No_type);
    return No_type;
}

Symbol isvoid_class::type_check() {
    e1->type_check();
    this->set_type(Bool);
    return Bool;
}

Symbol new__class::type_check() {
    if(type_name != SELF_TYPE && !classtable->is_type_defined(type_name))
    {
        this->set_type(Object);
        classtable->semant_error(this)
            << "Tentativa de instanciar um objeto de tipo indefinido: "
            << type_name
            << " .\n";
        return Object;
    }
    this->set_type(type_name);
    return type_name;
}

Symbol comp_class::type_check() {
    Symbol expr_type = e1->type_check();
    if (expr_type == Bool) {
        this->set_type(expr_type);
        return expr_type;
    }
    this->set_type(Object);
    classtable->semant_error(this)
        << "Argumento de 'not' possui tipo " 
        << expr_type 
        << " ao invés de Bool.\n";
    return Object;
}

Symbol leq_class::type_check() {
    Symbol left_type = e1->type_check();
    Symbol right_type = e2->type_check();

    if(left_type == Int && right_type == Int) {
        this->set_type(Bool);
        return Bool;
    }
    else
    {
        this->set_type(Object);
        classtable->semant_error(this) 
            << "Ambos os argumentos do operador <= deveriam ser do tipo Int"
            << " mas os argumentos são do tipo "
            << left_type
            << " e "
            << right_type
            << ".\n";
    }
    return this->get_type();
}

Symbol eq_class::type_check() {
    Symbol left_type = e1->type_check();
    Symbol right_type = e2->type_check();
    
    bool is_left_type_primitive = left_type == Int || left_type == Bool || left_type == Str;
    bool is_right_type_primitive = right_type == Int || right_type == Bool || right_type == Str;

    if ((is_left_type_primitive && is_right_type_primitive) && left_type != right_type)
    {
        classtable->semant_error(this) << "Comparação não permitida com tipo primitivo.\n";
    }

    this->set_type(Bool);
    return Bool;
}

Symbol lt_class::type_check() {
    Symbol left_type = e1->type_check();
    Symbol right_type = e2->type_check();

    if(left_type == Int && right_type == Int) {
        this->set_type(Bool);
        return Bool;
    }
    else
    {
        this->set_type(Object);
        classtable->semant_error(this) 
            << "Ambos os argumentos do operador < deveriam ser do tipo Int"
            << " mas os argumentos são do tipo "
            << left_type
            << " e "
            << right_type
            << ".\n";
    }
    return this->get_type();
}

Symbol neg_class::type_check() {
    
    //Verifica tipagem na operação de inversão de sinal ('~')
    Symbol inner_expression_type = e1->type_check();
    if (inner_expression_type != Int)
    { //Erro: operador não é um inteiro
        this->set_type(Object);
        classtable -> semant_error(this) 
            << "Argumento do operador '~' possui tipo " 
            << inner_expression_type 
            << " ao invés de Int.\n";
        return Object;
    }
    this->set_type(Int); //Verificação completada com sucesso
    return Int;
}

Symbol divide_class::type_check() {
	
    //Verifica tipagem de operadores de uma divisão ('/')
    Symbol left_operator_type = e1->type_check();
    Symbol right_operator_type = e2->type_check();
    if(left_operator_type == Int && right_operator_type == Int)
        this->set_type(Int); //Sucesso
    else
    { //Erro: pelo menos um dos operadores não é inteiro
        classtable->semant_error(this) 
            << "Ambos os argumentos do operador / deveriam ser do tipo Int"
            << " mas os argumentos são do tipo "
            << left_operator_type
            << " e "
            << right_operator_type
            << ".\n";
        this->set_type(Object);
    }
    return this->get_type();
}

Symbol mul_class::type_check() {
	
    //Verifica tipagem de operadores de uma multiplicação ('*')
    Symbol left_operator_type = e1->type_check();
    Symbol right_operator_type = e2->type_check();
    if(left_operator_type == Int && right_operator_type == Int)
        this->set_type(Int); //Sucesso
    else
    { //Erro: pelo menos um dos operadores não é inteiro
        classtable->semant_error(this) 
            << "Ambos os argumentos do operador * deveriam ser do tipo Int"
            << " mas os argumentos são do tipo "
            << left_operator_type
            << " e "
            << right_operator_type
            << ".\n";
        this->set_type(Object);
    }
    return this->get_type();
}

Symbol sub_class::type_check() {
	
    //Verifica tipagem de operadores de uma subtração ('-')
    Symbol left_operator_type = e1->type_check();
    Symbol right_operator_type = e2->type_check();
    if(left_operator_type == Int && right_operator_type == Int)
        this->set_type(Int); //Sucesso
    else
    { //Erro: pelo menos um dos operadores não é inteiro
        classtable->semant_error(this) 
            << "Ambos os argumentos do operador - deveriam ser do tipo Int"
            << " mas os argumentos são do tipo "
            << left_operator_type
            << " e "
            << right_operator_type
            << ".\n";
        this->set_type(Object);
    }
    return this->get_type();
}

Symbol plus_class::type_check() {
	
    //Verifica tipagem de operadores de uma adição ('+')
    Symbol left_operator_type = e1->type_check();
    Symbol right_operator_type = e2->type_check();
    if(left_operator_type == Int && right_operator_type == Int)
        this->set_type(Int); //Sucesso
    else
    { //Erro: pelo menos um dos operadores não é inteiro
        classtable->semant_error(this) 
            << "Ambos os argumentos do operador + deveriam ser do tipo Int"
            << " mas os argumentos são do tipo "
            << left_operator_type
            << " e "
            << right_operator_type
            << ".\n";
        this->set_type(Object);
    }
    return this->get_type();
}

Symbol let_class::type_check() {
    
    // Verificação de tipagem em uma expressão "let"
    symbol_table->enterscope();
    if (identifier == self) 
        classtable->semant_error(this) << "'self' não pode ser vinculado a uma expressão 'let'.\n";

    Symbol initial_type = init->type_check();

    if (type_decl != SELF_TYPE && !classtable->is_type_defined(type_decl))
        classtable->semant_error(this) 
            << "Tipo " 
            << type_decl 
            << " da variável de identificador "
            << identifier 
            << " não foi definido.\n";

    else if (initial_type != No_type && !classtable->is_subtype(initial_type, type_decl))
        classtable->semant_error(this)
            << "Inferência de tipo " 
            << initial_type 
            << " na inicialização de " 
            << identifier 
            << " não é compatível com tipo declarado " 
            << type_decl << ".\n";
            
    symbol_table->addid(identifier, new Symbol(type_decl));
    this->set_type(body->type_check()); //Checagem do interior da expressão let
    symbol_table->exitscope();
    return type;
}

Symbol block_class::type_check() {
    
    // Checagem de tipo de um bloco de expressões
    Symbol last_body_expression_type = Object;
    for (int i = body->first(); body->more(i); i = body->next(i))
        last_body_expression_type = body->nth(i)->type_check(); //Verifica a tipagem de cada operação dentro do bloco
    this->set_type(last_body_expression_type);
    return last_body_expression_type;
}

/// ---------------
/// DANNIEL

Symbol branch_class::type_check() {
    Symbol declaration_id = name;
    Symbol declaration_type = type_decl;
    
    if(declaration_id == self){
        classtable->semant_error(this) 
            << "'self' cannot be bound in a 'branch' expression.";                
    }

    symbol_table->enterscope();
    symbol_table->addid(declaration_id, new Symbol(declaration_type));

    Symbol branch_expr_type = expr->type_check();
    this->set_type(branch_expr_type);
    symbol_table->exitscope();

    return branch_expr_type;
}

Symbol typcase_class::type_check() {
    Symbol expr_type = expr->type_check();

    std::set<Symbol> branch_declaration_types;
    Symbol branch_result_type = Object;

    for(int i = cases->first(); cases->more(i); i = cases->next(i)){
        branch_class* branch = static_cast<branch_class*>(cases->nth(i));
        Symbol branch_declaration_type = branch->get_declaration_type();

        if(branch_declaration_types.find(branch_declaration_type) != branch_declaration_types.end()){
            classtable->semant_error(branch)
                << "Duplicate branch type"
                << branch_declaration_type
                << " in case statement type.\n";
        }
        else
            branch_declaration_types.insert(branch_declaration_type);
        
        if(i == cases->first())
            branch_result_type = branch->type_check();
        else
            branch_result_type = classtable->least_upper_bound(
                branch_result_type,
                branch->type_check()
            );
    }

    this->set_type(branch_result_type);
    return branch_result_type;
}

Symbol loop_class::type_check() {
    Symbol pred_type = pred->type_check();
    Symbol body_type = body->type_check();

    if (pred_type != Bool)
    {
        classtable->semant_error(this) 
            << "The predicate of while must be of type Bool,got "
            << pred_type
            << " type instead.\n";
    }

    this->set_type(Object);
    return Object; 
}

Symbol cond_class::type_check() {
    Symbol pred_type = pred->type_check();
    Symbol then_type = then_exp->type_check();
    Symbol else_type = else_exp->type_check();

    if(pred_type != Bool){
        classtable->semant_error(this) 
            << "The predicate of if must be of type Bool,got "
            << pred_type
            << " type instead.\n";
    }

    Symbol cond_type = classtable->least_upper_bound(then_type, else_type);
    this->set_type(cond_type);
    return cond_type;
}

Symbol dispatch_class::type_check() {
    Symbol expr_type = expr->type_check();

    if(expr_type != SELF_TYPE && !classtable->is_type_defined(expr_type)){
        classtable->semant_error(this)
            << "Undefined class "
            << expr_type 
            << " can't be dispatched.\n";

        this->set_type(Object);
        return type;
    }

    Symbol expr_type_name = expr_type == SELF_TYPE ? current_class_name : expr_type;
    method_class* method_def = get_method_def(expr_type_name, name);

    if(!method_def){
        classtable->semant_error(this)
            << "Undefined method "
            << name
            << " can't be dispatched.\n";
        
        this->set_type(Object);
        return type;
    }

    Symbol declared_return_type = method_def->get_return_type();
    Formals declared_method_args = method_def->get_formals();
    Expressions actual_method_args = this->actual;

    int n_declared_method_args = 0;
    int n_actual_method_args = 0;

    while (declared_method_args->more(n_declared_method_args)){
        n_declared_method_args = declared_method_args->next(n_declared_method_args);
    }
    while (actual_method_args->more(n_actual_method_args)){
        n_actual_method_args = actual_method_args->next(n_actual_method_args);
    }

    if(n_declared_method_args != n_actual_method_args){
        classtable->semant_error(this)
            << "On the dispatch of the method " << method_def->get_name()
            << ", the number of arguments " << n_actual_method_args
            << " is different from declared method's number of arguments " 
            << "(" << n_declared_method_args << ")" << ".\n";
    }

    n_declared_method_args = declared_method_args->first();
    n_actual_method_args = actual_method_args->first();

    Formal declared_argument;
    Expression actual_argument;
    bool is_valid_dispatch = true;
    while(
        declared_method_args->more(n_declared_method_args) &&
        actual_method_args->more(n_actual_method_args))
    {
        declared_method_args->nth(n_declared_method_args);
        actual_method_args->nth(n_actual_method_args);

        Symbol declared_argument_type = declared_argument->type_check();
        Symbol actual_argument_type = actual_argument->type_check();

        if(!classtable->is_subtype(actual_argument_type, declared_argument_type)){
            is_valid_dispatch = false;

            classtable->semant_error(this)
                << "In the dispatch of the method " 
                << method_def->get_name() 
                << ", type "
                << actual_argument_type 
                << " of provided argument " 
                << declared_argument->get_name() 
                << " is not compatible with the corresponding declared type " 
                << declared_argument_type 
                << " .\n";
        }

        n_declared_method_args = declared_method_args->next(n_declared_method_args);
        n_actual_method_args = actual_method_args->next(n_actual_method_args);
    }

    if(!is_valid_dispatch){
        this->set_type(Object);
        return type;
    }

    Symbol dispatch_type = declared_return_type == SELF_TYPE ? expr_type : declared_return_type;
    this->set_type(dispatch_type);
    return dispatch_type;
}

Symbol static_dispatch_class::type_check() {
    bool is_valid_dispatch = true;
    Symbol expr_type = expr->type_check();

    if(this->type_name != SELF_TYPE && !classtable->is_type_defined(type_name)){
        classtable->semant_error(this)
            << "Undefined class "
            << expr_type 
            << " can't be static dispatched.\n";

        this->set_type(Object);
        return type;
    }
    if(expr_type != SELF_TYPE && !classtable->is_type_defined(expr_type)){
        this->set_type(Object);
        return type;
    }
    if(!classtable->is_subtype(expr_type, this->type_name)){
        classtable->semant_error(this)
            << "The expression type "
            << expr_type
            << " is not compatible with declared static dispatch type "
            << this->type_name
            << ".\n";
        is_valid_dispatch = false;
    }

    method_class* method_def = get_method_def(type_name, name);

    if(!method_def){
        classtable->semant_error(this)
            << "Undefined method "
            << name
            << " can't be static dispatched.\n";
        
        this->set_type(Object);
        return type;
    }

    Symbol declared_return_type = method_def->get_return_type();
    Formals declared_method_args = method_def->get_formals();
    Expressions actual_method_args = this->actual;

    int n_declared_method_args = 0;
    int n_actual_method_args = 0;

    while (declared_method_args->more(n_declared_method_args)){
        n_declared_method_args = declared_method_args->next(n_declared_method_args);
    }
    while (actual_method_args->more(n_actual_method_args)){
        n_actual_method_args = actual_method_args->next(n_actual_method_args);
    }

    if(n_declared_method_args != n_actual_method_args){
        classtable->semant_error(this)
            << "On the dispatch of the method " << method_def->get_name()
            << ", the number of arguments " << n_actual_method_args
            << " is different from declared method's number of arguments " 
            << "(" << n_declared_method_args << ")" << ".\n";
    }

    n_declared_method_args = declared_method_args->first();
    n_actual_method_args = actual_method_args->first();

    Formal declared_argument;
    Expression actual_argument;
    while(
        declared_method_args->more(n_declared_method_args) &&
        actual_method_args->more(n_actual_method_args))
    {
        declared_method_args->nth(n_declared_method_args);
        actual_method_args->nth(n_actual_method_args);

        Symbol declared_argument_type = declared_argument->type_check();
        Symbol actual_argument_type = actual_argument->type_check();

        if(!classtable->is_subtype(actual_argument_type, declared_argument_type)){
            is_valid_dispatch = false;

            classtable->semant_error(this)
                << "In the dispatch of the method " 
                << method_def->get_name() 
                << ", type "
                << actual_argument_type 
                << " of provided argument " 
                << declared_argument->get_name() 
                << " is not compatible with the corresponding declared type " 
                << declared_argument_type 
                << " .\n";
        }

        n_declared_method_args = declared_method_args->next(n_declared_method_args);
        n_actual_method_args = actual_method_args->next(n_actual_method_args);
    }

    if(!is_valid_dispatch){
        this->set_type(Object);
        return type;
    }

    Symbol dispatch_type = declared_return_type == SELF_TYPE ? expr_type : declared_return_type;
    this->set_type(dispatch_type);
    return dispatch_type;
}

Symbol method_class::type_check(){
    symbol_table->enterscope();
    std::set<Symbol> defined_arguments;

    for(int i = formals->first(); formals->more(i); i = formals->next(i)){
        Formal arg = formals->nth(i);
        Symbol arg_name = arg->get_name();
        Symbol arg_type = arg->get_type();

        if(arg_name == self)
            classtable->semant_error(arg)
                << "'self' cannot be the name of a method argument.\n";
        else if(defined_arguments.find(arg_name) != defined_arguments.end())
            classtable->semant_error(arg)
                << "The argument "
                << arg_name
                << "in the method "
                << get_name()
                << "has already been defined.\n";
        else
            defined_arguments.insert(arg_name);

        if(classtable->is_type_defined(arg_type))
            symbol_table->addid(arg_name, new Symbol(arg_type));
        else
            classtable->semant_error(arg)
                << "The argument "
                << arg_name
                << "in the method "
                << get_name()
                << "has type undefined "
                << arg_type
                << ".\n";
    }

    Symbol declared_return_type = get_return_type();
    Symbol actual_return_type = this->expr->type_check();
    if(!classtable->is_subtype(actual_return_type, declared_return_type)){
        classtable->semant_error(this)
            << "O tipo de retorno inferido "
            << actual_return_type
            << " do metodo "
            << get_name()
            << " não é compativel com o tipo de retorno declarado "
            << declared_return_type
            << ".\n";
    }

    symbol_table->exitscope();
    return this->get_return_type();
}

Symbol attr_class::type_check(){
    Expression init_expr = this->get_init_expr();
    Symbol init_expr_type = init_expr->type_check();
    init_expr_type = init_expr_type == SELF_TYPE ? current_class_name : init_expr_type;

    // Checando se a atribuição tem um init
    if(dynamic_cast<const no_expr_class*>(init_expr) != nullptr){
        return this->get_type();
    }

    // Garatindo que não haverá atributos nomeados 'self'
    if(this->get_name() == self){
        classtable->semant_error(this)
            << "'self' cannot be the name of an attribute.\n";
        return this->get_type();
    }

    // Checando se o tipo do atributo foi definido.
    if(classtable->is_type_defined(this->get_type())){
        classtable->semant_error(init_expr)
            << "Atributo "
            << this->get_name()
            << " é definido pelo tipo indefinido "
            << this->get_type()
            << ".\n";
        return this->get_type();
    }

    bool matching_types = classtable->is_subtype(init_expr_type, this->get_type());

    if(!matching_types){
        classtable->semant_error(init_expr)
            << "Atributo "
            << this->get_name()
            << " é do tipo "
            << this->get_type()
            << " porém a expressão de inicialização é do tipo "
            << init_expr_type
            << ".\n";
    }
    return this->get_type();
}

Symbol assign_class::type_check() {
    
    // Verificação de tipos na associação de um valor a uma variável
    Symbol identifier = name;
    Expression assign_expression = expr;

    if (identifier == self) {
        classtable->semant_error(this) << "Não pode associar a 'self'.\n";
        return Object;
    }

    Symbol* identifier_type = symbol_table->lookup(identifier);

    if (!identifier_type) {
        classtable->semant_error(this) 
            << "Tentativa de associar a identificador desconhecido " 
            << identifier 
            << ".\n";

        this->set_type(Object);
        return this->get_type();
    }

    Symbol assign_expression_type = assign_expression->type_check();

    bool does_assign_conform_declared = classtable->is_subtype(
        assign_expression_type, 
        *identifier_type
    );

    if (!does_assign_conform_declared) {
        classtable->semant_error(this) 
            << "O identificador " 
            << identifier 
            << " foi declarado como "
            << *identifier_type
            << " mas foi associado com tipo incompatível "
            << assign_expression_type
            << ".\n";

        this->set_type(Object);
        return Object;
    }

    this->set_type(assign_expression_type);
    return assign_expression_type;
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

ostream& ClassTable::semant_error(Class_ c){                                                             
    return semant_error(c->get_filename(),c);
}    

ostream& ClassTable::semant_error(Symbol filename, tree_node *t){
    error_stream << filename << ":" << t->get_line_number() << ": ";
    return semant_error();
}

ostream& ClassTable::semant_error(tree_node *t) {
    error_stream << current_class_definition->get_filename() << ":" << t->get_line_number() << ": ";
    return semant_error();
}

ostream& ClassTable::semant_error(){                                                 
    semant_errors++;                            
    return error_stream;
} 


void error(){
    cerr << "A compilação foi interrompida devido a erros semânticos estáticos." << endl;
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
void program_class::semant(){
    initialize_constants();

    /* ClassTable constructor may do some semantic analysis */
    classtable = new ClassTable(classes);

    /* some semantic analysis code may go here */
    if(!classtable->install_custom_classes(classes)){
        error();
    }
    
    // Construir o grafo de herança usando o map
    if(!classtable->build_inheritance_graph())
        error();

    // Checa se classtable é acíclico e não possui herança de classe indefinida
    if(!classtable->check_if_classTable_is_ok())
        error();

    // Regitrando todos os métodos e atributos em um map indexado pelo nome da classe
    for(auto const& x : classtable->class_index)
        register_class_methods_and_attrs(x.second);
    
    // Checagem de tipo de todas as classes, atributos, métodos, expressões, etc
    for (int i = 0; classes->more(i); i = classes->next(i))
        type_check(classes->nth(i));

    // Sai com erro em caso de problemas semânticos
    if(classtable->errors())
        error();    
}


