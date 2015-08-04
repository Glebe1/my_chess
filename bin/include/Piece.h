#include <QIcon>

class Square;

class Piece
{
    QIcon *m_asset;

public:
    Piece();
    ~Piece();

    const QIcon& getIcon() const;
};
