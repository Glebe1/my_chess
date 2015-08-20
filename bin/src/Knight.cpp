#include <Knight.h>
#include <iostream>
#include <Board.h>

Knight::Knight(bool isWhite)
{
    m_color = isWhite;
    QPixmap pixmap(55, 55);
    if(isWhite)
        pixmap.fill(QColor(255, 11, 11));
    else
        pixmap.fill(QColor(11, 255, 11));
    m_asset = new QIcon(pixmap);
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

