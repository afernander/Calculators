import java.util.Scanner;

public class Lecturadeexpresion{

    private static String expresion;

    public static void lectura(){
        Scanner tecl = new Scanner(System.in);
        System.out.println("Inicio calculadora en java");
        System.out.println("Los datos se deben ingresar separados por un espacio entre cada signo o numero ejemplo: 3 + 4 - 5");
        System.out.println("Para la suma ciclica se debe de poner la expresion entre corchetes ejemplo: [ 1 , <= 5 , 1 ; 8 + 4 ] = 60");
        System.out.println("donde [ inicio , condicion fin , variacion ; exprecion ]");
        System.out.println("Para la suma condicional se debe de poner la expresion entre llaves ejemplo: { 3 < 5 ? 4 : 5 } = 4");
        System.out.println("donde { 1°_num_condicion condicion 2°_num_condicion ? exprecion1 : exprcion2 }");
        System.out.println ("ingrese la expresion a analizar");
        expresion = tecl.nextLine();
    }

    public static String[] analisar(){
        String[] expr = expresion.split(" ");
        return expr;
    }
    
}