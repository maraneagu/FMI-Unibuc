{-
class Functor f where
    fmap :: (a -> b) -> f a -> f b 

class Functor f => Applicative f where
    pure :: a -> f a 
    (<*>) :: f (a -> b) -> f a -> f b 

-- fmap (+1) (Just 5) = Just 6
-- ECHIVALENT (+1) <$> (Just 5) = Just 6
-}

-- 1.
data List a = Nil
            | Cons a (List a)
            deriving (Eq, Show)

instance Functor List where
    fmap f Nil = Nil
    fmap f (Cons x l) = Cons (f x) (fmap f l)

instance Applicative List where
    pure x = (Cons x) Nil

    Nil <*> xs = Nil
    Cons f fs <*> xs = concatList list_1 list_2
       where
        list_1 = fmap f xs
        list_2 = fs <*> xs

concatList :: List a -> List a -> List a 
concatList Nil l = l 
concatList (Cons x xs) l = Cons x (concatList xs l) 

-- 2.
data Cow = Cow {name :: String,
                age :: Int,
                weight :: Int}
            deriving (Eq, Show)

-- a)
noEmpty :: String -> Maybe String
noEmpty s
    | length s == 0 = Nothing
    | otherwise = Just s

noNegative :: Int -> Maybe Int
noNegative i
    | i < 0 = Nothing
    | otherwise = Just i

{-
-- b)
cowFromString :: String -> Int -> Int -> Maybe Cow
cowFromString s i j 
    | (noEmpty s) == Nothing = Nothing
    | (noNegative i) == Nothing = Nothing
    | (noNegative j) == Nothing = Nothing
    | otherwise = Just (Cow s i j)

Cow :: String -> Int -> Int -> Cow
fmap :: (a -> b) -> f a -> f b 

a - String
b - Int -> Int -> Cow
fmap :: (String -> (Int -> Int -> Cow)) -> Maybe String -> Maybe (Int -> Int -> Cow)
fmap Cow (noEmpty s) :: Maybe (Int -> Int -> Cow)

(<*>) :: f(a -> b) -> f a -> f b 
fmap Cow (noEmpty s) <*> (noNegative i) :: Maybe (Int -> Cow)
fmap Cow (noEmpty s) <*> (noNegative i) <*> (noNegative j) :: Maybe Cow
-}

-- c)
cowFromString :: String -> Int -> Int -> Maybe Cow
cowFromString s i j =
    Cow <$> (noEmpty s) <*> (noNegative i) <*> (noNegative j)

-- 3.
newtype Name = Name String 
             deriving (Eq, Show)
newtype Adress = Adress String 
               deriving (Eq, Show)

-- a)
validateLength :: Int -> String -> Maybe String
validateLength i s 
    | length s < i = Just s
    | otherwise = Nothing

-- b)
mkName :: String -> Maybe Name
mkName s 
    | (validateLength 25 s) == Just s = Just (Name s)
    | otherwise = Nothing

mkAddress :: String -> Maybe Adress
mkAddress s 
    | (validateLength 100 s) == Just s = Just (Adress s)
    | otherwise = Nothing

-- c)
mkPerson :: String -> String -> Maybe Person 
mkPerson s1 s2
    | mkName s1 == Nothing = Nothing
    | mkAddress s2 == Nothing = Nothing
    | otherwise = Just (Person s1 s2)