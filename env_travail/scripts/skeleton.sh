#!/bin/bash

# Fonctions

usage()
{
    echo "usage: $0 type filename"
    exit 1
}


# $1 : nom du fichier (avec extension)
# $2 : symbole de commentaire
header()
{
    echo -e "$2
$2 file : $1
$2 date : `date`
$2 author : $USER <$USER@enseirb-matmeca.fr>
$2 description :
$2
" >> $1
}


# $1 : nom du fichier
skeleton_bash()
{
    touch $1.sh
    header $1.sh \#
    echo -e "#!`which bash`

usage()
{
\techo \"usage: \$0 ...\"
\texit 1
}


# Boucle principale

if [ \$# -ne ... ]
then
\tusage
else
\texit 0
fi" >> $1.sh
    chmod u+x $1.sh
}
  

# $1 : nom du fichier
skeleton_latex()
{
    touch $1.tex
    header $1.tex %
    echo -e '\documentclass{article}
%\usepackage{}

\\begin{document}

\\end{document}' >> $1.tex
}


# Boucle principale

if [ $# -ne 2 ]
then
    usage
else
    if [ $1 = latex ]
    then
	skeleton_latex $2
    elif [ $1 = bash ]
    then
	skeleton_bash $2
    else
	echo "$1 type non reconnu ! Types disponibles : bash, latex"
	exit 1
    fi   
    exit 0
fi
