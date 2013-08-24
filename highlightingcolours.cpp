#include "highlightingcolours.h"

HighlightingColours loadColours()
{
    HighlightingColours colours;

    QSettings settings;
    settings.beginGroup("colours");
    colours.bracketsColour = settings.value("brackets", QColor(Qt::darkMagenta)).value<QColor>();
    colours.elementsColour = settings.value("elements", QColor(Qt::green)).value<QColor>();
    colours.attributesColour = settings.value("attributes", QColor(Qt::blue)).value<QColor>();
    colours.valuesColour = settings.value("values", QColor(Qt::darkMagenta)).value<QColor>();
    settings.endGroup();

    return colours;
}

void commitColours(HighlightingColours const& colours)
{
    QSettings settings;
    settings.beginGroup("colours");
    settings.setValue("brackets", colours.bracketsColour);
    settings.setValue("elements", colours.elementsColour);
    settings.setValue("attributes", colours.attributesColour);
    settings.setValue("values", colours.valuesColour);
    settings.endGroup();
}
