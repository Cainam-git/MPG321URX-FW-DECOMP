/* leon2m FUN_a01099fc @ 0xa01099fc-0xa0109ad0 (53 words).
 * Writes a and b through FUN_a00f308c to a pair of hardware registers chosen by sel: 0 = 0xcf011de0 / 0xcf011de8,
 * 1 = 0xcf011df0 / 0xcf011df8, 2 = 0xcf011e00 / 0xcf011e08, 3 = 0xcf011e10 / 0xcf011e18 (a then b, the second call
 * in tail position). Other sel values do nothing. No direct callers were found.
 */
extern void FUN_a00f308c(volatile unsigned int *r, unsigned int v);

void FUN_a01099fc(unsigned char sel, unsigned short a, unsigned short b)
{
    switch (sel) {
    case 0:
        FUN_a00f308c((volatile unsigned int *)0xcf011de0, a);
        FUN_a00f308c((volatile unsigned int *)0xcf011de8, b);
        break;
    case 1:
        FUN_a00f308c((volatile unsigned int *)0xcf011df0, a);
        FUN_a00f308c((volatile unsigned int *)0xcf011df8, b);
        break;
    case 2:
        FUN_a00f308c((volatile unsigned int *)0xcf011e00, a);
        FUN_a00f308c((volatile unsigned int *)0xcf011e08, b);
        break;
    case 3:
        FUN_a00f308c((volatile unsigned int *)0xcf011e10, a);
        FUN_a00f308c((volatile unsigned int *)0xcf011e18, b);
        break;
    }
}
