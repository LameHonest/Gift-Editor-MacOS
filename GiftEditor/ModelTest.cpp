#include "ModelTest.h"
#include <QDebug>

ModelTest::ModelTest()
{

}

void ModelTest::attachData(QStringList arrayQuest) {
    for (int i = 0; i < arrayQuest.count()-1; i=i+4)
    {
        addQuest(arrayQuest[i], arrayQuest[i+1], arrayQuest[i+2],arrayQuest[i+3]);
    }
    qDebug() << "Зашли в модель";
    printQuestions();
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


QStringList ModelTest::requestData(){
    QString total;
    QStringList resultList;
    for (auto const &element: vectorQuest) {
        if (element->questionType == MultipleChoise) {
            total = total + "::" + element->title + "::" + element->text + " {\n";
            QuestMultipleChoise *newQuest = static_cast<QuestMultipleChoise*>(element);
            for (auto const &listElement: newQuest->answers){
            total = total + listElement + "\n";
            }
            total = total + "}" + "\n";
        }
        if (element->questionType == MissedWord) {
            //total = total + element->title + element->text;
            //QuestMissedWord *newQuest = static_cast<QuestMissedWord*>(element);
            //total = total + newQuest->answer;
        }
        if (element->questionType == ShortAnswer) {
            total = total + "::" + element->title + "::" + element->text + " {\n";
            QuestShortAnswer *newQuest = static_cast<QuestShortAnswer*>(element);
            total = total + newQuest->answer + "\n}" + "\n";
        }
        if (element->questionType == TrueFalse) {
            total = total + "::" + element->title + "::" + element->text + " {";
            QuestTrueFalse *newQuest = static_cast<QuestTrueFalse*>(element);
            newQuest->answer = newQuest->answer.trimmed();
            total = total + newQuest->answer + "}\n";
        }
        if (element->questionType == MatchingSelection) {
            total = total + "::" + element->title + "::" + element->text + " {\n";
            QuestMatchingSelection *newQuest = static_cast< QuestMatchingSelection*>(element);
            for (int i = 0; i < newQuest->matchesArray.count(); i=i+2) {
                total = total + "=" + newQuest->matchesArray[i] + " -> " + newQuest->matchesArray[i+1] + "\n";
            }
            total = total + "}\n";
        }
        if (element->questionType == NumericAnswer) {
            total = total + "::" + element->title + "::" + element->text + " {";
            QuestNumericAnswer *newQuest = static_cast< QuestNumericAnswer*>(element);
            total = total + newQuest->answer + "}\n";
        }
        if (element->questionType == Essay) {
            total = total + "::" + element->title + "::" + element->text + " {}\n";
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
            qDebug() << element->title << element->text;
            QuestMissedWord *newQuest = static_cast<QuestMissedWord*>(element);
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
void ModelTest::addToVectorQuest() {
    QuestMatchingSelection* newMS = new QuestMatchingSelection();
    QStringList array = {"1","2","3"};
    //newMS->matchesArray = array;
    qDebug() << "Инициализировали сущность MS";
    //Test* question = static_cast<QuestMatchingSelection*>(newTest);
    Test* question = static_cast<Test*>(newMS);
    question->title = "Test title";
    question->text = "Test text";
    qDebug() << "Инициализировали сущность Test";
    vectorQuest.push_back(question);
    qDebug() << "Добавили в вектор";
    qDebug() << vectorQuest.at(0);
    qDebug() << vectorQuest.at(0)->title;
    qDebug() << vectorQuest.at(0)->text;
    qDebug() << "Вывели вектор Test";
    newMS = static_cast<QuestMatchingSelection*>(vectorQuest.at(0));
    //qDebug() << newMS->matchesArray;
    qDebug() << "Вывели вектор MS";
    //QuestTest::QuestTrueFalse *newQuest = new QuestTest::QuestTrueFalse;
    //newQuest->name = "Вставьте пропущенное слово";
    //questVector.push_back(newQuest);
}
