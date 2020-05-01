# Graphics_assignment
PA #9

Group Members:
Christian Nicoll
Killian Griffin
Noel Wiess
Cameron Jamieson

How to run:

  First copy and paste all files from the Assets folder into the main project directory where the source files will be compiled.
  To run with visual studios, include the graphics assignment folder as an included directory under vc++ compiler under project settings.
  
  Next, copy and paste all the .dll files from the bin folder from the sfml folder to the main project directory, make sure to specify
  additional libraries in visual studio project settings so that sfml works.
  
  If all is well a main menu with blokus graphics should display with options for different game types.
  
 
Test conditions:

  1) If not all assets are improperly included or can't be opened error messages will be printed to the console screen informing the 
      user. To verify, try removeing one of the .png images from the project directory.
    
  2) In the shape placer menu, the game will not crash if non-integer values are entered into the coordinate text blocks. This allows
    for a more stable game design. To verify, try enter a word or character into the text fields.
    
  3) In the shape placer menu, if the user entered in the wrong value into the coordinate boxes they have the ability to clear the text
      boxes by pressing "backspace".
      
  4) In the shape placer menu, the valid function will not allow the user to make illegal moves during there turn. For example, they are      restricted to only corner placement in the beggining of the game. Additonanly, they can only place peices the touch corners in the 
     gameboard and that do not cover opponenets peices.
     
  5)
  
  
  
  
  Polymorphism: The Blokus object is an abstract class that gives its inherented class' important game functionalities like places    peices, allowing users to choose their shape to place and finding the winner at the end of the game.
