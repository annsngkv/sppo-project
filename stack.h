#ifndef STACK_H
#define STACK_H

#include "exception.h"
#include <iostream>

template <class T>

class Stack
{
    private:
            T** stack; //массив указателей на объекты
            int max_size = 1024; //дефолтный размер стэка
            int top_idx = 0; //индекс верхнего элемента массива
    public:
        Stack(); //конструктор по умолчанию
        Stack(int size); //конструктор с параметром
        Stack(const Stack& stack_to_copy); //конструктор копирования
        ~Stack(); //деструктор
        void push(T* obj); //функция добавления объекта в стэк
        T* pop(); //функция извлечения объекта из стэка
        int getStackSize(); //функция получения размера стэка
};

/*
 * конструктор по умолчанию
*/
template <class T>
Stack<T>::Stack()
{
    stack = new T*[max_size];
}

/*
 * конструктор с пармаетром, который является размером стэка
 *
 * argument: int
*/
template <class T>
Stack<T>::Stack(int size)
{
    max_size = size;
    stack = new T*[size];
}

/*
 * конструктор копирования
*/
template <class T>
Stack<T>::Stack(const Stack& stack_to_copy)
{
    max_size = stack_to_copy.max_size;
    stack = new T*[max_size];

    for (int idx = 0; idx < max_size; idx ++) {
        stack[idx] = stack_to_copy.stack[idx];
    }
}

/*
 * деструктор класса
*/
template <class T>
Stack<T>::~Stack()
{
    delete [] stack;
    stack = NULL;
}

/*
 * функция добавления элемента в стэк, которая в случае добавления элемента в полный стэк
 * будет генеририровать исключение типа EStackOverflow
 *
 * argument: T* (указатель на объект)
*/
template <class T>
void Stack<T>::push(T* obj)
{
    if (top_idx >= max_size) {
        throw exc::EStackOverflow("Ошибка: cтек переполнен"); // генерируем исключение типа EStackOverflow, если стэк переполнен
    }

    stack[top_idx] = obj;
    top_idx++;
}

/*
 * функция извлечения элемента из стэка, которая в случае попытки извлечь элемент из пустого стэка
 * будет генеририровать исключение типа EStackEmpty
 *
 * return: T* (указатель на объект)
*/
template <class T>
T* Stack<T>::pop()
{
     top_idx--;

     if (top_idx < 0) {
         throw exc::EStackEmpty("Ошибка: cтек пуст"); // генерируем исключение типа EStackEmpty, если стэк пуст
     }

     return stack[top_idx];
}

/*
 * функция, возвращающая размерность стэка
 *
 * return: int
*/
template <class T>
int Stack<T>::getStackSize()
{
    return max_size;
}

#endif // STACK_H
