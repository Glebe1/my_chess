#include <Bishop.h>
#include <iostream>
#include <Square.h>
#include <Board.h>

Bishop::Bishop(bool isWhite):
    Piece(isWhite)
{
    m_piece_type = BISHOP;
}

bool Bishop::moveTo(int fromX,int fromY,int toX,int toY, Board* board)
{
    if ((fromX < 0) || (toX < 0) || (fromY < 0) || (toY < 0) ||
        (fromX >= 8) || (toX >= 8) || (fromY >= 8) || (toY >= 8))
        return false;

    if (std::abs(fromX-toX) != std::abs(fromY-toY))
        return false;

    int dX(1), dY(1);

    if(fromX > toX)
        if(fromY > toY)
        {
            dX = -1;
            dY = -1;
        }
        else
            dX = -1;
    else
        if(fromY > toY)
            dY = -1;
            
    while(std::abs(fromX-toX) > 1)
    {
        fromX = fromX + dX;
        fromY = fromY + dY;
        if(board->getSquare(fromX, fromY)->getPiece())
            return false;
    }

    return true;
}
