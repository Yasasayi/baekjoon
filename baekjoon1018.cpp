#include <stdio.h>

int main(void)
{
    int w = 21, x = 18, y = 54, z = 67;
    printf("%d %d ", ++w, x++);
    printf("%d %d ", --y, w + x + y - z);

    return 0;
}