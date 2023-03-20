#include <stdio.h>


/*
    n번째 비트 값을 임의로 변경하는 유틸리티 프로그램 구현
    (첫번째 자리는 0번째로 취급)
*/

// flags변수의 n번째 비트 값을 1로 만든 값을 반환
int bit_on(int flags, int n)
{
    return flags |= 1 << n;
}

// flags변수의 n번째 비트 값을 0으로 만든 값을 반환
int bit_off(int flags, int n)
{
    return flags &= ~(1 << n);
}

// flags변수의 n번째 비트 값을 반전(toggle)시킨 값을 반환
int bit_toggle(int flags, int n)
{
    return flags ^= 1 << n;
}

void dec_to_bin(unsigned n) {
    unsigned a = 0x80000000;
    for (int i = 0; i < 32; i++) {
        if ((a & n) == a)
            printf("1");
        else
            printf("0");
        a >>= 1;
    }
    printf("\n");
}


int main() {



    int flags = 0;                   // 00000000

    flags = bit_on(flags, 3);        // 00001000
    printf("flags변수의 3번째 비트 값을 1로 변환: ");
    dec_to_bin(flags);

    flags = bit_on(flags, 5);        // 00101000
    printf("flags변수의 5번째 비트 값을 1로 변환: ");
    dec_to_bin(flags);

    flags = bit_toggle(flags, 4);    // 00111000
    printf("flags변수의 4번째 비트 값을 반전: ");
    dec_to_bin(flags);

    flags = bit_off(flags, 3);       // 00110000
    printf("flags변수의 3번째 비트 값을 반전: ");
    dec_to_bin(flags);

}