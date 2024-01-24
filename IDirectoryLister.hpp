/*
** EPITECH PROJECT, 2024
** ppool11
** File description:
** IDirectoryLister
*/

#pragma once

#include <cstring>
#include <string>

class IDirectoryLister {
   public:
    virtual ~IDirectoryLister() = default;

    virtual bool open(const std::string &path, bool hidden) = 0;
    virtual std::string get() = 0;

    class OpenFailureException : public std::exception {
       public:
        [[nodiscard]] const char *what() const noexcept override {
            return strerror(errno);
        }
    };
    class NoMoreFileException : public std::exception {
       public:
        [[nodiscard]] const char *what() const noexcept override {
            return "End of stream";
        }
    };
};
