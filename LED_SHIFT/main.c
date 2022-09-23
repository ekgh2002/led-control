/*
 * LED_SHIFT.c
 *
 * Created: 2022-08-04 오전 11:30:27
 * Author : kccistc
 */ 
	//  76543210
	//  1. 함수선언
	//  2. 배열 처리로 프로그램을 구현
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
	//      1        300ms 유지
	//       1       300ms 유지
	//        1      300ms 유지
	//         1     300ms 유지
	//          1    300ms 유지
	//           1   300ms 유지
	//            1  300ms 유지

#define F_CPU 16000000UL   // 16MHz
#include <avr/io.h>
#include <util/delay.h>
shift_left_led_on()
{
	for (int i=0; i < 8; i++)
    {
	PORTA = 0x01 << i;
	_delay_ms(300);
	}
}
shift_right_led_on()
{
	for (int i=0; i < 8; i++)
	{
	 PORTA = 0x80 >> i;
     _delay_ms(300);
	}
}

int main(void)
{
	DDRA = 0xff;  //  port A에 연결된 led 연결 되어 있으므로 전부 출력 모드로 설정 (all 1)

		unsigned char led[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
		
		while (1)
		{
#if 1
			shift_left_led_on();
			
			shift_right_led_on();
		}
#endif
}


