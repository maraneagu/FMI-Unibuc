--1.

nrVocale :: [String] -> Int
nrVocale [] = 0
nrVocale (cuv:list) =
    if palindrom cuv
        then nrVocCuv cuv + nrVocale list
        else nrVocale list

palindrom :: String -> Bool
palindrom str = str == reverse str

nrVocCuv :: String -> Int
nrVocCuv "" = 0
nrVocCuv (c:str)
    | elem c "aeiouAEIOU" = 1 + nrVocCuv str
    | otherwise = nrVocCuv str

--2.
f :: Int -> [Int] -> [Int]
f nr [] = []
f nr (i:l) =
    if even i
        then i : nr : f nr l
        else i : f nr l

--3.
divizori :: Int -> [Int]
divizori x = [y | y <- [1,2..x], x `mod` y == 0]

--4.
listadiv :: [Int] -> [[Int]]
listadiv l = [[y | y <- [1,2..x], x `mod` y ==0] | x <- l]

--5.

--a.
inIntervalRec :: Int -> Int -> [Int] -> [Int]
inIntervalRec x y [] = []
inIntervalRec x y (i:l)  
    | i >= x && i <= y = i : inIntervalRec x y l
    | otherwise = inIntervalRec x y l

--b.
inIntervalComp :: Int -> Int -> [Int] -> [Int]
inIntervalComp x y l = [i | i <- l, i >= x, i <= y]

--6.

--a.
pozitiveRec :: [Int] -> Int
pozitiveRec [] = 0
pozitiveRec (i:l)
    | i > 0 = 1 + pozitiveRec l
    | otherwise = pozitiveRec l

--b.
pozitiveComp :: [Int] -> Int
pozitiveComp l = length[i | i <- l, i > 0]

--7.

--a.
pozitii :: Int -> [Int] -> [Int]
pozitii _ [] = []
pozitii i (x:l)
    | x `mod` 2 == 1 = i : pozitii (i+1) l
    | otherwise = pozitii (i+1) l

pozitiiImpareRec :: [Int] -> [Int]
pozitiiImpareRec l = pozitii 0 l

--b.
pozitiiImpareComp :: [Int] -> [Int]
pozitiiImpareComp l = [i | (x,i) <- zip l[0..], x `mod` 2 == 1]
