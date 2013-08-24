#ifndef HIGHLIGHTINGCOLOURS_H
#define HIGHLIGHTINGCOLOURS_H

#include <QSettings>
#include <QColor>

struct HighlightingColours {
    QColor bracketsColour;
    QColor elementsColour;
    QColor attributesColour;
    QColor valuesColour;
};


HighlightingColours loadColours();

void commitColours(HighlightingColours const& colours);

#endif // HIGHLIGHTINGCOLOURS_H
