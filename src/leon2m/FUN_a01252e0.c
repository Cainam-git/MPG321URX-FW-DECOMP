/* leon2m FUN_a01252e0 @ 0xa01252e0  MATCH (-mcpu=v8 -O2 -g)
 * Returns byte 0xB of row (param_1 & 0xFF) of the ROM table at 0x1A42A8 (22-byte rows, stride 0x16). Same shape as
 * FUN_a0125124 (byte 2) and FUN_a01250a8 (byte 1). The constant row offset is folded into the load:
 * add followed by ldub [%o0 + 0xb].
 */
extern unsigned char DAT_001a42a8[]; /* 0x1a42a8 */

unsigned char FUN_a01252e0(unsigned int param_1)
{
    return DAT_001a42a8[(param_1 & 0xff) * 0x16 + 0xb];
}
