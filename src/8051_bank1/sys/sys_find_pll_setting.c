/* sys_find_pll_setting  (FUN_CODE_d6bf)
 *
 * Return the index of the PLL setting that fits this chip variant.
 * Returns: index 0..5, 0 when none
 * Name basis: descriptive - searches CODE tables 0xDC7D / 0xDC83 by chip id 0xD511; result goes to clock reg
 *   0xD929
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d6bf @ 0xd6bf  OPTIMIZE(8,SPEED) LARGE
 * Source form: do-while over six entries; the chip id is tested in every round.
 */
#define CHIP_ID_20       0x20  /* chip variant with its own list */
#define PLL_LIST_ENTRIES 6
#define PLL_VALUE_CHIP20 0x30  /* value looked for in sys_pll_clock_list_chip20 */
#define PLL_VALUE_OTHER  0x60  /* value looked for in sys_pll_clock_list */

extern xdata unsigned char reg_chip_id;
extern code unsigned char sys_pll_clock_list_chip20[];
extern code unsigned char sys_pll_clock_list[];

/*
 * Return the index (0..5) of the first entry that holds the wanted value: PLL_VALUE_CHIP20 in
 * sys_pll_clock_list_chip20 on chip id 0x20, PLL_VALUE_OTHER in sys_pll_clock_list on the other chips.
 * Returns 0 when no entry matches.
 */
unsigned char sys_find_pll_setting(void)
{
    unsigned char index;

    index = 0;
    do {
        if (reg_chip_id == CHIP_ID_20) {
            if (sys_pll_clock_list_chip20[index] == PLL_VALUE_CHIP20) break;
        } else {
            if (sys_pll_clock_list[index] == PLL_VALUE_OTHER) break;
        }
        index++;
    } while (index != PLL_LIST_ENTRIES);

    if (index == PLL_LIST_ENTRIES) {
        index = 0;
    }
    return index;
}
