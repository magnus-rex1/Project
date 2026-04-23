#pragma once

#include <QWidget>

#include "ui_calculatorform.h"

class CalculatorForm : public QWidget {
    Q_OBJECT

public:
    explicit CalculatorForm(QWidget* parent = nullptr);

private slots:
    void updateResult();

private:
    Ui::CalculatorForm ui;
};
