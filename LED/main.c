/*
 * LED.c
 *
 * Created: 2022-08-03 오후 3:17:48
 * Author : kccistc
 */ 
#define F_CPU 16000000UL   // 16MHz
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRA = 0xff;  //  port A에 연결된 led 연결 되어 있으므로 전부 출력 모드로 설정 (all 1)
	//  76543210
	//  1. 전체 LED를 on --> 1초 유지 --> off --> 1초 유지
	//  2. 홀수번 BIT on --> 1초 유지 --> 짝수번 BIT on
	//  3. 전체 off --> 1초 유지  
	//  4. 배열 처리로 프로그램을 구현 
	//     [AVR] 배열 처리 LED left 순차 on
	//     unsigned char led[] = {    };
	//     76543210
	//            1  300ms 유지
	//           1   300ms 유지
    //          1    300ms 유지
	//         1     300ms 유지
	//        1      300ms 유지
	//       1       300ms 유지
	//      1        300ms 유지
	//     1         300ms 유지
	//      1
	//       1
	//        1
	//         1
	//          1
	//           1
	//            1
	unsigned char led[] = {0b10000000,0b01000000,0b00100000,0b00010000,0b00001000,0b00000100,0b00000010,0b0000001};
	
	while (1)
	{
		for(int i = 7; i>=0; i--)
		{
			_delay_ms(300);
			PORTA = led[i]; 
		}
		for(int i = 0; i<8; i++)
		{
			_delay_ms(300);
			PORTA = led[i];
		}
		//test
	}
}
