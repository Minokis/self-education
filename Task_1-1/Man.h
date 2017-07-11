//
//  Man.h
//  Task_1-1
//
//  Created by Anna Korniychuk on 7/11/17.
//
/* Задание: в текстовом файле хранится база отдела кадров, всего 100 сотрудников. Каждая строка файла содержит запись об одном сотруднике: фамилия и инициалы (30 позиций), год рождения (5 позиций), оклад (10 позиций). Написать программу, которая по заданной фамилии выводит на экран сведения о сотруднике, подсчитывая средний оклад всех запрошенных сотрудников.
 */

#ifndef MAN_H
#define MAN_H

const int name_length = 30;
const int year_length = 5;
const int pay_length = 10;
const int buf_length = name_length + year_length + pay_length;

class Man {
public:
    Man(int lName = 30); // конструктор
    ~Man(); // деструктор
    bool CompareName(const char*) const;
    char* GetName() const { return name; }
    int GetBirthYear() const { return birth_year; }
    float GetPay() const { return pay; }
    void Print() const;
    void SetName(const char*);
    void SetBirthYear(const char*);
    void SetPay(const char*);
private:
    char* name;
    int birth_year;
    float pay;
};

#endif /* MAN_H */
