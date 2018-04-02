# Where's Waldo? - Web Game

Based on the assignment requirements for this project, the most important requirement that I’m also the most Proud of is the Creativity. Using my love for Where’s Waldo Books as a child, I came up with this idea all on my own while I was playing around with the mouse package on elm-lang.org .

## Instructions

* Find Waldo (Duh) 10 Times to Win The Game
* But Make Sure Not to Click Randomly as Only 3 Lives are Given
* If You Find Yourself struggling to Find Him You can do 2 Things:
	* Get An Eye-test Done and Get Glasses!
	* See The Pattern in Which Waldo Moves Across the Board.

## Logic Behind The Game

The Game is designed in a way to make Waldo Harder to find with each successful spot. This is done by making the size decrease by 1px during each successful update in the update function. In this game 3 types of Msgs are used; one is the Mouse’s position to check whether the Player has clicked on Waldo (Checked with a tolerance to allow some flexibility as to where user clicks). The Second Msg (Result)  is used to then generate a pair of random coordinates for Waldo to move to a Random Location. The Third Msg used is just a Msg called “Startover” to reset all the variable upon the user clicking the “Try Again” or “Play Again” buttons from the Gameover and Won screens.

## Try It Yourself

* A Link to My Resume Can be Found [Here](http://ugweb.cas.mcmaster.ca/~sahnik/)
* A Link to the Web App Can be found under Projects in My Resume or [Here](http://ugweb.cas.mcmaster.ca/~sahnik/App.html)

## Acknowledgements

* The Links to the Images Used for the Characters in this Project can be Found Here: [Wizard/Girl](https://www.sbs.com.au/comedy/sites/sbs.com.au.comedy/files/styles/body_image/public/odlawwendawhitebeardwoof.jpg?itok=lWjvcu_R&mtime=1471329060), [Waldo](https://studio.code.org/v3/assets/e4nc0qGSS976MCW2Z2io1A/New%20and%20Improved%20Waldo.png), [Main Menu](https://images-na.ssl-images-amazon.com/images/I/817jhs%2BSwqL.jpg), and [Dog](https://kotaksuratriza.files.wordpress.com/2012/06/woof.gif).
* The Resume was Built on the Template I Found [Here](https://github.com/BlackrockDigital/startbootstrap-resume) and the Changes I Made Include:
	* Changed Awards Section to a list of Skills, Also removed Awards Icons in Original Website
	* Totally Changed Skills Section on Original Website to a Projects Section with Headings, Subheadings and Paragraphs.
	* Removed Facebook and Twitter Account Links as I do not Prefer those on a resume.
	* Embedded a Free To Use Visitor Counter at the Bottom Left Corner on the Skills Page to Keep Track of Site Activity.
* The Audio Used in this Game Includes: [Loading Music](https://www.youtube.com/watch?v=nboeOelWjis), [Lost Music](https://www.youtube.com/watch?v=5Wc3kwv0Ddw), [Won Music](https://www.youtube.com/watch?v=rRKZXpYfq30). Ps if you’re a real Nintendo Fan You Probably Already Know Where Those are From.

