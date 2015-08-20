#include <MainWindow.h>
#include <QFileDialog>
#include <Board.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QString filePath = QApplication::applicationDirPath();
    connect(ui.actionSaveGame, SIGNAL(triggered()), this, SLOT(onSaveGame()));

    m_gameboard = new Board(ui.gridLayout, filePath.toUtf8().constData());
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

