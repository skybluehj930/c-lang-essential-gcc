# 1. 비트마스크 유틸리티 구현

```c

/*
    n번째 비트 값을 임의로 변경하는 유틸리티 프로그램 구현
    (첫번째 자리는 0번째로 취급)
*/

// flags변수의 n번째 비트 값을 1로 만든 값을 반환
int bit_on(int flags, int n);

// flags변수의 n번째 비트 값을 0으로 만든 값을 반환
int bit_off(int flags, int n);

// flags변수의 n번째 비트 값을 반전(toggle)시킨 값을 반환
int bit_toggle(int flags, int n);

예)
int main() {



    int flags = 0;                   // 00000000

    flags = bit_on(flags, 3);        // 00001000
    flags = bit_on(flags, 5);        // 00101000
    flags = bit_toggle(flags, 4);    // 00111000
    flags = bit_off(flags, 3);       // 00110000
    
    . . .
}

```


## 비트연산 정리
```
// AND(&), 대응하는 두 비트가 모두 1일때 1을 반환
1010&1111 = 1010

// OR(|), 대응하는 두 비트중 하나라도 1일때 1을 반환
1010|1111 = 1111

// XOR(^), 대응하는 두 비트가 서로 다르면 1을 반환
1010^1111 = 0101

// NOT(~), 대응하는 비트의 값을 반전
~1010 = 0101

// Shift (<<, >>), 비트를 좌측 혹은 우측으로 이동
001010 << 2 = 101000
001010 >> 2 = 000010
```