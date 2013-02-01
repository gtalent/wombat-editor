#ifndef SAVEVARIABLES_H
#define SAVEVARIABLES_H

#include <QWidget>

namespace Ui {
class SaveVariables;
}

class SaveVariables : public QWidget
{
    Q_OBJECT
    
public:
    explicit SaveVariables(QWidget *parent = 0);
    ~SaveVariables();
    
private:
    Ui::SaveVariables *ui;
};

#endif // SAVEVARIABLES_H
