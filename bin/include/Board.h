#include <QGridLayout>
#include <vector>

class Square;
class Piece;

typedef std::vector<Piece*> pieces_array_t;

class Board
{
    void initiazePieces();
    void addPiece(int x, int y, Piece* new_piece);

    bool m_iswhiteturn;
    pieces_array_t m_pieces;
    Square* m_board[8][8];
    const char* m_path;

public:
    Board(QGridLayout *gridLayout, const char* filepath);
    ~Board();

    bool isWhiteTurn() const;
    void changeTurn();
    void initiazeSquares();
    Square* getSquare(int x,int y) const;

    void saveGameBoard(const char* filepath) const;
};
