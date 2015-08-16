#include <MainWindow.h>
#include <Board.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QString filePath = QApplication::applicationDirPath();
    filePath.append("/res/Images/pic1.png");

    ui.label->setScaledContents(1);
    ui.label->setPixmap(QPixmap(filePath));
    
    m_gameboard = new Board(ui.gridLayout);
    
    initiazePieces();
}

MainWindow::~MainWindow()
{
    delete m_gameboard;
}

void MainWindow::initiazePieces()
{
    Piece* new_piece = NULL;

    //1. create piece with correct params.
    std::cout << "add piece on (1, 2, false)" << std::endl;
    m_gameboard->addPiece(1, 2, false);
    std::cout << "add piece on (7, 5, true)" << std::endl;
    m_gameboard->addPiece(7, 5, true);
    std::cout << "add piece on (3, 1, false)" << std::endl;
    m_gameboard->addPiece(3, 1, false);
    //2. create piece with wrong params.
    std::cout << "add piece on (6, 5, true)" << std::endl;
    m_gameboard->addPiece(6, 5, true);
    std::cout << "add piece on (7, 9, false)" << std::endl;
    m_gameboard->addPiece(7, 9, false);
    //3. create piese on busy cell.
    std::cout << "add piece on (4, 7, true)" << std::endl;
    m_gameboard->addPiece(4, 7, true);
    std::cout << "add piece on (4, 7, false)" << std::endl;
    m_gameboard->addPiece(4, 7, false);
}

