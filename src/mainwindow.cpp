#include "mainwindow.hpp"

#include <QDockWidget>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    auto contents = new QDockWidget(tr("Table of Contents"), this);
    contents->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    addDockWidget(Qt::LeftDockWidgetArea, contents);
}
