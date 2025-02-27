#include <stdio.h>
#include <string.h>
int main()
{
    char prompt[] = "Give me a line";
    char str[6];
    char xyz[] = "hello world";
    char line[100];
    fgets(line, sizeof(line), stdin);
    strncpy(str, line, sizeof(str));
    // prompt[0] = 'S';
    printf("%s\n", str);
    return 0;
}