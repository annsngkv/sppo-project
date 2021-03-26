#include <QCoreApplication>
#include "stack.h"
#include <iostream>
#include "exception.h"

/*функция, рисующая разделяющую линию, между выводами программы*/
void drawSeparatorLine()
{
    int charCount = 30;
    std::cout << std::string(charCount, '-') << std::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int stack_size; //объявляем переменную которая будет отвечать за размерность стэка.

    std::cout << "Введите размерность стэка: ";
    std::cin >> stack_size; //инициализируем переменную, отвечающую за размерность стэка

    Stack <int> stack(stack_size); //создаем объект класса Stack с помощью конструктора с параметром;

    std::cout << "Размер стека: " << stack.getStackSize() << std::endl; //получаем размерность нашего стэка.
    drawSeparatorLine();

    //выполняем заполнение стэка
    try {
        for (int idx = 0; idx < stack_size; idx++) {
            stack.push(new int(idx));
        }
    } catch (const exc::EStackOverflow& e) {// ловим все исключения типа EStackOverflow
        std::cout << e.what() << std::endl; // обработка исключений
        drawSeparatorLine();
    }

    try {
        for (int idx = stack_size-1; idx >= 0; idx--) {
            std::cout << "Стэк вернул: " << stack.pop() << std::endl;
        }
    } catch (const exc::EStackEmpty& e) {// ловим все исключения типа EStackEmpty
        drawSeparatorLine();
        std::cout << e.what() << std::endl; // обработка исключений
        drawSeparatorLine();
    }

    return a.exec();
}
