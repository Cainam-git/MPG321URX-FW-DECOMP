/* leon2m FUN_a00bcb38 @ 0xa00bcb38 (-mcpu=v8 -O3 -g)
 * Reply frame 0xA802D078: bytes 7, 8 = '0', byte 9 = '0' + word 0xA802D340; then FUN_a00bac3c(0x16) (frame bytes from
 * command-table row 0x16), FUN_a00ba950(port) and FUN_a00babe4(port, 0xb) (sends 11 bytes, tail call).
 */
extern unsigned char DAT_a802d078[];
extern unsigned int DAT_a802d340;
extern void FUN_a00bac3c(unsigned char param_1);
extern void FUN_a00ba950(unsigned char port);
extern void FUN_a00babe4(unsigned char param_1, unsigned char param_2);

void FUN_a00bcb38(unsigned char port)
{
    DAT_a802d078[7] = 0x30;
    DAT_a802d078[8] = 0x30;
    DAT_a802d078[9] = DAT_a802d340 + 0x30;
    FUN_a00bac3c(0x16);
    FUN_a00ba950(port);
    FUN_a00babe4(port, 0xb);
}
