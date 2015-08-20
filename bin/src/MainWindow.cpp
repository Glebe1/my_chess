#include <MainWindow.h>
#include <Board.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QString filePath = QApplication::applicationDirPath();
    filePath.append("/res/Images/pic1.png");

    ui.label->setScaledContents(1);
    ui.label->setPixmap(QPixmap(filePath));

    m_gameboard = new Board(ui.gridLayout);
}

MainWindow::~MainWindow()
{
    delete m_gameboard;
}

