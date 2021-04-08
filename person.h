#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
    private:
        /* Id человека */
        long key;

        /* Фамилия */
        std::string last_name;

        /* Имя */

        std::string first_name;

        /* Отчество */
        std::string second_name;

    public:
        /* Конструктор класса по умолчанию */
        Person();

        /* Конструктор класса с параметрами */
        Person(long key, const std::string&, const std::string&, const std::string&);

        /* Деструктор класса */
        ~Person() {;}

        /* Конструктор копирования */
        Person(const Person&);//

        /* Функция получения фамилии человека */
        const std::string& getLastName() const { return last_name; }

        /* Функция получения имени человека */
        const std::string& getFirstName() const { return first_name; }

        /* Функция получения отчества человека */
        const std::string& getSecondName() const { return second_name; }

        /* Функция установки фамилии для человека */
        void setLastName(const std::string&);

        /* Функция установки имени для человека */
        void setFirstame(const std::string&);

        /* Функция установки отчества для человека */
        void setSecondName(const std::string&);
};

#endif // PERSON_H
