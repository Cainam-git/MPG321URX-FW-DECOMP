/* leon2m FUN_a0118b0c @ 0xa0118b0c  MATCH (-mcpu=v8 -O2 -g)
 * 
 */
extern unsigned int _DAT_a802d6a4;
#define _DAT_cf012e80 (*(volatile unsigned int *)0xcf012e80)
#define _DAT_cf012ff0 (*(volatile unsigned int *)0xcf012ff0)
#define _DAT_cf012ff4 (*(volatile unsigned int *)0xcf012ff4)
#define _DAT_cf012ff8 (*(volatile unsigned int *)0xcf012ff8)
extern void FUN_a00f2f88();

void FUN_a0118b0c(unsigned int param_1, unsigned int param_2) {
    unsigned int uVar1;
    unsigned int uVar2;

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
        uVar2 = param_1;
    } else {
        uVar2 = 10;
    }
    return (int)uVar2;
}
