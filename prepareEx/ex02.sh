#!/bin/sh

#S=1+2!+3!+...+n!

Giaithua(){
    p=1
    for ((i=1;i<=$1;i++))
    do
        p=$(($p*$i))
    done
    echo $p
}
Tong(){
    S=0;
    for ((j=1;j<=$1;j++))
    do
        S=$(($S+$(Giaithua $j)))
    done
    echo "Tong la: $S"
}
echo "Enter n:\c"
read n
Tong $n
exit 0


