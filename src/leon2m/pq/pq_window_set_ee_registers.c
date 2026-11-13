/* pq_window_set_ee_registers  (FUN_a00f6940)
 *
 * Write one of several register sets at 0xCF00EE2x / 0xCF00EE6x and three bytes behind them.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6940 @ 0xa00f6940-0xa00f6ab4, flags -mcpu=v8 -O3 -g.
 * Source form: one shared "case 0: case 4:" body and the case order as written (0, 4, 1, 2, 3);
 * separate bodies or other orders change the register choice or the block order.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define WINDOW_SELECT_A 0xcf00ec84   /* bits 0..1 (and bit 2 for set 4) take the set number */
#define REG_CF00EE40 0xcf00ee40
#define REG_CF00EE20 0xcf00ee20
#define REG_CF00EE24 0xcf00ee24
#define REG_CF00EE28 0xcf00ee28
#define REG_CF00EE2C 0xcf00ee2c
#define REG_CF00EE68 0xcf00ee68
#define REG_CF00EE30 0xcf00ee30
#define REG_CF00EE34 0xcf00ee34
#define REG_CF00EE38 0xcf00ee38
#define REG_CF00EE3C 0xcf00ee3c
#define REG_CF00EE50 0xcf00ee50
#define REG_CF00EE44 0xcf00ee44
#define REG_CF00EE48 0xcf00ee48
#define REG_CF00EE4C 0xcf00ee4c

#define MASK_SET_SELECT 0xfc        /* keeps bits 2..7 of WINDOW_SELECT_A */
#define EE50_BITS0_2 7

/*
 * Select register set 0..4 and write three bytes.
 *
 *   register_set  0..4; for any other value only the last four writes are done
 *   data0..data2  written to 0xCF00EE44, 0xCF00EE48 and 0xCF00EE4C at the end
 *
 * For sets 0..4 the set number goes into WINDOW_SELECT_A (OR-ed after clearing bits 0..1, so set 4 leaves bit 2
 * set), then:
 *   0 and 4: bit 6 of 0xCF00EE40 set, 0xCF00EE20 = 0x80, 0xCF00EE24 = 1;
 *   1:       bit 7 of 0xCF00EE40 set, 0xCF00EE28 = 0x80, 0xCF00EE2C = 1;
 *   2:       0xCF00EE68 = 0x40 (whole register), 0xCF00EE30 = 0x80, 0xCF00EE34 = 1;
 *   3:       0xCF00EE68 = 0x80 (whole register), 0xCF00EE38 = 0x80, 0xCF00EE3C = 1.
 * Then bits 0..2 of 0xCF00EE50 are set and the three bytes written.
 *
 * No direct call to it was found in the image.
 */
void pq_window_set_ee_registers(unsigned int register_set, unsigned char data0, unsigned char data1, unsigned char data2)
{
    switch (register_set) {
    case 0:
    case 4:
        R(WINDOW_SELECT_A) = (R(WINDOW_SELECT_A) & MASK_SET_SELECT) | register_set;
        R(REG_CF00EE40) |= 0x40;
        R(REG_CF00EE20) = 0x80;
        R(REG_CF00EE24) = 1;
        break;
    case 1:
        R(WINDOW_SELECT_A) = (R(WINDOW_SELECT_A) & MASK_SET_SELECT) | register_set;
        R(REG_CF00EE40) |= 0x80;
        R(REG_CF00EE28) = 0x80;
        R(REG_CF00EE2C) = 1;
        break;
    case 2:
        R(WINDOW_SELECT_A) = (R(WINDOW_SELECT_A) & MASK_SET_SELECT) | register_set;
        R(REG_CF00EE68) = 0x40;
        R(REG_CF00EE30) = 0x80;
        R(REG_CF00EE34) = 1;
        break;
    case 3:
        R(WINDOW_SELECT_A) = (R(WINDOW_SELECT_A) & MASK_SET_SELECT) | register_set;
        R(REG_CF00EE68) = 0x80;
        R(REG_CF00EE38) = 0x80;
        R(REG_CF00EE3C) = 1;
        break;
    }
    R(REG_CF00EE50) |= EE50_BITS0_2;
    R(REG_CF00EE44) = data0;
    R(REG_CF00EE48) = data1;
    R(REG_CF00EE4C) = data2;
}
