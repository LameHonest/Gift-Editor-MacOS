#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <QFile>
#include <QTextStream>


class ControllerParserFile
{
public:
    ControllerParserFile();
    QString parseCheck(QFile &);
    QVector <QString> parseFile (QFile &);
private:
//    void modelAddMultipleChoise(QString);
//    void modelAddMissedWord(QString);
//    void modelShortAnswer(QString);
//    void modelTrueFalse(QString);
//    void modelMatchingSelection(QString);
//    void modelNumericAnswer(QString);
//    void modelEssay(QString);

    void parseQuestStr (QString, QVector <QString>&);

    bool checkMultipleChoise (QString);
    bool checkMissedWord (QString);
    bool checkShortAnswer (QString);
    bool checkTrueFalse (QString);
    bool checkMatchingSelection (QString);
    bool checkNumericAnswer (QString);
    bool checkEssay (QString);
    bool searchSubStr (QString,QString);
};
#endif // FILEPARSER_H
