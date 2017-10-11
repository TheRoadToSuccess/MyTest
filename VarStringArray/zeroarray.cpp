#include <iostream>
#include <string>
#include <stdio.h>
#include <typeinfo>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

#define node_to_item(node, container, member) \
    (container *) (((char*) (node)) - offsetof(container, member))

struct pkt {
    int pk_type;
    int tag;
    int magic_num;
//    int a;
//    char data[];  // <-------- what does this mean ???     12 | 0 4 8 12
//    char data[0];  // <-------- what does this mean ???    12 | 0 4 8 12
//    char data[1];  // <-------- what does this mean ???    16 | 0 4 8 12
//    char *data[];  // <-------- what does this mean ???    16 | 0 4 8 16  [12 - 16] free
//    char *data[0];  // <-------- what does this mean ???   16 | 0 4 8 16  [12 - 16] free
//    char *data[1];  // <-------- what does this mean ???     24 | 0 4 8 16  [12 - 16] free
};

typedef struct pkt p_t;
int main(void)
{
    printf("size of char * = %ld \n", sizeof(char*));  // 8
    p_t pt;
    printf("size of pkt = %ld \n", sizeof(pkt));
    printf("size of pt = %ld \n", sizeof(pt));
    printf("addr pt = %ld \n", &pt);
    printf("addr pt.pk_type = %ld \n", &pt.pk_type);
    printf("addr pt.tag = %ld \n", &pt.tag);
    printf("addr pt.magic_num = %ld \n", &pt.magic_num);
    printf("addr pt.data = %ld \n", &pt.data);
    printf("addr pt.data = %ld \n", pt.data);

    printf("offsetof(p_t, pk_type) = %ld \n", offsetof(p_t, pk_type));    
    printf("offsetof(p_t, tag) = %ld \n", offsetof(p_t, tag));    
    printf("offsetof(p_t, magic_num) = %ld \n", offsetof(p_t, magic_num));    
    printf("offsetof(p_t, data) = %ld \n", offsetof(p_t, data));    


    printf("node_to_item(pt.pk_type, p_t, pk_type) = %ld \n", node_to_item(&pt.pk_type, p_t, pk_type));    
    printf("node_to_item(pt.tag, p_t, tag) = %ld \n", node_to_item(&pt.tag, p_t, tag));    
    printf("node_to_item(pt.magic_num, p_t, magic_num) = %ld \n", node_to_item(&pt.magic_num, p_t, magic_num));    
    printf("node_to_item(pt.data, p_t, data) = %ld \n", node_to_item(&pt.data, p_t, data));    
    printf("node_to_item(pt.data, p_t, data) = %ld \n", node_to_item(pt.data, p_t, data));    

    return 0;
}

#if 0
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
    printf("is same = %ld \n", typeid(*pa1) == typeid(*pa2) ? 1 : 0);   
    printf("is same = %ld \n", typeid(*pa1) == typeid(base) ? 1 : 0);   
    printf("is same = %ld \n", typeid(*pa1) == typeid(base) ? 1 : 0);   

    printf("is base = %ld \n", typeid(base).before(typeid(subbase)) ? 1 : 0);   
    printf("is base = %ld \n", typeid(base).before(typeid(subsubbase)) ? 1 : 0);   
    printf("is base = %ld \n", typeid(subbase).before(typeid(subsubbase)) ? 1 : 0);   
    printf("\n");
    
    printf("is base = %ld \n", typeid(subbase).before(typeid(base)) ? 1 : 0);   
    printf("is base = %ld \n", typeid(subsubbase).before(typeid(base)) ? 1 : 0);   
    printf("is base = %ld \n", typeid(subsubbase).before(typeid(subbase)) ? 1 : 0);   
    printf("\n");

    printf("is base = %ld \n", typeid(base).before(typeid(*pa1)) ? 1 : 0);   
    printf("is base = %ld \n", typeid(subbase).before(typeid(*pa1)) ? 1 : 0);   
    printf("is base = %ld \n", typeid(base).before(typeid(*pa2)) ? 1 : 0);   

    printf("\n");
    printf("is base 4 = %ld \n", typeid(*pa1).before(typeid(base)) ? 1 : 0);   
    printf("is base 4 = %ld \n", typeid(*pa1).before(typeid(subbase)) ? 1 : 0);   
    printf("is base 4 = %ld \n", typeid(*pa2).before(typeid(base)) ? 1 : 0);   

    void *pv1 = new subsubbase();
    void *pv2 = new subbase();
    printf("void *pa1 = new subsubbase name = %s \n", typeid(*pa1).name());
    printf("void *pa2 = new subbase name = %s \n", typeid(*pa2).name());
    printf("is same = %ld \n", typeid(*pa1) == typeid(*pa2) ? 1 : 0);   
    // printf("subsubbase size = %ld\n", sizeof(subsubbase));
*/
    return 0;
}
#endif

