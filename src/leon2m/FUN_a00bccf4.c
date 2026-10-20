/* leon2m FUN_a00bccf4 @ 0xa00bccf4-0xa00bcd54 (24 words), flags -mcpu=v8 -O3 -g.
 * Reply builder: with i = byte 0xa802cffd, writes '0', '0' + byte 0xa802d427[i] and '0' + byte 0xa802d42b[i]
 * into bytes 7, 8 and 9 of the transmit buffer 0xa802d078, fills the frame header with FUN_a00bac3c(0x1c), clears
 * the port's receive state (FUN_a00ba950) and sends 11 bytes (FUN_a00babe4). No direct callers (reached through
 * a table). The two byte arrays are members of the structure at 0xa802d290 (offsets 0x197 and 0x19b).
 */
struct R290 { unsigned char p000[0x197]; unsigned char a197[4]; unsigned char a19b[4]; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802cffd;
extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c(unsigned char);
extern void FUN_a00ba950(unsigned char);
extern void FUN_a00babe4(unsigned char, unsigned char);

void FUN_a00bccf4(unsigned char port)
{
    DAT_a802d078[7] = '0';
    DAT_a802d078[8] = DAT_a802d290.a197[DAT_a802cffd] + '0';
    DAT_a802d078[9] = DAT_a802d290.a19b[DAT_a802cffd] + '0';
    FUN_a00bac3c(0x1c);
    FUN_a00ba950(port);
    FUN_a00babe4(port, 0xb);
}
