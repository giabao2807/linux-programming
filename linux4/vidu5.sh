#!/bin/sh
echo "Nhap thoi diem trong ngay : "
read st
if [ $st = "sang" ]; then
echo "Chao buoi sang !"
elif [ $st = "chieu" ]; then
echo "Chao buoi chieu !"
else
echo "Chua xu ly !"
exit 1
fi
exit 0
