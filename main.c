#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "campo.h"
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#define limpa_tela() system("cls")
#define dorme(milis) Sleep(milis)
#else
#include <time.h>
#include <unistd.h>
#define limpa_tela() system("clear")
#define dorme(milis) usleep(milis * 1000)
#endif

void gameStarted(){
    char field[ALTURA][LARGURA];
    char booleanField[ALTURA][LARGURA];
    int direction;
    Piece* p;
    Player *plr;

    p = new_piece();
    startField(field, booleanField);
    piecesCoord(p);

    while(1){
        limpa_tela();
        drawField(field);

        if(p->e != P_PARADA){
            drawPieces(p, field);
            if (kbhit()) {
                direction = getch();
                changeDirection(p, direction, booleanField);
                pieceRotation(field,  p, booleanField);
                if(p->d == BAIXO){
                    fall_pieces(field, p, booleanField);
                    fall_pieces(field, p, booleanField);
                    fall_pieces(field, p, booleanField);
                }

            }
            move_piece(field, p, field);
            fall_pieces(field, p, booleanField);

        }else if(p->e == P_PARADA){
                Scoring(booleanField, field, p);
                p->e = P_CAINDO;
                free(p);
                p = new_piece();
                piecesCoord(p);
                gameover(field, booleanField, p);

        }
        dorme(100);

    }
}

int main(){

    gameStarted();

    return 0;
}
