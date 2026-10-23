/* leon2m FUN_a0123840 @ 0xa0123840-0xa01238e8 (42 words).
 * Polls for up to 25000 ticks of func_0x4008d594 (elapsed since the start value t from func_0x4008d588). Each
 * round: FUN_a0121374(0) == 1 ends the wait with result 0; register 0xcf03c640 > 0x83 sets byte DAT_a802d87e = 0
 * and ends with result 1; register 0xcf03c648 > 0x83 sets DAT_a802d87e = 1 and ends with result 1; otherwise
 * func_0x4008ced8() is called. The timeout returns 0. Called by FUN_a0147c94.
 * Source form: unsigned char result returned as r & 1; the start tick is an unsigned short local. Flags include
 * -msoft-float (the register addresses are rebuilt inside the loop instead of being hoisted).
 */
#define REG_cf03c640 (*(volatile unsigned int *)0xcf03c640)
#define REG_cf03c648 (*(volatile unsigned int *)0xcf03c648)

extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short start);
extern void func_0x4008ced8(void);
extern unsigned char FUN_a0121374(unsigned char blk);
extern unsigned char DAT_a802d87e;

unsigned char FUN_a0123840(void)
{
    unsigned short t;

    t = func_0x4008d588();
    unsigned char r = 0;

    do {
        if (FUN_a0121374(0) == 1)
            break;
        if (REG_cf03c640 > 0x83) {
            DAT_a802d87e = 0;
            r = 1;
            break;
        }
        if (REG_cf03c648 > 0x83) {
            DAT_a802d87e = 1;
            r = 1;
            break;
        }
        func_0x4008ced8();
    } while (func_0x4008d594(t) < 25000);
    return r & 1;
}
