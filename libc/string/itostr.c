#include <string.h>

void itostr(int N, char *str) {
    int i = 0;
    int sign = N;

    if (N < 0)
        N = -N;

    while (N > 0) {
      	str[i++] = N % 10 + '0';
	  	N /= 10;
    } 

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