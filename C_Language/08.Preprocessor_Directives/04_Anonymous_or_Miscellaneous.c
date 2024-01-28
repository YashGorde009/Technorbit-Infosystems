// #pragma, #line, #error
#include<stdio.h>
#pragma pack(1) // packing of 1 byte is recommended to avoid any sort of packing 
void main() 
{
    struct Demo // datatype
    {
        // double a;
        // short int b;
        // int d;        // After #pragma pack(1) : 23  after pack(2) : 24
        // char c;
        // double e;

        int a;
        char b;          // After #pragma pack(1) : 10  after pack(2) : 12
        int c;  
        char d;

        // double a;
        // short int b;
        // int d;        // size : 32  (without pragma)
        // char c;
        // double e;

        // int a;
        // char b;      // size : 16   (without pragma)
        // int c;  
        // char d;
    };

    struct Demo obj;  // object(obj)
    
    printf("Size Of Object 'obj' : %d\n", sizeof(obj)); // padding concept

    // ----------------x--------------

    // #line kadhi vaprayecha -> debugging purpose -> command line interface(out-dated) -> graphical interface
    //demo.c -> demo.i -> demo.asm -> demo.obj -> demo.exe

    #line 40 // constant(40)
    printf("%d\n",__LINE__);

    //-----------x--------------

    // #error kadhi vaprayecha -> to give user define error

    #ifndef a
        #error 'a' is not defined
    #endif

    //----------x---------------
}