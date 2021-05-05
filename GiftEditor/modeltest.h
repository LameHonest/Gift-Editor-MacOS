#ifndef TESTMODEL_H
#define TESTMODEL_H

#include <QString>
#include <QStringList>
#include <vector>

class ModelTest
{
public:
    ModelTest();
//Модель вопросов
    enum questType {MultipleChoise, MissedWord, ShortAnswer, TrueFalse, MatchingSelection, NumericAnswer, Essay};
    //Множественный выбор
    struct Test
    {
        questType questionType;
        QString title;
        QString text;
    };
    struct QuestMultipleChoise : public Test
    {
        QStringList answers;
    };
    //Пропущенное слово
    struct QuestMissedWord : public Test
    {
        QString firstHalf, secondHalf;
        QStringList answers;
    };
    //Короткий ответ
    struct QuestShortAnswer : public Test
    {
        QString answer;
    };
    //Верно-неверно
    struct QuestTrueFalse : public Test
    {
        QString answer;
    };
    //Выбор соотвествия
    struct QuestMatchingSelection : public Test
    {
        QStringList matchesArray;
    };
    //Числовой ответ
    struct QuestNumericAnswer : public Test
    {
        QString answer;
    };
    //Эссе
    struct QuestEssay: public Test
    {
    };

//Конец модели вопросов
//Методы:
    QStringList requestData();
    void attachData(QStringList);

    QString sendQuestType(int index);

    //Добавление вопроса
    void addQuest(QString,QString,QString,QString);
    void addMultipleChoiseQuest(QString qTitle, QString qText, QStringList qAnswers);
 //    void addMissedWordQuest(QVector <QString>);
    void addShortAnswerQuest(QString qTitle, QString qText, QString qAnswers);
    void addTrueFalseQuest(QString qTitle, QString qText, QString qAnswer);
    void addMatchingSelectionQuest(QString qTitle, QString qText, QStringList qAnswers);
    void addNumericAnswerQuest(QString qTitle, QString qText, QString qAnswer);
    void addEssayQuest(QString qTitle, QString qText);

    //Редактирование вопросов
    void editQuest(int index, QString qType, QStringList data);

    //Получение вопроса по индексу
    QStringList sendQuestByIndex(int index);

    //Отправка инвормации о вопросе
    QStringList sendMultipleChoiseQuest(Test *);
    //QStringList sendMissedWordQuest(int questIndex);
    QStringList sendShortAnswerQuest(Test *);
    QStringList sendTrueFalseQuest(Test *);
    QStringList sendMatchingSelectionQuest(Test *);
    QStringList sendNumericAnswerQuest(Test *);
    QStringList sendEssayQuest(Test *);

//Конец методов
//Вектор, в котором будут храниться вопросы:
    std::vector<Test *> vectorQuest;

private:
    void setUpTest(QString, QString, Test*, questType);
    void getStructType ();
    void getQuestType();
    void printQuestions();
};

#endif // TESTMODEL_H
