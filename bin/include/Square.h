#include <QPushButton>

class Piece;

class Square: public QObject
{
   Q_OBJECT
public:
    Square(int x, int y, Square* (&board)[8][8]);
    ~Square();

    QPushButton* getButton() const;
    Piece * setPiece(Piece * piece);
    Piece * getPiece();
    const int getX() const;
    const int getY() const;
public slots:
    void actionOnClick();

private:
    int m_x, m_y;
    QPushButton *m_button;
    Piece * m_piece;
    Square* (&m_board)[8][8];
    static Square* m_square; //contains selected square on board
};
