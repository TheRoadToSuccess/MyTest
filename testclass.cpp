#include <iostream>
#include <string>
#include <stdio.h>
#include <typeinfo>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

class base 
{
public:
    virtual void onCreate() = 0; 
};

class subbase :public base
{
public:
    subbase() {
        printf("constructor subbase \n");
        create();
    }

private:
    void onCreate()
    {
        printf("subbase::onCreate\n");
        create();
    }

public:
    virtual void create() 
    {
        printf("subbase::create\n");
    }
};

class subsubbase :public subbase
{
public:

    // virtual void onCreate()
    // {
    //     printf("subsubbase::onCreate\n");
    //     create();
    // }
  
    virtual void create()
    {
        printf("subsubbase::create\n");
        // subbase::create();
    } 
};



int main ()
{
    printf("%s\n",getenv("LD_PRELOAD"));

/*
subsubbase sub;

    printf("test \n");
    base *pa1 = new subsubbase();
    base *pa2 = new subbase();
    pa1->onCreate();
    // a1.onCreate();
    // a1.create();
    printf("base *pa1 = new subsubbase name = %s \n", typeid(*pa1).name());
    printf("base *pa2 = new subbase name = %s \n", typeid(*pa2).name());
    printf("base name = %s \n", typeid(base).name());
    printf("is same = %d \n", typeid(*pa1) == typeid(*pa2) ? 1 : 0);   
    printf("is same = %d \n", typeid(*pa1) == typeid(base) ? 1 : 0);   
    printf("is same = %d \n", typeid(*pa1) == typeid(base) ? 1 : 0);   

    printf("is base = %d \n", typeid(base).before(typeid(subbase)) ? 1 : 0);   
    printf("is base = %d \n", typeid(base).before(typeid(subsubbase)) ? 1 : 0);   
    printf("is base = %d \n", typeid(subbase).before(typeid(subsubbase)) ? 1 : 0);   
    printf("\n");
    
    printf("is base = %d \n", typeid(subbase).before(typeid(base)) ? 1 : 0);   
    printf("is base = %d \n", typeid(subsubbase).before(typeid(base)) ? 1 : 0);   
    printf("is base = %d \n", typeid(subsubbase).before(typeid(subbase)) ? 1 : 0);   
    printf("\n");

    printf("is base = %d \n", typeid(base).before(typeid(*pa1)) ? 1 : 0);   
    printf("is base = %d \n", typeid(subbase).before(typeid(*pa1)) ? 1 : 0);   
    printf("is base = %d \n", typeid(base).before(typeid(*pa2)) ? 1 : 0);   

    printf("\n");
    printf("is base 4 = %d \n", typeid(*pa1).before(typeid(base)) ? 1 : 0);   
    printf("is base 4 = %d \n", typeid(*pa1).before(typeid(subbase)) ? 1 : 0);   
    printf("is base 4 = %d \n", typeid(*pa2).before(typeid(base)) ? 1 : 0);   

    void *pv1 = new subsubbase();
    void *pv2 = new subbase();
    printf("void *pa1 = new subsubbase name = %s \n", typeid(*pa1).name());
    printf("void *pa2 = new subbase name = %s \n", typeid(*pa2).name());
    printf("is same = %d \n", typeid(*pa1) == typeid(*pa2) ? 1 : 0);   
    // printf("subsubbase size = %d\n", sizeof(subsubbase));
*/
    return 0;
}
