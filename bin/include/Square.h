#include <QPushButton>

class Square
{
public:
    Square();
    ~Square();

    QPushButton* getButton() const;

private:
    QPushButton *m_button;
};
