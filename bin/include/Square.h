#include <QPushButton>

class Piece;

class Square
{
public:
    Square();
    ~Square();

    QPushButton* getButton() const;
    Piece * setPiece(Piece * piece);

private:
    QPushButton *m_button;
    Piece * m_piece;
};
