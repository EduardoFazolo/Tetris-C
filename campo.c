#include "campo.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void gameover(char field [ALTURA][LARGURA], char booleanField[ALTURA][LARGURA], Piece *p){
    if(field[p->b4.x+1][p->b4.y] == '#'){
        system("cls");
        printf("\n\n\t\t\t\t  !!GAME OVER!! \n\n");
        exit(1);

    }
}

void seed(void) {
    srand(time(NULL));
    rand();
}

void startField (char field[ALTURA][LARGURA], char booleanField[ALTURA][LARGURA]) {
    int i, j;

    for (i = 0; i < ALTURA; i ++){
        for (j = 0; j < LARGURA; j++) {
          booleanField[i][j] = 'F';
        }
    }

    for (i = 0; i < ALTURA; i ++){
        for (j = 0; j < LARGURA; j++) {
          field[i][j] = TETO_E_CHAO;
        }
    }
    for (i = 0; i < ALTURA ; i++) {
        for (j = 0; j < LARGURA; j += (LARGURA - 1)){
          field[i][j] = PAREDES;
        }
    }
    for (i = 1; i < ALTURA-1; i ++){
        for (j = 1; j < LARGURA-1; j++) {
          field[i][j] = ESPACO;
        }
    }

}

void drawField (char field[ALTURA][LARGURA]) {
  int i, j;
  for (i = 0; i < ALTURA; i++) {
          printf("\t\t\t   ");
    for (j = 0; j < LARGURA; j++) {
      printf("%c", field[i][j]);
    }
    printf("\n");
  }
}


void drawPieces(Piece *p, char field[ALTURA][LARGURA]){
    field[p->b1.x][p->b1.y] = '#';
    field[p->b2.x][p->b2.y] = '#';
    field[p->b3.x][p->b3.y] = '#';
    field[p->b4.x][p->b4.y] = '#';
}

void drawSpaces(Piece *p, char field[ALTURA][LARGURA]){
    field[p->b1.x][p->b1.y] = ' ';
    field[p->b2.x][p->b2.y] = ' ';
    field[p->b3.x][p->b3.y] = ' ';
    field[p->b4.x][p->b4.y] = ' ';
}

void fillBoolField(Piece* p, char booleanField[ALTURA][LARGURA]){
    booleanField[p->b1.x][p->b1.y] = 'V';
    booleanField[p->b2.x][p->b2.y] = 'V';
    booleanField[p->b3.x][p->b3.y] = 'V';
    booleanField[p->b4.x][p->b4.y] = 'V';
}

void move_piece (char field[ALTURA][LARGURA], Piece* p, char booleanField[ALTURA][LARGURA]) {
   if (p->d == ESQUERDA ){
        if (p->b1.y > 1 && p->b2.y > 1 && p->b3.y > 1 && p->b4.y > 1){
            drawSpaces(p, field);
            p->b1.y -= 1;
            p->b2.y -= 1;
            p->b3.y -= 1;
            p->b4.y -= 1;
            drawPieces(p, field);
            p->d = STOP;
        }
   }
    else  if(p->d == DIREITA){
        if (p->b1.y < LARGURA-2 && p->b2.y < LARGURA-2 && p->b3.y < LARGURA-2 && p->b4.y < LARGURA-2){
            drawSpaces(p, field);
            p->b1.y += 1;
            p->b2.y += 1;
            p->b3.y += 1;
            p->b4.y += 1;
            drawPieces(p, field);
            p->d = STOP;
        }
   }
}


void fall_pieces(char field[ALTURA][LARGURA], Piece* p, char booleanField[ALTURA][LARGURA]){
    if(p->b1.x < ALTURA -2 && p->b2.x < ALTURA -2 && p->b3.x < ALTURA -2 && p->b4.x < ALTURA -2){
        if(booleanField[p->b1.x+1][p->b1.y] == 'F' && booleanField[p->b2.x+1][p->b2.y] == 'F' && booleanField[p->b3.x+1][p->b3.y] == 'F' && booleanField[p->b4.x+1][p->b4.y] == 'F'){
            drawSpaces(p, field);
            p->b1.x += 1;
            p->b2.x += 1;
            p->b3.x += 1;
            p->b4.x += 1;
            drawPieces(p, field);
            p->e = P_CAINDO;
        }else{
            p->e = P_PARADA;
            fillBoolField(p, booleanField);
        }
    }else{
        p->e = P_PARADA;
        fillBoolField(p, booleanField);
    }
}

