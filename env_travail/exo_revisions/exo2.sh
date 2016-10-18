#!/usr/bin/bash

usage()
{
    echo "usage: $0"
    exit 1
}


if [ $# -ne 0 ]
then
    usage
else
    LINES=$(cat passwd | cut -f 1 -d ':')
    N_LINES=0
    for i in $LINES
    do
	N_CHAR=$(echo $i | wc -m)
	if [ $N_CHAR -ge 9 ]
	then
	    echo "$i $N_CHAR"
	    N_LINES=$(($N_LINES+1))
	fi
    done
    echo "#logins : $N_LINES"
fi
	
    


