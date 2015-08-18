#include <QGridLayout>
#include <vector>

class Square;
class Piece;

typedef std::vector<Piece*> pieces_array_t;

class Board
{
    bool m_iswhiteturn;
    pieces_array_t m_pieces;
    Square* m_board[8][8];
public:
    Board(QGridLayout *gridLayout);
    ~Board();
    bool isWhiteTurn() const;
    void changeTurn();
    Square* getSquare(int x,int y) const;
    void initiazeSquares();
    void addPiece(int x, int y, bool isWhite);
};
