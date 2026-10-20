/* FUN_a00bdc60 (leon2m, 0xa00bdc60-0xa00bdcb0, 80 bytes, 20 words).
 * Flags: -mcpu=v8 -O3 -g. Judge: jf 100.00 match=True, rawcmp 0/20 mismatches.
 * Code facts: d = (_DAT_a802d2c0 >> 4) & 0xf; bytes 7 = 0x30, 8 = 0x30, 9 = d + 0x30 of DAT_a802d078
 * (ASCII "00<digit>", fw stores 9, 8, 7); FUN_a00bac3c(0x39); FUN_a00ba950(p) with p = (u8)param_1;
 * tail call FUN_a00babe4(p, 0xb). Twin of FUN_a00bdb48.
 * Fix vs draft: FUN_a00bac3c takes ONE argument (fw sets only %o0; the draft passed (0x39, 0)).
 * Aids: none.
 */
extern unsigned int _DAT_a802d2c0;
extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c(unsigned char param_1);
extern unsigned char FUN_a00ba950(unsigned char param_1);
extern void FUN_a00babe4(unsigned char param_1, unsigned char param_2);

void FUN_a00bdc60(unsigned char param_1)
{
    unsigned int uVar1;
    
    uVar1 = (_DAT_a802d2c0 >> 4) & 0xf;
    DAT_a802d078[7] = 0x30;
    DAT_a802d078[8] = 0x30;
    DAT_a802d078[9] = (uVar1 + 0x30);
    FUN_a00bac3c(0x39);
    (void)FUN_a00ba950(param_1);
    FUN_a00babe4(param_1, 0xb);
}
