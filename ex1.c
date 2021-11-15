#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <unistd.h>

//Toni Valverde

int main(int argc, char const *argv[]) {

  //Random Generator
  srand((unsigned)time(NULL));

  //Color Win32 API
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  WORD saved_attributes;
  GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  saved_attributes = consoleInfo.wAttributes;

    //By appareance order
  	int debug=0,i,j,menu,seconds,players=0,playercount=0,playerturn=0,dice[5],chances,highscore=0,restart,winner=0,pts=0,winnerpoints=0,scorewinner[5],scorepts[5],playcount=0;

    menu:

    printf("_________________________\n");
    printf("\n\tDROP DEAD\n");
    printf("_________________________\n");
    printf("\n\tMENU\n\n");
    if (debug == 1) {
      printf("\n\tDebug Mode");
      SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
      printf(" ON\n\n");
      SetConsoleTextAttribute(hConsole, saved_attributes);
    }
    if (debug == 0) {
      printf("\n\tDebug Mode");
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
      printf(" OFF\n\n");
      SetConsoleTextAttribute(hConsole, saved_attributes);
    }
    printf("_________________________\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("\n\tPLAY (1)\n\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    SetConsoleTextAttribute(hConsole, 6);
    printf("\n\tSCORES (2)\n\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    SetConsoleTextAttribute(hConsole, 9);
    printf("\n\tRESTART SCORES (3)\n\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    SetConsoleTextAttribute(hConsole, 5);
    printf("\n\tCREDITS (4)\n\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n\tDEBUGGING (5)\n\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("\n\tQUIT (6)\n\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    scanf("%d", &menu);

    if (menu == 1) {
      players=0;
      system("cls");
      printf("How many players are going to play? ");
      scanf("%d", &players);
      if (players == 1) {
        printf("\n\n\tMinimum Players: 2\n\n");
        sleep(2);
        system("cls");
        goto menu;
      }

      printf("\n\n\tGame Started!\n\n");
      playercount=0;
      playerturn=0;
      pts=0;
      winnerpoints=0;

        for (i=players;i>0;i--) {
          printf("Player %d ", playercount + 1);
          SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
          printf("Online\n");
          SetConsoleTextAttribute(hConsole, saved_attributes);
          playercount++;
        }

        sleep(2);
        system("cls");

        for (i=players;i>0;i--) {

          SetConsoleTextAttribute(hConsole, 3);
          printf("\nIt's Player %d Turn!\n", playerturn + 1);
          SetConsoleTextAttribute(hConsole, saved_attributes);

          for (chances=5;chances>0;chances--) {
            printf("\nPress Any key to roll the dice! ");
            getchar();
            scanf("%d", &dice[chances]);
            dice[chances] = rand() % (6 - 1 + 1) + 1;
            printf("\nYou've got a %d!\n", dice[chances]);
            if (dice[chances] == 2 || dice[chances] == 5) {
              pts = pts + 0;
            }
            if (dice[chances] == 1 || dice[chances] == 3 || dice[chances] == 4 || dice[chances] == 6) {
              pts = pts + dice[chances];
            }
          }
          printf("\n\n\tTotal Points: %d", pts);

          if (pts>winnerpoints) {
            winner = playerturn + 1;
            winnerpoints = pts;
            scorewinner[playcount] = winner;
            scorepts[playcount] = winnerpoints;
          }

          if (debug == 1) {
            printf("\n\nDebug:\nCurrent Points (pts): %d \nCurrent Winning Strike (winnerpoints): %d \nCurrent Player Turn (playerturn): %d \nPlayers in Game (playercount): %d \nCurrent Game Number (playcount): %d \nscorewinner: %d \nscorepts: %d \n", pts, winnerpoints, playerturn + 1, playercount, playcount, scorewinner, scorepts);
          }

          printf("\n\nWait 2 Seconds\n");
          sleep(2);
          pts=0;
          playerturn++;
        }
        printf("\nPlayer Number %d Won with %d points!\n", winner, winnerpoints);

        printf("\n\tEnd Game\n");
        sleep(5);
        playcount++;
        system("cls");
        goto menu;
    }

    if (menu == 2) {
      system("cls");
      SetConsoleTextAttribute(hConsole, 9);
      printf("\n\tSCORES\n\n");
      SetConsoleTextAttribute(hConsole, saved_attributes);

      for (i=0;i<5;i++) {
        printf("Player %d with %d points\n",scorewinner[i], scorepts[i]);
      }

      printf("\nRedirecting to the Menu in ");
      for (seconds=5;seconds>0;seconds--) {
        printf("%d ", seconds);
        sleep(1);
      }
      system("cls");
      sleep(2);
      goto menu;
    }

    if (menu == 3) {
      system("cls");
      for (i=0;i<5;i++) {
        scorewinner[i]=0;
        scorepts[i]=0;
      }
      printf("Scores Restarted.");
      sleep(2);
      system("cls");
      goto menu;
    }

    if (menu == 4) {
      system("cls");
      printf("Toni Valverde | tovape.github.io\n\n");
      printf("Redirecting to the Menu in ");
      for (seconds=5;seconds>0;seconds--) {
        printf("%d ", seconds);
        sleep(1);
      }
      system("cls");
      sleep(2);
      goto menu;
    }

    if (menu == 5) {
      system("cls");
      printf("Turn On Debug Mode?");
      printf("\nUse debug mode to see variable values in game\n");
      printf("\n\n\t 1 = Yes | 0 = No\n\n");
      scanf("%d", &debug);
      system("cls");
      goto menu;
    }

    if (menu == 6) {
      system("cls");
      printf("Bye!");
      sleep(3);
      return 0;
    }
    return 0;
  }
