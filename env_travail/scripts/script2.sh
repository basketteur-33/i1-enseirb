#!/bin/bash

echo "Commande : $0"
echo "PID : $$"
echo -e "Taille du vecteur arguments : $#"
echo "La liste de mes arguments est :"

for i in $*
do
    echo $i;
done
