/*
** EPITECH PROJECT, 2024
** ppool11
** File description:
** SafeDirectoryLister
*/

#include "SafeDirectoryLister.hpp"

#include <sys/types.h>

SafeDirectoryLister::SafeDirectoryLister() = default;

SafeDirectoryLister::SafeDirectoryLister(const std::string &path, bool hidden) {
    open(path, hidden);
}

SafeDirectoryLister::~SafeDirectoryLister() {
    if (_dir != nullptr)
        closedir(_dir);
}

bool SafeDirectoryLister::open(const std::string &path, bool hidden) {
    if (_dir != nullptr)
        closedir(_dir);
    _hidden = hidden;
    _dir = opendir(path.c_str());
    if (_dir == nullptr)
        throw OpenFailureException();
    return true;
}

std::string SafeDirectoryLister::get() {
    if (_dir == nullptr)
        return "";
    struct dirent *ent = readdir(_dir);
    if (ent == nullptr || (char *)ent->d_name == nullptr)
        throw NoMoreFileException();
    if (ent->d_name[0] == '.' && !_hidden)
        return get();
    return (char *)ent->d_name;
}
