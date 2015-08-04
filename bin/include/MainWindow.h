#include "ui_MainWindow.h"
#include <iostream>

class Square;
class Piece;

typedef std::vector<Piece*> pieces_array_t;

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initiazeSquares();
    void initiazePieces();

    void addPiece(int x, int y);

    Ui::MainWindow ui;
    Square* m_board[8][8];
    pieces_array_t m_pieces;
};

