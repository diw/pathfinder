#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"

#include <QSettings>

PreferencesDialog::PreferencesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferencesDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Colour Preferences");

    loadColours();
    recolourButtons();
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
