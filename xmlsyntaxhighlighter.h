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

    int const IN_COMMENT = 1;

    QList<HighlightingRule> highlightingRules;

    QTextCharFormat commentFormat;
    QTextCharFormat attributeFormat;
    QTextCharFormat valueFormat;
    QTextCharFormat elementFormat;

    QRegExp commentStart;
    QRegExp commentEnd;
};

#endif // XMLSYNTAXHIGHLIGHTER_H
