#include <Piece.h>

class Square;

class Bishop: public Piece
{
public:
    Bishop(bool isWhite);
    bool moveTo(int fromX, int fromY, int toX, int toY, Square* (&board)[8][8]);
};
