#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

void clearBuffer(void){
  int c;
  do{ c = getchar();
  } while(c != '\n' && c != EOF);
}

void initPlayer(char playername[][NAMELENGTH]) {
  printf("Bitte Spielernamen eingeben. (%i Zeichen)\n", NAMELENGTH-1);

  for (int i = 0; i < PLAYERCOUNT; i++ ){
    printf("Spieler %d: ", i+1);
    scanf("%s", playername[i]);
    clearBuffer();
    //assignStartpos(i, player);
  }
  //printf("Danke für die Eingabe, das Spiel beginnt!\n\n"); // Trommelwirbel

}

void PlayerAge(int playerage[]) {
  printf("Bitte Spieleralter eingeben.\n");

  for (int i = 0; i < PLAYERCOUNT; i++ ){
    printf("Spieler %d: ", i+1);
    scanf("%i", &playerage[i]);
    clearBuffer();
    //assignStartpos(i, player);
  }
  printf("Danke für die Eingabe, das Spiel beginnt!\n\n"); // Trommelwirbel

}

int begin(int playerage[]) {
  if(playerage[0] <= playerage[1]) return 0;
  else return 1;
}

void initPos(int startpos[][PLAYERFIGURES]) {
  for (int i = 0; i < PLAYERCOUNT; i++) {
    for (int k = 0; k < PLAYERFIGURES; k++) {
      startpos[i][k] = i* FIELDCOUNT / PLAYERCOUNT;
    }
  }
}

int dice(void){ // spuckt Würfelwert aus
  int wert = rand()%6+1;
  return wert;
}

int firstThrow(void){
  int wurf = dice();
  printf("Es wurde eine %i gewürfelt!\n", wurf);

  for(int i = 0; i < 3; i++) {
    if(wurf == 6) return 1;
  }
  return 0;
}


int main(void) {
  char playername[PLAYERCOUNT][NAMELENGTH] = {"\0"};
  int  playerage[PLAYERCOUNT];
  int  startpos[PLAYERCOUNT][PLAYERFIGURES];
  int  currentPlayer = 0;
  srand(time(NULL));

  initPlayer(playername);
  PlayerAge(playerage);

  currentPlayer = begin(playerage);
  printf("Spieler %s beginnt!\n", playername[currentPlayer]);
  initPos(startpos);


  firstThrow();


/*
  for (int i = 0; i < PLAYERCOUNT; i++ ){
    printf("Spieleralter: %i\n", playerage[i]);
  }
*/
}
