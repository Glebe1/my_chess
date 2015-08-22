#include <Pawn.h>
#include <iostream>
#include <Square.h>
#include <Board.h>

Pawn::Pawn(bool isWhite, std::string filepath)
{
    m_color = isWhite;
    m_piece_type = PAWN;

    filepath.append("/res/Images/Pawn");
    filepath.append((isWhite) ? "_white" : "_black");
    filepath.append(".png");

    QPixmap pixmap(filepath.c_str());
    m_asset = new QIcon(pixmap);
}

bool Pawn::moveTo(int fromX,int fromY,int toX,int toY, Board* board)
{
    if ((fromX < 0) || (toX < 0) || (fromY < 0) || (toY < 0) ||
        (fromX >= 8) || (toX >= 8) || (fromY >= 8) || (toY >= 8))
        return false;

    int dx(-1), first_row(1);
    if (isWhite())
    {
        dx = 1;
        first_row = 6;
    }

    if (fromY == toY)
    {
        if ((fromX-toX == dx) && !board->getSquare(toX, toY)->getPiece())
            return true; // move one square forvard
        else
            if ((fromX == first_row) && (toX == first_row - 2 * dx) &&
                !board->getSquare(first_row - dx, toY)->getPiece() &&
                !board->getSquare(first_row - 2 * dx, toY)->getPiece())
                return true; // move two squares forvard
    }
    else
        if ((std::abs(fromY-toY) == 1) && (fromX-toX == dx) &&
            board->getSquare(toX, toY)->getPiece())
            return true; // attack move

    return false;
}
