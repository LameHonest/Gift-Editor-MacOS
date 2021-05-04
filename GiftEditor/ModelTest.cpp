#include "ModelTest.h"
#include <QDebug>

ModelTest::ModelTest()
{

}

QString ModelTest::sendQuestType(int index) {
    if (vectorQuest.at(index)->questionType == MultipleChoise) {
        return "Multiple Choise";
    }
    if (vectorQuest.at(index)->questionType == ShortAnswer) {
        return "Short Answer";
    }
    if (vectorQuest.at(index)->questionType == MissedWord) {
        return "Missed Word";
    }
    if (vectorQuest.at(index)->questionType == TrueFalse) {
        return "True False";
    }
    if (vectorQuest.at(index)->questionType == MatchingSelection) {
        return "Matching Selection";
    }
    if (vectorQuest.at(index)->questionType == NumericAnswer) {
        return "Numeric Answer";
    }
    if (vectorQuest.at(index)->questionType == Essay) {
        return "Essay";
    }
    return "Error";
}

void ModelTest::attachData(QStringList arrayQuest) {
    for (int i = 0; i < arrayQuest.count()-1; i=i+4)
    {
        addQuest(arrayQuest[i], arrayQuest[i+1], arrayQuest[i+2],arrayQuest[i+3]);
    }
    qDebug() << "Зашли в модель";
    printQuestions();
}

void ModelTest::editQuest(int index, QString qType, QStringList data) {
    bool found = false;
    if (index <= vectorQuest.size()) {
        QString title = data[0], text = data[1], answer = data[2];
        if (qType == "Multiple Choise") {
            QStringList answerList;
            for (int i = 2; i < data.count(); i++) {
                answerList.push_back(data[i]);
            }
            addMultipleChoiseQuest(title,text, answerList);
            found = true;
        }
        if (qType == "Short Answer") {
            addShortAnswerQuest(title,text,answer);
            found = true;
        }
        if (qType == "True False") {
            addTrueFalseQuest(title,text,answer);
            found = true;
        }
        if (qType == "Matching Selection") {
            QStringList answerList;
            for (int i = 2; i < data.count(); i++) {
                answerList.push_back(data[i]);
            }
            addMatchingSelectionQuest(title,text,answerList);
            found = true;
        }
        if (qType == "Numeric Answer") {
            addNumericAnswerQuest(title,text,answer);
            found = true;
        }
        if (qType == "Essay") {
            addEssayQuest(title,text);
            found = true;
        }
    }
    if (found) {
        std::swap(vectorQuest[vectorQuest.size()],vectorQuest[index]);
        vectorQuest.erase(vectorQuest.end());
    }

}

//Настройка и добавление нового вопроса
void ModelTest::setUpTest(QString qTitle, QString qText, Test *question, questType qType){
    question->questionType = qType;
    question->text = qText;
    question->title = qTitle;
    vectorQuest.push_back(question);
}

//Добавление вопроса Множественного выбора
void ModelTest::addMultipleChoiseQuest(QString qTitle, QString qText, QStringList qAnswers) {
     Test* question = new Test();
     QuestMultipleChoise *newMultipleChoise = new QuestMultipleChoise();
     newMultipleChoise->answers = qAnswers;
     question = static_cast<Test*>(newMultipleChoise);
     setUpTest(qTitle, qText, question, MultipleChoise);
}

//Добавление вопроса Короткий ответ
void ModelTest::addShortAnswerQuest(QString qTitle, QString qText, QString qAnswers) {
    Test* question = new Test();
    QuestShortAnswer *newShortAnswer = new QuestShortAnswer();
    newShortAnswer->answer = qAnswers;
    question = static_cast<Test*>(newShortAnswer);
    setUpTest(qTitle, qText, question, ShortAnswer);
}

//Добавление вопроса Верно-неверно
void ModelTest::addTrueFalseQuest(QString qTitle, QString qText, QString qAnswer) {
    Test* question = new Test();
    QuestTrueFalse *newTrueFalse = new QuestTrueFalse();
    newTrueFalse->answer = qAnswer;
    question = static_cast<Test*>(newTrueFalse);
    setUpTest(qTitle, qText, question, TrueFalse);
}

//Добавление вопроса на выбор соотвествия
void ModelTest::addMatchingSelectionQuest(QString qTitle, QString qText, QStringList qAnswers) {
    Test* question = new Test();
    QuestMatchingSelection *newMatchingSelection = new QuestMatchingSelection();
    newMatchingSelection->matchesArray = qAnswers;
    question = static_cast<Test*>(newMatchingSelection);
    setUpTest(qTitle, qText, question, MatchingSelection);
}

