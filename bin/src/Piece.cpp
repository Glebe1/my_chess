#include <Piece.h>
#include <Square.h>

Piece::Piece()
{
    QPixmap pixmap(55, 55);
    pixmap.fill(QColor(rand() % 256, rand() % 256, rand() % 256));
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