void changeDirection (Piece* p, int d, char booleanField[ALTURA][LARGURA]) {
    if (d == 'a') {
    if(booleanField[p->b1.x][p->b1.y-1] == 'F' && booleanField[p->b2.x][p->b2.y-1] == 'F' && booleanField[p->b3.x][p->b3.y-1] == 'F' && booleanField[p->b4.x][p->b4.y-1] == 'F'){

        p->d = ESQUERDA;
        }
    }
    else if (d == 'd') {
    if(booleanField[p->b1.x][p->b1.y+1] == 'F' && booleanField[p->b2.x][p->b2.y+1] == 'F' && booleanField[p->b3.x][p->b3.y+1] == 'F' && booleanField[p->b4.x][p->b4.y+1] == 'F'){

        p->d = DIREITA;
        }
    }
    else if (d == 'w') {
        p->d = CIMA;
    }
    else if (d == 's') {
        p->d = BAIXO;
    }
}

Piece* new_piece () {
    Piece* p = (Piece*) malloc(sizeof(Piece));
    if (!p) {
        printf("Não foi possível criar uma nova peça!\n");
        exit(1);
    }
    seed();
    p->t = rand()%7;
    p->r = ROT_0;

    return p;
}

void piecesCoord(Piece* p){
    if(p->t == I){
        p->b1.x = 1;
        p->b2.x = 1;
        p->b3.x = 1;
        p->b4.x = 1;

        p->b1.y = (LARGURA/2)-2;
        p->b2.y = (LARGURA/2)-1;
        p->b3.y = (LARGURA/2);
        p->b4.y = (LARGURA/2)+1;

        p->height = 1;

    }
    else if(p->t == J){
        p->b1.x = 1;
        p->b2.x = 2;
        p->b3.x = 3;
        p->b4.x = 3;

        p->b1.y = (LARGURA/2);
        p->b2.y = (LARGURA/2);
        p->b3.y = (LARGURA/2);
        p->b4.y = (LARGURA/2)-1;

         p->height = 3;


    }
    else if(p->t == L){
        p->b1.x = 1;
        p->b2.x = 2;
        p->b3.x = 3;
        p->b4.x = 3;

        p->b1.y = (LARGURA/2)-1;
        p->b2.y = (LARGURA/2)-1;
        p->b3.y = (LARGURA/2)-1;
        p->b4.y = (LARGURA/2);

         p->height = 3;

    }
    else if(p->t == O){
        p->b1.x = 1;
        p->b2.x = 2;
        p->b3.x = 1;
        p->b4.x = 2;

        p->b1.y = (LARGURA/2)-1;
        p->b2.y = (LARGURA/2)-1;
        p->b3.y = (LARGURA/2);
        p->b4.y = (LARGURA/2);

         p->height = 2;

    }
    else if(p->t == S){
        p->b1.x = 1;
        p->b2.x = 1;
        p->b3.x = 2;
        p->b4.x = 2;

        p->b1.y = (LARGURA/2)+1;
        p->b2.y = (LARGURA/2);
        p->b3.y = (LARGURA/2);
        p->b4.y = (LARGURA/2)-1;

         p->height = 2;

    }
    else if(p->t == Z){
        p->b1.x = 1;
        p->b2.x = 1;
        p->b3.x = 2;
        p->b4.x = 2;

        p->b1.y = (LARGURA/2)-1;
        p->b2.y = (LARGURA/2);
        p->b3.y = (LARGURA/2);
        p->b4.y = (LARGURA/2)+1;

         p->height = 2;

    }
    else if(p->t == T){
        p->b1.x = 1;
        p->b2.x = 1;
        p->b3.x = 1;
        p->b4.x = 2;

        p->b1.y = (LARGURA/2)-1;
        p->b2.y = (LARGURA/2);
        p->b3.y = (LARGURA/2)+1;
        p->b4.y = (LARGURA/2);

         p->height = 2;

    }
}

