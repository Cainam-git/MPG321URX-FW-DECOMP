/* leon2m FUN_a00be424 @ 0xa00be424 (-mcpu=v8 -O2 -g)
 * Writes '0', '0' and '0' + bit 31 of _DAT_a802d46c to DAT_a802d078[7..9], calls FUN_a00bac3c(0x71) and
 * FUN_a00ba950(param_1), and ends with FUN_a00babe4(param_1, 0xB). Sibling functions use bit 15 with 0x73 and bit
 * 30 with 0x72.
 */
extern unsigned int _DAT_a802d46c;
extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c();
extern unsigned char FUN_a00ba950();
extern void FUN_a00babe4(unsigned char param_1, unsigned char param_2);

void FUN_a00be424(unsigned char param_1)
{
    unsigned int uVar1;
    
    uVar1 = (_DAT_a802d46c >> 0x1f) & 1;
    DAT_a802d078[7] = 0x30;
    DAT_a802d078[8] = 0x30;
    DAT_a802d078[9] = (uVar1 + 0x30);
    (void)FUN_a00bac3c(0x71);
    (void)FUN_a00ba950(param_1);
    FUN_a00babe4(param_1, 0xb);
}
