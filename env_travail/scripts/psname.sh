#!/bin/bash

usage()
{
    echo "usage: $0 nom_processus";
    exit 1;
}


# Boucle principale

if [ $# -ne 1 ]
then
    usage;
else
    ps | grep $1;
fi
    
    

