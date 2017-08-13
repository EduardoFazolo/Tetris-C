#ifndef CAMPO_H

#define LARGURA 16
#define ALTURA 23
#define LARGURA1 6
#define ALTURA1 6

#define TETO_E_CHAO '-'
#define PAREDES '|'
#define ESPACO ' '


typedef enum pieceType{
  I,
  J,
  L,
  O,
  S,
  T,
  Z
}pieceType;

typedef enum direcao{
  ESQUERDA,
  DIREITA,
  CIMA,
  BAIXO,
  STOP
} Direcao;

typedef enum estado{
    P_CAINDO,
    P_PARADA
}Estado;

typedef enum rotacao{
    ROT_0,
    ROT_1,
    ROT_2,
    ROT_3,
    NONE
}Rotacao;

typedef struct bloco{
    int x, y;
}Bloco;

typedef struct piece{
    Bloco b1, b2, b3, b4;
    pieceType t;
    Direcao d;
    Rotacao r;
    Estado e;
    int height;
}Piece;

typedef struct player{
    char nome[6];
    int pontos;
}Player;

void startField (char field[ALTURA][LARGURA], char booleanField[ALTURA][LARGURA]);
Piece* new_piece ();
void piecesCoord(Piece* p);
void drawField (char field[ALTURA][LARGURA]);
void drawPieces (Piece* p, char field[ALTURA][LARGURA]);
void move_piece (char field[ALTURA][LARGURA], Piece* p, char BooleanField[ALTURA][LARGURA]);
void changeDirection (Piece* p, int d, char booleanField[ALTURA][LARGURA]);
void fillBoolField(Piece* p, char booleanField[ALTURA][LARGURA]);
void fall_pieces(char field[ALTURA][LARGURA],Piece* p, char booleanField[ALTURA][LARGURA]);
void pieceRotation(char field[ALTURA][LARGURA], Piece* p, char booleanField[ALTURA][LARGURA]);
void clearLine(char booleanField[ALTURA][LARGURA],char field[ALTURA][LARGURA], int counter, int repete);
void Scoring(char field[ALTURA][LARGURA], char booleanField[ALTURA][LARGURA], Piece* p);
void gameover(char field[ALTURA][LARGURA], char booleanField[ALTURA][LARGURA], Piece *p);



#endif // CAMPO_H
