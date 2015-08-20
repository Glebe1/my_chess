#ifndef H_BISHOP
#define H_BISHOP

#include <Piece.h>

class Board;

class Bishop: public Piece
{
public:
    Bishop(bool isWhite, std::string filepath);
    bool moveTo(int fromX, int fromY, int toX, int toY, Board* board);
};

#endif
