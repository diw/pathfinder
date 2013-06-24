#ifndef XPATHVIEWER_H
#define XPATHVIEWER_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QtXmlPatterns/QXmlQuery>
#include <QTextStream>
#include <QVBoxLayout>

class XPathViewer : public QWidget
{
    Q_OBJECT
public:
    explicit XPathViewer(QTextStream & input, QWidget *parent = 0);
    virtual ~XPathViewer();
    
signals:
    
public slots:
    void highlightQueryResults(QString const& text);
private:
    QLineEdit* txtXPath;
    QTextEdit* txtXDoc;
    QVBoxLayout* mainLayout;

    QXmlQuery query;

};

#endif // XPATHVIEWER_H
