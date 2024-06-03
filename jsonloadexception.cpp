#include "JsonLoadException.h"

JsonLoadException::JsonLoadException(const std::string& msg) : message(msg) {}

const char* JsonLoadException::what() const noexcept {
    return message.c_str();
}
