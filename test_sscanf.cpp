#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    char buf[20][128] = {
                         "",
                         "123",
                         "123/",
                         "123/456",
                         "123/456/",
                         "123/456/234/",
                         "123#/456/234#",
                         "123/456#/234#",
                         "123/456/234/#",
                         "123/456/234##"
                         "12a",
                         "12a/",
                         "12a/4A6",
                         "12a/4A6/",
                         "12A/a56/23a/",
                         "1a3#/4A6/2a4#",
                         "12a/4A6#/2a4#",
                         "12A/4a6/z34/#",
                         "12a:/4A6/a34##",
                         "123//#",
                         "123/ / #",
    };
    char topic[128] = { 0 };
    char first[128] = { 0 };
    char second[128] = { 0 };
    char third[128] = { 0 };
    int ret = 0;

    for (int i = 0; i < 20; ++i)
    {
        memset(topic, 0, sizeof(topic));
        memset(first, 0, sizeof(first));
        memset(second, 0, sizeof(second));
        memset(third, 0, sizeof(third));
        ret = sscanf(buf[i], "%[^/]/%[^/]/%[^#]%1[#]*", topic, first, second, third);
        printf("buf[%d] = %s, ret = %d, topic = %s, first = %s, second = %s, third = %s\n", i, buf[i], ret, topic,
                first, second, third);
    }
    for (int i = 0; i < 20; ++i)
    {
        memset(topic, 0, sizeof(topic));
        memset(first, 0, sizeof(first));
        memset(second, 0, sizeof(second));
        memset(third, 0, sizeof(third));
        ret = sscanf(buf[i], "%[0-9a-zA-Z]/%[0-9a-zA-Z]/%[0-9a-zA-Z]%1[#]*", topic, first, second, third);
        printf("buf[%d] = %s, ret = %d, topic = %s, first = %s, second = %s, third = %s\n", i, buf[i], ret, topic,
                first, second, third);
    }
    return 0;
}

