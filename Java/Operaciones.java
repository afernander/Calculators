import java.util.Stack;

public class Operaciones{

    public static double operacion(Stack<String> expresion){
        double result=0;
        do{

            if(!expresion.isEmpty()){
                if(expresion.peek().equals("(")){
                    expresion.pop();
                  // System.out.println("eNTRE");
                   Stack<String> temp = new Stack<String>();
                   Stack<String> nuevoperar = new Stack<String>();
                   while(!expresion.peek().equals(")")){
                       //System.out.println("eNTRE");
                       temp.push(expresion.pop());
                       nuevoperar.push(temp.pop());
                   }
                   //imprimircola(nuevoperar);
                   double respuestatemp=operacion(nuevoperar);
                  // System.out.println(respuestatemp);
                   expresion.push(respuestatemp+"");
                }
            }

            if(!expresion.isEmpty()){
                if(expresion.peek().equals("[")){
                    expresion.pop();
                    expresion.push(sumaciclica(expresion)+"");
               }
            }

            if(!expresion.isEmpty()){
                if(expresion.peek().equals("{")){
                    expresion.pop();
                    expresion.push(sumacondicional(expresion)+"");
               }
            }
            
             double primernumero = Double.parseDouble(expresion.pop());
             result=primernumero;
             if(expresion.isEmpty()){
                //System.out.println("El resultado es : "+primernumero);
                result = primernumero;
                return primernumero;
                
            }
             String operacion = expresion.pop();

             if(!expresion.isEmpty()){
                if(expresion.peek().equals("[")){
                    expresion.pop();
                    expresion.push(sumaciclica(expresion)+"");
               }
            }

             if(!expresion.isEmpty()){
                if(expresion.peek().equals("{")){
                    expresion.pop();
                    expresion.push(sumacondicional(expresion)+"");
               }
            }

             if(!expresion.isEmpty()){
             if(expresion.peek().equals("(")){
                 expresion.pop();
               // System.out.println("eNTRE");
                Stack<String> temp = new Stack<String>();
                Stack<String> nuevoperar = new Stack<String>();
                while(!expresion.peek().equals(")")){
                    //System.out.println("eNTRE");
                    temp.push(expresion.pop());
                    nuevoperar.push(temp.pop());
                }
                //imprimircola(nuevoperar);
                double respuestatemp=operacion(nuevoperar);
               // System.out.println(respuestatemp);
                expresion.push(respuestatemp+"");
             }
            }

            

            if(operacion.equals("+")||operacion.equals("-")||operacion.equals("*")||operacion.equals("*")||operacion.equals("/")){

             double segundonumero = Double.parseDouble(expresion.pop());
            double resultado=0;
            
            switch(operacion){
                case "+":
                    resultado= primernumero + segundonumero;
                    expresion.push(resultado+"");
                    break;
                
                case "-":
                    resultado= primernumero - segundonumero;
                    expresion.push(resultado+"");
                    break;

                case "*":
                    resultado= primernumero * segundonumero;
                    expresion.push(resultado+"");
                    break;

                case "/":
                    resultado= primernumero / segundonumero;
                    expresion.push(resultado+"");
                    break;

                case "%":
                    resultado=  primernumero % segundonumero;
                    expresion.push(resultado+"");
                    break;
            }
            }else if(operacion.equals("#")||operacion.equals("r")){
                double resultado=0;
                switch(operacion){
                    case "#":
                        resultado= primernumero ;
                        expresion.push(resultado+"");
                        break;
                    
                    case "r":
                        resultado= Math.sqrt(primernumero);
                        expresion.push(resultado+"");
                        break;
                }

            }
            
        }while(!expresion.isEmpty());
        
        return result;
    }

    public static Stack<String> organizar(String [] expr){
        Stack<String> expresion = new Stack<>()  ;
        for(int i=expr.length-1 ; i>=0;i--){
            if(expr[i].equals("#")){
                String temp = expr[i];
                expr[i]=(Double.parseDouble(expr[i+1])*-1)+"";
                expr[i+1]=temp;
                expresion.pop();
                i++;
            }
            if(expr[i].equals("r")){
                String temp = expr[i];
                expr[i]=expr[i+1];
                expr[i+1]=temp;
                expresion.pop();
                i++;
            }
            expresion.add(expr[i]);

        }
        return expresion;
    }

    public static void imprimircola(Stack<String> impresion){

        while(!impresion.isEmpty()){
            
            System.out.println(impresion.pop());
        }

    }

public static double sumaciclica(Stack<String> expresion){
    
      // System.out.println("eNTRE");
       Stack<String> temp = new Stack<String>();
       Stack<String> nuevoperar = new Stack<String>();
       double inicio = Double.parseDouble(expresion.pop());
       //System.out.println(inicio);
       expresion.pop();
       String condicion = expresion.pop();
       //System.out.println(condicion);
       double fin =  Double.parseDouble(expresion.pop());
       //System.out.println(fin);
       expresion.pop();
       double variacion = Double.parseDouble(expresion.pop());
      // System.out.println(variacion);
       expresion.pop();
            while(!expresion.peek().equals("]")){
                temp.push(expresion.pop());
                nuevoperar.push(temp.pop());

            }
    
    double resultado=0;
    double operacion =operacion(nuevoperar);
    switch(condicion){
        case "<":
    for(double i = inicio ;i < fin ; i += variacion){
        resultado+=operacion ;
    }
    break;
    case "<=":
    for(double i = inicio ;i <= fin ; i += variacion){
        resultado+=operacion ;
    }
    break;
    case ">":
    for(double i = inicio ;i > fin ; i += variacion){
        resultado+=operacion ;
    }
    break;
    case ">=":
    for(double i = inicio ;i >= fin ; i += variacion){
        resultado+=operacion ;
    }
    break;
 }

    return resultado;
}

public static double sumacondicional(Stack<String> expresion){
    
    // System.out.println("eNTRE");
     Stack<String> temp = new Stack<String>();
     Stack<String> nuevoperar = new Stack<String>();
     double primer = Double.parseDouble(expresion.pop());
     //System.out.println(inicio);
    
     String condicion = expresion.pop();
     //System.out.println(condicion);
     double segundo =  Double.parseDouble(expresion.pop());
     //System.out.println(fin);
     expresion.pop();
     double verdad = Double.parseDouble(expresion.pop());
    // System.out.println(variacion);
    expresion.pop();
     double falso = Double.parseDouble(expresion.pop());
         
  
  double resultado=0;
  
  switch(condicion){
      case "<":
  if (primer < segundo){
      return verdad;
  }else{
      return falso;
  }
  
  case "<=":
  if (primer <= segundo){
    return verdad;
}else{
    return falso;
}
  
  case ">":
  if (primer > segundo){
    return verdad;
}else{
    return falso;
}

  case ">=":
  if (primer >= segundo){
    return verdad;
}else{
    return falso;
}
 
}

  return resultado;
}


public static void main(String [] args){
    Lecturadeexpresion lectura = new  Lecturadeexpresion();
    lectura.lectura();

    //imprimircola(organizar(lectura.analisar()));
   System.out.println("El resultado es : "+ operacion(organizar(lectura.analisar())));

}


}