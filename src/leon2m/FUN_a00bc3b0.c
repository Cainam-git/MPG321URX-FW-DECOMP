/* leon2m FUN_a00bc3b0 @ 0xa00bc3b0-0xa00bc3f8 (18 words), flags -mcpu=v8 -O3 -g.
 * Reply builder: writes '0', '0' and '0' + byte 0xa802d2a1 into bytes 7, 8 and 9 of the transmit buffer
 * 0xa802d078, fills the frame header with FUN_a00bacc4(6), clears the port's receive state (FUN_a00ba950) and
 * sends 11 bytes of the buffer with FUN_a01487e8 directly. No direct callers (reached through a table).
 */
extern unsigned char DAT_a802d2a1;
extern unsigned char DAT_a802d078[];
extern void FUN_a00bacc4(unsigned char);
extern void FUN_a00ba950(unsigned char);
extern void FUN_a01487e8(unsigned char, int, unsigned char *);

void FUN_a00bc3b0(unsigned char port)
{
    DAT_a802d078[7] = '0';
    DAT_a802d078[8] = '0';
    DAT_a802d078[9] = DAT_a802d2a1 + '0';
    FUN_a00bacc4(6);
    FUN_a00ba950(port);
    FUN_a01487e8(port, 0xb, DAT_a802d078);
}
