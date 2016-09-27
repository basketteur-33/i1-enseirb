# i1-enseirb

PARPAITE Thibault

Ce dépot github contient une proposition de correction des exercices de programmation C disponibles à cette adresse.
https://www.labri.fr/perso/fmoranda/pg101/

## Récupérer le projet github en local
Placez vous dans votre home directory (ou repertoire de votre choix)
```
cd ~
```

Clonez le répertoire github
```
git clone https://github.com/tparpaite/i1-enseirb.git
```

Pour mettre à jour votre branche locale à partir de la branche distante par la suite
```
git pull
```

## Compilation

Placez vous dans un repertoire contenant un Makefile (par exemple ~/i1-enseirb/prog_c/tp_01) et tapez la commande
```
make
```

Cela revient à taper la commande suivante (pour chaque exercice)
```
gcc -std=c99 -Wall -Werror -o exemple exemple.c
```


PS : N'hésitez pas à faire des remarques si vous trouvez une erreur ou ne comprenez pas une partie du code.  
PPS : Groupe 4 > all  
PPPS : C'est qui le WEI ??
