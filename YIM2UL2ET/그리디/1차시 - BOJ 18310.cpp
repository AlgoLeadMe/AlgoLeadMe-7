#include <iostream>

int main(void)
{
    int n, temp, index, result, up, down;
    long long value, tvalue;
    int villige[100000] = {0};

    value = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        villige[temp-1]++;
        value += temp-1;
    }

    result = 1, index = 0, up = n - villige[0], down = villige[0], tvalue = value; 
    // tvalue: 임시 value, up: 봐야할 집의 수, down: 지금까지 봐온 집의 수

    for (int i = 1; i < 100000; i++) {  // 마을 돌아보기
        if (villige[i] == 0) continue;  // i+1번째 위치에 집이 없으면 다음 위치로 이동

        tvalue += down * (i - index);   
        tvalue -= up * (i - index);
        down += villige[i];
        up -= villige[i];

        if (tvalue < value) {   // 지금 계산한 value가 저장했던 value보다 작으면
            value = tvalue;     // 지금 계산한 value값 저장.
            result = i+1;       // 정답으로 i+1번째 위치 저장
        }
        index = i;  // 최근 봤던 집의 위치를 기억하기
    }
    
    std::cout << result;
    return 0;
}