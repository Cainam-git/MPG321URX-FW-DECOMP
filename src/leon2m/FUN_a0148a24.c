/* FUN_a0148a24: returns 1 when FUN_a00de9f8(0) == 1 and FUN_a00de9f8(1) == 0x11; in that case it also prints
 * "WakeUpByPowerKey !" (s_001a6f10) and calls FUN_a0124b40() and FUN_a0124ab0(). When FUN_a00de9f8(0) != 1 it
 * reads FUN_a00de9f8(0) again and, unless that is 2, once more; it returns 0 then. Callers: FUN_a0083b60,
 * FUN_a0087020. The result is a _Bool (the firmware masks it with 1 before returning).
 */
extern unsigned char FUN_a00de9f8(unsigned char idx);
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a0124b40(void);
extern void FUN_a0124ab0(void);
extern char s_001a6f10[];             /* "WakeUpByPowerKey !\n" */

_Bool FUN_a0148a24(void)
{
    _Bool r = 0;

    if (FUN_a00de9f8(0) == 1) {
        if (FUN_a00de9f8(1) == 0x11) {
            r = 1;
            FUN_a00df170(s_001a6f10);
            FUN_a0124b40();
            FUN_a0124ab0();
        }
    } else if (FUN_a00de9f8(0) != 2) {
        FUN_a00de9f8(0);
    }
    return r;
}
