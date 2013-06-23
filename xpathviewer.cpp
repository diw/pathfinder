#include "xpathviewer.h"

XPathViewer::XPathViewer(QTextStream & input, QWidget* parent) :
    QWidget(parent)
{
    mainLayout = new QVBoxLayout();
    txtXDoc = new QTextEdit();
    txtXPath = new QLineEdit();
    mainLayout->addWidget(txtXPath);
    mainLayout->addWidget(txtXDoc);
    setLayout(mainLayout);
    txtXDoc->setText(input.readAll());
}

XPathViewer::~XPathViewer() {
    delete txtXDoc;
    delete txtXPath;
    delete mainLayout;
}
