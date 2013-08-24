#ifndef XMLSYNTAXHIGHLIGHTER_H
#define XMLSYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <memory>

#include "highlightingcolours.h"

class XmlSyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    XmlSyntaxHighlighter(HighlightingColours colours, QTextDocument* parent = 0);
    static std::unique_ptr<XmlSyntaxHighlighter> getDefaultHighlighter(HighlightingColours const& colours);

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

    HighlightingColours colours;
};

#endif // XMLSYNTAXHIGHLIGHTER_H
