#include <Square.h>

Square::Square()
{
    m_button = new QPushButton();
    m_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_button->setStyleSheet("background-color: rgba(0, 0, 0, 0)");
}

Square::~Square()
{
    delete m_button;
}

QPushButton* Square::getButton() const
{
    return m_button;
}
