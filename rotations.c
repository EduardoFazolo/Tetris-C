#include "campo.h"
#include <stdlib.h>
#include <stdio.h>

void rotacaoJ(Piece *p, char field[ALTURA][LARGURA]){
    if(p->d == CIMA &&  p->r == ROT_0){
        drawSpaces(p, field);
        p->b1.x += 2;
        p->b2.x += 1;
        p->b3.x += 0;
        p->b4.x -= 1;

        if(p->b1.y < LARGURA-2 && p->b2.y < LARGURA-2 && p->b3.y < LARGURA-2 && p->b4.y < LARGURA-2){
            p->b1.y += 1;
            p->b2.y -= 0;
            p->b3.y -= 1;
            p->b4.y -= 0;
        }else{
            p->b1.y += 0;
            p->b2.y -= 1;
            p->b3.y -= 2;
            p->b4.y -= 1;
        }
        drawPieces(p, field);
        p->r = ROT_1;
    }else if(p->d == CIMA && p->r == ROT_1){
        drawSpaces(p, field);
        p->b1.x += 1;
        p->b2.x += 0;
        p->b3.x -= 1;
        p->b4.x -= 0;

        p->b1.y -= 1;
        p->b2.y -= 0;
        p->b3.y += 1;
        p->b4.y += 2;
        drawPieces(p, field);
        p->r = ROT_2;
    }else if(p->d == CIMA && p->r == ROT_2){
        drawSpaces(p, field);
        p->b1.x -= 0;
        p->b2.x += 1;
        p->b3.x += 2;
        p->b4.x += 3;
        if(p->b1.y > 2 && p->b2.y > 2 && p->b3.y > 2 && p->b4.y > 2){
            p->b1.y -= 1;
            p->b2.y += 0;
            p->b3.y += 1;
            p->b4.y += 0;
        }else{
            p->b1.y -= 0;
            p->b2.y += 1;
            p->b3.y += 2;
            p->b4.y += 1;
        }
        drawPieces(p, field);
        p->r = ROT_3;
    }else if(p->d == CIMA && p->r == ROT_3){
        drawSpaces(p, field);
        p->b1.x -= 2;
        p->b2.x -= 1;
        p->b3.x += 0;
        p->b4.x -= 1;

        p->b1.y += 1;
        p->b2.y += 0;
        p->b3.y -= 1;
        p->b4.y -= 2;
        drawPieces(p, field);
        p->r = ROT_0;
    }
}

void rotacaoL(Piece *p, char field[ALTURA][LARGURA]){
    if(p->d == CIMA &&  p->r == ROT_0){
        drawSpaces(p, field);
        p->b1.x += 2;
        p->b2.x += 1;
        p->b3.x -= 0;
        p->b4.x += 1;

        if(p->b1.y < LARGURA-2 && p->b2.y < LARGURA-2 && p->b3.y < LARGURA-2 && p->b4.y < LARGURA-2){
            p->b1.y += 2;
            p->b2.y += 1;
            p->b3.y -= 0;
            p->b4.y -= 1;
        }else{
            p->b1.y += 1;
            p->b2.y += 0;
            p->b3.y -= 1;
            p->b4.y -= 2;
        }
        drawPieces(p, field);
        p->r = ROT_1;
    }else if(p->d == CIMA && p->r == ROT_1){
        drawSpaces(p, field);
        p->b1.x -= 1;
        p->b2.x += 0;
        p->b3.x += 1;
        p->b4.x -= 2;

        p->b1.y -= 1;
        p->b2.y -= 0;
        p->b3.y += 1;
        p->b4.y -= 0;
        drawPieces(p, field);
        p->r = ROT_2;
    }else if(p->d == CIMA && p->r == ROT_2){
        drawSpaces(p, field);
        p->b1.x += 1;
        p->b2.x += 0;
        p->b3.x -= 1;
        p->b4.x -= 0;

        if(p->b1.y < LARGURA-2 && p->b2.y < LARGURA-2 && p->b3.y < LARGURA-2 && p->b4.y < LARGURA-2){
            p->b1.y -= 1;
            p->b2.y += 0;
            p->b3.y += 1;
            p->b4.y += 2;
        }else{
            p->b1.y -= 2;
            p->b2.y -= 1;
            p->b3.y += 0;
            p->b4.y += 1;
        }

        drawPieces(p, field);
        p->r = ROT_3;
    }else if(p->d == CIMA && p->r == ROT_3){
        drawSpaces(p, field);
        p->b1.x -= 2;
        p->b2.x -= 1;
        p->b3.x += 0;
        p->b4.x += 1;

        p->b1.y += 0;
        p->b2.y -= 1;
        p->b3.y -= 2;
        p->b4.y -= 1;
        drawPieces(p, field);
        p->r = ROT_0;
    }
}

