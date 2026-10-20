/* leon2s FUN_a00876ec @ 0xa00876ec  MATCH (-mcpu=v8 -Os -g)
 * Returns byte 0x15 of row (param_1 & 0xFF) of the table at 0xA807A928 (40-byte rows). GCC computes the row offset
 * as ((x << 2) + x) << 3 = x * 40. Same shape as FUN_a00858f0 and FUN_a0091c38 (other strides and offsets).
 */
extern unsigned char ARR_a807a928[];

unsigned char FUN_a00876ec(unsigned int param_1)
{
    return ARR_a807a928[(param_1 & 0xff) * 40 + 0x15];
}
