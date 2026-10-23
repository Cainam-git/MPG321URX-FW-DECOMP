/* FUN_a0095ea4 (leon2s 0xa0095ea4-0xa0095ef8, 84 bytes; includes the unreachable ret/restore tail at 0xa0095ef0),
 * flags -mcpu=v8 -Os -g.
 * When FUN_a009584c() returns a zero byte: FUN_a0095e08(0), FUN_a0095e08(1), FUN_a00916a8(0), FUN_a00916a8(1),
 * FUN_a00958d4(0) and the tail call FUN_a00958d4(1). The argument 1 of the tail call is set in %i0 in the delay
 * slot of the first call.
 */
extern unsigned char FUN_a009584c(void);
extern void FUN_a0095e08(unsigned char);
extern void FUN_a00916a8(unsigned char);
extern void FUN_a00958d4(unsigned char);

void FUN_a0095ea4(void)
{
    if (FUN_a009584c() == 0) {
        FUN_a0095e08(0);
        FUN_a0095e08(1);
        FUN_a00916a8(0);
        FUN_a00916a8(1);
        FUN_a00958d4(0);
        FUN_a00958d4(1);
    }
}
