#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H
#define SPACE " "

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
        Stack <Person> * getStack() { return &stack ;}
};

/*
 * Метод, считывающий информацию о людях из входного потока (файла),
 * создающий на основе этой информации объекты класса Person,
 * и помещающий их в стек
 *
 * arg istream &
 * return bool
*/
bool PersonKeeper::readPersons(std::istream &stream)
{
    /* Сохранили состояние исключений потока */
    std::ios_base::iostate s = stream.exceptions();

    /*
     * Установили состояние таким образом, что при достижении
     * конца файла будет сгенерировано исключение
    */
    stream.exceptions(std::ios_base::eofbit);

    /* Cоздаем массив для временного хранения данных о людях */
    std::string *person_data = new std::string[3];

    for (int idx = 0; idx < stack.getStackSize(); idx++) {
        /* Критический участок.
         * Возможны исключительные ситуации такие как конец файла и переполнение стэка
        */
        try {
            /* Считываем информацию из входного потока в наш массив */
            stream >> person_data[0];
            stream >> person_data[1];
            stream >> person_data[2];

            /* Создаем экзэмпляр класса Person на основе полуенных данных и пушим его в стэк */
            stack.push(new Person(idx, person_data[0], person_data[1], person_data[2]));
        } catch (const std::ios_base::failure&) { // Ловим все исключения типа failure
            /* Обработка исключений */
            std::cout << "Конец файла!" << std::endl;
            stream.exceptions(s);

            return false;
        } catch (const exc::EStackOverflow& e) { // Ловим все исключения типа EStackOverflow
            /* Обработка исключений */
            std::cout << e.what() << std::endl;

            return false;
        }
    }

    return true;
}

/*
 * Метод, записывающий в выходной поток (файл) из стека информацию о людях
 *
 * arg ostream &
 * return bool
*/
bool PersonKeeper::writePersons(std::ostream &stream)
{
    /* Строка для временного хранения данных о людях */
    std::string person_data;

    /* Создаем копию нашего объекта stack, чтобы сам объект стэк не изменился */
    Stack <Person> stack_to_copy(stack);

    for (int idx = stack_to_copy.getStackSize() - 1; idx >= 0; idx--) {
        /* Критический участок.
         * Возможны исключительные ситуации такие как пустой стэк
        */
        try {
            /* Получаем указатель  на экзэмпляр класса Person из стэка */
            Person *person = stack_to_copy.pop();

            /* Получаем данные пользователя */
            person_data = person->getLastName() + SPACE + person->getFirstName() + SPACE + person->getSecondName();

            /* Записываем полученные данные в выходной поток */
            stream << person_data;

            /* Добавляем перенос строки*/
            stream << std::endl;
        } catch (const exc::EStackEmpty& e) { // Ловим все исключения типа EStackEmpty
            /* Обработка исключений */
            std::cout << e.what() << std::endl;

            return false;
        }
    }

    /*  Добавляем индикатор конца файла*/
    stream << std::ios_base::eofbit;

    return true;
}

#endif // PERSONKEEPER_H
