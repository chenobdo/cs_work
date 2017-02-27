#include <stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
    int i;
    for (i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
        printf("\n");
    }
}

void show_int(int x)
{
    show_bytes((byte_pointer) &x, sizeof(int)); // (byte_pointer) &x 这是强制变量类型转换的写法
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof(int)); //表达式sizeof(T)返回存储一个类型为T的对象所需要得字节数
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer) &x, sizeof(void *));
}