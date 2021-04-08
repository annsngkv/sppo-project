#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H
#define SPACE " "

#include <iostream>
#include "stack.h"
#include "person.h"
#include "exception.h"

class PersonKeeper
{
    private:
        /* Приватный член класса PersonKeeper - экзэмпляр класса Stack типа Person c размерностью по умолчанию (1024) */
        Stack <Person> stack;

        /* Конструктор недоступен вне класса */
        PersonKeeper() {;}

         /* Деструктор недоступен вне класса */
        ~PersonKeeper() {;}

        /* Запрещем копирование */
        PersonKeeper(PersonKeeper const&);
        PersonKeeper& operator = (PersonKeeper const&);

    public:
        /* Cтатический создающий метод, использующися для получения объекта-одиночки */
        static PersonKeeper& Instance()
        {
            static PersonKeeper person_keeper;

            return person_keeper;
        }

        /*
         * Метод, считывающий информацию о людях из входного потока (файла),
         * создающий на основе этой информации объекты класса Person,
         * и помещающий их в стек
        */
        bool readPersons(std::istream &);

        /* Метод, записывающий во выходной поток (файл) из стека информацию о людях */
        bool writePersons(std::ostream&);

        /* Метод, возвращаюющий стэк */
        Stack <Person>& getStack() { return stack ;}
};

#endif // PERSONKEEPER_H
