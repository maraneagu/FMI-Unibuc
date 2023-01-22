{-
[ x^2 |x <- [1..10], x `rem` 3 == 2]
[(x,y)| x<- [1..5], y <- [x..(x+2)]]
[(x,y)| x<-[1..3], let k = x^2, y <- [1..k]]
[ x | x<- "Facultatea de Matematica si Informatica", elem x ['A'..'Z']]
[[x..y]| x <- [1..5], y <- [1..5], x < y]
-}

--1.
factori :: Int -> [Int]
factori x = [y | y <- [1,2..x], x `mod` y == 0]

--2.
prim :: Int -> Bool
prim x
    | length(factori x) == 2 = True
    | otherwise = False

--3.
numerePrime :: Int -> [Int]
numerePrime x = [y | y <- [2,3..x], prim(y) == True]

--4.
myzip3 :: [Int] -> [Int] -> [Int] -> [(Int, Int, Int)]
myzip3 x y z = [(a,b,c) | ((a,b),c) <- zip (zip x y) z]

--5.
firstEl :: [(a,b)] -> [a]
firstEl l = map fst l

{-
-- LAMBDA EXPRESIE
firstEl l = map (\ (x,y) -> x) l

-- FUNCTIE DEFINITA
firstEl l = map f l
f :: (a,b) -> a
f (x,y) = x

-- FUNCTIE PREDEFINITA
firstEl x = map fst x
-}

--6.
sumList :: [[Int]] -> [Int]
{-
sumList l = map f l
f :: [Int] -> Int
f l = sum l
-}
sumList l = map sum l

--7.
pre12 :: [Int] -> [Int]
pre12 l = map f l
f :: Int -> Int 
f x
    | even x = div x 2
    | otherwise = x*2

--8.
elemL :: Char -> [String] -> [String]
elemL x l = filter (x `elem`) l

--9.
pimp :: [Int] -> [Int]
pimp l = map (\x -> x*x) (filter odd l)
