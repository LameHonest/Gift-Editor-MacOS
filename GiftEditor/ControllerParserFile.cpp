#include "ControllerParserFile.h"
#include <QDebug>
#include <iostream>
#include <QString>
#include <QTextCodec>

ControllerParserFile::ControllerParserFile()
{

}

void ControllerParserFile::parseQuestStr(QString questStr, QVector <QString> &vec) {
    QString qTitle, qText, qAnswers;
    qTitle = questStr.right(questStr.length() - questStr.indexOf("::") - 2);
    qText = qTitle.right(qTitle.length() - qTitle.indexOf("::") - 2);
    qTitle = qTitle.left(qTitle.indexOf("::"));
    int index = 0;
    for (int i = 0; i < qText.length(); i++) {
        if(qText[i] == "{") {
            index = i;
        }
    }
    qAnswers = qText.right(qText.length() - index - 1);
    qText = qText.left(index - 1);
    for (int i = 0; i < qAnswers.length(); i++){
        if(qAnswers[i] == "}") {
            index = i;
        }
    }
    qAnswers = qAnswers.left(index);
    vec.push_back(qTitle);
    vec.push_back(qText);
    vec.push_back(qAnswers);
}

QVector <QString> ControllerParserFile::parseFile(QFile &file) {
    QTextStream in(&file);
    in.setCodec("UTF-8");
    QVector<QString> vectorQuest, vectorResult;
    bool found = false;
    QString temp, quest;
    while (!in.atEnd()) {
        int numOfEmpty = 0;
        temp = in.readLine();
        if (!temp.isEmpty() || temp != "\n") {
            quest = quest + temp + " ";
            numOfEmpty++;
        }
        if (temp.isEmpty() || temp == "\n") {
            vectorQuest.push_back(quest);
            quest = "";
        }
    }
    if (!temp.isEmpty()) {
        vectorQuest.push_back(quest);
    }
   found = false;
   for (int i = 0; i < vectorQuest.count(); i++) {
       QString currentQuest = vectorQuest[i].right(vectorQuest[i].length() - vectorQuest[i].indexOf("{"));
       if (!found && checkMatchingSelection(currentQuest)) {
           vectorResult.push_back("Matching Selection");
           parseQuestStr(vectorQuest[i],vectorResult);
           found = true;
       }
       if (!found && checkShortAnswer(currentQuest)) {
           vectorResult.push_back("Short Answer");
           parseQuestStr(vectorQuest[i],vectorResult);
           found = true;
       }
       if (!found && checkNumericAnswer(currentQuest)) {
           vectorResult.push_back("Numeric Answer");
           parseQuestStr(vectorQuest[i],vectorResult);
           found = true;
       }
       if (!found && checkMultipleChoise(currentQuest)) {
           vectorResult.push_back("Multiple Choise");
           parseQuestStr(vectorQuest[i],vectorResult);
           found = true;
       }
       if (!found && checkTrueFalse(currentQuest)) {
           vectorResult.push_back("True False");
           parseQuestStr(vectorQuest[i],vectorResult);
           found = true;
       }
       if (!found && checkEssay(currentQuest)) {
          vectorResult.push_back("Essay");
          parseQuestStr(vectorQuest[i],vectorResult);
          found = true;
       }
       found = false;
       }
   for (int i = 0; i < vectorResult.count(); i=i+4){
       qDebug() << "Type:" <<vectorResult[i] <<"Title:" << vectorResult[i + 1] << "Text:" << vectorResult[i+2] << "Answers:" << vectorResult[i + 3] << endl;
   }
   return vectorResult;
}

QString ControllerParserFile::parseCheck(QFile &file) {
    parseFile(file);
//    QTextStream in(&file);
//    in.setCodec("UTF-8");
//    QStringList text = in.readAll().split("}"), parsedArray = in.readAll().split("");
//    std::string resultStr[text.count() * 2];
//    int index = 0;
//    bool found = false;
   QString retStr="";
    return retStr;
}

bool ControllerParserFile::checkEssay(QString checkStr) {
    if (checkStr.contains("{}", Qt::CaseInsensitive) || checkStr.contains("{ }", Qt::CaseInsensitive) || checkStr.contains("{/n}", Qt::CaseInsensitive)) {
        return true;
    }
    return false;
}

bool ControllerParserFile::checkTrueFalse(QString checkStr) {
    if ( checkStr.contains("{ F }", Qt::CaseInsensitive) || checkStr.contains("{ T }", Qt::CaseInsensitive) || checkStr.contains("{ FALSE }", Qt::CaseInsensitive)  || checkStr.contains("{ TRUE }", Qt::CaseInsensitive)  || checkStr.contains("{TRUE}", Qt::CaseInsensitive) || checkStr.contains("{T}", Qt::CaseInsensitive) || checkStr.contains("{FALSE}", Qt::CaseInsensitive) || checkStr.contains("{F}", Qt::CaseInsensitive)) {
        return true;
    }
    return false;
}

bool ControllerParserFile::checkMissedWord(QString checkStr) {
    //Доделать
    if (checkStr.contains("#", Qt::CaseInsensitive)) {
        return true;
    }
    return false;
}

bool ControllerParserFile::checkShortAnswer(QString checkStr) {
    if (checkStr.contains("=") && !checkStr.contains("~") && !checkStr.contains("->")) {
        return true;
    }
    return false;
}

bool ControllerParserFile::checkNumericAnswer(QString checkStr) {
    qDebug() << "Numeric Answer str = " << checkStr << endl;
    if (checkStr.count("#") == 1) {
        return true;
    }
    return false;
}

bool ControllerParserFile::checkMultipleChoise(QString checkStr) {
    //qDebug() << "Multiple Choise str = " << checkStr << endl;
    if (checkStr.contains("~", Qt::CaseInsensitive) || checkStr.contains("=", Qt::CaseInsensitive)) {
        return true;
    }
    return false;
}

bool ControllerParserFile::checkMatchingSelection(QString checkStr) {
    //qDebug() << "Matching Selection str = " << checkStr << endl;
    if (checkStr.contains("=", Qt::CaseInsensitive) && checkStr.contains("->", Qt::CaseInsensitive)) {
        return true;
    }
    return false;
}
