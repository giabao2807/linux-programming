#!/bin/sh
secretcode=agent007
until [ "$secretcode" = "$yourguess" ]
do 
	echo "Guess the code!"
	echo "Enter your guess: \c"
	read yourguess
done
echo "Wow! you are a genius!!"
exit 0
