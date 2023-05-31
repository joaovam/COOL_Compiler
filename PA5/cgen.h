#include <assert.h>
#include <stdio.h>
#include "emit.h"
#include "cool-tree.h"
#include "cgen_class_definition.h"
#include "symtab.h"
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

enum Basicness     {Basic, NotBasic};
#define TRUE 1
#define FALSE 0

class CgenClassTable;
typedef CgenClassTable *CgenClassTableP;

class CgenNode;
typedef CgenNode *CgenNodeP;

class CgenClassTable : public SymbolTable<Symbol,CgenNode> {
private:
   List<CgenNode> *nds;
   ostream& str;
   int stringclasstag;
   int intclasstag;
   int boolclasstag;
   int ioclasstag;
   int objectclasstag;
   int currentclasstag;
   std::map<Symbol, int> classtag_of;
   std::map<Symbol, Class_> class_definitions;

   std::map<Symbol, std::vector<Symbol>>              class_attributes;
   std::map<Symbol, std::set<Symbol>>                 class_directly_owned_attributes;
   std::map<Symbol, std::map<Symbol, attr_class*>>    class_attribute_defs;
   std::map<Symbol, std::vector<Symbol>>              class_methods;
   std::map<Symbol, std::map<Symbol, method_class*>>  class_method_defs;
   std::map<Symbol, std::map<Symbol, Symbol>>         class_method_defined_in;

   std::vector<Symbol>                                inheritance_tree_traversal;
   std::map<Symbol, Symbol>                           inheritance_parent;

   std::map<Symbol, cgen_class_definition>            cgen_class_definition_of;
   std::vector<Symbol>                                cgen_class_names;

   std::map<Symbol, std::map<Symbol, int>>            dispatch_offsets_of_class_methods;


// The following methods emit code for
// constants and global declarations.

   void code_global_data();
   void code_global_text();
   void code_bools(int);
   void code_select_gc();
   void code_constants();

// The following creates an inheritance graph from
// a list of classes.  The graph is implemented as
// a tree of `CgenNode', and class names are placed
// in the base class symbol table.

   void install_basic_classes();
   void install_class(CgenNodeP nd);
   void install_classes(Classes cs);
   void build_inheritance_tree();

   void transverse_inheritance_tree();
   void construct_protObjs();

   void set_relations(CgenNodeP nd);

   void attach_inherited_definitions_to(Class_ , Class_);
   void register_properties_and_definitions_of(Class_);

   cgen_class_definition construct_cgen_class_definition(Class_);
   void emit_nameTab();

public:
   int next_classtag();
   int get_classtag_for(Symbol );
   CgenClassTable(Classes, ostream& str);
   void code();
   CgenNodeP root();
};


class CgenNode : public class__class {
private: 
   CgenNodeP parentnd;                        // Parent of class
   List<CgenNode> *children;                  // Children of class
   Basicness basic_status;                    // `Basic' if class is basic
                                              // `NotBasic' otherwise
   Class_ c;
public:
   CgenNode(Class_ c,
            Basicness bstatus,
            CgenClassTableP class_table);

   void add_child(CgenNodeP child);
   List<CgenNode> *get_children() { return children; }
   void set_parentnd(CgenNodeP p);
   CgenNodeP get_parentnd() { return parentnd; }
   int basic() { return (basic_status == Basic); }
   Class_ get_class_definition() { return c; }
};

class BoolConst 
{
 private: 
  int val;
 public:
  BoolConst(int);
  void code_def(ostream&, int boolclasstag);
  void code_ref(ostream&) const;
};

