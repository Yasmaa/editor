#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "key.h"
#include <QString>
#include <QVector>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
   // QVector <QString> dict(6);


private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionExit_2_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionAbout_QtTxtEdit_triggered();

    void on_actionAbout_Qt_triggered();

    void on_actionLeft_Align_triggered();

    void on_actionRight_Align_triggered();

    void on_actionCenter_Align_triggered();

    void on_actionFont_Dialog_triggered();

    void on_actionColour_Dialog_triggered();

    void on_actionEncrypt_triggered();

    void on_actionDecrypt_triggered();

    void on_actionPdf_triggered();



private:
    Ui::MainWindow *ui;
    Key *uii;
    QString file_path;
};

#endif // MAINWINDOW_H
