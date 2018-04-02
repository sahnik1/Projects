{\rtf1\ansi\ansicpg1252\cocoartf1561\cocoasubrtf200
{\fonttbl\f0\fmodern\fcharset0 Courier;\f1\fnil\fcharset0 LucidaGrande;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;}
{\*\expandedcolortbl;;\cssrgb\c0\c0\c0;}
{\*\listtable{\list\listtemplateid1\listhybrid{\listlevel\levelnfc23\levelnfcn23\leveljc0\leveljcn0\levelfollow0\levelstartat1\levelspace360\levelindent0{\*\levelmarker \{square\}}{\leveltext\leveltemplateid1\'01\uc0\u9642 ;}{\levelnumbers;}\fi-360\li720\lin720 }{\listlevel\levelnfc23\levelnfcn23\leveljc0\leveljcn0\levelfollow0\levelstartat1\levelspace360\levelindent0{\*\levelmarker \{hyphen\}}{\leveltext\leveltemplateid2\'01\uc0\u8259 ;}{\levelnumbers;}\fi-360\li1440\lin1440 }{\listname ;}\listid1}
{\list\listtemplateid2\listhybrid{\listlevel\levelnfc23\levelnfcn23\leveljc0\leveljcn0\levelfollow0\levelstartat1\levelspace360\levelindent0{\*\levelmarker \{square\}}{\leveltext\leveltemplateid101\'01\uc0\u9642 ;}{\levelnumbers;}\fi-360\li720\lin720 }{\listname ;}\listid2}
{\list\listtemplateid3\listhybrid{\listlevel\levelnfc23\levelnfcn23\leveljc0\leveljcn0\levelfollow0\levelstartat1\levelspace360\levelindent0{\*\levelmarker \{square\}}{\leveltext\leveltemplateid201\'01\uc0\u9642 ;}{\levelnumbers;}\fi-360\li720\lin720 }{\listlevel\levelnfc23\levelnfcn23\leveljc0\leveljcn0\levelfollow0\levelstartat1\levelspace360\levelindent0{\*\levelmarker \{hyphen\}}{\leveltext\leveltemplateid202\'01\uc0\u8259 ;}{\levelnumbers;}\fi-360\li1440\lin1440 }{\listname ;}\listid3}}
{\*\listoverridetable{\listoverride\listid1\listoverridecount0\ls1}{\listoverride\listid2\listoverridecount0\ls2}{\listoverride\listid3\listoverridecount0\ls3}}
\margl1440\margr1440\vieww38200\viewh18920\viewkind0
\deftab720
\pard\pardeftab720\sl280\partightenfactor0

\f0\fs24 \cf2 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 # Wheres Waldo? - Web Game\
\
Based on the assignment requirements for this project, the most important requirement that I\'92m also the most Proud of is the Creativity. Using my love for Where\'92s Waldo Books as a child, I came up with this idea all on my own while I was playing around with the mouse package on elm-lang.org .\
\
## Instructions\
\
\pard\tx220\tx720\pardeftab720\li720\fi-720\sl280\partightenfactor0
\ls1\ilvl0\cf2 \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	
\f1 \uc0\u9642 
\f0 	}Find Waldo (Duh) 10 Times to Win The Game\
{\listtext	
\f1 \uc0\u9642 
\f0 	}But Make Sure Not to Click Randomly as Only 3 Lives are Given\
{\listtext	
\f1 \uc0\u9642 
\f0 	}If You Find Yourself struggling to Find Him You can do 2 Things:\
\pard\tx940\tx1440\pardeftab720\li1440\fi-1440\sl280\partightenfactor0
\ls1\ilvl1\cf2 {\listtext	\uc0\u8259 	}Get An Eye-test Done and Get Glasses!\
{\listtext	\uc0\u8259 	}See The Pattern in Which Waldo Moves Across the Board.\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 \
\pard\pardeftab720\sl280\partightenfactor0
\cf2 \
## Logic Behind The Game\
\
The Game is designed in a way to make Waldo Harder to find with each successful spot. This is done by making the size decrease by 1px during each successful update in the update function. In this game 3 types of Msgs are used; one is the Mouse\'92s position to check whether the Player has clicked on Waldo (Checked with a tolerance to allow some flexibility as to where user clicks). The Second Msg (Result)  is used to then generate a pair of random coordinates for Waldo to move to a Random Location. The Third Msg used is just a Msg called \'93Startover\'94 to reset all the variable upon the user clicking the \'93Try Again\'94 or \'93Play Again\'94 buttons from the Gameover and Won screens.\
\
## Try It Yourself\
\
\pard\tx220\tx720\pardeftab720\li720\fi-720\sl280\partightenfactor0
\ls2\ilvl0\cf2 \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	
\f1 \uc0\u9642 
\f0 	}A Link to My Resume Can be Found \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 [Here]({\field{\*\fldinst{HYPERLINK "http://ugweb.cas.mcmaster.ca/~sahnik/"}}{\fldrslt http://ugweb.cas.mcmaster.ca/~sahnik/}})\
\ls2\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	
\f1 \uc0\u9642 
\f0 	}A Link to the Web App Can be found under Projects in My Resume or [Here]({\field{\*\fldinst{HYPERLINK "http://ugweb.cas.mcmaster.ca/~sahnik/App.html"}}{\fldrslt http://ugweb.cas.mcmaster.ca/~sahnik/App.html}})\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 \
\pard\pardeftab720\sl280\partightenfactor0
\cf2 \
## Acknowledgements\
\
\pard\tx220\tx720\pardeftab720\li720\fi-720\sl280\partightenfactor0
\ls3\ilvl0\cf2 \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	
\f1 \uc0\u9642 
\f0 	}The Links to the Images Used for the Characters in this Project can be Found Here: [Wizard/Girl](https://www.sbs.com.au/comedy/sites/sbs.com.au.comedy/files/styles/body_image/public/odlawwendawhitebeardwoof.jpg?itok=lWjvcu_R&mtime=1471329060), [Waldo](https://studio.code.org/v3/assets/e4nc0qGSS976MCW2Z2io1A/New%20and%20Improved%20Waldo.png), and [Dog](https://kotaksuratriza.files.wordpress.com/2012/06/woof.gif).\
{\listtext	
\f1 \uc0\u9642 
\f0 	}The Resume was Built on the Template I Found [Here]({\field{\*\fldinst{HYPERLINK "https://github.com/BlackrockDigital/startbootstrap-resume"}}{\fldrslt https://github.com/BlackrockDigital/startbootstrap-resume}}) and the Changes I Made Include:\
\pard\tx940\tx1440\pardeftab720\li1440\fi-1440\sl280\partightenfactor0
\ls3\ilvl1\cf2 {\listtext	\uc0\u8259 	}Changed Awards Section to a list of Skills, Also removed Awards Icons in Original Website\
{\listtext	\uc0\u8259 	}Totally Changed Skills Section on Original Website to a Projects Section with Headings, Subheadings and Paragraphs.\
{\listtext	\uc0\u8259 	}Removed Facebook and Twitter Account Links as I do not Prefer those on a resume.\
{\listtext	\uc0\u8259 	}Embedded a Free To Use Visitor Counter at the Bottom Left Corner on the Skills Page to Keep Track of Site Activity.\
\pard\tx220\tx720\tx1133\pardeftab720\li720\fi-720\sl280\partightenfactor0
\ls3\ilvl0\cf2 {\listtext	
\f1 \uc0\u9642 
\f0 	}The Audio Used in this Game Includes: [Loading Music](), [Lost Music](), [Won Music](). Ps if you\'92re a real Nintendo Fan You Probably Already Know Where Those are From.\
}