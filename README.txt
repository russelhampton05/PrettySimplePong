

   ___          _   _            
  / _ \_ __ ___| |_| |_ _   _    
 / /_)/ '__/ _ \ __| __| | | |   
/ ___/| | |  __/ |_| |_| |_| |_  
\/    |_|  \___|\__|\__|\__, ( ) 
                        |___/|/  
 __ _                 _          
/ _(_)_ __ ___  _ __ | | ___     
\ \| | '_ ` _ \| '_ \| |/ _ \    
_\ \ | | | | | | |_) | |  __/_   
\__/_|_| |_| |_| .__/|_|\___( )  
               |_|          |/   
   ___                           
  / _ \___  _ __   __ _          
 / /_)/ _ \| '_ \ / _` |         
/ ___/ (_) | | | | (_| |         
\/    \___/|_| |_|\__, |         
                  |___/          



Disclaimer:

This was written using a student's copy of Visual Studio 2013 and the SFML libraries for the GUI. It is my own
whole work. This was written during my first semester senior year of my computer science degree. Written in the
winter of 2015.


Table of Contents:

1. [S-1] Mission


2. [S-2] Patterns used

3. [S-3] Pong design


4. [S-4] Ideas for future features


5. [S-5] Closing statements


6. [S-6] About me


[S-1] Mission

	I've been learning a lot in school and through my work with various companies and I decided to try and write something simply and as beautifully 
as possible. I believe that programming can be an art and a craft, and I hope that through the course of this project I get just a little 
bit better. I wanted to write something I wasn't ashamed to show anyone who cared to see. In that spirit, I've also decided to commit almost every step 
of the way to show the whole process. 

[S-2] Patterns used

	This project made use of the game loop pattern, the command design pattern, and the observer pattern. 

[S-3] Pong design
	
 	The game has paddles and balls. The paddles move at a constant rate. The balls have variable velocity based on menu options. They can gain velocity
by being hit by a paddle and they lose velocity based on a friction number. There is a minimum velocity that they can not go under. Paddles can move in eight
directions and are bound to their side of the game field. No matter how fast a ball is moving they will never go through walls are paddles, as the collision detection
is based on math and not sprite overlap.  

[S-4] Ideas for future features

	It would be interesting to see multiplayer added via a network socket.
	Ball-Ball collision would not be too hard to implement on the current base game.
	Hot seat multiplayer is also an option.
	Different game modes is another thing I was considering adding.
	
[S-5] Closing Statements

	This was a very fun project. If I had to optimize any part of it, it would definitely be the math. I'm convinced that I didn't do that as efficiently as
I could have. That section of the code was also where I had the most bugs. Everything else worked surprisingly smoothly. I attempted to write code in such a way
that allowed for extensibility. Any new features should be able to be put in with minimal rewriting or erasing of the base code. That was the goal, anyway.

	For next time I plan to also make better use of git features and use rebasing and branching more effectively. I also need to explore github tools as well.

	I learned a lot from this project about design patterns. A big thank you to Robert Nystrom who made his book available online so we all can learn about
game design patterns. You can find more information about that here:  http://gameprogrammingpatterns.com/  
Also thanks to SFML for the free, easy to use media library. They were a big help to get the graphics to the screen quickly and with minimal over head. They also
made it possible to pack all the libraries necessary to run inside of the actual .exe file, so no list of .dll's required. This was huge for this project because
the point of the thing was to write code for pong, not waste a lot of time drawing to the screen.

	I'd estimate this one took me about 20-30 hours of work to do. 

[S-6] About me


	My name is Russel Hampton and I live in Houston, Texas with my wife and son. I'm attending University of Houston as of 2015 set to graduate in the fall of 
2016 with an under graduate degree in computer science. I enjoy video games, chess, weight lifting, and spending time with my family. When I grow up I want
to be a software developer who is known for writing clean, effective code.

Criticism, funny jokes, and wisdom is welcome. You can email me here:

russel.hampton@gmail.com





