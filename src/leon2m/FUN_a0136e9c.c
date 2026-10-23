/* leon2m FUN_a0136e9c @ 0xa0136e9c (-mcpu=v8 -O3 -g)
 * Packs the eight bytes 0xA802A450 .. 0xA802A457 as 4-bit fields (byte n at bit 4 * n) into one word and writes it
 * through func_0x4008c5f8(1, 4, &w, 1); then writes (byte 0xA802A457) << 16 through func_0x4008c5f8(1, 8, &w2, 1).
 * Source form: Ghidra's type and symbol names are kept.
 */
extern unsigned char DAT_a802a450[];
extern unsigned char DAT_a802a457;
extern void func_0x4008c5f8();

void FUN_a0136e9c(void)
{
    unsigned int local_c;
    unsigned int local_10 = 0;

    local_c = DAT_a802a450[0] | (DAT_a802a450[1] << 4) |
              (DAT_a802a450[2] << 8) | (DAT_a802a450[3] << 12) |
              (DAT_a802a450[4] << 16) | (DAT_a802a450[5] << 20) |
              (DAT_a802a450[6] << 24) | (DAT_a802a450[7] << 28);

    func_0x4008c5f8(1, 4, &local_c, 1);

    local_10 = (unsigned int)DAT_a802a457 << 16;
    func_0x4008c5f8(1, 8, &local_10, 1);
}
