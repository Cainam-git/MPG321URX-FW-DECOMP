/* leon2m FUN_a00844f8 @ 0xa00844f8 (-mcpu=v8 -O2 -g)
 * Returns 1 when FUN_a014448c(1) & 0xff == 0xd and the word 0xA8024006 <= the word 0xA8024004, else 0.
 * Source form: an unsigned char result r returned as 'r & 1' (the firmware ends with 'and %i0, 1, %i0').
 */
extern unsigned short _DAT_a8024004;
extern unsigned short _DAT_a8024006;
extern int FUN_a014448c();

int FUN_a00844f8()
{
    unsigned int uVar1;
    unsigned char iVar2;
    
    uVar1 = FUN_a014448c(1);
    iVar2 = 0;
    if (((uVar1 & 0xff) == 0xd) && (_DAT_a8024006 <= _DAT_a8024004)) {
        iVar2 = 1;
    }
    return iVar2 & 1;
}