void rotacaoS(Piece *p, char field[ALTURA][LARGURA]){
    if(p->d == CIMA &&  p->r == ROT_0){
        drawSpaces(p, field);
        p->b1.x += 2;
        p->b2.x += 1;
        p->b3.x -= 0;
        p->b4.x -= 1;

        p->b1.y += 0;
        p->b2.y += 1;
        p->b3.y -= 0;
        p->b4.y += 1;

        drawPieces(p, field);
        p->r = ROT_1;
    }else if(p->d == CIMA && p->r == ROT_1){
        drawSpaces(p, field);
        p->b1.x -= 2;
        p->b2.x -= 1;
        p->b3.x -= 0;
        p->b4.x += 1;

        p->b1.y -= 0;
        p->b2.y -= 1;
        p->b3.y += 0;
        p->b4.y -= 1;
        drawPieces(p, field);
        p->r = ROT_0;
    }
}

void rotacaoZ(Piece *p, char field[ALTURA][LARGURA]){
    if(p->d == CIMA &&  p->r == ROT_0){
        drawSpaces(p, field);
        p->b1.x += 0;
        p->b2.x += 1;
        p->b3.x += 0;
        p->b4.x += 1;

        p->b1.y += 2;
        p->b2.y += 1;
        p->b3.y += 0;
        p->b4.y -= 1;

        drawPieces(p, field);
        p->r = ROT_1;
    }else if(p->d == CIMA && p->r == ROT_1){
        drawSpaces(p, field);
        p->b1.x += 0;
        p->b2.x -= 1;
        p->b3.x -= 0;
        p->b4.x -= 1;

        p->b1.y -= 2;
        p->b2.y -= 1;
        p->b3.y += 0;
        p->b4.y += 1;
        drawPieces(p, field);
        p->r = ROT_0;
    }
}

void rotacaoI(Piece *p, char field[ALTURA][LARGURA]){
    if(p->d == CIMA &&  p->r == ROT_0 && p->b1.x < ALTURA -3 && p->b2.x < ALTURA -3 && p->b3.x < ALTURA -3 && p->b4.x < ALTURA -3){
        drawSpaces(p, field);
        p->b1.x -= 1;
        p->b2.x += 0;
        p->b3.x += 1;
        p->b4.x += 2;

        if(p->b1.y < LARGURA-2 && p->b2.y < LARGURA-2 && p->b3.y < LARGURA-2 && p->b4.y < LARGURA-2){// antes da parede direita
            p->b1.y = p->b2.y;
            p->b2.y = p->b2.y;
            p->b3.y = p->b2.y;
            p->b4.y = p->b2.y;
        }else{
            p->b1.y = p->b3.y;      //rotação na parede direita
            p->b2.y = p->b3.y;
            p->b3.y = p->b3.y;
            p->b4.y = p->b3.y;
        }

        drawPieces(p, field);
        p->r = ROT_1;
    }else if(p->d == CIMA && p->r == ROT_1){
        drawSpaces(p, field);
        p->b1.x += 1;
        p->b2.x -= 0;
        p->b3.x -= 1;
        p->b4.x -= 2;

        if(p->b1.y < LARGURA-3 && p->b2.y < LARGURA-3 && p->b3.y < LARGURA-3 && p->b4.y < LARGURA-3){// antes da parede direita
            p->b1.y = p->b2.y-1;
            p->b2.y = p->b2.y;
            p->b3.y = p->b2.y+1;
            p->b4.y = p->b2.y+2;
        }else{
            p->b1.y = p->b2.y-3;
            p->b2.y = p->b2.y-2;
            p->b3.y = p->b2.y+1;
            p->b4.y = p->b2.y+2;
        }
        drawPieces(p, field);
        p->r = ROT_0;
    }
}

