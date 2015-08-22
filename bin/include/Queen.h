#ifndef H_QUEEN
#define H_QUEEN

#include <Piece.h>

class Board;

class Queen: public Piece
{
public:
    Queen(bool isWhite, std::string filepath);
    bool moveTo(int fromX, int fromY, int toX, int toY, Board* board);
};

#endif
