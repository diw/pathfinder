#ifndef XMLSYNTAXHIGHLIGHTER_H
#define XMLSYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class XmlSyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    XmlSyntaxHighlighter(QTextDocument* parent = 0);

protected:
    void highlightBlock(QString const& text);

private:
    struct HighlightingRule {
        QRegExp pattern;
        QTextCharFormat format;
    };

    QVector<HighlightingRule> highlightingRules;

};

#endif // XMLSYNTAXHIGHLIGHTER_H
