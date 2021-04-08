#ifndef EXCEPTION_H
#define EXCEPTION_H

namespace exc {
    class EStackException
    {
        private:
            /* Диагностическое сообщение */
            std::string message; //

        public:
            /* Конструктор с параметрами */
            EStackException(const std::string& arg_message) { message = arg_message; }

            /* Конструктор копирования */
            EStackException(const EStackException& arg) {  message = arg.message; }

            /* Деструктор */
            ~EStackException() {;}

            /* Функция вывода диагастического сообщения */
            const std::string& what() const { return message;}
    };

    /*
     * Наследование от класса EStackException
    */
    class EStackEmpty : public EStackException
    {
        public:

            /*
             * Конструктор с параметром класса EStackEmpty вызывает конструктор с параметром класса EStackException
             * и передает в него arg
             *
             * arg const string&
            */
            explicit EStackEmpty(const std::string arg) : EStackException(arg) {}

            /*
             * конструктор копирования класса EStackEmpty вызывает конструктор копирования класса EStackException
            */
            EStackEmpty(const  EStackEmpty& arg) : EStackException(arg) {}
    };

    /*
     * Наследование от класса EStackException
    */
    class EStackOverflow : public EStackException
    {
        public:

            /*
             * Конструктор с параметром класса EStackOverflow вызывает конструктор с параметром класса EStackException
             * и передает в него arg
             *
             * arg const string&
            */
            explicit EStackOverflow(const std::string& arg) : EStackException(arg) {}

            /*
             * Конструктор копирования класса EStackOverflow вызывает конструктор копирования класса EStackException
            */
            EStackOverflow(const  EStackOverflow& arg) : EStackException(arg) {}
    };
}

#endif // EXCEPTION_H
