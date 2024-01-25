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

List::Iterator List::begin() const
{
    return List::Iterator{*this, 0};
}

List::Iterator List::end() const
{
    return List::Iterator{*this, size()};
}

List::Iterator List::erase(List::Iterator it)
{
    if (&it.getList() != this)
        throw List::InvalidIteratorException();
    std::size_t idx = it.getIndex();
    if (idx >= size())
        throw List::InvalidIteratorException();
    delete *it;
    _content.erase(_content.begin() + (long)it.getIndex());
    return it;
}

List::Iterator List::insert(List::Iterator it, IObject* obj)
{
    if (&it.getList() != this)
        throw List::InvalidIteratorException();
    std::size_t idx = it.getIndex();
    if (idx > size())
        throw List::InvalidIteratorException();
    _content.insert(_content.begin() + (long)it.getIndex(), obj);
    return it;
}

List::Iterator::Iterator(const List& list, std::size_t index)
    : _list(list), _idx(index)
{
}

IObject* List::Iterator::operator*() const
{
    if (_idx >= _list.size())
        throw List::Iterator::OutOfRangeException();
    return _list._content[_idx];
}

List::Iterator& List::Iterator::operator++()
{
    _idx += 1;
    return *this;
}

bool List::Iterator::operator==(const Iterator& it) const
{
    return _idx == it._idx && &_list == &it._list;
}

bool List::Iterator::operator!=(const Iterator& it) const
{
    return !(*this == it);
}

std::size_t List::Iterator::getIndex() const
{
    return _idx;
}

const List& List::Iterator::getList() const
{
    return _list;
}
