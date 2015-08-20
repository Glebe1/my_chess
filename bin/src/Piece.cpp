#include <Piece.h>
#include <Square.h>

Piece::Piece(bool isWhite)
{
    m_color = isWhite;
    QPixmap pixmap(55, 55);
    if(isWhite)
        pixmap.fill(QColor(255, 11, 11));
    else
        pixmap.fill(QColor(11, 255, 11));
    m_asset = new QIcon(pixmap);
}

Piece::~Piece()
{
    delete m_asset;
}

const QIcon& Piece::getIcon() const
{
    return *m_asset;
}

bool Piece::isWhite() const
{
    return m_color;
}

bool Piece::isSameColor(Piece* piece) const
{
    if (!piece)
        return false;
    return (piece->isWhite() == m_color);
}

PieceType Piece::getPieceType() const
{
    return m_piece_type;
}
