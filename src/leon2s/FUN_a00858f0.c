/* leon2s FUN_a00858f0 @ 0xa00858f0 (-mcpu=v8 -Os -g)
 * Returns byte +1 of the 40-byte record (p & 0xff) at 0xA807A928.
 * Source form: Ghidra's type and symbol names are kept.
 */
extern unsigned char ARR_a807a928[];

unsigned char FUN_a00858f0(unsigned int param_1)
{
    return ARR_a807a928[(param_1 & 0xff) * 40 + 1];
}
