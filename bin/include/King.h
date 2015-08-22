#ifndef H_KING
#define H_KING

#include <Piece.h>

class Board;

class King: public Piece
{
public:
    King(bool isWhite, std::string filepath);
    bool moveTo(int fromX, int fromY, int toX, int toY, Board* board);
};

#endif
