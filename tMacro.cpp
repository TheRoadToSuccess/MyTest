#include <stdio.h>
#include <stdarg.h>

#define debug1(fmt, arg...) printf(fmt, ##arg)

#define debug2(...) printf(__VA_ARGS__)

// #define debug3(fmt, ...) printf(fmt, __VA_ARGS__)
#define debug3(fmt,...)  printf(fmt,__VA_ARGS__)

#define debug4(format, ...) printf(format, ## __VA_ARGS__)

#define debug5(X, ...) printf("Message" #X ": " __VA_ARGS__)
#define debug6(X, ...) printf(#X ": " __VA_ARGS__)
#define debug7(TAG, ...) printf( TAG ", " __VA_ARGS__)

int main ()
{
    debug1("debug1\n");
    debug1("%s, %d \n", "string", 10);

    debug2("debug2\n");
    debug2("%s, %d \n", "string", 10);

    // debug3("debug3\n");   // compile error.
    debug3("%s, %d \n", "string", 10);

    debug4("debug4\n");
    debug4("%s, %d \n", "string", 10);

    debug5("debug5\n");
    // debug5("%s, %d \n", "string", 10);
    debug5("TAG", "%s, %d \n", "string", 10);

    debug7("debug");
    // debug5("%s, %d \n", "string", 10);
    printf("\n\n");
    debug7("TAG", "%s, %d \n", "string", 10);
    return 0;
}
