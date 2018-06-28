#include <stdio.h>
struct Message {
	char data1;
	char data2;
	short data3;
	int data4;
	char data5;
};

void c_type_bit_print(char ch)
{
	// bit based moving..
	for (int i = 7; i >= 0; --i)
		putchar((ch & (1 << i)) ? '1' : '0');
	putchar(' ');
}

int main(void)
{
	char *p1;
	char a = 0x10;
	printf("char * size = (%d)\n", sizeof(char *));

	printf("a = %c = %d = %x = ", a, a, a);
	p1 = (char *)&a;
	c_type_bit_print(*p1);
	putchar('\n');

	int x = 0x01020304;
	char *p2;
	printf("x = %d = 0%x = ", x, x);

	p2 = (char *)&x;
	printf("(*p-> %x) ", *p2);
	// byte based moving..
	// 32bits(= 4bytes) 
	// [0 1][0 2][0 3][0 4]
	for (int i = 0; i < 4; ++i)
		c_type_bit_print(*p2++);
	putchar('\n');

	printf("struct Message size = (%d)\n", sizeof(struct Message));

	return 0;
}
