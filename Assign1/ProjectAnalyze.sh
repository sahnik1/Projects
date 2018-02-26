#!/bin/bash

#Question 1
output=$(git status | grep -c "up-to-date")

if [ $(echo "${output}" | wc -l) -eq 1 ]
then echo "Your local Repository is Up to Date with the Remote Repository"
else
echo "Your local Repository is Not Up to Date with the Remote Repository"
fi

#Question 2
git diff > changes.log
echo "Uncommitted Changes Put in changes.log"

#Question 3
find ./* -name "*" -exec grep -qi "#TODO" --exclude=README --exclude=changes.log --exclude=todo.log --exclude=ProjectAnalyze.sh {} \; -exec cat {} \; > todo.log
echo "Content of Files With The Tag #TODO Have Been Put Into todo.log"

#Question 4
for f in *.hs
do
        ghc -fno-code $f 2> error.log
done
echo "All Haskell Files Have Been Checked For Errors, All Errors are in error.log"

#Unique Feature 1
#Tells The User What Company Makes Their Processor
Cpuinfo=$(lscpu | grep "GenuineIntel")

echo "Would You Like to Know What Company Your Cpu is Made by? [y/n]"
read input

if [ ${input} == "y" ]
then if [ $(echo "${Cpuinfo}" | wc -l) -eq 1 ];
     then
     echo "You are Running an Intel Machine, GO TEAM BLUE!!"
     else
     echo "You are Running an AMD Machine, GO TEAM RED!!"
     fi
else
     echo "You Obviuosly Don't Care About Your Computer"
fi

#Unique Feature 2
#Allows User to Zip/Unzip Files With a More Intuitive Interface

echo "Would You Like to Make A Zip Archive With Multiple Files [y/n]"
read UserIn

if [ ${UserIn} == "y" ]
then echo "The Max Amount of Files Allowed is 2"
	 echo "Give The Path of Your First File:"
	 read UserIn2
	 echo "Give The Path of Your Second File:"
	 read UserIn3
	 echo "What Name Would You Like For The Archive?"
	 read UserIn4
	 zip ${UserIn4} ${UserIn2} ${UserIn3}
	 echo "Success, ${UserIn4}.zip Has Been Created"
	 echo "Would You Like To Remove The Original Files? [y/n]"
	 read UserIn5
	 	if [ UserIn5 == "y" ]
	 	then rm ${UserIn2}
	 		 rm ${UserIn3}
	 	else echo "The Original File(s) Have Not Been Modified"
	 	fi
else
	 echo "Ok, No Zip Archives Were Made"
fi

#Unique Feature 3
#Allows Users to Copy Files From One Directory to Another With a More Intuitive Interface

echo "Would You Like To Copy All The Files From One Directory To Another? [y/n]"
read userinput

if [ ${userinput} == "y" ]
then
	 echo "What is The Directory From Where You Would Like to Copy Files From?"
	 read userdir1
	 echo "What is The Directory You Would Like the Files to Be Copied to?"
	 read userdir2
	 cp -r ${userdir1}/. ${userdir2}/
	 echo "Success, Files From ${userdir1} Have Been Copied to ${userdir2}"
else
	echo "No Files Will Be Copied"
fi
