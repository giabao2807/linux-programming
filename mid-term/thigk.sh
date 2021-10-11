#!/bin/sh

ktrathamso()
{
    if test $# -eq 0
    then 
	echo "Khong co tham so dong len"
	#exit 1
    elif test $# -eq 1
	then
		if test -f "$1"
		then 
			echo "$1: la 1 file thong thuong"
		elif test -d "$1"
			then 
				echo "$1: la 1 thu muc"
			else
				echo "$1: khong tim thay thu muc"
		fi
    fi
} 
menu()
{
    echo "****************************************"
    echo "==> Menu for actor_movies.txt by Giabao:"
    echo "s or S: To sort file actor_movies.txt ascending by name => actor.txt"
    echo "t or T: To find movie by name actor"
    echo "q or Q: To quit this program"
    while true
    do
        echo "*******************************"
	    echo "=>>Enter your option and hit <Enter>: \c"
	    read option
	    case "$option" in 
		    s|S)	echo "Sort file actor_movies.txt by name: "
                    sort -t',' -k1 "actor_movies.txt" >> actor.txt
			    ;;
		    t|T)	read -p "Enter name actor: " name
                    grep "$name" $1 actor_movies.txt >> movie.txt
			    ;;
		    q|Q)	echo "Gia bao goodbye ~~"
			        exit 0
			    ;;
		    *)	echo "Invalid option; Try running the programming again"
			    ;;
	esac
done
}


echo "***********************************"
echo "* Bai thi giưa ky mon: LT Linux   *"
echo "* Ho va ten: Dinh Gia Bao         *"
echo "* Nhom:19N10                      *"
echo "* MSSV:102190252                  *"
echo "* De so:01                        *"
echo "***********************************"

ktrathamso actor_movies.txt
menu

exit 0