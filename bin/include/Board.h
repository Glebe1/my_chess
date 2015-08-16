#include <QGridLayout>
#include <vector>

class Square;
class Piece;

typedef std::vector<Piece*> pieces_array_t;

class Board
{
    pieces_array_t m_pieces;
    Square* m_board[8][8];
public:
    Board(QGridLayout *gridLayout);
    ~Board();
    void initiazeSquares();
    void addPiece(int x, int y, bool isWhite);
};
