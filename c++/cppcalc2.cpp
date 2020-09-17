#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include "calcex.h"
#include "calculator.h"
using namespace std;

class Ciclo {

  public: int main() {
      string line2;


      cout << "Ingrese expresion de la forma correcta: ";

      getline(cin, line2);



      char decision = line2[0];

      int result2 = 0;

      int a;
      char e;
      int b;
      int c;
      int d;

      switch (decision) {

        case '[':

          // line = [ 1 , < 5 , 1 ; 8 ];

          a = line2[2] - '0';
           e = line2[6];
          b = line2[8] - '0';
          c = line2[12] - '0';
          d = line2[16] - '0';




          switch (e) {
            case '<':
              for (int i = a; i < b; i = i + c) {

                result2 = result2 + d;
              }
              break;

            case '>':
              for (int i = a; i > b; i = i - c) {

                result2 = result2 + d;
              }
              break;

          }
          break;

        case '{':

          // line = { 3 < 5 ? 4 : 5 };

          int f = line2[2] - '0';
          char g = line2[4];
          int h = line2[6] - '0';
          int i = line2[10] - '0';
          int j = line2[14] - '0';


          switch (g) {
            case '<':
              if (f < h) result2 = i;
              else result2 = j;
              break;

            case '>':
              if (f > h) result2 = i;
              else result2 = j   ;
              break;

          }
          break;


      }

      cout << "The result = " <<  result2 << endl;

    }

};
