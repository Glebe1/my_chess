#ifndef H_ROOK
#define H_ROOK

#include <Piece.h>

class Board;

class Rook: public Piece
{
public:
    Rook(bool isWhite, std::string filepath);
    bool moveTo(int fromX, int fromY, int toX, int toY, Board* board);
};

#endif
