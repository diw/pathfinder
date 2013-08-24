#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"

#include <QColorDialog>

#include <functional>


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

    highlighter = XmlSyntaxHighlighter::getDefaultHighlighter(colours);
    highlighter->setDocument(ui->txtPreview->document());

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

