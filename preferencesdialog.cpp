#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"

#include <QSettings>
#include <QColorDialog>

#include <functional>


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

PreferencesDialog::PreferencesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferencesDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Colour Preferences");

    colours = loadColours();
    recolourButtons();

    // set up the signal mapping, since we are connecting each button to the same slot
    // we'll cheat and use std::bind instead of setting up a signal mapper
    connect(ui->btnAttributes, &QPushButton::clicked, std::bind(&PreferencesDialog::openColourPickerDialog, this, Buttons::ATTRIBUTES));
    connect(ui->btnValues, &QPushButton::clicked, std::bind(&PreferencesDialog::openColourPickerDialog, this, Buttons::VALUES));
    connect(ui->btnBrackets, &QPushButton::clicked, std::bind(&PreferencesDialog::openColourPickerDialog, this, Buttons::BRACKETS));
    connect(ui->btnElements, &QPushButton::clicked, std::bind(&PreferencesDialog::openColourPickerDialog, this, Buttons::ELEMENTS));

}

PreferencesDialog::~PreferencesDialog()
{
    delete ui;
}

void PreferencesDialog::recolourButtons()
{
    ui->btnBrackets->setStyleSheet(QString{"background-color: %1"}.arg(colours.bracketsColour.name()));
    ui->btnBrackets->setText(colours.bracketsColour.name());
    ui->btnAttributes->setStyleSheet(QString{"background-color: %1"}.arg(colours.attributesColour.name()));
    ui->btnAttributes->setText(colours.attributesColour.name());
    ui->btnElements->setStyleSheet(QString{"background-color: %1"}.arg(colours.elementsColour.name()));
    ui->btnElements->setText(colours.elementsColour.name());
    ui->btnValues->setStyleSheet(QString{"background-color: %1"}.arg(colours.valuesColour.name()));
    ui->btnValues->setText(colours.valuesColour.name());
}

void PreferencesDialog::openColourPickerDialog(Buttons sender)
{
    QColor* initialColour;
    switch (sender) {
        case Buttons::ATTRIBUTES:
            initialColour = &colours.attributesColour;
        case Buttons::VALUES:
            initialColour = &colours.valuesColour;
        case Buttons::ELEMENTS:
            initialColour = &colours.elementsColour;
        case Buttons::BRACKETS:
            initialColour = &colours.bracketsColour;
    }

    auto colour = QColorDialog::getColor(*initialColour, this, "Pick a Colour");
    if (colour.isValid()) {
        *initialColour = colour;
    }
    recolourButtons();
}

void PreferencesDialog::accept()
{
    commitColours(colours);
    done(QDialog::Accepted);
}

void PreferencesDialog::reject()
{
    done(QDialog::Rejected);
}

