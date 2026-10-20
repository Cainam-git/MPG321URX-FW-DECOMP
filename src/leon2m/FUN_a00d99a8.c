/* leon2m FUN_a00d99a8 @ 0xa00d99a8 (-mcpu=v8 -O2 -g)
 * 
 */
extern unsigned int _DAT_a802d338;
extern void FUN_a0125c34(void);
extern void FUN_a0125c3c(void);
extern unsigned char FUN_a012792c(void);
extern unsigned char FUN_a0127944(void);

void FUN_a00d99a8(void)
{
    if (FUN_a012792c() != 0) {
        FUN_a0125c34();
        return;
    }
    if (FUN_a0127944() != 0) {
        FUN_a0125c34();
        return;
    }
    if ((_DAT_a802d338 & 0x20) != 0) {
        FUN_a0125c34();
        return;
    }
    FUN_a0125c3c();
}
