/* leon2s FUN_a00d66bc @ 0xa00d66bc (-mcpu=v8 -Os -g)
 * The `bne,a` (branch always with annul) for the second check means the delay slot instruction `clr %o0` executes only if the branch is taken, setting up the return value. The final `b` to the common return point is also needed.
 */
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8078828[];
extern unsigned char DAT_a8079400[];

unsigned int FUN_a00d66bc(unsigned int param_1, unsigned int param_2)
{
    unsigned int uVar1;
    unsigned int uVar2;
    
    if ((param_1 & 0xff) == 0) {
        if ((param_2 & 0xff) == 1) {
            uVar1 = DAT_a8078832;
            uVar2 = (DAT_a8078828[uVar1] & 0xf);
            uVar2 = uVar2 * 3;
            uVar1 = uVar1 * 3;
            return (uVar1 << 8) + (uVar2 << 4) + 0xa8079400 + 0x23d;
        }
    }
    return 0;
}
