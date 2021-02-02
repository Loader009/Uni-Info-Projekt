
#define PLAYERCOUNT 2
#define PLAYERFIGURES 2
#define NAMELENGTH 14
#define DICE 2            // Würfel
#define FIELDCOUNT 40     // Wieviele?


typedef struct playDef {
  //int   number;                       // lets begin with player 1
  char* name[NAMELENGTH];
  int   startpos;
  int*  pos[PLAYERFIGURES][2] = {0,0};   // begin at zero position - real position is measured by the playernumber!
} playDef;


void enterName();
void assignStartpos(*player);
