#include <Square.h>
#include <Piece.h>

Square* Square::m_square = NULL;

Square::Square(int x, int y, Square* (&board)[8][8]):
    m_x(x), m_y(y), m_board(board), m_piece(NULL)
{
    m_button = new QPushButton();
    m_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_button->setStyleSheet("background-color: rgba(0, 0, 0, 0)");
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
    
    if (Square::m_square &&
        Square::m_square->getPiece()->moveTo(Square::m_square->getX(),
                                             Square::m_square->getY(),
                                             getX(), getY(), m_board))
    {
        if (!m_piece || (m_piece &&
            (Square::m_square->getPiece()->isWhite() != m_piece->isWhite())))
        {
            setPiece(Square::m_square->getPiece());
            Square::m_square->setPiece(NULL);
        }

        Square::m_square = NULL;
    }
    else if (m_piece)
        Square::m_square = this;
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

