/* FUN_a00a10ec (leon2s 0xa00a10ec-0xa00a1104, 24 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Clears word i of DAT_a8079184. Address word at 0xa00b86f8.
 * Leaf routine without a register window (no save).
 */
extern unsigned int DAT_a8079184[];

void FUN_a00a10ec(unsigned char i)
{
    DAT_a8079184[i] = 0;
}
