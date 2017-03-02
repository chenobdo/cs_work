#include <stdio.h>

char *gets(char *s)
{
    int c;
    char *dest = s;
    while ((c = getchar()) != '\n' && c != EOF);
    *dest++ = c;
    *dest++ = '\0';
    if (c == EOF)
        return NULL;
    return s;
}

void echo()
{
    char buf[4];
    gets(buf);
    puts(buf);
}

int main()
{
    
}