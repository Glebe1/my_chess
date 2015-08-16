#include "ui_MainWindow.h"

class Board;

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initiazePieces();
    Board* m_gameboard;
    Ui::MainWindow ui;
};

