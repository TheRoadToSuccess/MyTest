#include <iostream>
#include <stdio.h>

using namespace std;

// terminal case
void print(const char *s)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                return;
                // throw std::runtime_error("invalid format string: missing arguments");
            }
        }
        std::cout << *s++;
    }
}

// general case
template<typename T, typename... Args>
void print(const char *s, T value, Args... args)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                std::cout << value;
                s += 2; // this only works on 2 characters format strings ( %d, %f, etc ). Fails miserably with %5.4f
                print(s, args...); // call even when *s == 0 to detect extra arguments
                return;
            }
        }
        std::cout << *s++;
    }
}




int main ()
{
    print("123%s, %d", "1234", 3);
    return 0;
}
