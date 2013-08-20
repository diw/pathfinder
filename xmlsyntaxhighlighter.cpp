#include "xmlsyntaxhighlighter.h"

XmlSyntaxHighlighter::XmlSyntaxHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent), commentStart(R"(<!--)"), commentEnd(R"(-->)") {
    HighlightingRule rule;
    QStringList keywordPatterns;
    keywordPatterns << R"(\b?xml\b)" << "/>" << ">" << "<";

    for(QString const& pattern : keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format.setFontWeight(QFont::Bold);
        rule.format.setForeground(Qt::darkMagenta);
        highlightingRules.append(rule);
    }
    commentFormat.setForeground(Qt::gray);

    attributeFormat.setFontItalic(true);
    attributeFormat.setForeground(Qt::blue);
    highlightingRules.append({QRegExp{R"(\b[A-Za-z0-9_]+(?=\=))"}, attributeFormat});

    valueFormat.setForeground(Qt::red);

    elementFormat.setFontWeight(QFont::Bold);
    elementFormat.setForeground(Qt::green);
    highlightingRules.append({QRegExp{R"(\b[A-Za-z0-9_]+(?=[\s+/>]))"}, elementFormat});

}

void XmlSyntaxHighlighter::highlightBlock(QString const& text) {
    for(HighlightingRule const& rule : highlightingRules) {
        QRegExp expression{rule.pattern};
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
}
