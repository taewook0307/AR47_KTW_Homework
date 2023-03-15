﻿#include <iostream>

int main()
{
    //포인터는 64비트에서 8바이트 크기를 가진다.
    //32비트일 때 4바이트

    //int : 4Byte 정수
    //__int64 : 8Byte 정수
    __int64 Value = 10;

    {
        //포인터란 c++의 자료형의 한 형태이며
        //자료형 뒤에 *을 붙이는 문법을 통해 선언
        int* Ptr;

        //램에서의 위치를 의미

        int Value = 10;

        Value < 9;
        //Value는 10을 의미(값을 의미)
        //램에서의 n번째에 있는 10을 의미

        //Value가 표현하는 값이 2가지
        //1. 내부의 자신의 진짜 값 10
        //2. 그 이름을 통해서 램에 존재하게 되는 자신의 주소값(위치값)

        int* ValuePtr = &Value;
        //주소(램에서의 위치의 정수값)를 전문적으로 다루는 문법
        //주소값은 unsigned 정수


        //형변환
        //어떤 자료형 앞에 (자료형) : 이 자료형으로 바꿀 수 있으면 바꿔라

        __int64 Address = 0;
        Address = (__int64)ValuePtr;

        //가상 주소(virtual address)
        //운영체제가 임의대로 붙여준 가상의 주소값
    }

    {
        //2진수 표현
        int Value2 = 0b00000000000000000000000000000001;
        //16진수 표현
        int Value16 = 0xffffffff;
    }
}