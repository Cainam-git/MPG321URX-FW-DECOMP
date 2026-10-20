/* leon2m FUN_a0152f7c @ 0xa0152f7c (-mcpu=v8 -O2 -g)
 * This function calls `func_0x4008c194` with argument 1, masks the return value to its low byte, and if that byte equals 0x55 it tail-calls `func_0x4008fa34`; otherwise it simply returns. The only uncertainty is the exact semantics of the two external functions (their names are address-based placeholders), but the control flow and the `mov 1, %o0` in the call's delay slot are fully determined by the target assembly.
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
