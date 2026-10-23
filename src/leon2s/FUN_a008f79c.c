/* leon2s FUN_a008f79c @ 0xa008f79c  VRR signalling detector of an HDMI receiver port
 * -Os).
 *
 * Reads receiver register bytes with FUN_a00a657c(port, reg) (= byte at 0xCF000000 | (base[port] + reg) * 4, base
 * table 0xA00B4D9C; ports 0 and 1 only, other ports read 0) and returns flags:
 *   regs 0x164..0x166 == 1A 00 00: reg 0x161 == 1 -> bit 0 from reg 0x169 bit 0; reg 0x161 == 2 or 3 -> bit 0 |= reg
 *     0x169 bit 0; reg 0x16C bit 5 clear -> |= 0x10, set -> |= 2 and bit 4 = !(reg 0x169 bit 5);
 *   regs 0x360 == 0x7F, 0x363 & 0x3F == 4, 0x364..0x367 == 00 01 00 01: reg 0x36A & 3 == 1 -> result = 4 (replaces
 *     the bits above), == 3 -> result = 8.
 * Constants (HDMI / AMD specifications): 00 00 1A = AMD OUI in the FreeSync SPD InfoFrame (0x161 = its
 *   version); 0x7F = HDMI 2.1 Extended Metadata Packet, organisation 1 / tag 1 = VTEM,
 *   0x36A bits 0-1 = VRR_EN / M_CONST.
 * Caller: FUN_a006d61c(rec, port) sets rec[0xd] bit 2 when the result has bit 0 or bit 2; that byte reaches the
 *   main chip through mailbox portal 1 and ends in the 0xA802CBD4 port bit that selects the hfreq branch of
 *   FUN_a00dac38 (Leon2M).
 * key: the 0x16C test written as if (bit set) { r |= 2; if (0x169 bit 5) r &= ~0x10; else r |= 0x10; }
 *   else r |= 0x10; (other orders lose the be,a / bne delay-slot shape).
 */
extern unsigned int FUN_a00a657c(unsigned int param_1, unsigned short param_2);

unsigned char FUN_a008f79c(unsigned char port)
{
    unsigned char r = 0;

    if ((unsigned char)FUN_a00a657c(port, 0x164) == 0x1a && (unsigned char)FUN_a00a657c(port, 0x165) == 0
        && (unsigned char)FUN_a00a657c(port, 0x166) == 0) {
        if ((unsigned char)FUN_a00a657c(port, 0x161) == 1) {
            if (FUN_a00a657c(port, 0x169) & 1) r = 1;
        }
        if ((unsigned char)FUN_a00a657c(port, 0x161) == 2 || (unsigned char)FUN_a00a657c(port, 0x161) == 3) {
            if (FUN_a00a657c(port, 0x169) & 1) r |= 1;
            if (FUN_a00a657c(port, 0x16c) & 0x20) {
                r |= 2;
                if (FUN_a00a657c(port, 0x169) & 0x20) r &= ~0x10;
                else r |= 0x10;
            } else r |= 0x10;
        }
    }
    if ((unsigned char)FUN_a00a657c(port, 0x360) == 0x7f && (FUN_a00a657c(port, 0x363) & 0x3f) == 4
        && (unsigned char)FUN_a00a657c(port, 0x364) == 0 && (unsigned char)FUN_a00a657c(port, 0x365) == 1
        && (unsigned char)FUN_a00a657c(port, 0x366) == 0 && (unsigned char)FUN_a00a657c(port, 0x367) == 1) {
        if ((FUN_a00a657c(port, 0x36a) & 3) == 1) r = 4;
        else if ((FUN_a00a657c(port, 0x36a) & 3) == 3) r = 8;
    }
    return r;
}
