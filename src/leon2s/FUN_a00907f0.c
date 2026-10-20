/* FUN_a00907f0 (leon2s, 0xa00907f0-0xa00908d0, 56 words). Flags -mcpu=v8 -Os -g.
 Code facts: (u8 port, u8 *buf). w = FUN_a00a6544(0, port, 0x140); buf[0] = byte 0, buf[2] = byte 2. If byte 0 == 0x82 and byte 2 != 0: buf[1], buf[3] =
 bytes 1 and 3; for loop = 0, 4, 8: the 4 bytes of a6544(0, port, 0x144 + loop) go to buf[4 + loop ..]; the low 3 bytes of a6544(0, port, 0x150) go to
 buf[0x10..0x12]; return 1. Otherwise FUN_a00b15ac(buf, 0, 0x16) (memset) and return 0.
 Fixes vs draft: FUN_a00a6544's 3rd parameter is unsigned short (fw sll/srl 16 on loop + 0x144; the draft masked & 0xffff by hand);
 the last three stores in ascending source order 0x10, 0x11, 0x12. Aids: none.
 */
extern unsigned int FUN_a00a6544(unsigned int, unsigned int, unsigned short);
extern int FUN_a00b15ac(unsigned char *, unsigned int, unsigned int);

int FUN_a00907f0(unsigned char param_1, unsigned char *buf)
{
    unsigned int uVar1;
    unsigned int uVar2;
    unsigned int byte_16;
    unsigned int byte_0;
    int loop;

    uVar1 = FUN_a00a6544(0, param_1 & 0xff, 0x140);
    byte_0 = uVar1 & 0xff;
    byte_16 = (uVar1 >> 0x10) & 0xff;
    buf[0] = (unsigned char)byte_0;
    buf[2] = (unsigned char)byte_16;
    if (byte_0 == 0x82) {
        if (byte_16 != 0) {
            buf[1] = (unsigned char)(uVar1 >> 8);
            buf[3] = (unsigned char)(uVar1 >> 0x18);
            for (loop = 0; loop <= 0xb; loop = loop + 4) {
                uVar2 = FUN_a00a6544(0, param_1 & 0xff, loop + 0x144);
                buf[loop + 5] = (unsigned char)(uVar2 >> 8);
                buf[loop + 6] = (unsigned char)(uVar2 >> 0x10);
                buf[loop + 4] = (unsigned char)uVar2;
                buf[loop + 7] = (unsigned char)(uVar2 >> 0x18);
            }
            uVar2 = FUN_a00a6544(0, param_1 & 0xff, 0x150);
            buf[0x10] = (unsigned char)uVar2;
            buf[0x11] = (unsigned char)(uVar2 >> 8);
            buf[0x12] = (unsigned char)(uVar2 >> 0x10);
            return 1;
        }
    }
    FUN_a00b15ac(buf, 0, 0x16);
    return 0;
}
