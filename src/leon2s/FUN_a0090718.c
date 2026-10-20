/* leon2s FUN_a0090718 @ 0xa0090718-0xa00907f0 (54 words), flags -mcpu=v8 -Os -g. BYTE-EXACT: jf 100.00 match=True,
 * rawcmp_l2s.py 0/54 mismatches.
 * Code facts: (u8 port, u8 *buf) -> int. Packet capture of one HDMI receiver port: w = FUN_a00a6544(0, port, 0x180)
 * (32-bit word of the packet RAM, 0xce000000 | (u16 base[port] + offset)); buf[0] = byte 0, buf[2] = byte 2; byte 0 == 0x84 and byte 2 != 0:
 * buf[1], buf[3] = bytes 1, 3; words 0x184, 0x188 -> buf[4..0xb]; low 2 bytes of word 0x18c -> buf[0xc], buf[0xd];
 * return 1. Otherwise memset(buf, 0, 0x11), return 0. (0x84 = CTA-861 Audio InfoFrame type: reference knowledge.)
 * Caller: FUN_a00908d0 (RX status poll in LINK_STANDBY state 5) when RX reg 0x73 bit 2 is set and the third of the 3 flag bytes after the buf area is 0 (the other two are set to 1 first);
 * buf is inside the per-port RX state ARR_a807d3e4[port]. Not the source of the Big chip's keep-going bit (that is
 * rec+0xa6 in FUN_a00908d0). Matching form: the byte-exact FUN_a00907f0 form. Aids: none.
 */
extern unsigned int FUN_a00a6544(unsigned int, unsigned int, unsigned short);
extern int FUN_a00b15ac(unsigned char *, unsigned int, unsigned int);

int FUN_a0090718(unsigned char port, unsigned char *buf)
{
    unsigned int uVar1;
    unsigned int uVar2;
    unsigned int byte_16;
    unsigned int byte_0;
    int loop;

    uVar1 = FUN_a00a6544(0, port, 384);
    byte_0 = uVar1 & 0xff;
    byte_16 = (uVar1 >> 0x10) & 0xff;
    buf[0] = (unsigned char)byte_0;
    buf[2] = (unsigned char)byte_16;
    if (byte_0 == 0x84) {
        if (byte_16 != 0) {
            buf[1] = (unsigned char)(uVar1 >> 8);
            buf[3] = (unsigned char)(uVar1 >> 0x18);
            for (loop = 0; loop <= 7; loop = loop + 4) {
                uVar2 = FUN_a00a6544(0, port, loop + 0x184);
                buf[loop + 5] = (unsigned char)(uVar2 >> 8);
                buf[loop + 6] = (unsigned char)(uVar2 >> 0x10);
                buf[loop + 4] = (unsigned char)uVar2;
                buf[loop + 7] = (unsigned char)(uVar2 >> 0x18);
            }
            uVar2 = FUN_a00a6544(0, port, 0x18c);
            buf[0xc] = (unsigned char)uVar2;
            buf[0xd] = (unsigned char)(uVar2 >> 8);
            return 1;
        }
    }
    FUN_a00b15ac(buf, 0, 0x11);
    return 0;
}
