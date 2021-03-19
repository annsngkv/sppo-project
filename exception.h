#ifndef EXCEPTION_H
#define EXCEPTION_H

namespace exc {
    #include <string.h>

    class EStackException
    {
        private:
            char* message; //диагностическое сообщение

        public:
            EStackException(const char* arg_message); //конструктор с параметрами
            EStackException(const EStackException& arg); //конструктор копирования
            ~EStackException(); //деструктор
            const char* what() const { return message;} //функция вывода диагастического сообщения
    };

    /*
     * конструктор с параметром класса EStackException
     * argument: char*
    */
    EStackException::EStackException(const char* arg_message)
    {
        message = new char[strlen(arg_message)+1];

        strcpy(message, arg_message);
    }

    /*
     * конструктор копирования класса EStackException
    */
    EStackException::EStackException(const EStackException& arg)
    {
        message = new char[strlen(arg.message)+1];
        strcpy(message, arg.message);
    }

    /*
     * деструктор класса EStackException
    */
    EStackException::~EStackException()
    {
        delete message;
    }

    /*
     * наследуемся от класса EStackException
    */
    class EStackEmpty : public EStackException
    {
        public:

            /*
             * конструктор с параметром класса EStackEmpty вызывает конструктор с параметром класса EStackException
             * и передает в него arg
             *
             * argument: char*
            */
            explicit EStackEmpty(const char* arg) : EStackException(arg) {}

            /*
             * конструктор копирования класса EStackEmpty вызывает конструктор копирования класса EStackException
            */
            EStackEmpty(const  EStackEmpty& arg) : EStackException(arg) {}
    };
}

#endif // EXCEPTION_H
