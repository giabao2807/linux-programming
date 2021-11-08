#!/bin/sh
echo "result: 5 + 4 = "
read num
if [ "$num" -eq 9 ]
then
echo "true"
else
echo "wrong, 5 + 4 = 9"
fi
