#include <stdio.h>

#define NORM "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"

void highlight(unsigned char *data, int len, unsigned char *ptr, uint hl_len)
{
        int i = 0;
        int h = 0;
        printf("from %p printing %d bytes and highlight from %p a %d bytes\n",
               data, len, ptr, hl_len);
        for (i = 0; i < len; i++) {
                if (i % 16 == 0)
                        printf("\n%4d\t", i);
                if (i % 8 == 0)
                        printf(" ");

                if (h == 0 && ptr == data + i) {
                        h = 1;
                        printf("%s", RED);
                }

                printf("%.2X ", data[i]);

                if (h > 0) {
                        if (h == hl_len) {
                                h = 0;
                                printf("%s", NORM);
                        }
                        h++;
                }
        }
        if (h != 0)
                printf(NORM);
        printf("\n\n");
}
