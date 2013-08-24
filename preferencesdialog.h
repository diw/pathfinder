#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>
#include <QSignalMapper>

namespace Ui {
class PreferencesDialog;
}

class PreferencesDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PreferencesDialog(QWidget *parent = 0);
    ~PreferencesDialog();
    
private:
    enum Buttons {
        BRACKETS,
        ATTRIBUTES,
        VALUES,
        ELEMENTS
    };

    Ui::PreferencesDialog *ui;
    QColor bracketsColour;
    QColor elementsColour;
    QColor attributesColour;
    QColor valuesColour;

    void commitColours();
    void loadColours();
    void recolourButtons();

private slots:
    void openColourPickerDialog(Buttons sender);
    void accept() override;
    void reject() override;
};

#endif // PREFERENCESDIALOG_H
