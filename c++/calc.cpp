#include <iostream>
#include <sstream>
#include <string>
#include "calcex.h"
#include "calculator.h"
#include "cppcalc2.cpp"
using namespace std;

Calculator* calc;
Ciclo calc2;

int main() {
   string line;
 
 string decision;

cout << "Inicio calculadora en C++"<<endl;
cout << "Los datos se pueden ingresar los datos ya sea separados por espacio o no ejemplo : 3 + 4 ó 3+4"<<endl;
cout << "Desea hacer suma condicional o ciclo aditivo. 1-Para Si     2-Para No:  ";

getline(cin, decision);

if(decision=="1") calc2.main();

else{

   try {

      cout << "Ingrese una expresion calcular:    ";

      getline(cin, line);
      // line + '\n';

      calc = new Calculator();

      int result = calc->eval(line+" ");

      cout << "El resultado es : " << result << endl;

      delete calc;

   }
   catch(Exception ex) {
      cout << "Programa abortado , error! " << endl;
   }
 }
}
   
