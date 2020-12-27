#include "key.h"
#include "ui_key.h"
#include <QString>
#include <QFile>
#include <QTextStream>



Key::Key(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Key)
{
    ui->setupUi(this);
    ui->label_2->setVisible(false);
}

Key::~Key()
{
    delete ui;
}

void Key :: verify(){

    ui->label_2->setVisible(false);
    QFile file("/home/asmae/w/password.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return ;

     QTextStream in(&file);
     QString line = in.readLine();

     QString passe=ui->lineEdit->text();
     if(passe!=line){
        ui->label_2->setVisible(true);


     }else {

         this->close();



     }
}
