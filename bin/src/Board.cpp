#include <Square.h>
#include <Board.h>

#include <Rook.h>
#include <Queen.h>
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


Board::Board(QGridLayout *gridLayout, const char* dirpath, const char* loadfile)
    :m_path(dirpath)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
             m_board[i][j] = new Square(i, j, this);
             gridLayout->addWidget(m_board[i][j]->getButton(), i, j);
        }
    m_iswhiteturn = true;
    loadPiecesFromFile(loadfile);
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

    if (!new_piece)
        return;

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
    addPiece(7, 2, new Bishop(true, m_path));
    addPiece(0, 2, new Bishop(false, m_path));
    addPiece(0, 5, new Bishop(false, m_path));
    addPiece(7, 5, new Bishop(true, m_path));
    addPiece(7, 1, new Knight(true, m_path));
    addPiece(0, 1, new Knight(false, m_path));
    addPiece(0, 6, new Knight(false, m_path));
    addPiece(7, 6, new Knight(true, m_path));
    addPiece(0, 0, new Rook(false, m_path));
    addPiece(0, 7, new Rook(false, m_path));
    addPiece(7, 0, new Rook(true, m_path));
    addPiece(7, 7, new Rook(true, m_path));
    addPiece(0, 3, new Queen(false, m_path));
    addPiece(7, 3, new Queen(true, m_path));
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

    outfile.put(isWhiteTurn());

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
             if (m_board[i][j]->getPiece())
             {
                 outfile.put(i);
                 outfile.put(j);
                 outfile.put(m_board[i][j]->getPiece()->getPieceType());
                 outfile.put(m_board[i][j]->getPiece()->isWhite());
             }
    outfile.flush();
}

void Board::loadPiecesFromFile(const char* loadfilepath)
{
    std::ifstream loadfile(loadfilepath);
    char x, y, color, type, c;

    loadfile.get(c);
    m_iswhiteturn = c;
    bool iseof = true;
    while (iseof)
        {
            loadfile.get(x);
            loadfile.get(y);
            loadfile.get(type);
            iseof = loadfile.get(color);
            if(iseof)
                addPiece(x, y,
                         allocatePiece(static_cast<PieceType>(type), color));
        }
    loadfile.close();
}

Piece* Board::allocatePiece(PieceType type, bool color)
{
    switch (type)
    {
        case BISHOP:
            return new Bishop(color, m_path);
        case KNIGHT:
            return new Knight(color, m_path);
        case ROOK:
            return new Rook(color, m_path);
        case QUEEN:
            return new Queen(color, m_path);
        default:
            return NULL;
    }
}
