#ifndef std_types

#define std_types

typedef unsigned char       u8;   // 1 byte = 8 bits
typedef signed char         s8;   // 1 byte = 8 bits

typedef unsigned short int  u16;  //2 byte = 16 bits
typedef signed short int    s16;  // 2 byte = 16 bits

typedef unsigned long int   u32;  //4 byte = 32 bits

typedef float               f32;  //4 byte = 32 bits
typedef double              f64;  //8 byte = 64 bits
typedef long double         f128; //16 byte = 128 bits

#endif
/* check>>
    printf("%d\n", sizeof(unsigned char));
    printf("%d\n", sizeof(signed char));
    printf("%d\n", sizeof(unsigned short int));
    printf("%d\n", sizeof(signed short int));
    printf("%d\n", sizeof(unsigned long int));
    printf("%d\n", sizeof(double));
    printf("%d\n", sizeof(long double));
    printf("%d\n", sizeof(float));
*/