/* leon2s FUN_a009c434 @ 0xa009c434-0xa009c468 (13 words), flags -mcpu=v8 -Os -g.
 * Returns FUN_a00a7408(1, word +4 of the 52-byte port record DAT_a807db00[port]) != 0.
 * The base is DAT_a807db00 as a 52-byte struct; u8 param.
 */
struct port_rec { unsigned int w0; unsigned int w4; unsigned char rest[0x2c]; };
extern struct port_rec DAT_a807db00[];
extern unsigned int FUN_a00a7408(unsigned int, unsigned int);

int FUN_a009c434(unsigned char port)
{
    return FUN_a00a7408(1, DAT_a807db00[port].w4) != 0;
}
