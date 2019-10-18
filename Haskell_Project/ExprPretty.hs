{-|
Module : ExprType
Description : Contains The Instances of Show
			  For The Expr Type Expressions
Copyright : (c) Karanjot Singh Sahni 2018
License : MIT
Maintainer : sahnik@mcmaster.ca
Stability : experimental
Portability : DOS

- Instances of Show For Expr Types:
  - Expr Types When Computed Using
  	Functions such as partDiff, 
  	Simplify, and Parsed Are Shown
  	Using The Guidlines Below

- This Module Imports "ExprType"
-}
module ExprPretty where

import ExprType

-- | Function For Providing Brackets Around a String
parens1 :: String -> String
parens1 ss = "(" ++ ss ++ ")"

parens :: String -> String
parens ss = ss

-- | Instance of Show Class For The Expr Type Expressions
instance Show a => Show (Expr a) where
    show (Mult e1 e2)  = parens1 $ (show e1) ++ " !* " ++ (show e2)
    show (Add e1 e2) = parens1 $ (show e1) ++ " + " ++ (show e2)
    show (Var ss) = parens $ "var \"" ++ ss ++ "\""
    show (Const x) = parens $ "val " ++ show x
    show (Natlog x) = parens1 $ "Ln " ++ show x
    show (Exp x) = parens1 $ "e ^ " ++ show x
    show (Cos x) = parens $ "Cos " ++ show x
    show (Sin x) = parens $ "Sin " ++ show x
    show (Raise e1 e2) = parens1 $ show e1 ++ " ^ " ++ show e2