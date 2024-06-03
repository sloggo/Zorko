#ifndef JSONLOADEXCEPTION_H
#define JSONLOADEXCEPTION_H
#include <exception>
#include <string>

class JsonLoadException : public std::exception {
private:
    std::string message;

public:
    explicit JsonLoadException(const std::string& msg);

    virtual const char* what() const noexcept override;
};


#endif // JSONLOADEXCEPTION_H
