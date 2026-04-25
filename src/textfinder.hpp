#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
class QTextEdit;
QT_END_NAMESPACE

class TextFinder : public QWidget {
    Q_OBJECT

public:
    explicit TextFinder(QWidget* parent = nullptr);

private slots:
    void on_findButton_clicked();

private:
    QPushButton* ui_findButton;
    QTextEdit* ui_textEdit;
    QLineEdit* ui_lineEdit;
};
