#!/bin/bash
zenity --question --text "This is a question!" --no-wrap
if [ $s?=0 ];then
echo "You answered yes";
else
echo "You answered no";
fi
exit 0
