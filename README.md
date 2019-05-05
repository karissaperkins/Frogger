# Frogger
Welcome to the Frogger game! This was created by Anna Fronhofer, 
Karissa Perkins, and  Kristin Mills.


To run this program...

**IMPORTANT NOTE:** Please change your working directory to the project 
directory before running this program. You can do this in CLion by 
clicking on the run configurations (where it says "main.cpp|Debug" on 
a dropdown), choose "edit configurations", click on the three dot icon 
next to the working directory field and click on the third icon from 
the left on the top of the box that comes up (or select the project 
directory). 

The game is modeled after the classic arcade game by the same name. 
The user navigates a frog from its starting point at the bottom of 
the screen across a busy multi-lane road and a river to one of five 
end locations at the top of the screen. When the frog crosses the road,
it must avoid cars and trucks which are moving in both directions across
the road and at various speeds. After it makes it across the road, it then 
must cross the river by hopping between 
and landing on brown logs and green lily pads, which carry it with them. 
The logs and lily pads also move at various speeds and directions. 
If the frog makes it across, it stays in the end location and another frog
is introduced to the game. The user has three lives and a life is lost if 
the frog is hit by a car, lands in the water, gets carried off the screen 
on a log or lily pad, or lands on a frog already in an end location. 
The game is won when a user gets five frogs across to the five end 
locations without using all three of their lives. 



- Polymorphism: A vector of shape pointers called "shapes" includes 
circles and 
rectangles for logs and lily pads. The draw function is called on all
elements of the vector. 

- Keyboard input: Arrow keys move frog left, right, up, and down to move 
around the board. Pressing 'w' is a cheat to win the game and pressing 
'q' quits the game.  

- Mouse input: Buttons respond to mouse click for starting the game, 
viewing the leaderboard, and returning to the main menu. 

- Screens:  Start, Leaderboard, Game, Final-lose, Final-win, Final-win cheat
(for testing the win condition without going through all of the frogs).