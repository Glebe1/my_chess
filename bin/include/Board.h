#include <QGridLayout>
#include <vector>
#include <Piece.h>

class Square;

typedef std::vector<Piece*> pieces_array_t;

class Board
{
    //TODO: is used for development needs only,to be deleted
    void initiazePieces();
    void addPiece(int x, int y, Piece* new_piece);
    void loadPiecesFromFile(const char* loadfilepath);
    Piece* allocatePiece(PieceType type, bool color);

    bool m_iswhiteturn;
    pieces_array_t m_pieces;
    Square* m_board[8][8];
    const char* m_path;

public:
    //TODO: is used for development needs only, to be deleted
    Board(QGridLayout *gridLayout, const char* filepath);
    Board(QGridLayout *gridLayout, const char* dirpath, const char* loadfile);
    ~Board();

    bool isWhiteTurn() const;
    void changeTurn();
    void initiazeSquares();
    Square* getSquare(int x,int y) const;

    void saveGameBoard(const char* filepath) const;
};
