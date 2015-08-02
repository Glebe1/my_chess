#include <MainWindow.h>
#include <Square.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QString filePath = QApplication::applicationDirPath();
    filePath.append("/res/Images/pic1.png");

    ui.label->setScaledContents(1);
    ui.label->setPixmap(QPixmap(filePath));

    initiazeSquares();
}

MainWindow::~MainWindow()
{
 for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
             delete m_board[i][j];
}

void MainWindow::initiazeSquares()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
             m_board[i][j] = new Square();
             ui.gridLayout->addWidget(m_board[i][j]->getButton(), i, j);
        }
}

