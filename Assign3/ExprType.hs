{-|
Module : ExprType
Description : Contains The Type Definition for The Expr Type
Copyright : (c) Karanjot Singh Sahni 2018
License : MIT
Maintainer : sahnik@mcmaster.ca
Stability : experimental
Portability : DOS

- Expression Datatype
 - --------------------------------------
 - Wraps different operations in a
 - Expression Tree
 - Ops:
    Add - standard binary addition
    Mult - standard binary multiplication
    Const - wrapper for simple values
    Var - string identifier for vairables

- getVars Function
 - --------------------------------------
 - Utilizes The Union Function
 - Helps Extract Variables As a List of
   Strings From a Given Expr Expression.
-}
module ExprType where

import Data.List


-- | Expression DataType Declaration
data Expr a = Add (Expr a) (Expr a)   -- ^ Standard Binary Addition
            | Mult (Expr a) (Expr a)  -- ^ Standard Binary Multiplication
            | Const a                 -- ^ Value Wrapper
            | Var String              -- ^ Variable Identifier
            | Cos (Expr a)            -- ^ Cosine of Another Expression
            | Sin (Expr a)            -- ^ Since of Another Expression
            | Natlog (Expr a)         -- ^ Natural Log of Another Expression
            | Exp (Expr a)            -- ^ Base e to The Power of Another Expression
            | Raise (Expr a) (Expr a) -- ^ Raise an Expression to The Power of Another Expression
    deriving Eq

{- getVars :
            retrieves variable identifiers from
            an Expr
-}

-- | Function For Obtaining Variables From an Expr Type Expression
getVars :: Expr a        -- ^ Expr Type Expression as Input
            -> [String]  -- ^ List of Strings as Output
getVars (Add e1 e2) = getVars e1 `union` getVars e2
getVars (Mult e1 e2) = getVars e1 `union` getVars e2
getVars (Cos e1) = getVars e1
getVars (Sin e1) = getVars e1
getVars (Natlog e1) = getVars e1
getVars (Exp e1) = getVars e1
getVars (Raise e1 e2) = getVars e1 `union` getVars e2
getVars (Const _) = []
getVars (Var x) = [x]