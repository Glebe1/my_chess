#include <QPushButton>

class Piece;

class Square: public QObject
{
   Q_OBJECT
public:
    Square();
    ~Square();

    QPushButton* getButton() const;
    Piece * setPiece(Piece * piece);
    Piece * getPiece();

public slots:
    void actionOnClick();

private:
    QPushButton *m_button;
    Piece * m_piece;
    static Square* m_square; //contains selected square on board
};
