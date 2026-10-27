/* FUN_a00f2e98 (leon2m 0xa00f2e98-0xa00f2f88, 240 bytes), flags -mcpu=v8 -O3 -g.
 * Writes dev to the word register 0xcf011780, the low and high bytes of off to 0xcf011784 and 0xcf011788 and 0 to
 * 0xcf00bfcc, then the len bytes buf[0..len-1] one by one to 0xcf01178c; a delay loop of 0x20 nops follows each
 * step. Called by FUN_a010ae8c, FUN_a010af6c, FUN_a010afe4, FUN_a010b030, FUN_a010b07c, FUN_a010b0c8, FUN_a010b114,
 * FUN_a010b1b4, FUN_a010b200, FUN_a010b24c, FUN_a010b298, FUN_a010b2e4, FUN_a01186e0. Source form: the delay is a
 * static helper (unsigned char counter) inlined at each use; the low byte is written as (unsigned char)off.
 */
#define R780 (*(volatile unsigned int *)0xcf011780)
#define R784 (*(volatile unsigned int *)0xcf011784)
#define R788 (*(volatile unsigned int *)0xcf011788)
#define R78C (*(volatile unsigned int *)0xcf01178c)
#define RBFCC (*(volatile unsigned int *)0xcf00bfcc)

static void dly(void)
{
    unsigned char i;

    for (i = 0; i < 0x20; i++)
        __asm__("nop");
}

void FUN_a00f2e98(unsigned char dev, unsigned short off, unsigned short len, const unsigned char *buf)
{
    unsigned short i;

    dly();
    R780 = dev;
    dly();
    R784 = (unsigned char)off;
    R788 = off >> 8;
    RBFCC = 0;
    dly();
    for (i = 0; i < len; i++) {
        R78C = buf[i];
        dly();
    }
}
