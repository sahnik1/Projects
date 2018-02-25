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

#Question 3
find ./ -type f -name "TODO" -exec cat {} + >> todo.log
echo "Content of Files With Name #TODO Have Been Put Into todo.log"

#Question 4
for f in *.hs
do
        ghc -fno-code $f 2> error.log
done
echo "All Haskell Files Have Been Checked For Errors, All Errors are in error.log"

#Unique Feature 1
#Tells The User What Company Makes Their Processor
Cpuinfo=$(lscpu | grep "GenuineIntel")

if [ $(echo "${Cpuinfo}" | wc -l) -eq 1 ];
then
echo "You are Running an Intel Machine, GO TEAM BLUE!!"
else
echo "You are Running an AMD Machine, GO TEAM RED!!"
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
