#ifndef SEMANT_H_
#define SEMANT_H_

#include <assert.h>
#include <iostream.h>  
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

class GraphNode(){
  private:
  int name;
  GraphNode* parent;
  int parentName;

  public:
  GraphNode(int name, int parent, GraphNode* parentNode=NULL): name(name),parent(parent){}
}

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
  ostream& semant_error();
  ostream& semant_error(Class_ c);
  ostream& semant_error(Symbol filename, tree_node *t);
};


#endif

