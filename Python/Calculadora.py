import math
class Stack:
    def __init__(self):
        self.items = []

    def esVacia(self):
        return self.items == []

    def push(self, item):
        self.items.insert(0,item)

    def pop(self):
        return self.items.pop(0)

    def peek(self):
        return self.items[0]

    def size(self):
        return len(self.items)

def organizar(expresion):
    tokenlist = expresion.split()
    i= len(tokenlist)-1
    while(i>=0):
        if(tokenlist[i]=="#"):
            temp = tokenlist[i]
            tokenlist[i]=str(float(tokenlist[i+1])*-1)
            tokenlist[i+1]=temp
            i =i+1 
        if(tokenlist[i]=="r"):
            temp = tokenlist[i]
            tokenlist[i]=tokenlist[i+1]
            tokenlist[i+1]=temp
            i =i+1 
         
        i=i-1
    temp= Stack()
    expr= Stack()
    for token in tokenlist:
        temp.push(token)
        
    while(not temp.esVacia()):
        expr.push(temp.pop())
    
    return expr

def imprimircola(impresion= Stack()):

    while(not impresion.esVacia()):
        print(impresion.pop())

def operaciones (operacion= Stack()):
    
    while(not operacion.esVacia()):

        #parentesis
         if(operacion.peek()=="("):
             operacion.pop()
             temp= Stack()
             nuevoperar= Stack()

             while(not operacion.peek()==")"):
                 if(operacion.peek()==")"):
                     operacion.pop()
                 temp.push(operacion.pop())
             if(operacion.peek()==")"):
                     operacion.pop()
             operar1=str(operaciones(temp))
             operacion.push(operar1)

        #Suma ciclica
         if(operacion.peek()=="["):
             operacion.pop()
             temp= Stack()
             nuevoperar= Stack()
             inicio = float(operacion.pop())
             operacion.pop()
             if(operacion.peek()=="<"):
                 condicion = "<"
             elif(operacion.peek()=="<="):
                 condicion = "<="
             elif(operacion.peek()==">"):
                 condicion = ">"
             elif(operacion.peek()==">="):
                 condicion = ">="
             operacion.pop()
             fin = float(operacion.pop())
             operacion.pop()
             variacion = float(operacion.pop())
             operacion.pop()
             while(not operacion.peek()=="]"):
                 if(operacion.peek()=="]"):
                     operacion.pop()
                 temp.push(operacion.pop())
                 #nuevoperar.push(temp.pop())
             if(operacion.peek()=="]"):
                     operacion.pop()
             operar=float(operaciones(temp))
             operacion.push(str(sumaciclica(inicio,condicion , fin , variacion,operar)))
        
         #suma condicional

         if(operacion.peek()=="{"):
             operacion.pop()
             temp= Stack()
             nuevoperar= Stack()
             primero = float(operacion.pop())
             if(operacion.peek()=="<"):
                 condicion = "<"
             elif(operacion.peek()=="<="):
                 condicion = "<="
             elif(operacion.peek()==">"):
                 condicion = ">"
             elif(operacion.peek()==">="):
                 condicion = ">="
             operacion.pop()
             segundo1 = float(operacion.pop())
             operacion.pop()
             verdad = float(operacion.pop())
             operacion.pop()
             falso = float(operacion.pop())
             if(operacion.peek()=="}"):
                     operacion.pop()
             operacion.push(str(sumacondicional(primero,condicion , segundo1 , verdad,falso)))



         primer = float(operacion.pop())
         
         
         if(operacion.esVacia()):
             return primer
         operador=""
         if(operacion.peek()=="+"):
             operador="+"
             operacion.pop()
             segundo= float(operacion.pop())
         elif(operacion.peek()=='-'):
             operador="-"
             operacion.pop()
             segundo= float(operacion.pop())
             
         elif(operacion.peek()=='*'):
             operador="*"
             operacion.pop()
             segundo= float(operacion.pop())
             
         elif(operacion.peek()=='/'):
             operador="/"
             operacion.pop()
             segundo= float(operacion.pop())
         elif(operacion.peek()=='#'):
             operador="#"
             operacion.pop()
             segundo= 0
         elif(operacion.peek()=='r'):
             operador="r"
             operacion.pop()
             segundo= 0

             

            
        
         #print(operacion.pop())
         
         operacion.push(Evaluar(operador,primer,segundo))


def Evaluar(op, op1, op2):
    if op == "^":
        return op1 ** op2
    if op == "*":
        return op1 * op2
    elif op == "/":
        return op1 / op2
    elif op == "+":
        return op1 + op2
    elif op == "%":
        return op1 % op2
    elif op == "#":
        return op1 
    elif op == "r":
        return math.sqrt(op1)
    else:
        return op1 - op2    

def sumaciclica(inicio,condicion , fin , variacion , operar) :
    resultado=0
    if(condicion=="<"):
      while(inicio < fin):
         resultado = resultado + operar
         inicio =inicio + variacion
    elif(condicion=="<="):
          while(inicio <= fin):
             resultado = resultado + operar
             inicio =inicio + variacion
    elif(condicion==">"):
          while(inicio > fin):
             resultado = resultado + operar
             inicio =inicio + variacion
    elif(condicion==">="):
          while(inicio >= fin):
             resultado = resultado + operar
             inicio =inicio + variacion
    return resultado

def sumacondicional(primer,condicion , segundo , verdad , falso) :
    resultado= True

    if(condicion =="<"):
        resultado = (primer < segundo)
    elif(condicion =="<="):
        resultado = (primer <= segundo)
    elif(condicion ==">"):
        resultado = (primer > segundo)
    elif(condicion ==">="):
        resultado = (primer >= segundo)
    
    if(resultado== True):
        return verdad
    else:
        return falso





print("Inicio calculadora en Python")
print("Los datos se deben ingresar separados por un espacio entre cada signo o numero ejemplo: 3 + 4 - 5")
print(" ")
print("-Para la suma ciclica se debe de poner la expresion entre corchetes ejemplo: [ 1 , <= 5 , 1 ; 8 + 4 ] = 60")
print("donde [ inicio , condicion fin , variacion ; exprecion ]")
print(" ")
print("-Para la suma condicional se debe de poner la expresion entre llaves ejemplo: { 3 < 5 ? 4 : 5 } = 4")
print("donde { 1°_num_condicion condicion 2°_num_condicion ? exprecion1 : exprcion2 }")
print(" ")
print(" ")
cadena = input("Introduce una exprecion para analizar: ")
print('El resultado es: ',operaciones(organizar(cadena)))
#imprimircola(organizar(cadena))