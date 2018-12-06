#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct _stdobject_{
    va_list args;
    void* morph;
    va_list _arguments(int n_args){
        va_list this;
        va_start(this, n_args);
        return this;
    }
    void _end_arg(va_list a){
        va_end(a);
        return;
    }
    void* _get_type(const char[] type){
        void* deftype = NULL;
        char let = type[0];
        int invalid = 0;
        do{
            switch(let){
                case i:
                    return (int*)deftype;
                case c:
                    if(type[1] == 'h') return (char*)deftype;
                    else let = type[7];
                    invalid++;
                    continue;
                case f:
                case d:
                case l:
                case s:
                case u:
                    let = type[10];
                    invalid++;
                    continue;
                case a: 
                    let = type[6];
                    invalid++;
                    continue;
            }
        }while(invalid < 2);
        return deftype;
    }
}object;
