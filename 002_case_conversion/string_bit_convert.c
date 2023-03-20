#include <stdio.h>

int main() {
    char msg[16] = "Hello World!";
    /* 대소문자 변환 */
    for (int i = -1; msg[++i] - 33;)msg[i] - 32 ? msg[i] ^= 32 : 0;

    puts(msg);
}