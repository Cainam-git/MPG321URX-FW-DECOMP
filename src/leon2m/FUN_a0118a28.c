/* leon2m FUN_a0118a28 @ 0xa0118a28 (-mcpu=v8 -O2 -g)
 * The function masks `param_1` to 8 bits. If `param_2` is nonzero (fall-through path), it calls `FUN_a00f2b48(param_1, 0x10)`, ORs the result with 1, masks to 8 bits, and tail-calls `FUN_a00f2b8c(param_1, 0x10, that_value)`. If `param_2` is zero (branch target), it calls the same first function, ANDs the result with 0xfe, and tail-calls the second with that. Both paths return nothing. The two separate call sites for `FUN_a00f2b48` match the two blocks in the assembly.
 */
extern int FUN_a00f2b48();
extern int FUN_a00f2b8c();

void FUN_a0118a28(unsigned char param_1, unsigned char param_2)
{
    unsigned char uVar;
    
    param_1 &= 0xff;
    if (param_2 != 0) {
        uVar = FUN_a00f2b48(param_1, 0x10);
        FUN_a00f2b8c(param_1, 0x10, (uVar | 1) & 0xff);
    } else {
        uVar = FUN_a00f2b48(param_1, 0x10);
        FUN_a00f2b8c(param_1, 0x10, uVar & 0xfe);
    }
}
