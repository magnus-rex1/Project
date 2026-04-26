#include "songlist.hpp"

#include <QUiLoader>

#include <QListView>
#include <QListWidget>

#include <QFile>
#include <QTextStream>

using namespace Qt::StringLiterals;

static QWidget* loadUiFile(QWidget* parent)
{
    QFile file(u":/forms/songlist.ui"_s);
    if (!file.open(QIODevice::ReadOnly))
        qFatal("Cannot open resource file");

    return QUiLoader().load(&file, parent);
}

SongList::SongList(QWidget* parent)
    : QWidget(parent)
{
    QWidget* formWidget = loadUiFile(this);

    ui_songList = findChild<QListWidget*>("songList");
    ui_songPreview = findChild<QListView*>("songPreview");

    new QListWidgetItem(tr("Oak"), ui_songList);
    new QListWidgetItem(tr("Fir"), ui_songList);
    new QListWidgetItem(tr("Pine"), ui_songList);

    QListWidgetItem* newItem = new QListWidgetItem;
    newItem->setText(tr("Fig"));
    ui_songList->insertItem(1, newItem);

    setWindowTitle(tr("Song List"));
}
