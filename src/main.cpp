#include <QApplication>

#include <QCommandLineParser>
#include <QStringLiteral>
#include <QTranslator>

#include "calculatorform.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
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

    CalculatorForm calculatorform { nullptr };

    calculatorform.show();

    return app.exec();
}
