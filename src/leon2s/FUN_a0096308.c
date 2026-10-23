/* leon2s FUN_a0096308 @ 0xa0096308 (-mcpu=v8 -Os)
 * Returns 1 when bytes +1 and +2 of the 400-byte record p at 0xA807D7E0 are both 1, else 0.
 */
extern unsigned char DAT_a807d7e0;
extern unsigned char DAT_a807d7e2;

int FUN_a0096308(int param_1)
{
    int uVar1;
    unsigned char *p = (unsigned char *)&DAT_a807d7e0 + param_1 * 400;
    
    uVar1 = 1;
    if ((p[1] != 1) || (p[2] != 1)) {
        uVar1 = 0;
    }
    return uVar1;
}
