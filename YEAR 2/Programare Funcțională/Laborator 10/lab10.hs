-- 1. Identity
newtype Identity a = Identity a
instance Functor Identity where
    fmap f (Identity x) = Identity (f x)

-- 2. Pair
data Pair a = Pair a a
instance Functor Pair where
    fmap f (Pair x y) = Pair (f x)(f y)

-- 3. Constant
data Constant a b = Constant b
instance Functor (Constant a) where
    fmap f (Constant y) = Constant (f y)

-- 4. Two
data Two a b = Two a b
instance Functor (Two a) where
    fmap f (Two x y) = Two x (f y)

-- 5. Three
data Three a b c = Three a b c
instance Functor (Three a b) where
    fmap f(Three x y z) = Three x y (f z)

-- 6. Three'
data Three' a b = Three' a b b
instance Functor (Three' a) where
    fmap f(Three' x y z) =  Three' x (f y)(f z)

-- 7. Four
data Four a b c d = Four a b c d
instance Functor (Four a b c) where
    fmap f(Four w x y z) = Four w x y (f z)

-- 8. Four''
data Four'' a b = Four'' a a a b
instance Functor (Four'' a) where
    fmap f(Four'' w x y z) = Four'' w x y (f z)

-- 9. Quant
data Quant a b = Finance | Desk a | Bloor b
instance Functor (Quant a) where
    fmap f Finance = Finance
    fmap f (Desk a) = Desk a
    fmap f (Bloor b) = Bloor (f b)

-- 10. LiftItOut
data LiftItOut f a = LiftItOut (f a)
instance Functor f => Functor (LiftItOut f) where
    fmap g (LiftItOut x) = LiftItOut (fmap g x)

-- 11. Parappa
data Parappa f g a = DaWrappa (f a)(g a)
instance (Functor f, Functor g) => Functor (Parappa f g) where
    fmap g (DaWrappa x y) = DaWrappa (fmap g x)(fmap g y)

-- 12. IgnoreOne
data IgnoreOne f g a b = IgnoreSomething (f a)(g b)
instance Functor g => Functor (IgnoreOne f g a) where
    fmap h (IgnoreSomething x y) = IgnoreSomething x (fmap h y)

-- 13. Notorious
data Notorious g o a t = Notorious (g o)(g a)(g t)
instance Functor g => Functor (Notorious g o a) where
    fmap h (Notorious x y z) = Notorious x y (fmap h z)

-- 14. GoatLord
data GoatLord a = NoGoat | OneGoat a | MoreGoats (GoatLord a)(GoatLord a)(GoatLord a)
instance Functor GoatLord where
    fmap f NoGoat = NoGoat
    fmap f (OneGoat x) = OneGoat (f x) 
    fmap f (MoreGoats x y z) = MoreGoats (fmap f x)(fmap f y)(fmap f z)

-- 15. TalkToMe
data TalkToMe a = Halt | Print String a | Read (String -> a)
instance Functor TalkToMe where
    fmap h Halt = Halt
    fmap h (Print f a) = Print f (h a)
    fmap h (Read g) = Read (h.g)




