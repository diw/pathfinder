#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"

#include <QSettings>
#include <QColorDialog>

#include <functional>

PreferencesDialog::PreferencesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferencesDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Colour Preferences");

    loadColours();
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

void PreferencesDialog::commitColours()
{
    QSettings settings;
    settings.beginGroup("colours");
    settings.setValue("brackets", bracketsColour);
    settings.setValue("elements", elementsColour);
    settings.setValue("attributes", attributesColour);
    settings.setValue("values", valuesColour);
    settings.endGroup();
}

void PreferencesDialog::loadColours()
{
    QSettings settings;
    settings.beginGroup("colours");
    bracketsColour = settings.value("brackets", QColor(Qt::darkMagenta)).value<QColor>();
    elementsColour = settings.value("elements", QColor(Qt::green)).value<QColor>();
    attributesColour = settings.value("attributes", QColor(Qt::blue)).value<QColor>();
    valuesColour = settings.value("values", QColor(Qt::darkMagenta)).value<QColor>();
    settings.endGroup();
}

void PreferencesDialog::recolourButtons()
{
    ui->btnBrackets->setStyleSheet(QString{"background-color: %1"}.arg(bracketsColour.name()));
    ui->btnAttributes->setStyleSheet(QString{"background-color: %1"}.arg(attributesColour.name()));
    ui->btnElements->setStyleSheet(QString{"background-color: %1"}.arg(elementsColour.name()));
    ui->btnValues->setStyleSheet(QString{"background-color: %1"}.arg(valuesColour.name()));
}

void PreferencesDialog::openColourPickerDialog(Buttons sender)
{
    QColor* initialColour;
    switch (sender) {
        case Buttons::ATTRIBUTES:
            initialColour = &attributesColour;
        case Buttons::VALUES:
            initialColour = &valuesColour;
        case Buttons::ELEMENTS:
            initialColour = &elementsColour;
        case Buttons::BRACKETS:
            initialColour = &bracketsColour;
    }

    auto colour = QColorDialog::getColor(*initialColour, this, "Pick a Colour");
    if (colour.isValid()) {
        *initialColour = colour;
    }
    recolourButtons();
}

void PreferencesDialog::accept()
{
    commitColours();
    done(QDialog::Accepted);
}

void PreferencesDialog::reject()
{
    done(QDialog::Rejected);
}

