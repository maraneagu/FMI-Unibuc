--1
f1 :: [Int] -> Int
f1 l = foldr (+) 0 (map(\x -> x*x) (filter odd l))

--2
f2 :: [Bool] -> Bool
f2 l = foldr (&&) True l

--3
f3 :: (Int -> Bool) -> [Int] -> Bool
f3 p l = foldr (&&) True (map p l)

--4
f4 :: (Int -> Bool) -> [Int] -> Bool
f4 p l = foldr (||) False (map p l)

--5
mapFoldr :: (a -> b) -> [a] -> [b]
mapFoldr f l = foldr (\x y -> f x : y) [] l 

filterFoldr :: (a -> Bool) -> [a] -> [a]
filterFoldr p l = foldr (\x y -> if (p x) then x : y else y) [] l

--6
f6 :: [Int] -> Int
f6 l = foldl (\x y -> x * 10 + y) 0 l

--7
--(a)
rmChar :: Char -> String -> String
rmChar c s = foldr (\x y -> if (x /= c) then x : y else y) "" s

--(b)
rmCharRec :: String -> String -> String
rmCharRec s1 s2 = 