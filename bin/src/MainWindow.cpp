#include <MainWindow.h>
#include <Square.h>
#include <Piece.h>

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
    for (pieces_array_t::iterator it = m_pieces.begin();
         it != m_pieces.end(); ++it)
        delete *it;
}

void MainWindow::initiazeSquares()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
             m_board[i][j] = new Square();
             ui.gridLayout->addWidget(m_board[i][j]->getButton(), i, j);
        }
    initiazePieces();
}

void MainWindow::addPiece(int x, int y)
{
    Piece* new_piece = NULL;
    Piece* old_piece = NULL;

    if ((x < 0) || (x > 7) || (y < 0) || (y > 7))
        return;

    new_piece = new Piece();
    old_piece = m_board[x][y]->setPiece(new_piece);
    if (old_piece)
    {
        pieces_array_t::iterator pos = std::find(m_pieces.begin(),
                                                 m_pieces.end(), old_piece);
        if (pos != m_pieces.end())
            m_pieces.erase(pos);
        delete old_piece;
        std::cout << "   old piece deleted" << std::endl;
    }

    m_pieces.push_back(new_piece);
    std::cout << "   new piece created" << std::endl;
}

void MainWindow::initiazePieces()
{
    Piece* new_piece = NULL;

    //1. create piece with correct params.
    std::cout << "add piece on (1, 2)" << std::endl;
    addPiece(1, 2);
    std::cout << "add piece on (7, 5)" << std::endl;
    addPiece(7, 5);
    std::cout << "add piece on (3, 1)" << std::endl;
    addPiece(3, 1);
    //2. create piece with wrong params.
    std::cout << "add piece on (9, 5)" << std::endl;
    addPiece(9, 5);
    std::cout << "add piece on (7, 9)" << std::endl;
    addPiece(7, 9);
    //3. create piese on busy cell.
    std::cout << "add piece on (4, 7)" << std::endl;
    addPiece(4, 7);
    std::cout << "add piece on (4, 7)" << std::endl;
    addPiece(4, 7);
}
