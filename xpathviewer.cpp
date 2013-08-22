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

    txtXDoc->setReadOnly(true);
    query.setFocus(txtXDoc->toPlainText());
    highlighter = new XmlSyntaxHighlighter(txtXDoc->document());
    connect(txtXPath, SIGNAL(textEdited(QString)), this, SLOT(highlightQueryResults(QString)));
}

XPathViewer::~XPathViewer() {
    delete txtXDoc;
    delete txtXPath;
    delete mainLayout;
}

void XPathViewer::highlightQueryResults(QString const& text) {
    query.setQuery(txtXPath->text());
}

void XPathViewer::updateSyntaxHighlighterColours()
{

}
