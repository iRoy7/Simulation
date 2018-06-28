#include <stdio.h>
char str[33];
char s[3];

int bits_update(int n, int m, int i, int j)
{
	// Check a validation
	if (i >= 32 || i > j) return 0;

	int allONE = ~0;
	printf("\n\n allONE = %d = %x \n", allONE, allONE);

	// j = 12(12/4bytes = 3), j+1 = 13;
	int left = allONE << (j + 1);
	printf("After left 13 shifts: \n");
	printf("all ONE = %d = %x\n", left, left);

	int a = 1;
	printf("\n\n Current a = %d = %x \n", a, a);
	// i = 4 (4/4bytes = 1)
	int b = (a << i);
	printf("After left 4 shifts: \n");
	printf("NoW a = %d = %x \n", b, b);

	int c = 1;
	int right = ((c << i) - 1);
	printf("\n\n Current right(c) = %d = %x\n", right, right);

	// Masking!!
	// left = ff ff e0 00, right = 0f;
	// left | right = ff ff e0 0f
	int mask = left | right;
	printf("\n\n Current mask = %d = %x \n", mask, mask);

	// n = 103217 = 19331
	// [ff][ff][e0][0f]
	// &   [ 1][93][31]
	//-------------------
	//     [ 1][80][01]
	printf("\n\n Current n = %d = %x \n", n, n);
	int n_cleared = n & mask;
	printf("After n cleared masking = %d = %x \n", n_cleared, n_cleared);

	// m = 13
	printf("\n\n Current m = %d = %x \n", m, m);
	// i = 4(4/4bytes) left shift
	int m_shifted = m << i;
	printf("After m shift = %d = %x \n", m_shifted, m_shifted);

	// n_cleared = 18001, m_shifted = d0
	// n_cleared | m_shifted = 1 8 0 d 1
	int msk = n_cleared | m_shifted;
	printf("\n\n n_cleared | m_shifted = %d = %x \n", msk, msk);

	return msk;
}


int main(void)
{
	int i;
	printf("Size of integer(%d) = %d\n", sizeof(int), sizeof(i));

	int a = 103217;
	int b = 13;
	int c = bits_update(a, b, 4, 12);

	printf("\n\n Current c = %d = %x \n", c, c);
	printf("Ref 15 = %d = %x \n", 15, 15);

	for (int i = 0; i < 32; ++i)
	{
		//   [  0 |   0][  0 |   1][  8 |   0][  d |   1]
		// & [0000|0000][0000|0000][0000|0000][0000|0001]
		// ----------------------------------------------
		//                                             1
		int lsb = c & 1;
		sprintf(s, "%d", lsb);
		str[i] = s[0];
		c = c >> 1;
	}

	printf(" Results: %s\n", str);
	char buf[33] = { 0, };
	for (int i = 31, j = 0; i >= 0 && j < 32; --i, ++j)
		buf[j] = str[i];
	buf[32] = '\0';
	printf("\n\n Results: %s\n", buf);

	char buf2[6] = { '1', '8', '0', 'd' , '1', '\0' };
	printf("\n\n 16(Hexadecimal) string  = %s\n", buf2);
	int num;
	sscanf(buf2, "%x", &num);
	printf("Converted number = %d = %x \n", num, num);

	printf("\n\n End programming..\n");

	return 0;
}
