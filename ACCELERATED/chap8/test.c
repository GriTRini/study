#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
void main(void) {
    char answer;
    int count = 0;
    char s[] = {1, 2, 3, 4};
    for (int i = 0; s[i]; ++i) {
        if(s[i] >= 'A') {
            answer = false;
            break;
        }
        ++count;
    }
    if (count < 4 || count > 6) {
        answer = false;
    }

    printf("%s", answer)
}