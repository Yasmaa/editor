#ifndef KEY_H
#define KEY_H

#include <QDialog>
#include <QString>

namespace Ui {
class Key;
}

class Key : public QDialog
{
    Q_OBJECT

public:
    explicit Key(QWidget *parent = 0);
    ~Key();

public:
    Ui::Key *ui;


public slots :
    void verify();

public:
    QString  a="0";
};




#endif // KEY_H
