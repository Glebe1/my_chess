#include <Knight.h>
#include <iostream>
#include <Board.h>

Knight::Knight(bool isWhite, std::string filepath)
{
    m_color = isWhite;
    m_piece_type = KNIGHT;

    filepath.append("/res/Images/Knight");
    filepath.append((isWhite) ? "_white" : "_black");
    filepath.append(".png");

    QPixmap pixmap(filepath.c_str());
    m_asset = new QIcon(pixmap);
}

bool Knight::moveTo(int fromX,int fromY,int toX,int toY, Board* board)
{
    if ((fromX >= 0) && (toX >= 0) && (fromY >= 0) && (toY >= 0) &&
        (fromX < 8) && (toX < 8) && (fromY < 8) && (toY < 8))
        if (std::abs(fromX-toX) + std::abs(fromY-toY) == 3)
            return true;

    return false;
}

