#
# file : backup.sh
# date : ven. oct.  7 14:06:23 CEST 2016
# author : thparpai <thparpai@enseirb-matmeca.fr>
# description :
#

#!/usr/bin/bash

usage()
{
    echo "usage: $0 n_files"
    exit 1
}


# Boucle principale

if [ $# -ne 1 ]
then
    usage
else
    FILES=`ls -t | head -$1 | tr '\n' ' '`
    echo -e "$FILES\nDo you want to compress and archive theses files (y/n) ?"
    read ANSWER

    if [ $ANSWER = "y" ]
    then
	echo "Enter the archive name :"
	read ANSWER
	tar -czf $ANSWER.tar.gz $FILES
	echo "Saved in $ANSWER.tar.gz"
    elif [ $ANSWER = "n" ]
    then
	echo "Archive not created"
    else
	echo "Unknown answer, quit"
	exit 1
    fi

    exit 0 
fi
