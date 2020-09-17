import Text.Parsec
import Text.Parsec.String
import Text.Parsec.Token
import Text.Parsec.Expr
import Text.Parsec.Language
import qualified Data.Map as M
import qualified Control.Monad.State as S
import Control.Monad.Error
import Control.Monad.Identity

--Lexico

def = emptyDef {  identStart = letter
            , identLetter = alphaNum
            , opStart = oneOf "+-*/="
            , opLetter = oneOf "+-*/="
             }
lexer :: TokenParser()
lexer = makeTokenParser def

--Expresion en arbol

data Expression = Constant Double
                | Identifier String
                | Addition Expression Expression
                | Subtraction Expression Expression
                | Multiplication Expression Expression
                | Division Expression Expression
                | Negation Expression 
                | Assignment Expression Expression
                deriving Show

-- Parser

parseNumber :: Parser Expression
parseNumber = do 
    v <- naturalOrFloat lexer
    case v of 
        Left i -> return $ Constant $ fromIntegral i
        Right n -> return $ Constant n
parseIdentifier :: Parser Expression
parseIdentifier = do
    i <- identifier lexer 
    return $ Identifier i

parseExpression :: Parser Expression
parseExpression = (flip buildExpressionParser) parseTerm [
    [ Prefix (reservedOp lexer "-" >> return Negation)
    , Prefix (reservedOp lexer "+" >> return id)
    ]
    ,[Infix (reservedOp lexer "*" >> return Multiplication) AssocLeft
    , Infix (reservedOp lexer "/" >> return Division) AssocLeft
    ]
    ,[Infix (reservedOp lexer "+" >> return Addition) AssocLeft
    , Infix (reservedOp lexer "-" >> return Subtraction) AssocLeft
    ]
    ,[Infix (reservedOp lexer "=" >> return Assignment) AssocRight
    ]
 ]



parseTerm :: Parser Expression
parseTerm = parens lexer parseExpression
            <|> parseNumber
            <|> parseIdentifier

parseInput :: Parser Expression
parseInput = do
    whiteSpace lexer
    ex <- parseExpression
    eof
    return ex

-- Evaluador

type SymTab = M.Map String Double

type Evaluator a = S.StateT SymTab (ErrorT String Identity) a 

runEvaluator :: Evaluator Double -> SymTab -> Either String (Double, SymTab)
runEvaluator calc symtab = runIdentity $ runErrorT $ S.runStateT calc symtab

eval :: Expression -> Evaluator Double

eval (Constant x) = return x

eval (Identifier i) = do
    symtab <- S.get
    case M.lookup i symtab of
        Nothing -> fail $ "Variable indefinida" ++ i
        Just e -> return e 

eval (Addition eLeft eRigth) = do
    lft <- eval eLeft
    rgt <- eval eRigth
    return $ lft + rgt

eval (Subtraction eLeft eRigth) = do
  lft <- eval eLeft
  rgt <- eval eRigth
  return $ lft - rgt

eval (Multiplication eLeft eRigth) = do
    lft <- eval eLeft
    rgt <- eval eRigth
    return $ lft * rgt

eval (Division eLeft eRigth) = do
        lft <- eval eLeft
        rgt <- eval eRigth
        return $ lft / rgt

eval (Negation e)= do
    val <- eval e 
    return $ -val

eval (Assignment (Identifier i) e) = do
    val <- eval e 
    S.modify (M.insert i val)
    return val

eval (Assignment _ _) =
    fail "La assignacion de la izquierda debe ser un identificador"

defaultVars :: M.Map String Double 
defaultVars = M.fromList
    [ ("e", exp 1)
    , ("pi", pi)
    ]

-- runEvaluator retorna ya sea un o String (Double, Symtab Double)

calculate :: SymTab -> String ->(String, SymTab)
calculate symtab s =
    case parse parseInput "" s of
    Left err -> ("error: " ++ (show err), symtab)
    Right exp -> case runEvaluator (eval exp) symtab of
        Left err                    ->("error: " ++ err, symtab)
        Right (val, newSymTab) -> (show val, newSymTab)

loop :: SymTab -> IO ()
loop symTab = do
    
    putStr("ingrese la expresion a analisar : \n")
    line <- getLine
    if null line
    then return ()
    else do
        let (result, symTab') = calculate symTab line
        putStr("Resultado= ")
        putStrLn result
        loop symTab'

main =  do
    putStr("Inicio calculadora en haskell \n")
    putStr("-Los datos se pueden ingresar los datos ya sea separados por espacio o no ejemplo : 3 + 4 ó 3+4\n")
    putStr("\n")
    putStr("-Para finalizar la ejecucion entrar una linea en blanco.\n")
    loop defaultVars
--show
--Entre expresiones , una por linea . Una linea vacia para salir --