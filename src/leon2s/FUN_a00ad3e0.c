/* leon2s FUN_a00ad3e0 @ 0xa00ad3e0 (-mcpu=v8 -Os -g)
 * Returns 1 when one of these holds, else 0: FUN_a0083ed0(p) & 0xFF (p = param_1 & 0xFF) is 1 and bit 6 of
 * register 0xCF0132C0 is set; that value is 0 and bit 7 of 0xCF0132C0 is set; byte +0x11F of p's 300-byte record
 * in the table at 0xA807DC18 is 1 and DAT_a8079316 is 1.
 */
extern int FUN_a0083ed0(int);
#define REG_CF0132C0 (*(volatile unsigned int *)0xcf0132c0)
extern unsigned char DAT_a8079316;

int FUN_a00ad3e0(int param_1)
{
    unsigned int result;
    unsigned char *p;
    
    param_1 &= 0xff;
    result = FUN_a0083ed0(param_1) & 0xff;
    
    if (result == 1) {
        if (REG_CF0132C0 & 0x40)
            return 1;
    } else if (result == 0) {
        if (REG_CF0132C0 & 0x80)
            return 1;
    }
    
    p = (unsigned char *)(param_1 * 300 + 0xa807dc18);
    if (p[0x11f] == 1 && DAT_a8079316 == 1)
        return 1;
    
    return 0;
}
