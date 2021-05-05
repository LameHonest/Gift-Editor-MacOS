#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "ControllerParserFile.h"
#include <QFile>
#include <QVector>

class ControllerApp
{
public:
    ControllerApp();
    //Парсинг файла
    QStringList parseFile(QFile &);
    //?
    QStringList sendData(QString);
    QStringList prepareDataModel(QString);
    void acceptQuest (QString);
    //Работа с моделью
    QStringList getQuestData(int index);//Содержимое вопроса
    QString requestQuestType(int index);//Тип вопроса
    QStringList requestModelData();
    void clearModel();//отчистка модели
    void editQuest(int index, QString qType,QStringList data);//редактирование
    void sendModelMultipleChoise(QString,QString,QString);
    void sendModelMissedWord();
    void sendModelShortAnswer(QString, QString, QString);
    void sendModelTrueFalse(QString, QString, QString);
    void sendModelMatchingSelection(QString, QString, QString);
    void sendModelNumericAnswer(QString, QString, QString);
    void sendModelEssay(QString, QString);
};

#endif // APPCONTROLLER_H
