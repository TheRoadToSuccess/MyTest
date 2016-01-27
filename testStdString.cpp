#include <iostream>
#include <string>
#include <stdio.h>

int main ()
{

{
    char c = '0';
    printf("char '0' c = %c, int = %d \n", c, c);
}
{
    char c = '\0';
    printf("char '_0' c = %c, int = %d \n", c, c);
}
{
    int i = 0;
    char c = (char)i;
    printf("char c = %c, int c = %d, int i = %d", c, c, i);
}

{
    std::string str ("Test string");
    std::cout << "size: " << str.size() << "\n";
    std::cout << "length: " << str.length() << "\n";
    std::cout << "capacity: " << str.capacity() << "\n";
    std::cout << "max_size: " << str.max_size() << "\n";
    std::cout << "string.c_str : " << str.c_str() << "\n";
    std::cout << "string.data: " << str.data() << "\n";
    std::cout << "========================================= " << "\n";
    std::cout << " \n ";
}

{
    std::string str ("Test string \0 hello world");
    std::cout << "size: " << str.size() << "\n";
    std::cout << "length: " << str.length() << "\n";
    std::cout << "capacity: " << str.capacity() << "\n";
    std::cout << "max_size: " << str.max_size() << "\n";
    std::cout << "string.c_str : " << str.c_str() << "\n";
    std::cout << "string.data: " << str.data() << "\n";
    std::cout << "========================================= " << "\n";
    std::cout << " \n ";
}
{
    std::string str ("Test string \0 hello world", sizeof("Test string \0 hello world"));
    std::cout << "size: " << str.size() << "\n";
    std::cout << "length: " << str.length() << "\n";
    std::cout << "capacity: " << str.capacity() << "\n";
    std::cout << "max_size: " << str.max_size() << "\n";
    std::cout << "string.c_str : " << str.c_str() << "\n";
    std::cout << "string.data: " << str.data() << "\n";
    std::cout << "========================================= " << "\n";
    std::cout << " \n ";

{
    std::string tmpstr2 (str);
    std::cout << "size: " << tmpstr2.size() << "\n";
    std::cout << "length: " << tmpstr2.length() << "\n";
    std::cout << "capacity: " << tmpstr2.capacity() << "\n";
    std::cout << "max_size: " << tmpstr2.max_size() << "\n";
    std::cout << "string.c_str : " << tmpstr2.c_str() << "\n";
    std::cout << "string.data: " << tmpstr2.data() << "\n";
    std::cout << "========================================= " << "\n";
    std::cout << " \n ";
}

{
    std::string tmpstr2 (str);
    std::cout << "tmpstr2(str)" << "\n";
    std::cout << "size: " << tmpstr2.size() << "\n";
    std::cout << "length: " << tmpstr2.length() << "\n";
    std::cout << "capacity: " << tmpstr2.capacity() << "\n";
    std::cout << "max_size: " << tmpstr2.max_size() << "\n";
    std::cout << "string.c_str : " << tmpstr2.c_str() << "\n";
    std::cout << "string.data: " << tmpstr2.data() << "\n";
    std::cout << "========================================= " << "\n";
    std::cout << " \n ";
}

{
    std::string tmpstr2 (str.c_str());
    std::cout << "tmpstr2(str.c_str())" << "\n";
    std::cout << "size: " << tmpstr2.size() << "\n";
    std::cout << "length: " << tmpstr2.length() << "\n";
    std::cout << "capacity: " << tmpstr2.capacity() << "\n";
    std::cout << "max_size: " << tmpstr2.max_size() << "\n";
    std::cout << "string.c_str : " << tmpstr2.c_str() << "\n";
    std::cout << "string.data: " << tmpstr2.data() << "\n";
    std::cout << "========================================= " << "\n";
    std::cout << " \n ";
}


{
    std::string tmpstr2 (str.c_str(), str.size());
    std::cout << "tmpstr2(str.c_str(), size)" << "\n";
    std::cout << "size: " << tmpstr2.size() << "\n";
    std::cout << "length: " << tmpstr2.length() << "\n";
    std::cout << "capacity: " << tmpstr2.capacity() << "\n";
    std::cout << "max_size: " << tmpstr2.max_size() << "\n";
    std::cout << "string.c_str : " << tmpstr2.c_str() << "\n";
    std::cout << "string.data: " << tmpstr2.data() << "\n";
    std::cout << "========================================= " << "\n";
    std::cout << " \n ";
}
{
    std::string tmpstr2 (str.data());
    std::cout << "tmpstr2(str)" << "\n";
    std::cout << "size: " << tmpstr2.size() << "\n";
    std::cout << "length: " << tmpstr2.length() << "\n";
    std::cout << "capacity: " << tmpstr2.capacity() << "\n";
    std::cout << "max_size: " << tmpstr2.max_size() << "\n";
    std::cout << "string.c_str : " << tmpstr2.c_str() << "\n";
    std::cout << "string.data: " << tmpstr2.data() << "\n";
    std::cout << "========================================= " << "\n";
    std::cout << " \n ";
}

{
    std::string tmpstr2 (str.data(), str.size());
    std::cout << "tmpstr2(str)" << "\n";
    std::cout << "size: " << tmpstr2.size() << "\n";
    std::cout << "length: " << tmpstr2.length() << "\n";
    std::cout << "capacity: " << tmpstr2.capacity() << "\n";
    std::cout << "max_size: " << tmpstr2.max_size() << "\n";
    std::cout << "string.c_str : " << tmpstr2.c_str() << "\n";
    std::cout << "string.data: " << tmpstr2.data() << "\n";
    std::cout << "========================================= " << "\n";
    std::cout << " \n ";
}





}


{
    std::string str ("Test string \0 hello world");
    std::cout << "size: " << str.size() << "\n";
    std::cout << "length: " << str.length() << "\n";
    std::cout << "capacity: " << str.capacity() << "\n";
    std::cout << "max_size: " << str.max_size() << "\n";
    std::cout << "string.c_str : " << str.c_str() << "\n";
    std::cout << "string.data: " << str.data() << "\n";
    std::cout << "========================================= " << "\n";
    std::cout << " \n ";
}
  return 0;
}
