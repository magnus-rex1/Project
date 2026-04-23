#include "calculatorform.hpp"

CalculatorForm::CalculatorForm(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    connect(ui.inputSpinBox1, &QSpinBox::valueChanged, this, &CalculatorForm::updateResult);
    connect(ui.inputSpinBox2, &QSpinBox::valueChanged, this, &CalculatorForm::updateResult);
}

void CalculatorForm::updateResult()
{
    const int sum = ui.inputSpinBox1->value() + ui.inputSpinBox2->value();
    ui.outputWidget->setText(QString::number(sum));
}
