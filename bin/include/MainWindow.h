#include "ui_MainWindow.h"

class Square;

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initiazeSquares();

    Ui::MainWindow ui;
    Square* m_board[8][8];
};

