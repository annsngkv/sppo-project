#ifndef PERSON_H
#define PERSON_H

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

/*
 * Конструктор по умолчанию
*/
Person::Person()
{
   key = 0;
   last_name = "NoName";
   first_name = "NoName";
   second_name = "NoName";
}

/*
 * Конструктор с параметрами, заполняющий все приватные член-данные класса
 *
 * arg long key
 * arg const string last_name
 * arg const string first_name
 * arf const string second_name
*/
Person::Person(long init_key, const std::string& init_last_name , const std::string& init_first_name, const std::string& init_second_name)
{
    key = init_key;
    last_name = init_last_name;
    first_name = init_first_name;
    second_name = init_second_name;
}

/*
 * Конструктор копирования
*/
Person::Person(const Person &person_to_copy)
{
    key = person_to_copy.key;
    last_name = person_to_copy.last_name;
    first_name = person_to_copy.first_name;
    second_name = person_to_copy.second_name;
}

/*
 * Функция для установки фамилии человеку
 *
 * arg const string& new_last_name
*/
void Person::setLastName(const std::string &new_last_name)
{
    last_name = new_last_name;
}

/*
 * Функция для установки имени человеку
 *
 * arg const string& new_first_name
*/
void Person::setFirstame(const std::string &new_first_name)
{
    first_name = new_first_name;
}

/*
 * Функция для установки отчества человеку
 *
 * arg const string& new_second_name
*/
void Person::setSecondName(const std::string &new_second_name)
{
    second_name = new_second_name;
}

#endif // PERSON_H
