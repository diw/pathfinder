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
    
private slots:
    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_actionPreferences_triggered();

    void on_tabOpenDocs_tabCloseRequested(int index);

private:
    Ui::MainWindow *ui;

    int tabCount;

    void writeSettings();
    void readSettings();
};

#endif // MAINWINDOW_H
