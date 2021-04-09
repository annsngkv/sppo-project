#ifndef STACK_H
#define STACK_H

#include "exception.h"
#include <iostream>

template <class T>

class Stack
{
    private:
        /* Массив объектов */
        T* stack;

        /* Дефолтный размер стэка */
        int max_size = 1024;

        /* Индекс верхнего элемента массива */
        int top_idx = 0;

    public:
        /* Конструктор по умолчанию */
        Stack();

        /* Конструктор с параметром */
        Stack(int size);

        /* Конструктор копирования */
        Stack(const Stack<T>& stack_to_copy);

        /* Деструктор */
        ~Stack();

        /* Функция добавления объекта в стэк */
        void push(T& obj);

        /* Функция извлечения объекта из стэка */
        T& pop();

        /* Функция получения размера стэка */
        int getStackSize();
};

/*
 * Конструктор по умолчанию
*/
template <class T>
Stack<T>::Stack()
{
    stack = new T[max_size];
}

/*
 * Конструктор с пармаетром, который является размером стэка
 *
 * arg int
*/
template <class T>
Stack<T>::Stack(int size)
{
    max_size = size;
    stack = new T[size];
}

/*
 * Конструктор копирования
*/
template <class T>
Stack<T>::Stack(const Stack<T> &stack_to_copy)
{
    max_size = stack_to_copy.max_size;
    top_idx = stack_to_copy.top_idx;
    stack = new T[max_size];

    for (int idx = 0; idx < top_idx; idx ++) {
        stack[idx] = stack_to_copy.stack[idx];
    }
}

/*
 * Деструктор класса
*/
template <class T>
Stack<T>::~Stack()
{
    delete [] stack;
    stack = NULL;
}

/*
 * Функция добавления элемента в стэк, которая в случае добавления элемента в полный стэк
 * будет генеририровать исключение типа EStackOverflow
 *
 * arg T&(ссылка на объект)
*/
template <class T>
void Stack<T>::push(T& obj)
{
    if (top_idx >= max_size) {
        throw exc::EStackOverflow("Ошибка: cтек переполнен"); // генерируем исключение типа EStackOverflow, если стэк переполнен
    }

    stack[top_idx] = obj;
    top_idx++;   
}

/*
 * Функция извлечения элемента из стэка, которая в случае попытки извлечь элемент из пустого стэка
 * будет генеририровать исключение типа EStackEmpty
 *
 * return T& (ссылка на объект)
*/
template <class T>
T& Stack<T>::pop()
{
     top_idx--;

     if (top_idx < 0) {
         throw exc::EStackEmpty("Ошибка: cтек пуст"); // генерируем исключение типа EStackEmpty, если стэк пуст
     }

     return stack[top_idx];
}

/*
 * Функция, возвращающая размерность стэка
 *
 * return int
*/
template <class T>
int Stack<T>::getStackSize()
{
    return max_size;
}

#endif // STACK_H
