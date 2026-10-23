/* leon2s FUN_a00911bc @ 0xa00911bc (-mcpu=v8 -Os -g)
 * q = p & 1; r = FUN_a0074f60(q); when byte +4 of the 24-byte entry q at 0xA807CC64 is non-zero, r <<= 2; returns
 * (u16)r. Source form: the array is declared at 0xA807CC64 with the +4 in the index.
 */
extern int FUN_a0074f60();
extern unsigned char ARR_a807cc64[];

unsigned short FUN_a00911bc(unsigned int param_1)
{
    unsigned int uVar1;
    
    param_1 = param_1 & 1;
    uVar1 = FUN_a0074f60(param_1);
    if (ARR_a807cc64[param_1 * 24 + 4] != 0) {
        uVar1 = uVar1 << 2;
    }
    return (unsigned short)uVar1;
}
