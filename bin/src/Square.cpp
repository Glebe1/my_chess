#include <Square.h>
#include <Piece.h>

Square* Square::m_square = NULL;

Square::Square()
{
    m_button = new QPushButton();
    m_piece = NULL;
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
    
    if (Square::m_square)
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
