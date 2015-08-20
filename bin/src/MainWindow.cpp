#include <MainWindow.h>
#include <QFileDialog>
#include <Board.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QString filePath = QApplication::applicationDirPath();
    filePath.append("/res/Images/pic1.png");
    connect(ui.actionSaveGame, SIGNAL(triggered()), this, SLOT(onSaveGame()));

    ui.label->setScaledContents(1);
    ui.label->setPixmap(QPixmap(filePath));

    m_gameboard = new Board(ui.gridLayout);
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

