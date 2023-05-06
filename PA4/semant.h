#ifndef SEMANT_H_
#define SEMANT_H_

#include <assert.h>
#include <iostream>  
#include <map>
#include <vector>
#include <set>
#include "cool-tree.h"
#include "stringtab.h"
#include "symtab.h"
#include "list.h"

#define TRUE 1
#define FALSE 0

class ClassTable;
typedef ClassTable *ClassTableP;

// This is a structure that may be used to contain the semantic
// information such as the inheritance graph.  You may use it or not as
// you like: it is only here to provide a container for the supplied
// methods.


class ClassTable {
private:
  std::map<Symbol, std::vector<Symbol>> inheritance_graph;

  int semant_errors;
  void install_basic_classes();
  ostream& error_stream;

public:

  std::map<Symbol, Class_> class_index;
  std::map<Symbol, Symbol> parent_index;

  ClassTable(Classes);
  int errors() { return semant_errors; }

  bool install_custom_classes(Classes classes);
  bool build_inheritance_graph();
  bool search_for_cycle_in_inheritance_graph();
  bool inheritance_graph_dfs(Symbol symbol);
  Symbol least_upper_bound(Symbol x, Symbol y);
  bool check_if_classTable_is_ok();

  ostream& semant_error();
  ostream& semant_error(Class_ c);
  ostream& semant_error(Symbol filename, tree_node *t);
};


ClassTable *classtable;

//use for type check
Symbol current_class_name;
Class_ current_class_definition;
std::map<Symbol, method_class*> current_class_methods;
std::map<Symbol, attr_class*> current_class_attrs;

//contains all the methods and attributes index by the name of the Class
std::map<Symbol, std::map<Symbol, method_class*>> class_methods;
std::map<Symbol, std::map<Symbol, attr_class*>> class_attrs;

#endif

