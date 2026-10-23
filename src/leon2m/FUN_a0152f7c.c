/* leon2m FUN_a0152f7c @ 0xa0152f7c (-mcpu=v8 -O2 -g)
 * If func_0x4008c194(1) & 0xff == 0x55 (RAM copy of FUN_a002c194), tail-calls func_0x4008fa34 (RAM copy of
 * FUN_a002fa34); otherwise returns.
 */
/* 0x4008c194 */
extern int func_0x4008c194(int);
/* 0x4008fa34 */
extern void func_0x4008fa34(void);

void FUN_a0152f7c(void)
{
    if ((func_0x4008c194(1) & 0xff) == 0x55) {
        func_0x4008fa34();
    }
}
