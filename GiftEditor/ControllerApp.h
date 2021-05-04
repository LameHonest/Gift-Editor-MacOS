#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

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
    QString requestQuestType(int index);
    QStringList requestModelData();
    void clearModel();
    void editQuest(int index, QString qType,QStringList data);
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
