#include "ui_MainWindow.h"

class Board;

class MainWindow : public QMainWindow
{

Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onSaveGame();
    void onLoadGame();

private:
    Board* m_gameboard;
    Ui::MainWindow ui;
};

