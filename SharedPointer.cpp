/*
** EPITECH PROJECT, 2024
** ppool11
** File description:
** IDirectoryLister
*/

#include "SharedPointer.hpp"

#include <utility>

SharedPointer::SharedPointer() = default;
SharedPointer::SharedPointer(IObject *ptr) : _ptr(ptr)
{
    incrementCount();
}
SharedPointer::SharedPointer(const SharedPointer &other)
    : _ptr(other._ptr), _count(other._count)
{
    incrementCount();
}

SharedPointer::~SharedPointer()
{
    decrementCount();
}

void SharedPointer::swap(SharedPointer &other) noexcept
{
    std::swap(_ptr, other._ptr);
    std::swap(_count, other._count);
}
void SharedPointer::reset(IObject *ptr) noexcept
{
    decrementCount();
    _ptr = ptr;
    incrementCount();
}

std::size_t SharedPointer::use_count() const
{
    return (_count != nullptr) ? *_count : 0;
}

IObject *SharedPointer::operator->() const
{
    return _ptr;
}
IObject &SharedPointer::operator*() const
{
    return *_ptr;
}
SharedPointer &SharedPointer::operator=(IObject *ptr)
{
    decrementCount();
    _ptr = ptr;
    incrementCount();
    return *this;
}
SharedPointer &SharedPointer::operator=(const SharedPointer &other)
{
    decrementCount();
    _count = other._count;
    _ptr = other._ptr;
    incrementCount();
    return *this;
}

void SharedPointer::incrementCount()
{
    if (_ptr == nullptr)
        return;
    if (_count == nullptr)
        _count = new std::size_t(1);
    else
        *_count += 1;
}
void SharedPointer::decrementCount()
{
    if (_count == nullptr)
        return;
    *_count -= 1;
    if (*_count == 0) {
        delete _ptr;
        delete _count;
    }
    _count = nullptr;
    _ptr = nullptr;
}
