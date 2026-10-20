/* leon2s FUN_a00b0264 @ 0xa00b0264  MATCH (-mcpu=v8 -Os -g)
 * Returns byte 0xB5 of the 300-byte entry (param_1 & 0xFF) of the table at 0xA807DC18.
 */
extern unsigned char ARR_a807dc18[];

unsigned char FUN_a00b0264(unsigned int param_1)
{
    return ARR_a807dc18[(param_1 & 0xff) * 300 + 0xb5];
}
