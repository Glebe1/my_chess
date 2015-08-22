#include <Square.h>
#include <Piece.h>
#include <Board.h>

Square* Square::m_square = NULL;

Square::Square(int x, int y, Board* board):
    m_x(x), m_y(y), m_board(board), m_piece(NULL)
{
    m_button = new QPushButton();
    m_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_button->setStyleSheet("background-color: rgba(0, 0, 0, 0)");
    m_button->setIconSize(QSize(48, 48));
    connect(m_button, SIGNAL (released()), this, SLOT (actionOnClick()));
}

Square::~Square()
{
    delete m_button;
}

QPushButton* Square::getButton() const
{
    return m_button;
}

Piece* Square::setPiece(Piece *piece)
{
    Piece *ret = m_piece;

    if (piece)
        m_button->setIcon(piece->getIcon());
    else
        m_button->setIcon(QIcon());

    m_piece = piece;
    return ret;
}

void Square::actionOnClick()
{
    if (Square::m_square == this)
        return;
    
    if (Square::m_square)
    {
        if (Square::m_square->getPiece()->moveTo(Square::m_square->getX(),
                                                 Square::m_square->getY(),
                                                 getX(),
                                                 getY(),
                                                 m_board) &&
            !Square::m_square->getPiece()->isSameColor(m_piece))
        {
            setPiece(Square::m_square->getPiece());
            Square::m_square->setPiece(NULL);
            m_board->changeTurn();
        }

        Square::m_square->setSelected(false);
        Square::m_square = NULL;
    }
    else if (m_piece && m_piece->isWhite() == m_board->isWhiteTurn())
    {
        Square::m_square = this;
        Square::m_square->setSelected(true);
    }
}

Piece* Square::getPiece()
{
    return m_piece;
}

const int Square::getX() const
{
    return m_x;
}

const int Square::getY() const
{
    return m_y;
}

void Square::setSelected(bool isSelected)
{
    if (isSelected)
        m_button->setStyleSheet("background-color: rgba(0, 250, 0, 60)");
    else
        m_button->setStyleSheet("background-color: rgba(0, 0, 0, 0)");
}

