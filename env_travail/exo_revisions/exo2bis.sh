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
    LINES=$(cat passwd | cut -f 1 -d ':' | grep -E ^.{9})

    for i in $LINES
    do
	echo "$i $(echo $i | wc -m)"
    done


    echo "#logins : $(echo $LINES | wc -w)"
fi
