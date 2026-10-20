/* leon2s FUN_a006d61c @ 0xa006d61c  refresh the status flags of one input port record
 * -Os).
 *
 * rec = 20-byte port record (0xA807A824 + 20 * (id - 1)), port = receiver index. r = FUN_a008f79c(port) (the VRR
 * signalling detector, byte-exact):
 *   rec[0xd] bit 2 (0x04) = r bit 0 OR r bit 2   <- the line-rate switch
 *   rec[0xd] bit 3 = r bit 1; bit 4 = r bit 4; bit 7 = r bit 3; (each a separate read-modify-write of rec[0xd])
 *   halfword +0xe bit 14 = FUN_a008f9e4(port), bit 15 = FUN_a008f9c0(port);
 *   type rec[0] == 5: halfword +0x12 bit 6 = FUN_a0091420(0, port); other types: FUN_a0091420(1, port), bit 6 cleared;
 *   rec[0xd] bit 6 = bit <port> of 0xA8078C35, bit 5 = bit <port> of 0xA8078C5B.
 * rec[0xd] is published by FUN_a006fbac (byte 1 of descriptor word 0) through MailBox_Write FUN_a0072a4c to portal 1,
 * read by the Big chip's FUN_a01387a4 into template +0xc, copied by FUN_a0136d20 into port entry bit 4, and from
 * there reaches the line-rate path of the panel row picker FUN_a00dac38. r bit 0 = AMD FreeSync SPD InfoFrame seen,
 * bit 2 = HDMI 2.1 VTEM with VRR_EN (see FUN_a008f79c).
 * key: the type test written as 'if (rec->b0 != 5) {...} else ...' (other port first).
 */
struct PortRec { unsigned char b0, b1; unsigned short h2, h4, h6, h8, ha; unsigned char bc, bd; unsigned short he, h10, h12; };
extern unsigned char DAT_a8078c35, DAT_a8078c5b;
extern unsigned char FUN_a008f79c(unsigned char);
extern unsigned char FUN_a008f9e4(unsigned char);
extern unsigned char FUN_a008f9c0(unsigned char);
extern unsigned char FUN_a0091420(unsigned char, unsigned char);

void FUN_a006d61c(struct PortRec *rec, unsigned int port)
{
    unsigned char p = port;
    unsigned char r = FUN_a008f79c(p);

    if ((r & 1) || (r & 4)) rec->bd |= 4; else rec->bd &= ~4;
    if (r & 2) rec->bd |= 8; else rec->bd &= ~8;
    if (r & 0x10) rec->bd |= 0x10; else rec->bd &= ~0x10;
    if (r & 8) rec->bd |= 0x80; else rec->bd &= ~0x80;
    if (FUN_a008f9e4(p)) rec->he |= 0x4000; else rec->he &= ~0x4000;
    if (FUN_a008f9c0(p)) rec->he |= 0x8000; else rec->he &= ~0x8000;
    if (rec->b0 != 5) {
        FUN_a0091420(1, p);
        rec->h12 &= ~0x40;
    } else {
        if (FUN_a0091420(0, p)) rec->h12 |= 0x40; else rec->h12 &= ~0x40;
    }
    if ((DAT_a8078c35 >> (unsigned char)port) & 1) rec->bd |= 0x40; else rec->bd &= ~0x40;
    if ((DAT_a8078c5b >> (unsigned char)port) & 1) rec->bd |= 0x20; else rec->bd &= ~0x20;
}
