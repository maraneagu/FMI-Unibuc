data Punct = Pt [Int]

data Arb = Vid | F Int | N Arb Arb
         deriving Show

class ToFromArb a where
    toArb :: a -> Arb
    fromArb :: Arb -> a

--1
--a)
f :: [Int] -> String
f [x] = show x
f (x:l) = show x ++ "," ++ f l

instance Show Punct where
    show (Pt []) = "()"
    show (Pt l) = "(" ++ f l ++ ")"

--b)
instance ToFromArb Punct where
    toArb (Pt []) = Vid
    toArb (Pt (x:l)) = N (F x) (toArb (Pt l))

    fromArb Vid = Pt []
    fromArb (F x) = Pt [x]
    fromArb (N st dr) = Pt (x ++ y)
        where
            Pt x = fromArb st
            Pt y = fromArb dr

--2
data Geo a = Square a | Rectangle a a | Circle a
    deriving Show

class GeoOps g where
    perimeter :: (Floating a) => g a -> a
    area :: (Floating a) => g a -> a

instance GeoOps Geo where
    perimeter (Square x) = 4 * x
    perimeter (Rectangle x y) = 2 * (x+y)
    perimeter (Circle x) = 2 * x *pi

    area (Square x) = x^2
    area (Rectangle x y) = x * y
    area (Circle x) = x^2 * pi

instance (Floating a, Eq a) => Eq (Geo a) where
    x == y = perimeter x == perimeter y

-- Floating a, Eq a - constrangeri pentru tipul a
    
    