#include <QApplication>

#include <QCommandLineParser>
#include <QFile>
#include <QStringLiteral>
#include <QTranslator>

#include "songlist.hpp"
#include "textfinder.hpp"

using namespace Qt::StringLiterals;

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    // QApplication::setStyle(QStyleFactory::create("Fusion"));
    QFile file(u":/forms/Darkeum/Darkeum.qss"_s);
    // QFile file(u"forms/Combinear/Combinear.qss"_s);
    // QFile file(u"forms/Takezo/Takezo.qss"_s);
    if (!file.open(QIODevice::ReadOnly))
        qFatal("Cannot open resource file");
    app.setStyleSheet(QTextStream(&file).readAll());
    // QCoreApplication::setOrganizationName("MagnusRex"_L1);
    // QCoreApplication::setApplicationName("Project"_L1);
    // QCoreApplication::setApplicationVersion("0.1"_L1);
    //
    // // Translator mainTranslator;
    // // mainTranslator.setBaseName("project"_L1);
    // // mainTranslator.install();
    //
    // QCommandLineParser parser;
    // parser.setApplicationDescription(Tr::tr("Application description"));
    // parser.addHelpOption();
    // parser.addVersionOption();
    // parser.addPositionalArgument("File"_L1, Tr::tr("positional argument"));
    // parser.process(app);

    // CalculatorForm calculatorform { nullptr };
    // calculatorform.show();

    // TextFinder textFinder;
    // textFinder.show();

    SongList songList;
    songList.show();

    return app.exec();
}
