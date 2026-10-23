/* leon2m FUN_a00be38c @ 0xa00be38c (-mcpu=v8 -O3 -g)
 * Reply frame 0xA802D078: bytes 7, 8 = '0', byte 9 = '0' + bit 30 of word 0xA802D484; then FUN_a00bac3c(0x6f) (frame bytes from
 * command-table row 0x6f), FUN_a00ba950(port) and FUN_a00babe4(port, 0xb) (sends 11 bytes, tail call).
 */
extern unsigned char DAT_a802d078[];
extern unsigned int _DAT_a802d484;
extern void FUN_a00bac3c(unsigned char param_1);
extern void FUN_a00ba950(unsigned char port);
extern void FUN_a00babe4(unsigned char param_1, unsigned char param_2);

void FUN_a00be38c(unsigned char port)
{
    DAT_a802d078[7] = 0x30;
    DAT_a802d078[8] = 0x30;
    DAT_a802d078[9] = ((_DAT_a802d484 >> 0x1e) & 1) + 0x30;
    FUN_a00bac3c(0x6f);
    FUN_a00ba950(port);
    FUN_a00babe4(port, 0xb);
}
