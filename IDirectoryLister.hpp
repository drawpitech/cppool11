/*
** EPITECH PROJECT, 2024
** ppool11
** File description:
** IDirectoryLister
*/

#pragma once

#include <string>

class IDirectoryLister {
   public:
    virtual ~IDirectoryLister() = default;

    virtual bool open(const std::string& path, bool hidden) = 0;
    virtual std::string get() = 0;

    class OpenFailureException : public std::exception {};
    class NoMoreFileException : public std::exception {};
};
