﻿#include <iostream>

int main()
{
    int Value = 0b00000000000000000000000000000001;

    int* Ptr = &Value;

    char* CharPtr = reinterpret_cast<char*>(Ptr);

    char Test0 = CharPtr[0];
    char Test1 = CharPtr[1];
    char Test2 = CharPtr[2];
    char Test3 = CharPtr[3];
}

// big endian
// 낮은 주소에 데이터의 높은 바이트부터 저장하는 방식
// little endian
// 낮은 주소에 데이터의 낮은 바이트부터 저장하는 방식