void rotacaoT(Piece *p, char field[ALTURA][LARGURA]){
    if(p->d == CIMA &&  p->r == ROT_0){
        drawSpaces(p, field);
        p->b1.x -= 1;
        p->b2.x += 0;
        p->b3.x += 1;
        p->b4.x -= 1;

        p->b1.y += 1;
        p->b2.y -= 0;
        p->b3.y -= 1;
        p->b4.y -= 1;
        drawPieces(p, field);
        p->r = ROT_1;
    }else if(p->d == CIMA && p->r == ROT_1){
        drawSpaces(p, field);
        p->b1.x += 1;
        p->b2.x += 0;
        p->b3.x -= 1;
        p->b4.x -= 1;

        p->b1.y += 1;
        p->b2.y -= 0;
        p->b3.y -= 1;
        p->b4.y += 1;
        drawPieces(p, field);
        p->r = ROT_2;
    }else if(p->d == CIMA && p->r == ROT_2){
        drawSpaces(p, field);
        p->b1.x += 1;
        p->b2.x += 0;
        p->b3.x -= 1;
        p->b4.x += 1;

        p->b1.y -= 1;
        p->b2.y -= 0;
        p->b3.y += 1;
        p->b4.y += 1;
        drawPieces(p, field);
        p->r = ROT_3;
    }else if(p->d == CIMA && p->r == ROT_3){
        drawSpaces(p, field);
        p->b1.x -= 1;
        p->b2.x -= 0;
        p->b3.x += 1;
        p->b4.x += 1;

        p->b1.y -= 1;
        p->b2.y += 0;
        p->b3.y += 1;
        p->b4.y -= 1;
        drawPieces(p, field);
        p->r = ROT_0;
    }

}

void pieceRotation(char field[ALTURA][LARGURA], Piece* p, char booleanField[ALTURA][LARGURA]){
    if(p->b1.x < ALTURA -2 && p->b2.x < ALTURA -2 && p->b3.x < ALTURA -2 && p->b4.x < ALTURA -2){
        if(booleanField[p->b1.x+1][p->b1.y] == 'F' && booleanField[p->b2.x+1][p->b2.y] == 'F' && booleanField[p->b3.x+1][p->b3.y] == 'F' && booleanField[p->b4.x+1][p->b4.y] == 'F' &&
           booleanField[p->b1.x][p->b1.y+1] == 'F' && booleanField[p->b2.x][p->b2.y+1] == 'F' && booleanField[p->b3.x][p->b3.y+1] == 'F' && booleanField[p->b4.x][p->b4.y+1] == 'F' &&
           booleanField[p->b1.x][p->b1.y-1] == 'F' && booleanField[p->b2.x][p->b2.y-1] == 'F' && booleanField[p->b3.x][p->b3.y-1] == 'F' && booleanField[p->b4.x][p->b4.y-1] == 'F'){
            if(p->t == I)
                rotacaoI(p, field);
            else if(p->t == J)
                rotacaoJ(p, field);
            else if(p->t == L)
                rotacaoL(p, field);
            else if(p->t == S)
                rotacaoS(p, field);
            else if(p->t == Z)
                rotacaoZ(p, field);
            else if(p->t == T)
                rotacaoT(p, field);
        }
    }
}
