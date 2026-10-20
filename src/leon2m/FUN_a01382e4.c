/* leon2m FUN_a01382e4 @ 0xa01382e4  MATCH (-mcpu=v8 -O2 -g)
 * Copies the bytes at offsets 0x30, 0x31 and 0x32 of the structure at 0xA802E3D0 into a zero-initialized 4-byte
 * local buffer and calls FUN_a01370dc(0x7E, 4, buf, 0). The three-element initializer of the 4-byte array produces
 * the firmware's clr [%fp-16] before the byte stores. Takes no arguments and returns nothing.
 */
extern int FUN_a01370dc();
extern unsigned char DAT_a802e3d0[];

void FUN_a01382e4(void)
{
    unsigned char local_10[4] = {DAT_a802e3d0[0x30], DAT_a802e3d0[0x31], DAT_a802e3d0[0x32]};
    FUN_a01370dc(0x7e, 4, local_10, 0);
}
