#include "person-keeper.h"


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
    std::string delimiter = " ";

    for (int idx = 0; idx < stack.getStackSize(); idx++) {
        /* Критический участок.
         * Возможны исключительные ситуации такие как конец файла и переполнение стэка
        */
        try {
            /* Считываем информацию из входного потока в строку */
            std::string new_string;
            std::getline(stream, new_string);

            /*
             * Выполняем разделение строки по пробелу, для того
             * чтобы мы могли отследить, что файл пришел с некорректными данными,
             * а именно, что в какой-то строке указана не вся инфромация о человеке,
             * если все успешно, то записываем каждую часть в массив person_data
            */
            size_t pos = new_string.find(delimiter);
            int separete_idx;

            for (separete_idx = 0; separete_idx < 2 && pos != std::string::npos; separete_idx++) {
                person_data[separete_idx] = new_string.substr(0, pos);
                new_string.erase(0, pos + delimiter.length());
                pos = new_string.find(delimiter);
            }

            if (separete_idx == 1 || separete_idx == 0) {// Генерируем исключение, если в строке 1 или 2 слова
                throw std::string("Данные из файла некорректны!");
            }

            person_data[separete_idx] = new_string.substr(0, pos);
            new_string.erase(0, pos + delimiter.length());

            /* Создаем экзэмпляр класса Person на основе полуенных данных и пушим его в стэк */
            Person person(idx, person_data[0], person_data[1], person_data[2]);
            stack.push(person);
        } catch (const std::ios_base::failure&) { // Ловим все исключения типа failure
            /* Обработка исключений */
            std::cerr << "Конец файла!" << std::endl;
            stream.exceptions(s);
            // Очищаем память
            delete [] person_data;

            return false;
        } catch (const exc::EStackOverflow& e) { // Ловим все исключения типа EStackOverflow
            /* Обработка исключений */
            std::cerr << e.what() << std::endl;
            // Очищаем память
            delete [] person_data;

            return false;
        }
    }

    // Очищаем память
    delete [] person_data;

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
            /* Получаем экзэмпляр класса Person из стэка */
            Person person = stack_to_copy.pop();

            /* Получаем данные пользователя */
            person_data = person.getLastName() + SPACE + person.getFirstName() + SPACE + person.getSecondName();

            /* Записываем полученные данные в выходной поток */
            stream << person_data;

            /* Добавляем перенос строки*/
            stream << std::endl;
        } catch (const exc::EStackEmpty& e) { // Ловим все исключения типа EStackEmpty
            /* Обработка исключений */
            std::cerr << e.what() << std::endl;
            /*  Добавляем индикатор конца файла*/
            stream << std::ios_base::eofbit;

            return false;
        }
    }

    /*  Добавляем индикатор конца файла*/
    stream << std::ios_base::eofbit;

    return true;
}
