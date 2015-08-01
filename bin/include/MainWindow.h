#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow ui;
};
