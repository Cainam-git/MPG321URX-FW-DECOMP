/* leon2s FUN_a009193c @ 0xa009193c (-mcpu=v8 -Os -g)
 * Returns byte 0x15 of the 28-byte per-port record p (p = the parameter byte) in the table at 0xA807D580 (built as
 * 0xA807D400 | 0x180 by sethi/or). The multiplication by 28 compiles to the sll/sub/sll sequence.
 */
extern unsigned char ARR_a807d580[];

unsigned char FUN_a009193c(unsigned int param_1)
{
    return ARR_a807d580[(param_1 & 0xff) * 28 + 0x15];
}
