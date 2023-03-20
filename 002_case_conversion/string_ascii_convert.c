#include <stdio.h>
int main() {
    char msg[256];
     printf("input : ");
     gets(msg); 
    /* 대소문자 변환 */
    for (int i = 0; msg[i]; i++) {
        if (msg[i] >= 65 && msg[i] <= 90) msg[i] += 32;
        else if (msg[i] >= 97 && msg[i] <= 122) msg[i] -= 32;
    }
    puts(msg);
}