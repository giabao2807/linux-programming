#!/bin/sh

isPrime()
{
    declare local i
    declare local x2
    local x=$1

    if [ $x -lt 2 ] 
    then
     echo "$n khong phai so nguyen to"
    else
        count=0
        for ((i=2;i<=$x;i++))
        do 
            if [ $(($x % $i)) -eq 0 ]
            then    count=$(($count+1))
            fi
        done

        if [ $count -eq 1 ] 
        then
             echo "$n la so nguyen to"
        else
        echo "$n khong phai so nguyen to"
        fi
    fi
}

echo "Enter n: "
read n
isPrime $n
exit 0
