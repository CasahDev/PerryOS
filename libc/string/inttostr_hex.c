#include <string.h>
#include <kernel/tty.h>

void inttostr_hex(int N, char *str) {
    int i = 0;
    int sign = N;

    if (N < 0)
        N = -N;

    while (N > 0) {
        int value = N % 16;

        if (value < 10) {
            str[i++] = value + '0';
        } else {
            str[i++] = (value - 10) + 'a';
        }

        N /= 16;
    }
    
    str[i++] = 'x';
    str[i++] = '0';

    if (sign < 0) {
        str[i++] = '-';
    }
    
    str[i] = '\0';

    for (int j = 0, k = i - 1; j < k; j++, k--) {
        char temp = str[j];
        str[j] = str[k];
        str[k] = temp;
    }
}