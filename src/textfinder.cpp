#include "textfinder.hpp"

#include <QUiLoader>

#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

#include <QFile>
#include <QTextStream>

using namespace Qt::StringLiterals;

static QWidget* loadUiFile(QWidget* parent)
{
    QFile file(u":/forms/textfinder.ui"_s);
    if (!file.open(QIODevice::ReadOnly))
        qFatal("Cannot open resource file");

    return QUiLoader().load(&file, parent);
}

static QString loadTextFile()
{
    QFile inputFile(u":/forms/input.txt"_s);
    if (!inputFile.open(QIODevice::ReadOnly))
        qFatal("Cannot open resource file");

    return QTextStream(&inputFile).readAll();
}

TextFinder::TextFinder(QWidget* parent)
    : QWidget(parent)
{
    QWidget* formWidget = loadUiFile(this);

    ui_findButton = findChild<QPushButton*>("findButton");
    ui_textEdit = findChild<QTextEdit*>("textEdit");
    ui_lineEdit = findChild<QLineEdit*>("lineEdit");

    QMetaObject::connectSlotsByName(this);

    ui_textEdit->setText(loadTextFile());

    auto* layout = new QVBoxLayout(this);
    layout->addWidget(formWidget);

    setWindowTitle(tr("Text Finder"));
}

void TextFinder::on_findButton_clicked()
{
    QString searchString = ui_lineEdit->text();
    QTextDocument* document = ui_textEdit->document();

    bool found = false;

    document->undo();

    if (searchString.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search Field"),
            tr("The search field is empty. "
               "Please enter a word and click Find."));
    } else {
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();

        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchString, highlightCursor,
                QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight, QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);
            }
        }

        cursor.endEditBlock();

        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                tr("Sorry, the word cannot be found."));
        }
    }
}
