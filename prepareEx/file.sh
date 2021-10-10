#!/bin/bash


#kiem tra file da ton tai hay k
file="./ex04.sh"
if [ -e $file ]
then
    echo “File exists”
else
    echo “File does not exists”
fi

#-d file true nếu file là thư mục
#-e file true nếu file tồn tại trên đĩa
#-f file true nếu file là tập tin thông thường
#-g file true nếu set group id được thiết lập trên file
#-r file true nếu file cho phép đọc
#-s file true nếu kích thước file khác không
#-w file true nếu file cho phép ghi
#-x file true nếu file được phép thực thi 