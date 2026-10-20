/* leon2m FUN_a0125124 @ 0xa0125124  MATCH (-mcpu=v8 -O2 -g)
 * Returns byte 2 of row (param_1 & 0xFF) of the ROM table at 0x1A42A8 (22-byte rows, stride 0x16). The base is
 * loaded with sethi/or, followed by a single byte load.
 */
// FUN_a0125124 at 0xa0125124
extern unsigned char DAT_001a42a8[];  // placed at 0x1a42a8 (base for the table)

unsigned char FUN_a0125124(unsigned int param_1)
{
    return DAT_001a42a8[(param_1 & 0xff) * 0x16 + 2];
}
