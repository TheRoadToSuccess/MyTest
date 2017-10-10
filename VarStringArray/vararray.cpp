#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <stdarg.h>
#include <stdio.h>


typedef struct
{
    int data_len;
    char data[0];
}buff_st_1;

typedef struct
{
    int data_len;
    char *data;
}buff_st_2;

typedef struct 
{
    int data_len;
    char data[];
}buff_st_3;

typedef struct 
{
    uint32_t id;
    uint32_t age;
}student_st;


typedef struct 
{
    std::string key;
    char val[10][0];
} key_map_1;

typedef struct 
{
    std::string key;
    // char val[10][];
} key_map_2;

typedef struct 
{
    std::string key;
    // char val[][];
} key_map_3;

typedef struct 
{
    std::string key;
    char *val[];
} key_map_4;

typedef struct 
{
    std::string key;
    char *val[0];
} key_map_5;

typedef struct 
{
    std::string key;
    char **val;
} key_map_6;

void print_stu(const student_st *stu)
{
    printf("id:%u,age:%u\n", stu->id, stu->age);
}


class VarArray
{
public:
    int nLen;
    // char *ppVA;
    std::vector<std::string> vecArray;

    VarArray(int argc, ...)
        : nLen(argc)
    {
        va_list ap;
        va_start(ap, argc);

        for (int i = 0; i < argc; i++) {
            // printf("%d\n", va_arg(ap, int));
            // printf("%f\n", va_arg(ap, double));
            // printf("this %p, argv[%d] = %s\n", this, i, va_arg(ap, char*));
            vecArray.push_back(va_arg(ap, char *));
        }

        va_end(ap);

        printf("nlen = %d, vecArray size[%d] \n", nLen, vecArray.size());
    }

    ~VarArray()
    {

    }
};


struct key_map_7
{
    std::string key;
    VarArray *pVar;
};


int main()
{
    printf("buff_st_1 data[0] size[%d]\n", sizeof(buff_st_1));
    printf("buff_st_2 *data   size[%d]\n", sizeof(buff_st_2));
    printf("buff_st_3 data[]  size[%d]\n", sizeof(buff_st_3));
    printf("key_map_1 var[10][0] size[%d]\n", sizeof(key_map_1));
    printf("key_map_2 var[10][]  size[%d]\n", sizeof(key_map_2));
    printf("key_map_3 var[][]    size[%d]\n", sizeof(key_map_3));
    printf("key_map_4 *var[]     size[%d]\n", sizeof(key_map_4));
    printf("key_map_5 *var[0]    size[%d]\n", sizeof(key_map_5));
    printf("key_map_6 **var      size[%d]\n", sizeof(key_map_6));
    printf("key_map_p *pVar      size[%d]\n", sizeof(key_map_7));
    printf("VarArray             size[%d]\n", sizeof(VarArray));

    key_map_7 km7[] ={ 
                    {"1233", new VarArray(1, "123")},
                    {"1233", new VarArray(2, "123", "1234")},
                    {"1233", new VarArray(1, "123")},
                    {"1233", new VarArray(3, "123", "123", "234")},

                    {"", NULL},  // end flag
    };


    // print km7
    for (int i = 0; ; ++i) {
        if ("" == km7[i].key && NULL == km7[i].pVar) {
            break;
        }
        printf("index[%d], key = %s \n", i, km7[i].key.c_str());
        if (NULL != km7[i].pVar) {
            std::vector<std::string>::iterator iter = km7[i].pVar->vecArray.begin();
            while (iter != km7[i].pVar->vecArray.end()) {
                printf("    v[%s]\n", (*iter).c_str());
                ++iter;
            }
        }
    }

    // For Free Array: km7
    for (int i = 0; ; ++i) {
        if ("" == km7[i].key && NULL == km7[i].pVar) {
            break;
        }
        if (NULL != km7[i].pVar) {
            delete km7[i].pVar;
            km7[i].pVar = NULL;
        }
    }


    student_st *stu = (student_st *)malloc(sizeof(student_st));
    stu->id = 100;
    stu->age = 23;

    student_st *tmp = NULL;

    buff_st_1 *buff1 = (buff_st_1 *)malloc(sizeof(buff_st_1) + sizeof(student_st));
    buff1->data_len = sizeof(student_st);
    memcpy(buff1->data, stu, buff1->data_len);
    printf("buff1 address:%p,buff1->data_len address:%p,buff1->data address:%p\n",
            buff1, &(buff1->data_len), buff1->data);

    tmp = (student_st*)buff1->data;
    print_stu(tmp);

    buff_st_2 *buff2 = (buff_st_2 *)malloc(sizeof(buff_st_2));
    buff2->data_len = sizeof(student_st);
    buff2->data = (char *)malloc(buff2->data_len);
    memcpy(buff2->data, stu, buff2->data_len);
    printf("buff2 address:%p,buff2->data_len address:%p,buff2->data address:%p\n",
            buff2, &(buff2->data_len), buff2->data);

    tmp = (student_st *)buff2->data;
    print_stu(tmp);

    buff_st_3 *buff3 = (buff_st_3 *)malloc(sizeof(buff_st_3) + sizeof(student_st));
    buff3->data_len = sizeof(student_st);
    memcpy(buff3->data, stu, buff3->data_len);
    printf("buff3 address:%p,buff3->data_len address:%p,buff3->data address:%p\n",
            buff3, &(buff3->data_len), buff3->data);

    tmp = (student_st*)buff1->data;
    print_stu(tmp);

    free(buff1);

    free(buff2->data);
    free(buff2);

    free(buff3);
    free(stu);
    return 0;
}
