#ifndef XPATHVIEWER_H
#define XPATHVIEWER_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QtXmlPatterns/QXmlQuery>
#include <QTextStream>
#include <QVBoxLayout>

#include "xmlsyntaxhighlighter.h"

class XPathViewer : public QWidget
{
    Q_OBJECT
public:
    explicit XPathViewer(QTextStream & input, QWidget *parent = 0);
    virtual ~XPathViewer();
    
signals:
    
public slots:
    void highlightQueryResults(QString const& text);
    void updateSyntaxHighlighterColours();
private:
    QLineEdit* txtXPath;
    QTextEdit* txtXDoc;
    QVBoxLayout* mainLayout;
    XmlSyntaxHighlighter* highlighter;

    QXmlQuery query;

};

#endif // XPATHVIEWER_H
