#ifndef H_KNIGHT
#define H_KNIGHT

#include <Piece.h>

class Board;

class Knight: public Piece
{
public:
    Knight(bool isWhite);
    bool moveTo(int fromX, int fromY, int toX, int toY, Board* board);
};

#endif
