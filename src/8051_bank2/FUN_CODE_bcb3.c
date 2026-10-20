/* 8051_bank2 FUN_CODE_bcb3 @ 0xbcb3  BYTE-EXACT under OPTIMIZE(7,SPEED) LARGE.
 * Note: 'OPTIMIZE(7,SPEED) LARGE' is NOT in tools/config.json alt_c51opts yet; it must be added for
 * accept8051.py to find this match (bank 2 is LARGE; d751 / 00fc are already accepted at OPTIMIZE(7)).
 * Send the "region" command packet over the service bus: addr = FUN_CODE_e4e9() (32-bit value at XDATA 0x0717),
 * size = XDATA[0x0644] * 0x40000 (0x0644 = byte 4 of the flash-chip record at 0x0640, see FUN_CODE_0003);
 * 10-byte packet 09 DE, addr (4 bytes, low byte first), size / 2 (4 bytes, low byte first); then
 * FUN_CODE_bfcf(0x6E, 10, packet) (I2C write to slave 0x6E with XOR checksum) and its status is returned.
 * Only caller: FUN_CODE_00fc (returns it to FUN_CODE_a8a3, enter ISP, which treats 0 as success).
 * Locals in the LARGE-model XDATA block 0x08EE: addr 0x08EE, size 0x08F2, packet 0x08F6..0x08FF; q is a register
 * pointer (OPTIMIZE(7) keeps it in DPTR).
 * What made it exact: the tail 'LCALL bfcf / RET' is OPTIMIZE(7) (level 8 turns it into LJMP), and the low byte of
 * addr is read through an xdata byte pointer 'q = (unsigned char xdata *)&addr; pkt[2] = q[3];', which at level 7
 * gives the firmware's MOV DPTR,#0x08EE / INC DPTR x3 / MOVX (a plain '((unsigned char *)&addr)[3]' folds to
 * MOV DPTR,#0x08F1; '(unsigned char)addr' at level 7 reads all four bytes). Same q[3] works with 'q++ x3', 'q += 3'
 * and '*(q + 3)'.
 */
extern unsigned char xdata DAT_EXTMEM_0644;
extern unsigned long FUN_CODE_e4e9(void);
extern unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);

unsigned char FUN_CODE_bcb3(void)
{
    unsigned long addr;
    unsigned long size;
    unsigned char pkt[10];
    unsigned char xdata *q;
    addr = FUN_CODE_e4e9();
    size = DAT_EXTMEM_0644 * 0x40000UL;
    pkt[0] = 0x09;
    pkt[1] = 0xde;
    q = (unsigned char xdata *)&addr; pkt[2] = q[3];
    pkt[3] = (unsigned char)(addr >> 8);
    pkt[4] = (unsigned char)(addr >> 16);
    pkt[5] = (unsigned char)(addr >> 24);
    pkt[6] = (unsigned char)(size / 2);
    pkt[7] = (unsigned char)((size / 2) >> 8);
    pkt[8] = (unsigned char)((size / 2) >> 16);
    pkt[9] = (unsigned char)((size / 2) >> 24);
    return FUN_CODE_bfcf(0x6e, 10, pkt);
}
