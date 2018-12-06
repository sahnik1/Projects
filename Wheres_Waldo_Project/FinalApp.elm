module WheresWaldo exposing (..)

import Html exposing (..)
import Html.Attributes as Att
import Html.Events exposing (onClick)
import Platform.Cmd as Cmd
import Platform.Sub as Sub
import Svg exposing (..)
import Svg.Attributes exposing (..)
import Mouse as Mouse
import Random


{- Model Given an Alias Type as Position with x,y (for Mouse Msg), Size with x,y , Counter for Score, Lives for 3 Chances, and Gamestate for Menu Interactions -}
type State = Menu | Game
--Type State Used As a Way to Differentiate and Categorize Menus

type alias Model = { position : { x : Float, y : Float }, size : { x : Int, y : Int}, counter : Int, gamestate : State, lives : Int }

init : (Model,Cmd.Cmd Msg)
init = ({ position = { x = 400 , y = 400 }, size = { x = 100, y = 100 }, counter = 0, gamestate = Menu, lives = 4 }, Cmd.none)
--Makes Waldo Initially Stay at (400,400) With a Width and Height of 100 and a Score of Zeroes.
--Also, the Gamestate is Set to Menu to View Main Menu and 4 lives are Set to Give a Total of 3 Lives During the Game

{- Msg Type Declared as Mouse's Position -}
type Msg = MouseMsg Mouse.Position | Result (Int, Int) | StartOver

{- Update Function for Updating x,y Coordinates and Size of Waldo While Also Updating the Gamestate and Lives/Score -}
update : Msg -> Model -> (Model,Cmd.Cmd Msg)
update msg model = 
    
    case msg of

      --In Case of a Mouse Click, the Position of Waldo Relative to the Click is Analyzed With a Tolerance of 300
      (MouseMsg pos)->
            if (abs( (toFloat pos.x) - model.position.x ) <= 300) && (abs( (toFloat pos.y) - model.position.y ) <= 300) then
              let
                currentmodel = { position = {x = model.position.x , y = model.position.y }, size = {x = model.size.x - 1 , y = model.size.y - 1}, counter = model.counter + 1, gamestate = Game, lives = model.lives }
                  in (currentmodel, Random.generate Result (Random.pair (Random.int 0 1200) (Random.int 0 700)))
            else
              let
                currentmodel = { position = {x = model.position.x , y = model.position.y }, size = {x = model.size.x , y = model.size.y}, counter = model.counter, gamestate = Game, lives = model.lives - 1 }
                  in (currentmodel, Cmd.none)

      --If the User Successfully Clicks Waldo, Then a Random Tuple of Numbers is Generated to Randomly Move Waldo
      Result (num1, num2) ->
              let
                currentmodel = { position = {x = toFloat num1, y = toFloat num2 }, size = {x = model.size.x , y = model.size.y}, counter = model.counter, gamestate = Game, lives = model.lives }

                  in (currentmodel, Cmd.none)

      --After a Player has Lost All of Their Lives, a Chance to Startover is Given in Which the init is Called
      StartOver ->
              init

{- Several Views Made, One for Game, Main Menu and Gameover Screen-}

--Style for the Gameview Seen By Player in Game
gamestyle = Att.style [("text-align", "center")
                    ,("font-size", "15px")
                    , ("color", "#505050")
                    , ("backgroundColor", "#303030")
                    , ("width", "100%")
                    , ("height", "100%")
                    , ("background-image", "url(\"https://i.imgur.com/beKI6iB.jpg\")")
                    ,("font-family", "Raleway, sans-serif")
                    ]

--Style for the Main Menu View and Game Over View
mainstyle = Att.style [("text-align", "center")
                    ,("font-size", "20px")
                    ,("color", "#F0F0F0")
                    ,("backgroundColor", "#303030")
                    ,("font-family", "Raleway, sans-serif")
                    ,("top", "50%")
                    ,("left", "50%")
                    ]

--Main Menu View Defined With An Image That I Photoshopped
menuview model = div [mainstyle]
                     [ Html.node "link" [Att.rel "stylesheet", Att.type_ "text/css", Att.href "https://fonts.googleapis.com/css?family=Chicle|Raleway"] []
                     , Html.img [ Att.src "./Plz.jpg"] []
                     , audio [Att.src "./load.mp3", Att.autoplay True, Att.loop True] []]

--Game Over View With Final Score, Waldo Image, Try Again Button and a Link to the Source Code
overview model = let
                strcounter = toString model.counter
              in    
                  div [mainstyle]
                      [ Html.node "link" [Att.rel "stylesheet", Att.type_ "text/css", Att.href "https://fonts.googleapis.com/css?family=Chicle|Raleway"] []
                      , h1 [] [Html.text "You Lost!"]
                      , svg [width "1000",height "420", preserveAspectRatio "True"]
                      [ image [x "300", y "30", width "400" , height "400" , xlinkHref "https://studio.code.org/v3/assets/e4nc0qGSS976MCW2Z2io1A/New%20and%20Improved%20Waldo.png"] []]
                      , p [] [Html.text "You Scored: ", Html.text strcounter]
                      , p [] [Html.text "You Only Needed ", Html.text (toString (10 - model.counter)), Html.text " More Points To Win!"]
                      , p [] [Html.text "Hint: Theres A Pattern As To Where Waldo Is Even If You Can't Find Him"]
                      , audio [ Att.src "./lost.mp3", Att.autoplay True] []
                      , button [Html.Events.onClick StartOver] [Html.text "Try Again"]
                      , p [] [Html.a [Att.href "https://github.com/sahnik1/CS1XA3/tree/master/Assign2", Att.style [("color", "white")]] [Html.text "Source Code"]]]

--Main Game View with Many Different Characters including Waldo, Some are Fixed While Others Move in Relation to Waldo (Hence the Pattern Mentioned in overview)
gameview model = let
              posX = model.position.x
              posY = model.position.y 
              strcounter = toString model.counter
              strlives = toString model.lives
          in
            div [gamestyle]
              [ Html.node "link" [Att.rel "stylesheet", Att.type_ "text/css", Att.href "https://fonts.googleapis.com/css?family=Chicle|Raleway"] []
              , h1 [Att.style [("background-size", "cover")]] [Html.text "Score: ", Html.text strcounter]
              , h1 [Att.style [("background-size", "cover")]] [Html.text "Lives: ", Html.text strlives]
              , svg [width "1500",height "750", preserveAspectRatio "True"]
              [ image [x (toString (posX)), y (toString (posY)), width (toString model.size.x) , height (toString model.size.y) , xlinkHref "https://studio.code.org/v3/assets/e4nc0qGSS976MCW2Z2io1A/New%20and%20Improved%20Waldo.png"] []
              , image [x (toString (posX * 0.252345 )), y (toString (posY*0.78534)), width (toString model.size.x) , height (toString model.size.y) , xlinkHref "./girl.png"] []
              , image [x (toString (posX *0.121)), y (toString (posY*0.32)), width (toString model.size.x) ,  height (toString model.size.y) , xlinkHref "./wiz.png"] []
              , image [x (toString (posX*0.932)), y (toString (posY *0.113)), width (toString model.size.x) ,  height (toString model.size.y) , xlinkHref "./wiz.png"] []
              , image [x (toString (posX*0.87)), y (toString (posY * 0.234)), width (toString model.size.x),  height (toString model.size.y), xlinkHref "https://kotaksuratriza.files.wordpress.com/2012/06/woof.gif"] []
              , image [x (toString (posX + 150)), y (toString (posY+100)), width (toString model.size.x) ,  height (toString model.size.y) , xlinkHref "./girl.png"] []
              , image [x (toString (posY*0.9)), y (toString (posX*0.45)), width (toString model.size.x) ,  height (toString model.size.y) , xlinkHref "./wiz.png"] []
              , image [x (toString (posY*0.87)), y (toString (posX * 0.234)), width (toString model.size.x),  height (toString model.size.y), xlinkHref "./girl.png"] []
              , image [x (toString (posY * 0.965)), y (toString (posX * 0.653)), width (toString model.size.x) ,  height (toString model.size.y) , xlinkHref ".https://kotaksuratriza.files.wordpress.com/2012/06/woof.gif"] []
              , image [x (toString (posX+45)), y (toString (posX * 0.56)), width (toString model.size.x),  height (toString model.size.y), xlinkHref "./girl.png"] []
              , image [x (toString (posX)), y (toString (posY + 100)), width (toString model.size.x) ,  height (toString model.size.y) , xlinkHref "./girl.png"] []
              , image [x (toString (876)), y (toString (678)), width (toString model.size.x),  height (toString model.size.y), xlinkHref "./girl.png"] []
              , image [x (toString (446)), y (toString (464)), width (toString model.size.x) ,  height (toString model.size.y) , xlinkHref "https://kotaksuratriza.files.wordpress.com/2012/06/woof.gif"] []
              , image [x (toString (654)), y (toString (356)), width (toString model.size.x),  height (toString model.size.y), xlinkHref "./girl.png"] []
              , image [x (toString (250)), y (toString (400)), width (toString model.size.x) ,  height (toString model.size.y) , xlinkHref "https://kotaksuratriza.files.wordpress.com/2012/06/woof.gif"] []]
              ]

wonview model = let
                strcounter = toString model.counter
              in    
                  div [mainstyle]
                      [ Html.node "link" [Att.rel "stylesheet", Att.type_ "text/css", Att.href "https://fonts.googleapis.com/css?family=Chicle|Raleway"] []
                      , h1 [] [Html.text "Congratulations!"]
                      , svg [width "1000",height "520", preserveAspectRatio "True"]
                      [ image [x "250", y "30", width "500" , height "500" , xlinkHref "https://studio.code.org/v3/assets/e4nc0qGSS976MCW2Z2io1A/New%20and%20Improved%20Waldo.png"] []]
                      , h2 [] [Html.text "YOU WON!!"]
                      , audio [ Att.src "./won.mp3", Att.autoplay True] []
                      , button [Html.Events.onClick StartOver] [Html.text "Play Again"]
                      , p [] [Html.a [Att.href "https://github.com/sahnik1/CS1XA3/tree/master/Assign2", Att.style [("color", "white")]] [Html.text "Source Code"]]]

--View Function Decides Which View to be Shown Based on Gamestate and Lives
view : Model -> Html.Html Msg
view model =

    if (model.counter == 10) then wonview model

    else if (model.lives <= 0) then overview model

    else if (model.gamestate == Menu) && (model.counter < 10) then menuview model

    else if (model.gamestate == Game) && (model.counter < 10 ) then gameview model

    else wonview model

{- Subscriptions -}
subscriptions : Model -> Sub Msg
subscriptions model = Mouse.ups MouseMsg

{- Main -}
main : Program Never Model Msg
main = Html.program
          { init = init,
            view = view,
            update = update,
            subscriptions = subscriptions
            }