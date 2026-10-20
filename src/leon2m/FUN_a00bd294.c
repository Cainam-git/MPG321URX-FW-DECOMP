/* leon2m FUN_a00bd294 @ 0xa00bd294-0xa00bd2e0 (19 words), flags -mcpu=v8 -O3 -g.
 * Reply builder: writes '0', '0' and '0' + (halfword 0xa802d2c4 & 0xf) into bytes 7, 8 and 9 of the transmit
 * buffer 0xa802d078, fills the frame header with FUN_a00bac3c(0x25), clears the port's receive state
 * (FUN_a00ba950) and sends 11 bytes (FUN_a00babe4). No direct callers (reached through a table).
 * Source form: the low nibble is taken into an unsigned short local first; written inside the byte store, GCC
 * narrows the halfword load to a byte load.
 */
extern unsigned short DAT_a802d2c4;
extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c(unsigned char);
extern void FUN_a00ba950(unsigned char);
extern void FUN_a00babe4(unsigned char, unsigned char);

void FUN_a00bd294(unsigned char port)
{
    unsigned short v = DAT_a802d2c4 & 0xf;

    DAT_a802d078[7] = '0';
    DAT_a802d078[8] = '0';
    DAT_a802d078[9] = v + '0';
    FUN_a00bac3c(0x25);
    FUN_a00ba950(port);
    FUN_a00babe4(port, 0xb);
}
