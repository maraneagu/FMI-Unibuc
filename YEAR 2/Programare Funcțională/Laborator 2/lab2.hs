import Data.List

--1
poly2 :: Integer -> Integer -> Integer -> Integer -> Integer
poly2 a b c x = a*x*x+b*x+c

--2
eeny :: Integer -> String

{-
eeny x = if (even x)
        then "meeny"
        else "eeny"
-}

eeny x = if(x `mod` 2 == 0)
        then "meeny"
        else "eeny"

--3
fizzbuzz :: Integer -> String

{-
fizzbuzz x = if(x `mod` 3==0&& x `mod` 5==0)
            then "FizzBuzz"
            else if(x `mod` 3==0)
                then "Fizz"
                else if(x `mod` 5==0)
                    then "Buzz"
                    else ""
-}

fizzbuzz x 
    | mod x 15 == 0 = "FizzBuzz"
    | mod x 3 == 0 = "Fizz"
    | mod x 5 == 0 = "Buzz"
    | otherwise = ""

--4

fibonacciCazuri :: Integer -> Integer
fibonacciCazuri n
    | n<2 = n
    | otherwise = fibonacciCazuri (n-1) + fibonacciCazuri (n-2)

--5

tribonacci :: Integer -> Integer
tribonacci n
    | n<3 = 1
    | n==3 = 2
    | otherwise = tribonacci (n-1) + tribonacci (n-2) + tribonacci (n-3)


--6

binomial :: Integer -> Integer -> Integer
binomial n k
    | k==0 = 1
    | n==0 = 0
    | otherwise = binomial (n-1) (k-1) + binomial (n-1) k 

--7

--a.
verifL :: [Int] -> Bool
verifL l = mod (length l) 2 ==0

--b.
takefinal :: [Int] -> Int -> [Int]
takefinal l n
    | (length l)<n = l
    | otherwise = drop ((length l) - n) l