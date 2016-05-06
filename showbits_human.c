#include <stdio.h>

void showbits(const unsigned int x)
{
	int i;
	const int int_bits = (sizeof(int) * 8) - 1;
	for (i = int_bits; i >= 0; i--) {
		if ((i + 1) % 4 == 0 && i != int_bits)
			putchar(' ');
		(x & (1u << i)) ? putchar('1') : putchar('0');
	}
	printf("\n");
}
