#include <Queen.h>
#include <iostream>
#include <Square.h>
#include <Board.h>

Queen::Queen(bool isWhite, std::string filepath)
{
    m_color = isWhite;
    m_piece_type = QUEEN;

    filepath.append("/res/Images/Queen");
    filepath.append((isWhite) ? "_white" : "_black");
    filepath.append(".png");

    QPixmap pixmap(filepath.c_str());
    m_asset = new QIcon(pixmap);
}

bool Queen::moveTo(int fromX,int fromY,int toX,int toY, Board* board)
{
    if ((fromX < 0) || (toX < 0) || (fromY < 0) || (toY < 0) ||
        (fromX >= 8) || (toX >= 8) || (fromY >= 8) || (toY >= 8))
        return false;

    if ((fromX != toX && fromY != toY) && 
        std::abs(fromX-toX) != std::abs(fromY-toY))
        return false;

    int dX(0), dY(0);

    if(fromX == toX)
        if(fromY > toY)
            dY = -1;
        else
            dY = 1;
    else
        if (fromY == toY)
            if(fromX > toX)
                dX = -1;
            else
                dX = 1;
        else
        {
            dX = 1;
            dY = 1;

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
        }

    while(std::abs(fromX-toX) > 1 || std::abs(fromY-toY) > 1 )
    {
        fromX = fromX + dX;
        fromY = fromY + dY;
        if(board->getSquare(fromX, fromY)->getPiece())
            return false;
    }

    return true;
}
