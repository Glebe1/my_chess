#include <QIcon>

class Square;

class Piece
{
    QIcon *m_asset;
    bool m_color;
public:
    Piece(bool isWhite);
    ~Piece();
    bool isWhite();

    const QIcon& getIcon() const;
};
