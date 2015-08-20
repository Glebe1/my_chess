#include <Square.h>
#include <Board.h>
#include <Bishop.h>
#include <Knight.h>

#include <iostream>

Board::Board(QGridLayout *gridLayout)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
             m_board[i][j] = new Square(i, j, this);
             gridLayout->addWidget(m_board[i][j]->getButton(), i, j);
        }
    m_iswhiteturn = true;
    initiazePieces();
}

Board::~Board()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
             delete m_board[i][j];
    for (pieces_array_t::iterator it = m_pieces.begin();
        it != m_pieces.end(); ++it)
    {
        std::cout << "    deleting " << (*it)->getPieceType() << std::endl;
        delete *it;
    }
}

void Board::addPiece(int x, int y, Piece* new_piece)
{
    if ((x < 0) || (x > 7) || (y < 0) || (y > 7))
    {
        delete new_piece;
        return;
    }

    Piece* old_piece = m_board[x][y]->setPiece(new_piece);

    if (old_piece)
    {
        pieces_array_t::iterator pos = std::find(m_pieces.begin(),
                                                 m_pieces.end(), old_piece);
        if (pos != m_pieces.end())
            m_pieces.erase(pos);
        delete old_piece;
    }

    m_pieces.push_back(new_piece);
}

void Board::initiazePieces()
{
    addPiece(1, 2, new Bishop(true));
    addPiece(7, 5, new Knight(false));
    addPiece(3, 1, new Bishop(false));
    addPiece(6, 5, new Knight(true));
    addPiece(7, 6, new Knight(false));
    addPiece(4, 7, new Bishop(true));
    addPiece(2, 2, new Knight(true));
    addPiece(4, 2, new Bishop(false));
}

bool Board::isWhiteTurn() const
{
    return m_iswhiteturn;
}

void Board::changeTurn()
{
    m_iswhiteturn = !m_iswhiteturn;
}

Square* Board::getSquare(int x,int y) const
{
    return m_board[x][y];
}
