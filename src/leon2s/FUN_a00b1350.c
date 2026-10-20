/* FUN_a00b1350 (leon2s 0xa00b1350-0xa00b1394, 68 bytes), flags -mcpu=v8 -Os -g.
 * Calls FUN_a00a6c98(port, 0x487, 4, v) three times for one port with v = 0, 1, 0; the last call is a tail call.
 * FUN_a00a6c98 takes the port as a byte and the second argument as a halfword.
 */
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned int, unsigned int);

void FUN_a00b1350(unsigned char port)
{
    FUN_a00a6c98(port, 0x487, 4, 0);
    FUN_a00a6c98(port, 0x487, 4, 1);
    FUN_a00a6c98(port, 0x487, 4, 0);
}
