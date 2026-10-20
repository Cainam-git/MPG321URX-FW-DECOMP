/* leon2m FUN_a00c0ff4 @ 0xa00c0ff4-0xa00c1078 (33 words), flags -mcpu=v8 -O3 -g. No direct callers.
 * UART command handler: takes byte 9 of the port's receive record (0xa802d049 for port 2, 0xa802d0a1 for port 3,
 * 0xa802d0d9 otherwise) as an ASCII digit. For '0' or '1' it runs FUN_a00b88cc(), FUN_a00baa6c(port),
 * FUN_a00ba950(port) and FUN_a00bab80(port, 6) (called, not inlined) and returns 0; any other value returns 0xff.
 * The digit value itself is not stored. Source form: one exit with the result in a variable (as in FUN_a00c0c74); d is an unsigned short.
 */
extern unsigned char DAT_a802d049, DAT_a802d0a1, DAT_a802d0d9;
extern void FUN_a00b88cc(void);
extern void FUN_a00baa6c(unsigned char);
extern void FUN_a00ba950(unsigned char);
extern void FUN_a00bab80(unsigned char, int);

int FUN_a00c0ff4(unsigned char port)
{
    unsigned char v;
    unsigned short d;
    int r;

    if (port == 2)
        v = DAT_a802d049;
    else if (port == 3)
        v = DAT_a802d0a1;
    else
        v = DAT_a802d0d9;
    d = v - 0x30;
    r = 0xff;
    if ((unsigned char)d <= 1) {
        FUN_a00b88cc();
        FUN_a00baa6c(port);
        FUN_a00ba950(port);
        FUN_a00bab80(port, 6);
        r = 0;
    }
    return r;
}
