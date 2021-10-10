#!/bin/sh

#this variable is global and can used anywhere in this bash script
VAR="global variable"

function giabao
{
    #this variable is local and only use in here
    local VAR='local variable'
    echo $VAR
}

echo $VAR
giabao #call my function
echo $VAR