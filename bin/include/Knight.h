#ifndef H_KNIGHT
#define H_KNIGHT

#include <Piece.h>

class Square;

class Knight: public Piece
{
public:
    Knight(bool isWhite);
    bool moveTo(int fromX, int fromY, int toX, int toY, Square* (&board)[8][8]);
};

#endif
