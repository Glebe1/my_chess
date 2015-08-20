#include <Piece.h>
#include <Square.h>

Piece::Piece()
{
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
