#include "xpathviewer.h"

XPathViewer::XPathViewer(QTextStream & input, XmlSyntaxHighlighter* highlighter, QWidget* parent) :
    QWidget(parent),
    highlighter(highlighter)
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
    highlighter->setDocument(txtXDoc->document());
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

void XPathViewer::takeHighlighterFocus()
{
    highlighter->setDocument(txtXDoc->document());
}

void XPathViewer::takeNewHighlighter(XmlSyntaxHighlighter* newHighlighter)
{
    highlighter = newHighlighter;
    takeHighlighterFocus();
}
