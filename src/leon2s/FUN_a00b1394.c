/* FUN_a00b1394 (leon2s 0xa00b1394-0xa00b1418, 132 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Writes 1 to register 0xcf037c80; until register 0xcf037c84 reads 1, copies register 0xcf03c820 to 0xcf03c830;
 * then reads the 63 consecutive words at 0xcf037c88 into the byte buffer buf (low byte of each) and writes 0 to
 * 0xcf037c80. The first parameter is not used.
 * One register pointer variable is reused for 0xcf037c80, 0xcf037c84 and the read loop: the firmware keeps all
 * three in the same register.
 */
#define REG_7C80 (*(volatile unsigned int *)0xcf037c80)
#define REG_7C84 (*(volatile unsigned int *)0xcf037c84)
#define REG_C820 (*(volatile unsigned int *)0xcf03c820)
#define REG_C830 (*(volatile unsigned int *)0xcf03c830)
#define REG_7C88 ((volatile unsigned int *)0xcf037c88)

void FUN_a00b1394(unsigned char port, unsigned char *buf)
{
    volatile unsigned int *p;
    unsigned char i;

    p = &REG_7C80;
    *p = 1;
    p = &REG_7C84;
    while (*p != 1)
        REG_C830 = REG_C820;
    p = REG_7C88;
    for (i = 0; i < 63; i++)
        buf[i] = *p++;
    p = &REG_7C80;
    *p = 0;
}
