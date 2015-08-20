#include <Knight.h>
#include <iostream>
#include <Board.h>

Knight::Knight(bool isWhite):
    Piece(isWhite)
{
    m_piece_type = KNIGHT;
}

bool Knight::moveTo(int fromX,int fromY,int toX,int toY, Board* board)
{
    if ((fromX >= 0) && (toX >= 0) && (fromY >= 0) && (toY >= 0) &&
        (fromX < 8) && (toX < 8) && (fromY < 8) && (toY < 8))
        if (std::abs(fromX-toX) + std::abs(fromY-toY) == 3)
            return true;

    return false;
}

