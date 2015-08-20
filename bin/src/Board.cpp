#include <Square.h>
#include <Board.h>

#include <Bishop.h>
#include <Knight.h>

#include <fstream>

Board::Board(QGridLayout *gridLayout, const char* filepath)
    :m_path(filepath)
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
        delete *it;
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
    addPiece(1, 2, new Bishop(true, m_path));
    addPiece(3, 1, new Bishop(false, m_path));
    addPiece(4, 2, new Bishop(false, m_path));
    addPiece(4, 7, new Bishop(true, m_path));
    addPiece(6, 5, new Knight(true));
    addPiece(7, 6, new Knight(false));
    addPiece(7, 5, new Knight(false));
    addPiece(2, 2, new Knight(true));
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

void Board::saveGameBoard(const char* filepath) const
{
    std::ofstream outfile (filepath);

    outfile.put(isWhiteTurn() + '0');
    outfile.put('\n');

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
             if (m_board[i][j]->getPiece())
             {
                 outfile.put(i + '0');
                 outfile.put(j + '0');
                 outfile.put(m_board[i][j]->getPiece()->getPieceType()+'0');
                 outfile.put(m_board[i][j]->getPiece()->isWhite()+'0');
                 outfile.put('\n');
             }
    outfile.flush();
}
