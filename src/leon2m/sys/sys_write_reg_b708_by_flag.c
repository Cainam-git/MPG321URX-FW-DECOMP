/* sys_write_reg_b708_by_flag  (FUN_a0110f5c)
 *
 * Write one of two values to a register by a flag.
 * Name basis: descriptive - reg_write32 on a 0xB708xxxx register; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0110f5c @ 0xa0110f5c, flags -mcpu=v8 -O3 -g.
 * Source form: reg_write32 is declared without a prototype (extern int f();). The first call is made with two
 * arguments, the second with six, as in the firmware; both arms repeat the second call.
 */
extern int reg_write32();

/*
 * Write 0x5003814 (flag non-zero) or 0x500AE16 (flag 0) to register 0xB7080168, then write the value 4 to
 * register 0xB7080388. Parameter 2 is not used; parameters 3 to 6 are handed to the second reg_write32 call
 * after the value 4. No caller is known.
 */
void sys_write_reg_b708_by_flag(unsigned char flag, int unused_2, int extra_3, int extra_4, int extra_5, int extra_6)
{
    if (flag != 0) {
        reg_write32(0xb7080168, 0x5003814);
        reg_write32(0xb7080388, 4, extra_3, extra_4, extra_5, extra_6);
    } else {
        reg_write32(0xb7080168, 0x500ae16);
        reg_write32(0xb7080388, 4, extra_3, extra_4, extra_5, extra_6);
    }
}
