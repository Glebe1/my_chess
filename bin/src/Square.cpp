#include <Square.h>
#include <Piece.h>

Square::Square()
{
    m_button = new QPushButton();
    m_piece = NULL;
    m_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_button->setStyleSheet("background-color: rgba(0, 0, 0, 0)");
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
