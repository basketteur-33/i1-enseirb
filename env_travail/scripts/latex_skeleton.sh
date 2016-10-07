#!/bin/bash

usage()
{
    echo "usage: $0 filename"
    exit 1
}


# Boucle principale

if [ $# -ne 1 ]
then
    usage
else
    touch $1.tex
    exit 0
fi
