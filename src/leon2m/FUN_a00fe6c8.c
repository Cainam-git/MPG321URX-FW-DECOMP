/* leon2m FUN_a00fe6c8 @ 0xa00fe6c8  MATCH (-mcpu=v8 -O3 -g)
 * Returns 0x51 or 0x61 when bits 0x12 of the hardware register 0xCF02DC04 are clear (bit 0 of 0xCF011750 selects
 * the +0x10), otherwise 0x71 or 0x81 (bit 0 of 0xCF011674). Callers: FUN_a01012a8, FUN_a0152a20.
 * Source form: one result variable, with the "bits clear" case tested first (== 0).
 */
#define R(a) (*(volatile unsigned int *)(a))

unsigned char FUN_a00fe6c8(void)
{
    unsigned char v;

    if ((R(0xcf02dc04) & 0x12) == 0)
        v = ((R(0xcf011750) & 1) << 4) + 0x51;
    else
        v = ((R(0xcf011674) & 1) << 4) + 0x71;
    return v;
}
