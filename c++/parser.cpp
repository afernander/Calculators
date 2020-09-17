#include "parser.h"
#include "calcex.h"
#include <string>
#include <sstream>

Parser::Parser(istream* in) {
   scan = new Scanner(in);
}

Parser::~Parser() {
   try {
      delete scan;
   } catch (...) {}
}

AST* Parser::parse() {
   return Prog();
}

AST* Parser::Prog() {
   AST* result = Expr();
   Token* t = scan->getToken();

   if (t->getType() != eof) {
      cout << "Syntax Error: Expected EOF, found token at column " << t->getCol() << endl;
      throw ParseError;
   }

   return result;
}

AST* Parser::Expr() {
   return RestExpr(Term());
}

AST* Parser::RestExpr(AST* e) {
   Token* t = scan->getToken();

   if (t->getType() == add) {
      
      return RestExpr(new AddNode(e,Term()));
   }

   if (t->getType() == sub)
      return RestExpr(new SubNode(e,Term()));

   if (t->getType() == module)
      return RestExpr(new ModNode(e,Term()));

   if (t->getType() == pow)
      return RestExpr(new PowNode(e,Term()));

   if (t->getType() == raiz)
      return RestExpr(new RaizNode(e));

   if (t->getType() == times)
      return RestExpr(new TimesNode(e,Term()));

   if (t->getType() == divide)
      return RestExpr(new DivideNode(e,Term()));

   if (t->getType() == condicion)
      return RestExpr(new CondNode(e,Term()));

   if (t->getType() == cambio)
      return RestExpr(new CambioNode(e));

   scan->putBackToken();

   return e;
}

AST* Parser::Term() {
   //write your Term() code here. This code is just temporary
   //so you can try the calculator out before finishing it.
   Token* t = scan->getToken();

   if (t->getType() == number) {
      istringstream in(t->getLex());
      int val;
      in >> val;
      return new NumNode(val);
   }

   cout << "Term not implemented" << endl;

   throw ParseError; 
}

AST* Parser::RestTerm(AST* e) {
   cout << "RestTerm not implemented" << endl;

   throw ParseError; 
}

AST* Parser::Storable() {
   cout << "Storable not implemented" << endl;

   throw ParseError; 
}

AST* Parser::Factor() {
   cout << "Factor not implemented" << endl;

   throw ParseError; 
}
   
