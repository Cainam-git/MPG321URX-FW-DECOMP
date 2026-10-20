/* leon2m FUN_a00bdec0 @ 0xa00bdec0-0xa00bdf28 (26 words), flags -mcpu=v8 -O3 -g.
 * Reply builder: writes the 11-byte frame "5b00\\00011\r" into the transmit buffer 0xa802d078, clears the port's
 * receive state (FUN_a00ba950) and sends 0x26 bytes (FUN_a00babe4). No direct callers (reached through a table).
 */
extern unsigned char DAT_a802d078[];
extern void FUN_a00ba950(unsigned char);
extern void FUN_a00babe4(unsigned char, unsigned char);

void FUN_a00bdec0(unsigned char port)
{
    DAT_a802d078[0] = '5';
    DAT_a802d078[1] = 'b';
    DAT_a802d078[2] = '0';
    DAT_a802d078[3] = '0';
    DAT_a802d078[4] = '\\';
    DAT_a802d078[5] = '0';
    DAT_a802d078[6] = '0';
    DAT_a802d078[7] = '0';
    DAT_a802d078[8] = '1';
    DAT_a802d078[9] = '1';
    DAT_a802d078[10] = '\r';
    FUN_a00ba950(port);
    FUN_a00babe4(port, 0x26);
}
