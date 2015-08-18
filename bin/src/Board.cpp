#include <Square.h>
#include <Board.h>
#include <Bishop.h>

Board::Board(QGridLayout *gridLayout)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
             m_board[i][j] = new Square(i, j, this);
             gridLayout->addWidget(m_board[i][j]->getButton(), i, j);
        }
    m_iswhiteturn = true;
}

Board::~Board()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
             delete m_board[i][j];
    for (pieces_array_t::iterator it = m_pieces.begin();
        it != m_pieces.end(); ++it)
        delete *it;
}

void Board::addPiece(int x, int y, bool isWhite)
{
    Piece* new_piece = NULL;
    Piece* old_piece = NULL;

    if ((x < 0) || (x > 7) || (y < 0) || (y > 7))
        return;

    new_piece = new Bishop(isWhite);
    old_piece = m_board[x][y]->setPiece(new_piece);
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
