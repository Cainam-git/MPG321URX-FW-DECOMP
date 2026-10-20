/* FUN_a00c86bc (leon2s 0xa00c86bc-0xa00c8760, 164 bytes), flags -mcpu=v8 -Os -g.
 * Calls FUN_a00c7bf8(port) and prints s_9f1c1fa0 through the ROM print func_0xa0f83044 when its low byte is
 * non-zero. Reads the five bytes 0x1d..0x21 of port through func_0xa0fb7fd8(port, 0, 0x1d + i) into the
 * stack buffer buf[5], passes them to FUN_a00c80f0(port, buf, 0x74, 0x10, 5) and prints s_9f1c1fc0 with the
 * 8-bit result when that result is non-zero.
 * Source forms: unsigned char loop counter (the firmware clears it on both paths of the first test).
 */
extern char s_9f1c1fa0[], s_9f1c1fc0[];
extern int func_0xa0f83044(const char *, ...);
extern unsigned int FUN_a00c7bf8(unsigned char param_1);
extern int FUN_a00c80f0(unsigned char param_1, unsigned char *param_2, unsigned char param_3,
                        unsigned char param_4, unsigned short param_5);
extern unsigned char func_0xa0fb7fd8(unsigned char, int, unsigned short);

void FUN_a00c86bc(unsigned char port)
{
    unsigned char buf[5];
    unsigned char i;
    unsigned char r;

    if ((unsigned char)FUN_a00c7bf8(port))
        func_0xa0f83044(s_9f1c1fa0);
    for (i = 0; i < 5; i++)
        buf[i] = func_0xa0fb7fd8(port, 0, i + 0x1d);
    r = FUN_a00c80f0(port, buf, 0x74, 0x10, 5);
    if (r)
        func_0xa0f83044(s_9f1c1fc0, r);
}