//Добавление вопроса числовой ответ
void ModelTest::addNumericAnswerQuest(QString qTitle, QString qText, QString qAnswer){
    Test* question = new Test();
    QuestNumericAnswer* newNumericAnswer = new QuestNumericAnswer();
    newNumericAnswer->answer = qAnswer;
    question = static_cast<Test*>(newNumericAnswer);
    setUpTest(qTitle, qText, question, NumericAnswer);
}

//Добавление вопроса числовой ответ
void ModelTest::addEssayQuest(QString qTitle, QString qText){
    Test* question = new Test();
    QuestEssay* newEssay = new QuestEssay();
    question = static_cast<Test*>(newEssay);
    setUpTest(qTitle, qText, question, Essay);
}

QStringList ModelTest::sendNumericAnswerQuest(Test *newTest) {
    QStringList resultList;
    resultList.push_back(newTest->title);
    resultList.push_back(newTest->text);
    QuestNumericAnswer *newQuest = static_cast<QuestNumericAnswer*>(newTest);
    resultList.push_back(newQuest->answer);
    return resultList;
}

QStringList ModelTest::sendEssayQuest(Test *newTest) {
    QStringList resultList;
    resultList.push_back(newTest->title);
    resultList.push_back(newTest->text);
    return resultList;
}

QStringList ModelTest::sendMatchingSelectionQuest(Test *newTest) {
    QStringList resultList;
    resultList.push_back(newTest->title);
    resultList.push_back(newTest->text);
    QuestMatchingSelection *newQuest = static_cast< QuestMatchingSelection*>(newTest);
    for (auto &element: newQuest->matchesArray) {
        resultList.push_back(element);
    }
    return resultList;
}

QStringList ModelTest::sendTrueFalseQuest(Test *newTest) {
    QStringList resultList;
    resultList.push_back(newTest->title);
    resultList.push_back(newTest->text);
    QuestTrueFalse *newQuest = static_cast<QuestTrueFalse*>(newTest);
    resultList.push_back(newQuest->answer);
    return resultList;
}

QStringList ModelTest::sendShortAnswerQuest(Test *newTest) {
    QStringList resultList;
    resultList.push_back(newTest->title);
    resultList.push_back(newTest->text);
    QuestShortAnswer *newQuest = static_cast<QuestShortAnswer*>(newTest);
    resultList.push_back(newQuest->answer);
    return resultList;
}

QStringList ModelTest::sendMultipleChoiseQuest(Test * newTest){
    QStringList resultList;
    resultList.push_back(newTest->title);
    resultList.push_back(newTest->text);
    QuestMultipleChoise *newQuest = static_cast<QuestMultipleChoise*>(newTest);
    for (auto &element: newQuest->answers) {
        resultList.push_back(element);
    }
    return resultList;
}

QStringList ModelTest::requestData(){
    QString total;
    QStringList resultList;
    for (auto const &element: vectorQuest) {
        if (element->questionType == MultipleChoise) {
            QStringList buf = sendMultipleChoiseQuest(element);
            total = total + "::" + buf[0] + "::" + buf[1] + " {\n";
            for (int i = 2; i < buf.count(); i++) {
                total = total + buf[i] + "\n";
            }
            total = total + "}" + "\n";
        }
        if (element->questionType == MissedWord) {
            //total = total + element->title + element->text;
            //QuestMissedWord *newQuest = static_cast<QuestMissedWord*>(element);
            //total = total + newQuest->answer;
        }
        if (element->questionType == ShortAnswer) {
            QStringList buf = sendShortAnswerQuest(element);
            total = total + "::" + buf[0] + "::" + buf[1]+ " {\n";
            total = total + buf[2] + "\n}" + "\n";
        }
        if (element->questionType == TrueFalse) {
            QStringList buf = sendTrueFalseQuest(element);
            total = total + "::" + buf[0] + "::" + buf[1] + " {";
            buf[2] = buf[2].trimmed();
            total = total + buf[2] + "}\n";
        }
        if (element->questionType == MatchingSelection) {
            QStringList buf = sendMatchingSelectionQuest(element);
            total = total + "::" + buf[0] + "::" + buf[1] + " {\n";
            for (int i = 2; i < buf.count(); i=i+2) {
                total = total + "=" + buf[i] + " -> " + buf[i+1] + "\n";
            }
            total = total + "}\n";
        }
        if (element->questionType == NumericAnswer) {
            QStringList buf = sendNumericAnswerQuest(element);
            total = total + "::" + buf[0] + "::" + buf[1] + " {";
            total = total + buf[2] + "}\n";
        }
        if (element->questionType == Essay) {
            QStringList buf = sendEssayQuest(element);
            total = total + "::" + buf[0] + "::" + buf[1] + " {}\n";
        }
        resultList.push_back(total);
        total = "";
    }
    return resultList;
}

