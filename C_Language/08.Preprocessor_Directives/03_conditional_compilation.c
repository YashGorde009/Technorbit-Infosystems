// conditional compilation directives -> 1.#if, 2.#endif, 3.#elif, 4.#else, 5.#ifdef, 6.#ifndef, 7.#undef
// condtion var compilation depend ahe, jar condn true jali tar compilation karayche jar false jali tar nai karayche
#include<stdio.h>
#define a 10
#define age 18

void main() 
{
    printf("value of a : %d\n", a);
    #undef a
    #define a 20                        // 7.#undef
    puts("After conditional compilation directive -> #undef...");
    printf("value of a : %d\n", a);

    //-------------------x--------------------

    #if age > 20 // 1.#if

    // lines of code         // hi condn jar true jali tr ha block of code compilation la pathvayecha nahi tar nahi pathvayecha(mhanje human understandable 
                             // code ch conversion machine understandable code madhe honarch nai -> tevdha vel vachel)

    #elif age > 19 // 3.#elif

    // lines of code         // jar varcha condn false jali tar hi condn check kar

    #else //4.else     

    // lines of code         // jar sagly condn false jali tar ha code compilation la pathayecha

    #endif  //2.#endif       // varchi condn kuth pariyant valid ahe he sangnya sathi #endif 

    // lines of code         // ha code compilation la janar ahe 

    //----------------------x-----------------

    #ifdef b //5.ifdef
        printf("%d\n", b);
    #endif

    #ifndef b //6.ifndef
        #define b 10
    #endif
    
    printf("%d\n", b);

    //---------------x------------------------
}

