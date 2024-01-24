/*
** EPITECH PROJECT, 2024
** ppool11
** File description:
** IDirectoryLister
*/

#pragma once

#include <dirent.h>

#include <cstring>

#include "IDirectoryLister.hpp"

class SafeDirectoryLister : public IDirectoryLister {
   public:
    SafeDirectoryLister();
    SafeDirectoryLister(const std::string &path, bool hidden);
    ~SafeDirectoryLister() override;

    bool open(const std::string &path, bool hidden) override;
    std::string get() override;

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

   private:
    DIR *_dir = nullptr;
    bool _hidden = false;
};
