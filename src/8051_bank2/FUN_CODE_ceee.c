/* 8051_bank2 FUN_CODE_ceee @ 0xceee  update agent: set / clear the SPI flash's write-protect bits through the scaler
 * (OPTIMIZE(8,SPEED) LARGE).
 * Code facts: reads a status byte sr (FUN_CODE_de9a), clears the 10-byte buffer XDATA 0x0436 and sends two service
 * packets to slave 0x6E (FUN_CODE_bfcf, 10 bytes each, 4000-unit wait after each, FUN_CODE_d059):
 *   09 53 <op> 00 .. 00 01   with op = 0x50 when chip-record byte XDATA 0x0641 is set, else 0x06;
 *   09 53 01 <v> 00 .. 00 02 with v = on == 1 ? (sr & 0x63) | 0x9C or (sr & 0x43) | 0xB4
 *                                       : sr & 0x63 or sr & 0x43,
 *   the 0x63 / 0x9C pair when chip-record byte 0x0640 == 3 and 0x0644 != 0x80, else the 0x43 / 0xB4 pair.
 * The byte after 0x53 is a JEDEC SPI flash opcode: 0x06 = Write Enable, 0x50 = Enable Write Status Register
 * (SST-style chips), 0x01 = Write Status Register with v as the new status value. With on = 1, v has the
 * block-protect bits set (0x9C or 0xB4); with on = 0 they are cleared. FUN_CODE_a8a3 (enter ISP) calls it with 0
 * right before handing the scaler to ROM ISP, and the partial-update path calls it with 0 / 1 around its steps.
 */
extern unsigned char xdata DAT_EXTMEM_0436[];
extern unsigned char xdata DAT_EXTMEM_0640, DAT_EXTMEM_0641, DAT_EXTMEM_0644;
unsigned char FUN_CODE_de9a(void);
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);

void FUN_CODE_ceee(unsigned char on)
{
    unsigned char sr;
    unsigned char i;
    sr = FUN_CODE_de9a();
    for (i = 0; i < 10; i++) DAT_EXTMEM_0436[i] = 0;
    DAT_EXTMEM_0436[0] = 9;
    DAT_EXTMEM_0436[1] = 0x53;
    if (DAT_EXTMEM_0641) DAT_EXTMEM_0436[2] = 0x50; else DAT_EXTMEM_0436[2] = 0x06;
    DAT_EXTMEM_0436[9] = 1;
    FUN_CODE_bfcf(0x6e, 10, DAT_EXTMEM_0436);
    FUN_CODE_d059(0x0fa0);
    DAT_EXTMEM_0436[2] = 0x01;
    if (on == 1) {
        if (DAT_EXTMEM_0640 == 3 && DAT_EXTMEM_0644 != 0x80) DAT_EXTMEM_0436[3] = (sr & 0x63) | 0x9c;
        else DAT_EXTMEM_0436[3] = (sr & 0x43) | 0xb4;
    } else {
        if (DAT_EXTMEM_0640 == 3 && DAT_EXTMEM_0644 != 0x80) DAT_EXTMEM_0436[3] = sr & 0x63;
        else DAT_EXTMEM_0436[3] = sr & 0x43;
    }
    DAT_EXTMEM_0436[9] = 2;
    FUN_CODE_bfcf(0x6e, 10, DAT_EXTMEM_0436);
    FUN_CODE_d059(0x0fa0);
}
