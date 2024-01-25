/*
** EPITECH PROJECT, 2024
** ppool11
** File description:
** List
*/

#pragma once

#include <vector>

#include "IObject.hpp"

struct List
{
   public:
    ~List();

    bool empty() const;
    std::size_t size() const;
    IObject*& front();
    IObject* front() const;
    IObject*& back();
    IObject* back() const;
    void pushBack(IObject* obj);
    void pushFront(IObject* obj);
    void popFront();
    void popBack();
    void clear();
    void forEach(void (*function)(IObject*));

    class InvalidOperationException : public std::exception
    {};

    class Iterator
    {
       public:
        Iterator(const List& list, std::size_t index);

        IObject* operator*() const;
        Iterator& operator++();
        bool operator==(const Iterator& it) const;
        bool operator!=(const Iterator& it) const;

        class OutOfRangeException : public std::exception
        {};

        std::size_t getIndex() const;
        const List& getList() const;

       private:
        const List& _list;
        std::size_t _idx;
    };

    List::Iterator begin() const;
    List::Iterator end() const;
    List::Iterator erase(List::Iterator it);
    List::Iterator insert(List::Iterator it, IObject* obj);

    class InvalidIteratorException : public std::exception
    {};

   private:
    std::vector<IObject*> _content;
};
