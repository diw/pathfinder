#include "xpathviewer.h"

XPathViewer::XPathViewer(QWidget *parent) :
    QWidget(parent)
{
}

XPathViewer::~XPathViewer() {
    delete txtXDoc;
    delete txtXpath;
}
