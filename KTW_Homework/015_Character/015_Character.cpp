﻿int main()
{
    // 램은 비트의 집합
    // 글자 => 비트로 전환
       
    // 문자를 표현하는 방식은
    // 특정 글자를 정수 1개와 매칭
       
    // char는 1바이트 문자형 = 아스키 코드
    char Ch = 'A';
    // 정수로 표현한다면 255
       
    // 앞쪽에 L을 붙여서 표현
    // 2바이트 문자형
    // L을 안 붙여주면 1바이트 문자형이라고 생각
    // 아스키 코드로 모든 문자를 표현하기 힘듬 => 유니코드
    wchar_t wch = L'A';

    // 유니코드도 한계 발생 => 국가 코드 생성
    // UTF-8
    // 글자를 1, 2, 3, 4바이트로 표현
    // u8 표현은 14이상부터 표현 가능
    char Arr = u8'A';

    // 이런 개념을 인코딩
       
    // 아스키 코드는 255개만 표현
    // 멀티바이트 어떤건 1바이트 어떤건 2바이트로 표현
    // 와이드 바이트 모두다 2바이트 == 유니코드
    // utf-8, utf-16, utf-32
}
