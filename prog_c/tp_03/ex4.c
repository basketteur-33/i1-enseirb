#include <stdlib.h>
#include <stdio.h>

void usage(char *s) {
  perror(s);
  exit(1);
}


/* Retourne le caractere associe a un numero de joueur */
char playerid_to_sign(int player_id) {
  if (player_id == 1)
    return 'X';
  return 'O';
}
  

/* Retourne le numero de joueur associe a un caractere */
int sign_to_playerid(char c) {
  if (c == 'O')
    return 1;
  return 2;
}


void display_grid(char t[3][3]) {
  for (int i = 0 ; i < 3 ; i++) {
    for (int j = 0 ; j < 3 ; j++) 
      printf("|%c", t[i][j]);
    printf("|\n");
  }
}


/* Effectue un mouvement (mise a jour de la grille)  */
void play(int player_id, char t[3][3], int i, int j) {
  char sign = playerid_to_sign(player_id); 

  t[i][j] = sign;
  printf("Move en [%d][%d]\n\n", i, j);
}


/* Retourne 0 si pas de gagnant, 1 ou 2 sinon */
int check_lines(char t[3][3]) {
  /* Horizontales */
  for (int i = 0 ; i < 3 ; i++) {
    for (int j = 1 ; j < 3 ; j++) {
      if (t[i][j] != t[i][j-1] || t[i][j] == '.')
	break;
      if (j == 2)
	return sign_to_playerid(t[i][j]);
    }
  }	   
      
  /* Verticales */
  for (int j = 0 ; j < 3 ; j++) {
    for (int i = 1 ; i < 3 ; i++) {
      if (t[i][j] != t[i-1][j] || t[i][j] == '.')
	break;
      if (i == 2)
	return sign_to_playerid(t[i][j]);
    }
  }

  /* Diagonales */
  /* TODO */
  return 0;
}

  
/* Retourne 1 si la partie est terminee, 0 sinon */
int check_game(char t[3][3]) {  
  int res = check_lines(t);

  if (res) {
    printf("Le joueur %d a gagné !\n\n", res);
    display_grid(t);
    return 1;
  }

  return 0;
}  
    

/* Retourne 1 si le mouvement est valide, 0 sinon */
int is_valid(char t[3][3], int i, int j) {
  if (i >= 0 && i < 3 && j >= 0 && j < 3 && t[i][j] == '.')
    return 1;

  printf("Mouvement invalide...\n");
  display_grid(t);
  return 0;
}


/* Attention decalage d'indice : un mouvement en [1,2] devient [0][1] en indices */
void next_turn(int player_id, char t[3][3]) {
  int i, j;
  int valid_move = 0;

  while (!valid_move) {
    printf("\n[Joueur %d]\n", player_id);
    printf("Ligne : ");
    scanf("%d", &i);
    printf("Colonne : ");
    scanf("%d", &j);

    valid_move = is_valid(t, i-1, j-1);
  }

  play(player_id, t, i-1, j-1);
}
 

void start_game() {
  /* On initialise la grille */
  char t[3][3] = { {'.', '.', '.'},
		   {'.', '.', '.'},
		   {'.', '.', '.'} };

  int player_id = 1;

  while(!check_game(t)) {
    display_grid(t);
    next_turn(player_id, t);

    if (player_id == 1)
      player_id = 2;
    else 
      player_id = 1;
  }
}


int main(int argc, char *argv[]) {
  if (argc != 1)
    usage("usage: ./ex4");
  
  start_game();

  return EXIT_SUCCESS;
}
