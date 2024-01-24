/*
** EPITECH PROJECT, 2024
** ppool11
** File description:
** List
*/

#pragma once

#include <vector>

#include "IObject.hpp"

struct List {
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

    class InvalidOperationException : public std::exception {};

   private:
    std::vector<IObject *> _content;
};
