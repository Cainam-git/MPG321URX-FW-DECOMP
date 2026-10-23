/* leon2m FUN_a0118b0c @ 0xa0118b0c (-mcpu=v8 -O2 -g)
 * Clears bit 7 of register 0xCF012FF0, writes 6 to 0xCF012E80, calls FUN_a00f2f88(0xf4, 0, 0x400, p1). With h = halfword
 * +0x0a of the transformed row *DAT_a802d6a4: h > 0x86f -> 0xCF012FF0 = 0xb, 0xCF012FF4 = 0, 0xCF012FF8 = 1;
 * h > 0x437 -> 0xCF012FF0 = 0xa, 0xCF012FF4 = 0x40, 0xCF012FF8 = 0; otherwise nothing more. p2 is not used.
 */
extern unsigned int _DAT_a802d6a4;
#define _DAT_cf012e80 (*(volatile unsigned int *)0xcf012e80)
#define _DAT_cf012ff0 (*(volatile unsigned int *)0xcf012ff0)
#define _DAT_cf012ff4 (*(volatile unsigned int *)0xcf012ff4)
#define _DAT_cf012ff8 (*(volatile unsigned int *)0xcf012ff8)
extern void FUN_a00f2f88();

void FUN_a0118b0c(unsigned int param_1, unsigned int param_2) {
    unsigned int uVar1;

    _DAT_cf012ff0 = _DAT_cf012ff0 & 0xffffff7f;
    _DAT_cf012e80 = 6;
    FUN_a00f2f88(0xf4, 0, 0x400, param_1);
    uVar1 = *(unsigned short *)(_DAT_a802d6a4 + 10);
    if (uVar1 > 0x86f) {
        _DAT_cf012ff0 = 0xb;
        _DAT_cf012ff4 = 0;
        _DAT_cf012ff8 = 1;
    } else if (uVar1 > 0x437) {
        _DAT_cf012ff0 = 0xa;
        _DAT_cf012ff4 = 0x40;
        _DAT_cf012ff8 = 0;
    }
}
