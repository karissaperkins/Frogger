# AnimalFacts
Welcome to our Animal Facts Maker! This was created by Kristin Mills, Echo Norcott, 
and Delaney Sullivan.

This program gives a user some facts about various animals and is directed towards 
learning.

To run this program...

**IMPORTANT NOTE:** Please change your working directory to the project directory before 
running this program. You can do this in CLion by clicking on the run configurations 
(where it says "main.cpp|Debug" on a dropdown), choose "edit configurations", click 
on the three dot icon next to the working directory field and click on the third icon 
from the left on the top of the box that comes up (or select the project directory). 

To start the program, use a mouse to click on the begin button on the main screen.
Once this button is clicked you enter into the facts part of the program. 
Each page of this portion presents facts about a different animal. The vital stats
about an animal are presented on a rectangle shape and a fun fact is presented on 
a circle. These facts are provided in a .csv file and read in for each animal (stored
as an animal struct). Animals are stored in a vector of animals that is indexed by a 
global variable that is incremented and decremented with arrow key presses. 

For each page, the shapes are added to a vector of shape pointers and the draw function is 
called on each shape (using polymorphism). 

This project also uses the SOIL library to load images and has a static 
library for each Mac and Windows in the repo as well as a soil.h file. The images are 
all loaded in prior to the start of the program into a textures vector so that they do
not need to be loaded in each time they are needed (this saves time once the program 
starts, but may cause it to take up to a minute before the program window opens).


To change between facts you can use the left and right arrow keys to move around.
You can move back and forth between all facts until you pass by the last fact which 
will take you to the exit screen where you are able to click another button to start 
the program over.

