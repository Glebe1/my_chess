#include <Knight.h>
#include <iostream>

Knight::Knight(bool isWhite):
    Piece(isWhite)
{
}

bool Knight::moveTo(int fromX,int fromY,int toX,int toY, Square* (&board)[8][8])
{
    if ((fromX >= 0) && (toX >= 0) && (fromY >= 0) && (toY >= 0) &&
        (fromX < 8) && (toX < 8) && (fromY < 8) && (toY < 8))
        if (std::abs(fromX-toX) + std::abs(fromY-toY) == 3)
            return true;

    return false;
}