void ModelTest::addQuest(QString qType, QString qTitle, QString qText, QString qAnswers){
    Test* question = new Test();
    if (qType == "Multiple Choise") {
        QuestMultipleChoise *newMultipleChoise = new QuestMultipleChoise();
        //newMultipleChoise->answer = qAnswers;
        question = static_cast<Test*>(newMultipleChoise);
        question->questionType = MultipleChoise;
        question->text = qText;
        question->title = qTitle;
        vectorQuest.push_back(question);
    }
    if (qType == "Missed Word") {
        qDebug() << "Добавили Missed Word";
        QuestMissedWord *newMissedWord = new QuestMissedWord();
        //newMissedWord->answer = qAnswers;
        question = static_cast<Test*>(newMissedWord);
        question->questionType = MissedWord;
        question->text = qText;
        question->title = qTitle;
        vectorQuest.push_back(question);
    }
    if (qType == "Short Answer") {
        qDebug() << "Добавили Short Answer";
        QuestShortAnswer *newShortAnswer = new QuestShortAnswer();
        //newShortAnswer->answer = qAnswers;
        question = static_cast<Test*>(newShortAnswer);
        question->text = qText;
        question->title = qTitle;
        vectorQuest.push_back(question);
    }
    if (qType == "True False") {
        qDebug() << "Добавили True False";
        QuestTrueFalse *newTrueFalse = new QuestTrueFalse();
        //newTrueFalse->answer = qAnswers;
        question = static_cast<Test*>(newTrueFalse);
        question->questionType = TrueFalse;
        question->text = qText;
        question->title = qTitle;
        vectorQuest.push_back(question);
    }
    if (qType == "Matching Selection") {
        qDebug() << "Добавили Matching Selection";
        QuestMatchingSelection* newMatchSelect = new QuestMatchingSelection();
        //newMatchSelect->answer = qAnswers;
        question = static_cast<Test*>(newMatchSelect);
        question->questionType = MatchingSelection;
        question->text = qText;
        question->title = qTitle;
        vectorQuest.push_back(question);
    }
    if (qType == "Numeric Answer") {
        QuestNumericAnswer* newNumericAnswer = new QuestNumericAnswer();
        newNumericAnswer->answer = qAnswers;
        question = static_cast<Test*>(newNumericAnswer);
        question->questionType = NumericAnswer;
        question->text = qText;
        question->title = qTitle;
        vectorQuest.push_back(question);
    }
    if (qType == "Essay") {
        QuestEssay* newEssay = new QuestEssay();
        question = static_cast<Test*>(newEssay);
        question->questionType = Essay;
        question->text = qText;
        question->title = qTitle;
        vectorQuest.push_back(question);
    }

}

void ModelTest::printQuestions() {

    for (auto const &element: vectorQuest) {
        if (element->questionType == MultipleChoise) {
            qDebug() << element->title << element->text;
            QuestMultipleChoise *newQuest = static_cast<QuestMultipleChoise*>(element);
            for (auto const &listElement: newQuest->answers){
            qDebug() << listElement;
            }
        }
        if (element->questionType == MissedWord) {
            //qDebug() << element->title << element->text;
            //QuestMissedWord *newQuest = static_cast<QuestMissedWord*>(element);
            //qDebug() << newQuest->answer;
        }
        if (element->questionType == ShortAnswer) {
            qDebug() << element->title << element->text;
            QuestShortAnswer *newQuest = static_cast<QuestShortAnswer*>(element);
            qDebug() << newQuest->answer;
        }
        if (element->questionType == TrueFalse) {
            qDebug() << element->title << element->text;
            QuestTrueFalse *newQuest = static_cast<QuestTrueFalse*>(element);
            qDebug() << newQuest->answer;
        }
        if (element->questionType == MatchingSelection) {
            qDebug() << element->title << element->text;
            QuestMatchingSelection *newQuest = static_cast< QuestMatchingSelection*>(element);
            for (auto const &listElement: newQuest->matchesArray){
            qDebug() << listElement;
            }
        }
        if (element->questionType == NumericAnswer) {
            qDebug() << element->title << element->text;
            QuestNumericAnswer *newQuest = static_cast< QuestNumericAnswer*>(element);
            qDebug() << newQuest->answer;
        }
        if (element->questionType == Essay) {
            qDebug() << element->title << element->text;
            //QuestEssay *newQuest = static_cast<QuestEssay*>(element);
        }
    }
}

