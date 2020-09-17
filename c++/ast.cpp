#include "ast.h"
#include <iostream>
#include "calculator.h"
#include "math.h"

// for debug information uncomment
//#define debug

AST::AST() {}

AST::~AST() {}

BinaryNode::BinaryNode(AST* left, AST* right):
   AST(),
   leftTree(left),
   rightTree(right)
{}

BinaryNode::~BinaryNode() {
#ifdef debug
   cout << "In BinaryNode destructor" << endl;
#endif

   try {
      delete leftTree;
   } catch (...) {}

   try {
      delete rightTree;
   } catch(...) {}
}
   
AST* BinaryNode::getLeftSubTree() const {
   return leftTree;
}

AST* BinaryNode::getRightSubTree() const {
   return rightTree;
}

UnaryNode::UnaryNode(AST* sub):
   AST(),
   subTree(sub)
{}

UnaryNode::~UnaryNode() {
#ifdef debug
   cout << "In UnaryNode destructor" << endl;
#endif

   try {
      delete subTree;
   } catch (...) {}
}
   
AST* UnaryNode::getSubTree() const {
   return subTree;
}

AddNode::AddNode(AST* left, AST* right):
   BinaryNode(left, right)
{}

int AddNode::evaluate() {
   return getLeftSubTree()->evaluate() + getRightSubTree()->evaluate();
}

SubNode::SubNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int SubNode::evaluate() {
   return getLeftSubTree()->evaluate() - getRightSubTree()->evaluate();
}

TimesNode::TimesNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int TimesNode::evaluate() {
   return getLeftSubTree()->evaluate() * getRightSubTree()->evaluate();
}

DivideNode::DivideNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int DivideNode::evaluate() {
   return getLeftSubTree()->evaluate() / getRightSubTree()->evaluate();
}

ModNode::ModNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int ModNode::evaluate() {
   return getLeftSubTree()->evaluate() % getRightSubTree()->evaluate();
}

PowNode::PowNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int PowNode::evaluate() {
   return pow(getLeftSubTree()->evaluate(), getRightSubTree()->evaluate());
}

CondNode::CondNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int CondNode::evaluate() {
   return pow(getLeftSubTree()->evaluate(), getRightSubTree()->evaluate());
}


CambioNode::CambioNode(AST* sub):
   UnaryNode(sub)
{}

int CambioNode::evaluate() {
   return (getSubTree()->evaluate())*-1;
}

RaizNode::RaizNode(AST* sub):
   UnaryNode(sub)
{}

int RaizNode::evaluate() {
   return sqrt(getSubTree()->evaluate());
}

NumNode::NumNode(int n) :

   AST(),
   val(n)
{}

int NumNode::evaluate() {
   return val;
}




