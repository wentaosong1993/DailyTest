#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveAsFile();
    void printFile();
    void quitFile();


private:
    Ui::MainWindow *ui;
    QString fileName;
};

#endif // MAINWINDOW_H
