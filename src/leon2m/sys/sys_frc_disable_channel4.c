/* sys_frc_disable_channel4  (FUN_a0108544)
 *
 * Clear bit 4 in three converter registers and write the restart value.
 * Name basis: descriptive - 0xCF011BF8, 0xCF011A00 and 0xCF011800, then 1 to 0xCF011CC0; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0108544 @ 0xa0108544, flags -mcpu=v8 -O3 -g.
 * Source form: the print routine is declared with three integer parameters (the format string goes in the first);
 * the registers are read and written back with an explicit mask.
 */
extern int dbg_printf(unsigned int, unsigned int, unsigned int);

#define reg_sys_frc_control (*(volatile unsigned int *)0xcf011800)
#define REG_CF011A00 (*(volatile unsigned int *)0xcf011a00)
#define REG_CF011BF8 (*(volatile unsigned int *)0xcf011bf8)
#define REG_CF011CC0 (*(volatile unsigned int *)0xcf011cc0)

/*
 * Clear bit 4 in the registers 0xCF011BF8, 0xCF011A00 and 0xCF011800 (in that order), after printing
 * "SetFRCCHRW(4) 0", then write 1 to register 0xCF011CC0. The same clearing as sys_frc_set_channel_bit_triple
 * does for bit 4 with `on` = 0. Nothing in the image calls it.
 */
void sys_frc_disable_channel4(void)
{
    dbg_printf("\033[1;31m---->SetFRCCHRW(%d) %d\r\n\033[m", 4, 0);
    REG_CF011BF8 = REG_CF011BF8 & 0xffffffef;
    REG_CF011A00 = REG_CF011A00 & 0xffffffef;
    reg_sys_frc_control = reg_sys_frc_control & 0xffffffef;
    REG_CF011CC0 = 1;
}
