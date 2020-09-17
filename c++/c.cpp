



/*#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include "calcex.h"
#include "calculator.h"
using namespace std;

class Ciclo{

public:int main() {
  string line2;
  

      //cout << "Ingrese expresion de la forma correcta: ";

      //getline(cin, line);
      
      // line = [ 1 , < 5 , 1 ; 8 + 4];

     char cadena[] = "[ 8 , < 16 , 2 ; 4+3 ]";
    char delimitador[] = " ";
    char *token = strtok(cadena, delimitador);
    token = strtok(NULL, delimitador);
    int a = *token-'0';
    token = strtok(NULL, delimitador);
    token = strtok(NULL, delimitador);
    string e = token;
    token = strtok(NULL, delimitador);
    int b = *token-'0';
    token = strtok(NULL, delimitador);
    token = strtok(NULL, delimitador);
    int c = *token-'0';
   token = strtok(NULL, delimitador);
    token = strtok(NULL, delimitador);
    int d = *token-'0';
        
        int result2=0;

    int w=0;
   if(e.compare("<")==0) w=1;
   else if(e.compare("<=")==0) w=2;
   else if(e.compare(">")==0) w=3;
   else if(e.compare(">=")==0) w=4;


      switch(w){
        case 1:
     for(int i=a; i<b; i=i+c){

         result2 = result2+d;
      }
    //break;
    case 2:
     for(int i=a; i<=b; i=i+c){

         result2 = result2+d;
      }
    //break;
    case 3:
     for(int i=a; i>b; i=i-c){

         result2 = result2+d;
      }
    //break;
    case 4:
     for(int i=a; i>=b; i=i-c){

         result2 = result2+d;
      }
    //break;
 }


      cout << "The result = " <<  d << endl;

      

   }
   
};*/