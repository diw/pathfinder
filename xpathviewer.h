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

private:
    QLineEdit* txtXPath;
    QTextEdit* txtXDoc;
    QVBoxLayout* mainLayout;

    QXmlQuery xmlDoc;

};

#endif // XPATHVIEWER_H
