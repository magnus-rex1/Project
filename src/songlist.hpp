#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
class QListWidget;
class QListView;
QT_END_NAMESPACE

class SongList : public QWidget {
    Q_OBJECT

public:
    explicit SongList(QWidget* parent = nullptr);

private:
    QListWidget* ui_songList;
    QListView* ui_songPreview;
};
