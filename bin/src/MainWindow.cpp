#include <MainWindow.h>
#include <QFileDialog>
#include <Board.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.actionSaveGame, SIGNAL(triggered()), this, SLOT(onSaveGame()));
    connect(ui.actionLoadGame, SIGNAL(triggered()), this, SLOT(onLoadGame()));

    QString filePath = QApplication::applicationDirPath();
    QString defaultBoardPath = QApplication::applicationDirPath();
    defaultBoardPath.append("/res/Boards/Default_Board.cbb");
    m_gameboard = new Board(ui.gridLayout,
                            filePath.toUtf8().constData(),
                            defaultBoardPath.toUtf8().constData());

    ui.label->setScaledContents(1);
    filePath.append("/res/Images/pic1.png");
    ui.label->setPixmap(QPixmap(filePath));

}

MainWindow::~MainWindow()
{
    delete m_gameboard;
}

void MainWindow::onSaveGame()
{
    QString fn = QFileDialog::getSaveFileName(this, tr("Save as..."),
                                              QString(),
                                              tr("CB files (*.cbb)"));
    m_gameboard->saveGameBoard(fn.toUtf8().constData());
}

void MainWindow::onLoadGame()
{
    QString fn = QFileDialog::getOpenFileName(this, tr("load file"),
                                                        QString(),
                                                        tr("CB files (*.cbb)"));
    if (fn.isEmpty())
        return;

    delete m_gameboard;
    QString filePath = QApplication::applicationDirPath();

    m_gameboard = new Board(ui.gridLayout, filePath.toUtf8().constData(),
                            fn.toUtf8().constData());
}


