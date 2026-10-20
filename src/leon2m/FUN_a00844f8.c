/* leon2m FUN_a00844f8 @ 0xa00844f8 (-mcpu=v8 -O2 -g)
 * The function calls `FUN_a014448c(1)`, checks the lower 8 bits of the result against 0xd, and if equal also checks that `_DAT_a8024006 <= _DAT_a8024004`. It returns 1 if both conditions hold, else 0 (masked with 1). The main uncertainty is the exact return type—the target ends with `and %i0, 1, %i0` before `ret; restore`, suggesting the return value is masked, but the C return type could be int with the mask applied explicitly.
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
