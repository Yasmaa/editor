#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <qtextedit.h>
#include <QFontDialog>
#include <QFont>
#include <QFontDatabase>
#include <QTextCursor>
#include <QColor>
#include <QColorDialog>
#include <QSyntaxHighlighter>
#include <QtGui>
#include <QPrinter>
#include <QPainter>
#include <QDebug>
#include <string>
#include <simplecrypt.h>
#include <key.h>





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit); // Removes the sidegaps from the text editor


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    file_path=""; // Clear the path
    ui->textEdit->setText(""); // Make the editor blank
}

void MainWindow::on_actionOpen_triggered()
{
 QString file_name = QFileDialog::getOpenFileName(this,"Open a file");
 QFile file (file_name);
 file_path=file_name;

  if(!file.open(QFile::ReadOnly | QFile::Text)){
    QMessageBox::critical(this,"Error Opening File","File Cannot be Opened!");
    return;
  }
  else{
    //Read the file
    QTextStream in(&file);
    QString fileText = in.readAll();
    ui->textEdit->setText(fileText);
    file.close();
  }
}

void MainWindow::on_actionSave_triggered()
{
     QFile file(file_path);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
      //Simply return if the user cancels or does something unexpected!
      return;
    }
    else{
      //Read the file
      QTextStream writeData(&file);
      QString fileText = ui->textEdit->toPlainText();
      writeData << fileText;
      file.flush();
      file.close();
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Open a file");
    QFile file (file_name);
    file_path = file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
       //Simply return if the user cancels or does something unexpected!
        return;
     }
     else{
       //Read the file
       QTextStream writeData(&file);
       QString fileText = ui->textEdit->toPlainText();
       writeData << fileText;
       file.flush();
       file.close();
     }
}

void MainWindow::on_actionExit_2_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();

}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionAbout_QtTxtEdit_triggered()
{
    QMessageBox::about(this,"About QtTextEdit"," Copyright Gajesh Bhat 2017");
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this,"About Qt Creator.");
}

void MainWindow::on_actionLeft_Align_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
}

void MainWindow::on_actionRight_Align_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignRight);
}

void MainWindow::on_actionCenter_Align_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_actionFont_Dialog_triggered()
{
    bool ok;
    QFont fontStyle = QFontDialog::getFont(&ok,this);

    if(ok){
            QTextCharFormat format;
            format.setFont(fontStyle);
            QTextCursor txtCursor(ui->textEdit->textCursor());
            txtCursor.setCharFormat(format);
            txtCursor.clearSelection();
            ui->textEdit->setTextCursor(txtCursor);
    }
    else{
            return;
    }

}

void MainWindow::on_actionColour_Dialog_triggered()
{

    QColor txtColour = QColorDialog::getColor();
    ui->textEdit->setTextColor(txtColour);

}
void MainWindow:: on_actionEncrypt_triggered()
{
    SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023)); //some random number
    crypto.setCompressionMode(SimpleCrypt::CompressionAlways);


    QString fileText = ui->textEdit->toPlainText();

     //Encryption
   QString encrypted = crypto.encryptToString(fileText);
   ui->textEdit->setText(encrypted);
}

void MainWindow::on_actionDecrypt_triggered(){

    uii =  new Key(this);

    uii->show();



        SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023)); //some random number






       QString fileText = ui->textEdit->toPlainText();
       QString decrypted = crypto.decryptToString(fileText);

       ui->textEdit->setText(decrypted);






}

void MainWindow:: on_actionPdf_triggered()
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);


    int l=file_path.length();
    QString file = file_path.left(l-3);


    file+="pdf";
    printer.setOutputFileName(file);
    QPainter painter;
    if(!painter.begin(&printer)){

        qWarning("failed to open file");

    }

    QString fileText = ui->textEdit->toPlainText();
    painter.drawText(10,10,fileText);
    if(!printer.newPage()){
         qDebug() << "failed";

    }



}
