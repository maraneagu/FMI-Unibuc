data Fruct
    = Mar String Bool
    | Portocala String Int

ionatanFaraVierme = Mar "Ionatan" False
goldenCuVierme = Mar "Golden Delicious" True
portocalaSicilia10 = Portocala "Sanguinello" 10
listaFructe = [Mar "Ionatan" False,
            Portocala "Sanguinello" 10,
            Portocala "Valencia" 22,
            Mar "Golden Delicious" True,
            Portocala "Sanguinello" 15,
            Portocala "Moro" 12,
            Portocala "Tarocco" 3,
            Portocala "Moro" 12,
            Portocala "Valencia" 2,
            Mar "Golden Delicious" False,
            Mar "Golden" False,
            Mar "Golden" True]

--1
--a)
ePortocalaDeSicilia :: Fruct -> Bool
ePortocalaDeSicilia (Mar x y) = False
ePortocalaDeSicilia (Portocala x y) =
    if x == "Sicilia" 
        then True
        else  False

--b)
nrFeliiSicilia :: [Fruct] -> Int
nrFeliiSicilia lf = sum [y | (Portocala x y) <- lf]

--c)
nrMereViermi :: [Fruct] -> Int
nrMereViermi lf = length [(Mar x y) | (Mar x y) <- lf, y == True]

--2
type NumeA = String
type Rasa = String
data Animal = Pisica NumeA | Caine NumeA Rasa
            deriving Show

--a)
vorbeste :: Animal -> String
vorbeste (Pisica n) = "Meow!"
vorbeste (Caine n r) = "Woof!"

--b)
rasa :: Animal -> Maybe String
rasa (Caine n r) = Just r
rasa (Pisica n) = Nothing

--3
data Linie = L [Int]
        deriving Show
data Matrice = M [Linie]
        deriving Show

--a)
suma :: Linie -> Int
suma (L l) = sum [x | x <- l]

verifica :: Matrice -> Int -> Bool
verifica (M m) n = foldr (||) False [True | l <- m, suma l == n]

--b)
lungime :: Linie -> Int
lungime (L l) = length l

pozitiv :: Linie -> Bool
pozitiv (L l) = foldr (&&) True [True | x <- l, x > 0]

doarPozN :: Matrice -> Int -> Bool
doarPozN (M m) n = foldr (&&) True [True | x <- (filter (\l -> lungime l == n) m), pozitiv x == True]

--c)
l_egale :: [Int] -> Bool
l_egale [] = True
l_egale (x:l) = all (==x) l

corect :: Matrice -> Bool
corect (M m) = l_egale [lungime l | l <- m]

