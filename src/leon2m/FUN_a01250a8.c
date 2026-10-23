/* leon2m FUN_a01250a8 @ 0xa01250a8 (-mcpu=v8 -O2 -g)
 * Returns byte 1 of the 22-byte (0x16) record (p & 0xff) of the table at 0x1a42a8.
 */
extern unsigned char DAT_001a42a8[]; /* 0x1a42a8 */

unsigned char FUN_a01250a8(unsigned int param_1)
{
    return DAT_001a42a8[(param_1 & 0xff) * 0x16 + 1];
}
