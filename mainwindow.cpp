#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "xpathviewer.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int initialTabCount = ui->tabOpenDocs->count();
    for (int i = 0; i < initialTabCount; ++i) {
        ui->tabOpenDocs->removeTab(0);
    }
    ui->tabOpenDocs->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    // open up a file and launch a tab for it
    QString fileName = QFileDialog::getOpenFileName(this, "Open XML File", "", "XML File (*.xml)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            // we'll put an error message here and then return
            return;
        } else {
            QTextStream in(&file);
            XPathViewer* viewer = new XPathViewer(in, 0);
            // get the file name
            QFileInfo fileInfo(file.fileName());
            QString simpleName(fileInfo.fileName());
            int index = ui->tabOpenDocs->addTab(viewer, simpleName);
            ui->tabOpenDocs->setCurrentIndex(index);
            ui->tabOpenDocs->setVisible(true);
            ui->lblPrompt->setVisible(false);
            file.close();
        }
    }
}

void MainWindow::on_actionExit_triggered()
{
    // prompt to quit
}

void MainWindow::on_actionPreferences_triggered()
{
    // show a preferences dialog
}
