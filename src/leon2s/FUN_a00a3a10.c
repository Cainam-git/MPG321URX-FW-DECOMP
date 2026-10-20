/* FUN_a00a3a10 (leon2s, 0xa00a3a10-0xa00a3b68, 86 words). Flags -mcpu=v8 -Os -g.
 * u8 port. If ARR_a807db6c[port] != ARR_a807873c[port]: prints DAT_a006bb50 with port and copies db6c[port]
 * into 873c[port]. DAT_a80791aa = 1. If bit 6 of FUN_a0091d64(port, 0x40) is set:
 * FUN_a0091cf4(port, 0x31, (ARR_a80791f4[port] << 4 | ARR_a80791fc[port]) & 0xff), FUN_a0094ac4(port, 1),
 * ARR_a80791f0[port] = 0, then FUN_a00a8054(port, 4, 0xe2, low byte) and FUN_a00a8054(port, 4, 0xe3, high
 * byte) of the u16 ARR_a8078732[ARR_a80791f0[port]] (the first index is store-forwarded to 0 =
 * 'ldub 0xa8078733'; the second re-loads f0[port] after the call), FUN_a0091b74/FUN_a0091a88/FUN_a0091b00(port),
 * word 5 of the 7-word ARR_a807d580 record: bit 11 off, bit 12 on; db6c[port] = 3, ARR_a80791e8[port] = 0.
 * Else db6c[port] = 2. Returns 0.
 * The 0xe2/0xe3 values are the low and high byte of ARR_a8078732[f0[port]]; the array is not volatile.
 */
extern int FUN_a0073044(const char *, ...);
extern unsigned char FUN_a0091d64(unsigned int, unsigned int);
extern void FUN_a0091cf4(unsigned int, unsigned int, unsigned int);
extern void FUN_a0094ac4(unsigned char, unsigned char);
extern void FUN_a00a8054(unsigned int, unsigned int, unsigned int, unsigned char);
extern void FUN_a0091b74(unsigned int);
extern void FUN_a0091a88(unsigned int);
extern void FUN_a0091b00(unsigned int);

extern unsigned int ARR_a807db6c[];
extern unsigned int ARR_a807873c[];
extern unsigned int ARR_a80791f4[];
extern unsigned int ARR_a80791fc[];
extern unsigned char DAT_a80791aa;
extern unsigned short ARR_a8078732[];
extern unsigned int ARR_a807d580[];
extern unsigned char ARR_a80791f0[];
extern unsigned char ARR_a80791e8[];
extern const char DAT_a006bb50[];

unsigned int FUN_a00a3a10(int param_1) {
    unsigned int *p4_;
    unsigned int idx;
    unsigned int uVar2;

    param_1 &= 0xff;
    idx = param_1;

    if (ARR_a807db6c[idx] != ARR_a807873c[idx]) {
        FUN_a0073044(DAT_a006bb50, param_1);
        ARR_a807873c[idx] = ARR_a807db6c[idx];
    }

    DAT_a80791aa = 1;

    if (FUN_a0091d64(param_1, 0x40) & 0x40) {
        uVar2 = (ARR_a80791f4[idx] << 4 | ARR_a80791fc[idx]) & 0xff;
        FUN_a0091cf4(param_1, 0x31, uVar2);
        FUN_a0094ac4(param_1, 1);

        ARR_a80791f0[param_1] = 0;
        FUN_a00a8054(param_1, 4, 0xe2, ARR_a8078732[ARR_a80791f0[param_1]] & 0xff);
        FUN_a00a8054(param_1, 4, 0xe3, ARR_a8078732[ARR_a80791f0[param_1]] >> 8);

        FUN_a0091b74(param_1);
        FUN_a0091a88(param_1);
        FUN_a0091b00(param_1);

        p4_ = ARR_a807d580 + param_1 * 7;
        uVar2 = p4_[5];
        ARR_a807db6c[idx] = 3;
        p4_[5] = (uVar2 & 0xfffff7ff) | 0x1000;
        ARR_a80791e8[param_1] = 0;
    } else {
        ARR_a807db6c[idx] = 2;
    }

    return 0;
}
