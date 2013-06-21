#ifndef XPATHVIEWER_H
#define XPATHVIEWER_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>

class XPathViewer : public QWidget
{
    Q_OBJECT
public:
    explicit XPathViewer(QWidget *parent = 0);
    virtual ~XPathViewer();
    
signals:
    
public slots:

private:
    QLineEdit* txtXpath;
    QTextEdit* txtXDoc;
    
};

#endif // XPATHVIEWER_H
