/* leon2m FUN_a013562c @ 0xa013562c-0xa01356fc (52 words), flags -mcpu=v8 -O3 -g. Callers: FUN_a012c320 and others.
 * Sends mailbox command 0xd with func_0x4008f3f4(0xd, 0, a / 16, b, 0) (the RAM copy of FUN_a002f3f4), then
 * repeats FUN_a01350dc() and FUN_a0134de0() until the body of FUN_a0132cd4 (inlined here: when byte 0xa802cb8f is
 * 1, copies byte 0xa802cb8e bytes of 0xa802de40 to dst, clears 0xa802cb8f and returns 1) returns 1.
 * Exact form: the divisor 16 is held in a local (the firmware divides with sdiv by the immediate 16).
 */
extern unsigned char DAT_a802cb8f, DAT_a802cb8e;
extern unsigned char DAT_a802de40[];
extern void func_0x4008f3f4(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern void FUN_a01350dc(void);
extern void FUN_a0134de0(void);

static unsigned char FUN_a0132cd4(unsigned char *dst)
{
    unsigned char r = 0;
    unsigned char i;

    if (DAT_a802cb8f == 1) {
        for (i = 0; i < DAT_a802cb8e; i++)
            dst[i] = DAT_a802de40[i];
        DAT_a802cb8f = 0;
        r = 1;
    }
    return r & 1;
}

void FUN_a013562c(unsigned short a, unsigned char b, unsigned char *dst)
{
    int n = 16;

    func_0x4008f3f4(0xd, 0, a / n, b, 0);
    while (!FUN_a0132cd4(dst)) {
        FUN_a01350dc();
        FUN_a0134de0();
    }
}
