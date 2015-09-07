#include <King.h>
#include <iostream>
#include <Square.h>
#include <Board.h>

King::King(bool isWhite, std::string filepath)
{
    m_color = isWhite;
    m_piece_type = KING;

    filepath.append("/res/Images/King");
    filepath.append((isWhite) ? "_white" : "_black");
    filepath.append(".png");

    QPixmap pixmap(filepath.c_str());
    m_asset = new QIcon(pixmap);
}

bool King::moveTo(int fromX,int fromY,int toX,int toY, Board* board)
{
    if ((fromX < 0) || (toX < 0) || (fromY < 0) || (toY < 0) ||
        (fromX >= 8) || (toX >= 8) || (fromY >= 8) || (toY >= 8))
        return false;

    if (std::abs(fromX - toX) <= 1 && std::abs(fromY - toY) <= 1)
        return true;

    if (fromX == toX && !getMoved())
    {
        if (fromY + 2 == toY)
        {
            if (board->getSquare(fromX, fromY + 1)->getPiece() ||
                board->getSquare(fromX, fromY + 2)->getPiece())
                return false;

            if (board->getSquare(fromX, fromY + 3)->getPiece() &&
                !board->getSquare(fromX, fromY + 3)->getPiece()->getMoved())
            {
                board->getSquare(fromX, fromY + 3)->getPiece()->setMoved();
                setMoved();

                board->getSquare(fromX, fromY + 2)->setPiece(this);
                board->getSquare(fromX, fromY + 1)->setPiece(
                                 board->getSquare(fromX, fromY + 3)->getPiece());
                board->getSquare(fromX, fromY)->setPiece(NULL);
                board->getSquare(fromX, fromY + 3)->setPiece(NULL);
                board->changeTurn();
            }
        }
        else if(fromY - 2 == toY)
        {
            if(board->getSquare(fromX, fromY - 1)->getPiece() ||
               board->getSquare(fromX, fromY - 2)->getPiece() ||
               board->getSquare(fromX, fromY - 3)->getPiece())
                return false;

            if(board->getSquare(fromX, fromY - 4)->getPiece() &&
               !board->getSquare(fromX, fromY - 4)->getPiece()->getMoved())
            {
                board->getSquare(fromX, fromY - 4)->getPiece()->setMoved();
                setMoved();

                board->getSquare(fromX, fromY - 2)->setPiece(this);
                board->getSquare(fromX, fromY - 1)->setPiece(
                                 board->getSquare(fromX, fromY - 4)->getPiece());
                board->getSquare(fromX, fromY)->setPiece(NULL);
                board->getSquare(fromX, fromY - 4)->setPiece(NULL);
                board->changeTurn();
            }
        }
    }

    return false;
}
