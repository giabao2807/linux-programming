#!/bin/sh
if test $# -eq 0
then 
	echo "Usage: $0 ordinary_file"
	#exit 1
elif test $# -eq 1
	then
		if test -f "$1"
		then 
			filename="$1"
			set `ls -il $filename`
			inode="$1"
			size="$6"
			echo "Name\t\tInode\tSize"
			echo 
			echo "$filename\t$inode\t$size"
		elif test -d "$1"
			then 
				echo "$1: is a directory"
			else
				echo "$1: directory not found"
		fi
fi

exit 0
