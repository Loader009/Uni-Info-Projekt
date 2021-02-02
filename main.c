#include <stdio.h>
#include <time.h>
#include "main.h"


void initPlayer(playDef *player) {
  printf("Bitte Spielernamen eingeben. (%i Zeichen)\n", NAMELENGTH);

  for (int i = 0; i < PLAYERCOUNT; i++ ){
    printf("Spieler %d: ", i+1);
    scanf("%s", player[i].name);

    assignStartpos(i, player);
  }
  printf("Danke für die Eingabe, das Spiel beginnt!"); // Trommelwirbel

}

void assignStartPos(int playerNumber, playDef *player) {
  player[playerNumber].startPos = FIELDCOUNT / playerNumber * (playerNumber+1);
}


void move(int *dice, int *figure) {
  payer[playerNumber]->pos[*figure] += *dice;
}

// returns 0 (true) if answer to question is yes
int decide(char* question) {
  char decision = 'n';

  printf("%s (j/n) ", question);
  scanf("%c", &decision);

  while( decision != 'j' && decision != 'n' ) {
    printf("Es wurde weder 'j', noch 'n' eingegeben, bitte erneut eingeben. (j/n) ");
    scanf("%c", &decision);
  }
  else if(decision == 'j') { return 0; }
  else { return decide(question); }

  // This doesn't happen - but in case it does.
  printf("\nFehler bei decide()!!!\ndecision = '%c'", decision);
  exit(1);
}


int main(void) {
  playDef player[PLAYERCOUNT];

  int currentPlayer;
  int fieldCount; // What is possible? How much do we want? What is default for the game? min/max

  initPlayer(player);

}
