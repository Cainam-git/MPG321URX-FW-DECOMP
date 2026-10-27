/* FUN_a00dda4c (leon2m 0xa00dda4c-0xa00ddac4, 120 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes the constants 0x10, 0x1b, 2, 1, 0x19, 0x1b to the word registers 0xcf03cf40, 0xcf03cf44, 0xcf03cf48,
 * 0xcf03cf4c, 0xcf03cf44, 0xcf03cf44, then 0xff to 0xcf03cf5c..0xcf03cf68 and 0xf to 0xcf03cf6c. Nothing in the
 * image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a00dd904 and
 * FUN_a00ddac4.
 */
#define R340 (*(volatile unsigned int *)0xcf03cf40)
#define R344 (*(volatile unsigned int *)0xcf03cf44)
#define R348 (*(volatile unsigned int *)0xcf03cf48)
#define R34C (*(volatile unsigned int *)0xcf03cf4c)
#define R35C (*(volatile unsigned int *)0xcf03cf5c)
#define R360 (*(volatile unsigned int *)0xcf03cf60)
#define R364 (*(volatile unsigned int *)0xcf03cf64)
#define R368 (*(volatile unsigned int *)0xcf03cf68)
#define R36C (*(volatile unsigned int *)0xcf03cf6c)

void FUN_a00dda4c(void)
{
    R340 = 0x10;
    R344 = 0x1b;
    R348 = 2;
    R34C = 1;
    R344 = 0x19;
    R344 = 0x1b;
    R35C = 0xff;
    R360 = 0xff;
    R364 = 0xff;
    R368 = 0xff;
    R36C = 0xf;
}
