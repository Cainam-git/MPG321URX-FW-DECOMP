/* leon2s FUN_a0094c54 @ 0xa0094c54-0xa0094e40, -mcpu=v8 -Os -g.
 * (u8 port), void. Reads 16 byte registers of port through FUN_a00a7fd8(port, 0, reg) in the order 0x62, 0x63,
 * 0x66, 0x67, 0x6a, 0x6b, 0x3c, 0x3d, 0x60, 0x61, 0x64, 0x65, 0x68, 0x69, 0x3a, 0x3b. When bit 0 of register 9
 * is set, prints "... VTOTAL = 0x%02x%02x, VDE = ..., VSW = ..., VFP = ..." with the pairs (0x3d, 0x3c),
 * (0x63, 0x62), (0x67, 0x66), (0x6b, 0x6a) and "... HTOTAL = ..., HDE = ..., HSW = ..., HFP = ..." with
 * (0x3b, 0x3a), (0x61, 0x60), (0x65, 0x64), (0x69, 0x68) through FUN_a0073044; otherwise passes
 * "... PSTABLE flag is failed" to FUN_a00734c4 (tail call). The values are unsigned char locals (three of them
 * live in the stack frame).
 */
extern short FUN_a00a7fd8(unsigned int, unsigned short, unsigned short);
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);

void FUN_a0094c54(unsigned char port)
{
    unsigned char v62, v63, v66, v67, v6a, v6b, v3c, v3d;
    unsigned char v60, v61, v64, v65, v68, v69, v3a, v3b;

    v62 = FUN_a00a7fd8(port, 0, 0x62);
    v63 = FUN_a00a7fd8(port, 0, 0x63);
    v66 = FUN_a00a7fd8(port, 0, 0x66);
    v67 = FUN_a00a7fd8(port, 0, 0x67);
    v6a = FUN_a00a7fd8(port, 0, 0x6a);
    v6b = FUN_a00a7fd8(port, 0, 0x6b);
    v3c = FUN_a00a7fd8(port, 0, 0x3c);
    v3d = FUN_a00a7fd8(port, 0, 0x3d);
    v60 = FUN_a00a7fd8(port, 0, 0x60);
    v61 = FUN_a00a7fd8(port, 0, 0x61);
    v64 = FUN_a00a7fd8(port, 0, 0x64);
    v65 = FUN_a00a7fd8(port, 0, 0x65);
    v68 = FUN_a00a7fd8(port, 0, 0x68);
    v69 = FUN_a00a7fd8(port, 0, 0x69);
    v3a = FUN_a00a7fd8(port, 0, 0x3a);
    v3b = FUN_a00a7fd8(port, 0, 0x3b);
    if (FUN_a00a7fd8(port, 0, 9) & 1) {
        FUN_a0073044("\x1b[0m\t\t - VTOTAL = 0x%02x%02x, VDE = 0x%02x%02x, VSW = 0x%02x%02x, VFP = 0x%02x%02x \n",
                     v3d, v3c, v63, v62, v67, v66, v6b, v6a);
        FUN_a0073044("\x1b[0m\t\t - HTOTAL = 0x%02x%02x, HDE = 0x%02x%02x, HSW = 0x%02x%02x, HFP = 0x%02x%02x \n",
                     v3b, v3a, v61, v60, v65, v64, v69, v68);
    } else
        FUN_a00734c4("\x1b[0m\t\t - PSTABLE flag is failed \n");
}
