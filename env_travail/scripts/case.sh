#!/bin/bash

case $1 in
    *.sh)
	echo "$1 est un script bash"
	;;
    *.txt)
	echo "$1 est un fichier texte"
	;;
    *)
	echo "No se"
	;;
esac
