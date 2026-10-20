/* leon2s FUN_a008ae18 @ 0xa008ae18 (-mcpu=v8 -Os -g)
 * Sets bit param_1 of the byte 0xA8078B31: load byte, 'sll %o5, %o0, %o5' with %o5 = 1, or, store.
 */
extern unsigned char DAT_a8078b31;

void FUN_a008ae18(unsigned char param_1)
{
    DAT_a8078b31 = (unsigned char)((1 << param_1) | DAT_a8078b31);
    return;
}
