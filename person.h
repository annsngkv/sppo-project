#ifndef PERSON_H
#define PERSON_H

class Person

{
    private:
        long key;//id человека
        std::string last_name;//фамилия
        std::string first_name;//имя
        std::string second_name;//отчество

    public:
        Person();//конструктор класса по умолчанию
        Person(long key, const std::string&, const std::string&, const std::string&);//конструктор класса с параметрами
        ~Person();//деструктор класса
        Person(const Person&);//конструктор копирования
        const std::string& getLastName() const { return last_name; }//функция получения фамилии человека
        const std::string& getFirstName() const { return first_name; }//функция получения имени человека
        const std::string& getSecondName() const { return second_name; }//функция получения отчества человека
        void setLastName(const std::string&);//функция установки фамилии для человека
        void setFirstame(const std::string&);//функция установки имени для человека
        void setSecondName(const std::string&);//функция установки отчества для человека
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

/* Деструктор*/
Person::~Person(){}

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
