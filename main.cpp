#include <QCoreApplication>
#include "stack.h"
#include <iostream>
#include "exception.h"
#include "person.h"
#include "person-keeper.h"
#include <fstream>
#include <experimental/filesystem>

#define PERSONS_FILE_PATH "/../sppo-project/persons.txt"
#define FILE_TO_COPY_PATH "/../sppo-project/file_to_copy.txt"

namespace fs = std::experimental::filesystem;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* Открываем файл persons.txt для чтения и ассоциируем его с объектом класса ifstream - persons */
    std::ifstream persons(fs::current_path().string() + PERSONS_FILE_PATH);

    /* Открываем файл file_to_copy на запись и ассоциируем его с объектом класса ofstream - file_to_copy */
    std::ofstream file_to_copy(fs::current_path().string() + FILE_TO_COPY_PATH);

    /* Считываем пользователей из файла persons.txt и помещаем их в стэк */
    PersonKeeper::Instance().readPersons(persons);

    /* Записываем в файл file_to_copy.txt из стека информацию о людя */
    PersonKeeper::Instance().writePersons(file_to_copy);

    return a.exec();
}
