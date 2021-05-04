#include "ControllerApp.h"
#include <QDebug>

#include "ModelGlobals.h"

ControllerApp::ControllerApp()
{

}

QStringList ControllerApp::prepareDataModel(QString str) {
    QStringList list = str.split("{!SPLIT_CARACT!}");
    QString result, questType, questTitle, questText, questAnswers;
    for (int i = 0; i < list.count()-1; i=i+2) {
         qDebug () << list[i] << list[i+1];
        questType = list[i];
        questTitle = list[i+1].left(list[i+1].indexOf("{"));
        questTitle = questTitle.right( questTitle.length() - questTitle.indexOf("::") - 2);
        questText = questTitle.right(questTitle.length() - questTitle.indexOf("::") - 2);
        questTitle = "::" + questTitle.left(questTitle.indexOf("::")) + "::";
        questAnswers = "{" + list[i+1].right(list[i+1].length() - list[i+1].indexOf("{") - 1);
        result = result + questType + "{!SPLIT_CARACT!}" + questTitle +"{!SPLIT_CARACT!}" + questText + "{!SPLIT_CARACT!}" + questAnswers + "{!SPLIT_CARACT!}";
    }
    QStringList resultList = result.split("{!SPLIT_CARACT!}");
    for (int i = 0; i < resultList.count(); i++){
         qDebug() << "Элемент: " << i <<" = "<<resultList[i];
    }
    return  resultList;

}

QStringList ControllerApp::requestModelData(){
    return newModelTest->requestData();
}

void ControllerApp::acceptQuest(QString quest) {
    newModelTest->attachData(prepareDataModel(quest));
}

void ControllerApp::clearModel() {
    newModelTest->vectorQuest.resize(0);
}

QStringList ControllerApp::parseFile(QFile &file) {
    QFile &fileToParse = file;
    ControllerParserFile *newFileParser = new ControllerParserFile();
    QVector <QString> vec = newFileParser->parseFile(fileToParse);
    for (int i = 0; i < vec.count(); i=i+4) {
        if (vec[i] == "Multiple Choise") {
            sendModelMultipleChoise(vec[i+1],vec[i+2],vec[i+3]);
        }
        if (vec[i] == "Missed Word") {

        }
        if (vec[i] == "Short Answer") {
            sendModelShortAnswer(vec[i+1],vec[i+2],vec[i+3]);
        }
        if (vec[i] == "True False") {
            sendModelTrueFalse(vec[i+1],vec[i+2],vec[i+3]);
        }
        if (vec[i] == "Matching Selection") {
            sendModelMatchingSelection(vec[i+1],vec[i+2],vec[i+3]);
        }
        if (vec[i] == "Numeric Answer") {
            sendModelNumericAnswer(vec[i+1],vec[i+2],vec[i+3]);
        }
        if (vec[i] == "Essay") {
            sendModelEssay(vec[i+1],vec[i+2]);
        }
    }
    return newModelTest->requestData();
}

void ControllerApp::sendModelEssay(QString qTitle, QString qText) {
    newModelTest->addEssayQuest(qTitle,qText);
}

void ControllerApp::sendModelNumericAnswer(QString qTitle, QString qText, QString qAnswers){
    newModelTest->addNumericAnswerQuest(qTitle,qText,qAnswers);
}

void ControllerApp::sendModelMatchingSelection(QString qTitle, QString qText, QString qAnswers){
    QStringList answerList = qAnswers.split(QRegExp("(\\=|\\->)"));
    answerList.removeAt(0);
    for (auto &element: answerList) {
        element = element.trimmed();
    }
    newModelTest->addMatchingSelectionQuest(qTitle,qText,answerList);
}

void ControllerApp::sendModelTrueFalse(QString qTitle, QString qText, QString qAnswers) {
    newModelTest->addTrueFalseQuest(qTitle,qText,qAnswers);
}

void ControllerApp::sendModelMissedWord(){
}

void ControllerApp::sendModelShortAnswer(QString qTitle, QString qText, QString qAnswers) {
    newModelTest->addShortAnswerQuest(qTitle,qText,qAnswers);
}
void ControllerApp::sendModelMultipleChoise(QString qTitle, QString qText, QString qAnswers){
    QStringList answersList;
    QString results;
    for (int i = 0; i < qAnswers.count(); i ++) {
        if (qAnswers[i+1] != "/n" && qAnswers[i+1] != " ") {
            if (qAnswers[i] == "=") {
                results = results + "=";
            } else {
                if (qAnswers[i] == "~") {
                    results = results + "~";
                }
            }
        }
    }
    answersList = qAnswers.split(QRegExp("(\\=|\\~)"));
    answersList.removeAt(0);
    for (int i = 0; i < answersList.count(); i++) {
        if (i <= results.count()) {
            answersList[i] = results[i] + answersList[i].trimmed();
        }
    }
    newModelTest->addMultipleChoiseQuest(qTitle, qText, answersList);
}


QStringList ControllerApp::sendData(QString str) {
    QStringList strList = str.split("{!SPLIT_CARACT!}");
    return strList;
}
