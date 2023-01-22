data Expr = Const Int -- constanta de Int
          | Expr :+: Expr -- adunare
          | Expr :*: Expr -- inmultire
          deriving Eq

data Operation = Add | Mult 
               deriving (Eq, Show)

data Tree = Lf Int -- frunza
          | Node Operation Tree Tree
          deriving (Eq, Show)

-- 1.1
instance Show Expr where
    show (Const x) = show x
    show (a :+: b) = "(" ++ show a ++ " + " ++ show b ++ ")"
    show (a :*: b) = "(" ++ show a ++ " * " ++ show b ++ ")"

-- 1.2
evalExpr :: Expr -> Int
evalExpr (Const x) = x
evalExpr (a :+: b) = evalExpr a + evalExpr b
evalExpr (a :*: b) = evalExpr a * evalExpr b

expr1 = ((Const 2 :*: Const 3) :+: (Const 0 :*: Const 5))
test11 = evalExpr expr1

expr2 = (Const 2 :*: (Const 3 :+: Const 4))
test12 = evalExpr expr2

expr3 = (Const 4 :+: (Const 3 :*: Const 3))
test13 = evalExpr expr3

expr4 = (((Const 1 :*: Const 2) :*: (Const 3 :+: Const 1)) :*: Const 2)
test14 = evalExpr expr4

--1.3
evalArb :: Tree -> Int
evalArb (Lf x) = x
evalArb (Node op a b) =
    case op of
        Mult -> evalArb a * evalArb b
        Add -> evalArb a + evalArb b 

arb1 = Node Add (Node Mult (Lf 2) (Lf 3)) (Node Mult (Lf 0) (Lf 5))
test21 = evalArb arb1

arb2 = Node Mult (Lf 2) (Node Add (Lf 3)(Lf 4))
test22 = evalArb arb2

arb3 = Node Add (Lf 4) (Node Mult (Lf 3)(Lf 3))
test23 = evalArb arb3

arb4 = Node Mult (Node Mult (Node Mult (Lf 1)(Lf 2))(Node Add (Lf 3)(Lf 1))) (Lf 2)
test24 = evalArb arb4

--1.4
expToArb :: Expr -> Tree
expToArb (Const x) = Lf x
expToArb (a :+: b) = Node Add (expToArb a)(expToArb b)
expToArb (a :*: b) = Node Mult (expToArb a)(expToArb b)

--2
class Colection c where
    -- crearea unei colectii vide
    empty :: c key value

    -- crearea unei colectii cu un element
    singleton :: key -> value -> c key value

    -- adaugarea/actualizarea unui element intr-o colectie
    insert
        :: Ord key
        => key -> value -> c key value -> c key value
    
    -- cautarea unui element intr-o colectie
    lookup 
        :: Ord key 
        => key -> c key value -> Maybe value

    -- stergerea (marcarea ca sters a) unui element dintr-o colectie
    delete
        :: Ord key
        => key -> c key value -> c key value

    -- obtinerea listei cheilor
    keys :: c key value -> [key]

    -- obtinerea listei valorilor
    values :: c key value -> [value]

    -- obtinerea listei elementelor
    toList :: c key value -> [(key, value)]

    fromList
        :: Ord key
        => [(key, value)] -> c key value 

--2.1
keys = map fst.toList

values = map snd.toList

fromList ((x,y) : xs) = insert x y (fromList xs)

--2.2
newtype Pairlist k v 
    = PairList {getPairList :: [(k,v)]}

instance Collection PairList where
    empty = PairList []
    singleton k v = Pairlist [(k,v)]
    insert k v (PairList l) = PairList ((k,v) : l)
    