#!/bin/bash

usage()
{
    echo "usage: $0 arg1 arg2 ... argn";
    exit 1;
}

# Boucle principale

if [ $# -lt 1 ]
then
    usage
else
    res=0
    while [ $# -gt 0 ]
    do
	tmp=$(($tmp + $1))
	echo $res + $1 = $tmp
	res=$tmp
	shift
    done

    exit 0;
fi
	
