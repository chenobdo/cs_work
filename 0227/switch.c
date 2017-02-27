#include <stdio.h>

int switch_eg(int x) {
    int result = x;

    switch (x) {
        case 100 :
            retuslt *= 13;
            break;
        case 102 :
            result += 10;
            break;
        case 103 :
            result += 11;
            break;
        case 104 :
        case 106 :
            result *= result;
            break;
        default :
            result = 0;
    }

    return result;
}