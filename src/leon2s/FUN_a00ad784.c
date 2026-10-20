/* FUN_a00ad784 (leon2s, 0xa00ad784-0xa00ad7c8, 68 bytes, 17 words).
 * Flags: -mcpu=v8 -Os -g. Judge: jf 100.00 match=True, rawcmp_l2s 0/17 mismatches.
 * Code facts: port = (u8)param_1; result 0; if bit 6 (0x40) of FUN_a00a6bb8(port, 0x8f) is set,
 * result = (FUN_a00ad668(port) != 0) (u8 test btst 0xff). Returns result as a u8 (fw: the final
 * 'and %i0,1,%i0' is the u8 return extension narrowed by nonzero-bits).
 * Fix vs draft: return type and result are unsigned char (unsigned int gives no final and). Aids: none.
 */
extern unsigned int FUN_a00a6bb8(unsigned int param_1, unsigned short param_2);
extern unsigned char FUN_a00ad668(unsigned int param_1);

unsigned char FUN_a00ad784(unsigned int param_1)
{
    unsigned char result = 0;
    param_1 = param_1 & 0xff;
    if ((FUN_a00a6bb8(param_1, 0x8f) & 0x40) != 0) {
        if (FUN_a00ad668(param_1) != 0)
            result = 1;
        else
            result = 0;
    }
    return result;
}
