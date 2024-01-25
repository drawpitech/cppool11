/*
** EPITECH PROJECT, 2024
** ppool11
** File description:
** List
*/

#include "List.hpp"

List::~List()
{
    clear();
}

bool List::empty() const
{
    return _content.empty();
}
std::size_t List::size() const
{
    return _content.size();
}

IObject*& List::front()
{
    if (empty())
        throw List::InvalidOperationException();
    return _content.front();
}
IObject* List::front() const
{
    if (empty())
        throw List::InvalidOperationException();
    return _content.front();
}
IObject*& List::back()
{
    if (empty())
        throw List::InvalidOperationException();
    return _content.back();
}
IObject* List::back() const
{
    if (empty())
        throw List::InvalidOperationException();
    return _content.back();
}

void List::pushBack(IObject* obj)
{
    _content.push_back(obj);
}
void List::pushFront(IObject* obj)
{
    _content.insert(_content.begin(), obj);
}

void List::popFront()
{
    if (empty())
        throw List::InvalidOperationException();
    delete front();
    _content.erase(_content.begin());
}
void List::popBack()
{
    if (empty())
        throw List::InvalidOperationException();
    delete back();
    _content.pop_back();
}
void List::clear()
{
    forEach([](IObject* obj) { delete obj; });
    _content.clear();
}

void List::forEach(void (*function)(IObject*))
{
    for (auto& elem : _content)
        function(elem);
}