void Scoring(char field[ALTURA][LARGURA],char booleanField[ALTURA][LARGURA], Piece* p){
    int counter = 0;
    if (p->t == I){
        if(p->r == ROT_0){
            counter = p->b1.x;
            clearLine(field, booleanField, counter, 1);
          }
        else if(p->r == ROT_1){
                counter = p->b4.x;
                clearLine(field, booleanField, counter, 4);
                counter = p->b3.x;
                clearLine(field, booleanField, counter, 3);
                counter = p->b2.x;
                clearLine(field, booleanField, counter, 2);
            }
        }

    else if(p->t == S){
        if(p->r == ROT_0){
            counter = p->b3.x;
            clearLine(field, booleanField, counter, 2);
            counter = p->b2.x;
            clearLine(field, booleanField, counter, 1);
          }
        else if(p->r == ROT_1){
                counter = p->b4.x;
                clearLine(field, booleanField, counter,3);
                counter = p->b3.x;
                clearLine(field, booleanField, counter, 2);
                counter = p->b1.x;
                clearLine(field, booleanField, counter, 1);
            }
    }

    else if(p->t == L){
        if(p->r == ROT_0){
            counter = p->b4.x;
            clearLine(field, booleanField, counter, 3);
            counter = p->b2.x;
            clearLine(field, booleanField, counter, 2);
            counter = p->b1.x;
            clearLine(field, booleanField, counter, 1);
          }
        else if(p->r == ROT_1){
                counter = p->b4.x;
                clearLine(field, booleanField, counter, 2);
                counter = p->b3.x;
                clearLine(field, booleanField, counter, 1);
            }
        else if(p->r == ROT_2){
                counter = p->b1.x;
                clearLine(field, booleanField, counter, 3);
                counter = p->b2.x;
                clearLine(field, booleanField, counter, 2);
                counter = p->b3.x;
                clearLine(field, booleanField, counter, 1);

        }
        else if(p->r == ROT_3){
                counter = p->b3.x;
                clearLine(field, booleanField, counter, 2);
                counter = p->b4.x;
                clearLine(field, booleanField, counter, 1);

        }

    }

    else if(p->t == J){
        if(p->r == ROT_0){
            counter = p->b4.x;
            clearLine(field, booleanField, counter, 3);
            counter = p->b2.x;
            clearLine(field, booleanField, counter, 2);
            counter = p->b1.x;
            clearLine(field, booleanField, counter, 1);
          }
        else if(p->r == ROT_1){
                counter = p->b3.x;
                clearLine(field, booleanField, counter, 2);
                counter = p->b4.x;
                clearLine(field, booleanField, counter, 1);
            }
        else if(p->r == ROT_2){
                counter = p->b1.x;
                clearLine(field, booleanField, counter, 3);
                counter = p->b2.x;
                clearLine(field, booleanField, counter, 2);
                counter = p->b3.x;
                clearLine(field, booleanField, counter, 1);

        }
        else if(p->r == ROT_3){
                counter = p->b4.x;
                clearLine(field, booleanField, counter, 2);
                counter = p->b3.x;
                clearLine(field, booleanField, counter, 1);

        }

    }

    else if(p->t == Z){
        if(p->r == ROT_0){
            counter = p->b3.x;
            clearLine(field, booleanField, counter, 2);
            counter = p->b2.x;
            clearLine(field, booleanField, counter, 1);
          }
        else if(p->r == ROT_1){
                counter = p->b1.x;
                clearLine(field, booleanField, counter, 3);
                counter = p->b2.x;
                clearLine(field, booleanField, counter, 2);
                counter = p->b4.x;
                clearLine(field, booleanField, counter, 1);
            }
    }

    else if(p->t == T){
        if(p->r == ROT_0){
            counter = p->b4.x;
            clearLine(field, booleanField, counter, 2);
            counter = p->b1.x;
            clearLine(field, booleanField, counter, 1  );
        }
        else if(p->r == ROT_1){
                counter = p->b3.x;
                clearLine(field, booleanField, counter, 3);
                counter = p->b1.x;
                clearLine(field, booleanField, counter, 2);
                counter = p->b2.x;
                clearLine(field, booleanField, counter, 1);
            }
        else if(p->r == ROT_2){
                counter = p->b1.x;
                clearLine(field, booleanField, counter, 2);
                counter = p->b4.x;
                clearLine(field, booleanField, counter, 1);
        }
        else if(p->r == ROT_3){
                counter = p->b2.x;
                clearLine(field, booleanField, counter, 3);
                counter = p->b1.x;
                clearLine(field, booleanField, counter, 2);
                counter = p->b3.x;
                clearLine(field, booleanField, counter, 1);

        }

    }

    else if(p->t == O){
            counter = p->b4.x;
            clearLine(field, booleanField, counter, 2);
            counter = p->b1.x;
            clearLine(field, booleanField, counter, 1);

    }


}

void clearLine(char booleanField[ALTURA][LARGURA],char field[ALTURA][LARGURA], int counter, int repete){
    int i,j, k, zero = 0;

    while(zero < repete){
        k = 0;
        for(i = counter; i == counter; i--){
            for(j = 1; j <LARGURA-1; j++){
                if(booleanField[i][j] == 'V'){
                    k++;
                }
            }
        }
        if(k == LARGURA-2){
            for(i=counter; i == counter; i--){
                for(j=1;j<LARGURA-1;j++){
                    field[i][j] = ESPACO;
                    booleanField[i][j] = 'F';
                }
            }
            for(i=counter-1; i >= 1 ;i--){
                for(j=1;j<LARGURA-1;j++){
                    if(booleanField[i][j] == 'V'){
                        field[i][j] = ESPACO;
                        booleanField[i][j] = 'F';
                        field[i+1][j] = '#';
                        booleanField[i+1][j] = 'V';

                    }
                }
            }
        }
        zero++;
    }
}
