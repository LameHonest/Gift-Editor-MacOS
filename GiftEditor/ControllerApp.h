#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

//#include "globals.h"
#include "ControllerParserFile.h"
#include <QFile>
#include <QVector>

class ControllerApp
{
public:
    ControllerApp();
    QStringList parseFile(QFile &);
    QStringList sendData(QString);
    QStringList prepareDataModel(QString);
    void acceptQuest (QString);
    QStringList requestModelData();
    void clearModel();
private:
    void sendModelMultipleChoise(QString,QString,QString);
    void sendModelMissedWord();
    void sendModelShortAnswer(QString, QString, QString);
    void sendModelTrueFalse(QString, QString, QString);
    void sendModelMatchingSelection(QString, QString, QString);
    void sendModelNumericAnswer(QString, QString, QString);
    void sendModelEssay(QString, QString);
};

#endif // APPCONTROLLER_H
