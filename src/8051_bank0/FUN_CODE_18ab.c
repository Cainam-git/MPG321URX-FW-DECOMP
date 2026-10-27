/* 8051_bank0 FUN_CODE_18ab @ 0x18ab..0x18bb (16 B)
 * Calls FUN_CODE_18bb (bit: XDATA 0xD511 == 0x20) and returns 0 as an unsigned long on both outcomes.
 * No LCALL or LJMP to 0x18AB occurs in the bank-0 image. Options: OPTIMIZE(8,SPEED) REGFILE(R.ORC).
 * Source form: 'r = 0' in both arms. The first arm's store is dropped after the jumps are laid out (R7 is already
 * 0), which leaves the firmware's 'JNC / SJMP' pair; the second arm keeps 'CLR A / MOV R7,A'.
 */
extern bit FUN_CODE_18bb(void);

unsigned long FUN_CODE_18ab(void)
{
    unsigned char r = 0;

    if (FUN_CODE_18bb()) {
        r = 0;
    } else {
        r = 0;
    }
    return r;
}
