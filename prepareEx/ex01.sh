#!/bin/sh

#s=1+2^2+3^3+...+n^n
Tong(){
    S=1
    for ((i=2;i<=$1;i++))
    do
        tmp=$i
        for ((j=2;j<=$i;j++))
        do 
            tmp=$(($tmp*$i))
        done
        S=$(($S + $tmp))
    done
    echo "Tong la $S"
}

echo "Enter n:\c"
read n
Tong $n
exit 0