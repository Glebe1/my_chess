#ifndef H_PIECE
#define H_PIECE

#include <QIcon>

typedef enum
{
    KING = 0,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT,
    PAWN
} PieceType;

class Board;

class Piece
{
protected:
    QIcon *m_asset;
    bool m_color;
    PieceType m_piece_type;
    bool m_is_moved;

public:
    Piece();
    ~Piece();
    bool getMoved() const;
    bool setMoved();
    virtual bool moveTo(int fromX,int fromY,int toX,int toY, Board* board) = 0;

    const QIcon& getIcon() const;
    bool isWhite() const;
    bool isSameColor(Piece* piece) const;
    PieceType getPieceType() const;
};

#endif
