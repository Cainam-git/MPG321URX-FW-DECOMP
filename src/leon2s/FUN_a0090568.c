/* leon2s FUN_a0090568 @ 0xa0090568-0xa0090638 (52 words), flags -mcpu=v8 -Os -g. BYTE-EXACT: jf 100.00 match=True,
 * rawcmp_l2s.py 0/52 mismatches.
 * Code facts: (u8 port, u8 *buf) -> int. Packet capture of one HDMI receiver port: w = FUN_a00a6544(0, port, 0x160)
 * (32-bit word of the packet RAM, 0xce000000 | (u16 base[port] + offset)); the same copy as FUN_a0090498 (twin): byte 0 != 0 -> bytes 1..3,
 * words 0x164..0x178 -> buf[4..0x1b], low 3 bytes of word 0x17c -> buf[0x1c..0x1e], return 1; else memset 0x22, 0.
 * Area 0x160 is the one FUN_a008f79c parses (bytes 0x164..0x166 == 1A 00 00 = AMD OUI, reference knowledge).
 * Caller: FUN_a00908d0 (RX status poll in LINK_STANDBY state 5) when RX reg 0x73 bit 1 is set and FUN_a008f79c(port) == 0 and the third of the 3 flag bytes after the buf area is 0 (the other two are set to 1 first);
 * buf is inside the per-port RX state ARR_a807d3e4[port]. Not the source of the Big chip's keep-going bit (that is
 * rec+0xa6 in FUN_a00908d0). Matching form: the FUN_a0090498 form. Aids: none.
 */
extern unsigned int FUN_a00a6544(unsigned int, unsigned int, unsigned short);
extern int FUN_a00b15ac(unsigned char *, unsigned int, unsigned int);

int FUN_a0090568(unsigned char port, unsigned char *buf)
{
    unsigned int w;
    unsigned int w2;
    int loop;
    unsigned int b0;

    w = FUN_a00a6544(0, port, 0x160);
    b0 = w & 0xff;
    buf[0] = b0;
    if (b0 != 0) {
        buf[1] = (unsigned char)(w >> 8); buf[2] = (unsigned char)(w >> 0x10); buf[3] = (unsigned char)(w >> 0x18);
        for (loop = 0; loop <= 0x17; loop = loop + 4) {
            w2 = FUN_a00a6544(0, port, loop + 0x164);
            buf[loop + 4] = (unsigned char)w2; buf[loop + 5] = (unsigned char)(w2 >> 8); buf[loop + 6] = (unsigned char)(w2 >> 0x10); buf[loop + 7] = (unsigned char)(w2 >> 0x18);
        }
        w = FUN_a00a6544(0, port, 0x17c);
        buf[0x1c] = (unsigned char)w; buf[0x1d] = (unsigned char)(w >> 8); buf[0x1e] = (unsigned char)(w >> 0x10);
        return 1;
    }
    FUN_a00b15ac(buf, 0, 0x22);
    return 0;
}
