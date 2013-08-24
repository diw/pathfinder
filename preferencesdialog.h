#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>
#include <QSignalMapper>

struct HighlightingColours {
    QColor bracketsColour;
    QColor elementsColour;
    QColor attributesColour;
    QColor valuesColour;
};

HighlightingColours loadColours();
void commitColours(HighlightingColours const& colours);

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
    HighlightingColours colours;

    void recolourButtons();

private slots:
    void openColourPickerDialog(Buttons sender);
    void accept() override;
    void reject() override;
};

#endif // PREFERENCESDIALOG_H
