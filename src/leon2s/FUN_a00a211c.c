/* FUN_a00a211c (leon2s, 0xa00a211c-0xa00a2230, 276 bytes, 69 words).
 * Flags: -mcpu=v8 -Os -g. Judge: jf 100.00 match=True, rawcmp_l2s 0/69 mismatches.
 * Code facts: port = (u8)param_1; regs = word +4 of the 52-byte port record DAT_a807db00[port];
 * n = (regs[2] & 0xff) << 16 | regs[1] >> 16 (24 bits), m = regs[3] & 0xffffff. When both are
 * non-zero: rate = FUN_a00a20c4(port) / 10 for mode 0 (mode = (u8)FUN_a00a20a8(port)), 0xa6/0x14d/
 * 0x1bc/0x22b for modes 1..4, 0x29a for 5 and 6, 0 otherwise (jump table); returns
 * (u16)((rate * n / m * 10000) >> 7). Else returns 0.
 * Fix vs draft: the register block behind record word +4 is volatile: the fw reads the FULL words
 * at +4/+8/+0xc (ld) and extracts the fields; a plain pointer lets gcc narrow them to ldub/lduh.
 * Same MMIO-pointer convention as FUN_a0098300 (record word +0x18) and the src users of record
 * word +0 (FUN_a00a7408 reads, RMW at +0x84 in FUN_a009c6e4). Aids: none.
 */
/* FUN_a00a211c at 0xa00a211c */
struct port_regs {
    unsigned int field0;
    volatile unsigned int *field4;   /* +4: per-port register block */
    unsigned int field8;    /* +8 */
    unsigned int field_c;   /* +0xc: base address */
    unsigned int field_10;
    unsigned int field_14;
    unsigned int field_18;  /* +0x18: cfg pointer */
    unsigned int field_1c;
    unsigned int field_20;
    unsigned int field_24;
    unsigned int field_28;
    unsigned int field_2c;
    unsigned int field_30;
};

extern struct port_regs DAT_a807db00[];            /* 0xa807db00 */
extern unsigned char FUN_a00a20a8(unsigned int param_1);   /* 0xa00a20a8 */
extern unsigned short FUN_a00a20c4(unsigned char idx);     /* 0xa00a20c4 */

unsigned short FUN_a00a211c(unsigned int param_1)
{
    unsigned int uVar3, uVar4;
    unsigned short uVar1;
    struct port_regs *rec;
    volatile unsigned int *ptr;
    unsigned char v;

    param_1 &= 0xff;
    rec = &DAT_a807db00[param_1];
    ptr = rec->field4;

    uVar4 = ((ptr[2] & 0xff) << 16) | (ptr[1] >> 16);
    uVar3 = ptr[3] & 0xffffff;

    if (uVar4 != 0 && uVar3 != 0) {
        v = FUN_a00a20a8(param_1);
        uVar1 = 0;
        switch (v) {
        case 0:
            uVar1 = FUN_a00a20c4(param_1) / 10;
            break;
        case 1:
            uVar1 = 0xa6;
            break;
        case 2:
            uVar1 = 0x14d;
            break;
        case 3:
            uVar1 = 0x1bc;
            break;
        case 4:
            uVar1 = 0x22b;
            break;
        case 5:
        case 6:
            uVar1 = 0x29a;
            break;
        }
        return (unsigned short)((uVar1 * uVar4 / uVar3 * 10000) >> 7);
    }
    return 0;
}
