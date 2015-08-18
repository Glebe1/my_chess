#ifndef H_PIECE
#define H_PIECE

#include <QIcon>

class Board;

class Piece
{
protected:
    QIcon *m_asset;
    bool m_color;
public:
    Piece(bool isWhite);
    ~Piece();
    bool isWhite();
    virtual bool moveTo(int fromX,int fromY,int toX,int toY, Board* board) = 0;
    const QIcon& getIcon() const;
    bool isSameColor(Piece* piece) const;
};

#endif
