#ifndef H_PAWN
#define H_PAWN

#include <Piece.h>

class Board;

class Pawn: public Piece
{
public:
    Pawn(bool isWhite, std::string filepath);
    bool moveTo(int fromX, int fromY, int toX, int toY, Board* board);
};

#endif
