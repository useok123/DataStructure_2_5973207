#include <stdio.h>

void IEEE(float num) {  //함수 선언
    unsigned int* p = (unsigned int*)&num;  // float의 비트를 그대로 가져오기
    unsigned int bits = *p;

    unsigned int sign = (bits >> 31) & 1;   // 부호 1비트
    unsigned int exponent = (bits >> 23) & 0xFF;  // 지수 8비트
    unsigned int mantissa = bits & 0x7FFFFF;  // 가수 23비트

    printf("부호 (1비트) : %u\n", sign);    // 부호 출력
    printf("지수 (8비트) : ", exponent);    //지수 출력
    for (int i = 7; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);  //지수 출력 시프트 연산 우 반복
    }
    printf("\n");

    printf("가수 (23비트) : ");
    for (int i = 22; i >= 0; i--) {
        printf("%d", (mantissa >> i) & 1);  //가수 출력 시프트연산 우 반복
    }
    printf("\n");
}

int main() {
    float num;  //변수 설정
    printf("실수를 입력하세요 : ");
    scanf_s("%f", &num);    //실수 입력

    IEEE(num);  //함수 실행

    return 0;
}