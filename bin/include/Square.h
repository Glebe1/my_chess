#include <QPushButton>

class Board;
class Piece;

class Square: public QObject
{
   Q_OBJECT
public:
    Square(int x, int y, Board* board);
    ~Square();

    QPushButton* getButton() const;
    Piece * setPiece(Piece * piece);
    Piece * getPiece();
    const int getX() const;
    const int getY() const;
    void setSelected(bool isSelected);
public slots:
    void actionOnClick();

private:
    int m_x, m_y;
    QPushButton *m_button;
    Piece * m_piece;
    Board* m_board;
    static Square* m_square; //contains selected square on board
};
