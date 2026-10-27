/* 8051_bank2 FUN_CODE_cee9 @ 0xcee9  update agent: "e551(); write-protect off" wrapper (built
 * with OPTIMIZE(8,SPEED) LARGE + LX51 linker code packing: tools/lx51judge.py 8051_bank2 FUN_CODE_cee9 <this file>).
 * void FUN_CODE_cee9(void) { FUN_CODE_e551(); FUN_CODE_ceee(0); } - Keil C51 emits LCALL e551; R7 = 0; LJMP ceee and
 * the LX51 linker removes the final LJMP because FUN_CODE_ceee is placed directly behind it (5 bytes remain). This is
 * the evidence that the update agent was linked with LX51 code packing. FUN_CODE_e551 is an empty function (a single
 * RET). FUN_CODE_ceee is included because the jump removal needs it to follow;
 * its own documented copy is src/8051_bank2/FUN_CODE_ceee.c. Called four times by FUN_CODE_a8a3 (partial update).
 */
extern unsigned char xdata DAT_EXTMEM_0436[];
extern unsigned char xdata DAT_EXTMEM_0640, DAT_EXTMEM_0641, DAT_EXTMEM_0644;
unsigned char FUN_CODE_de9a(void);
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);

void FUN_CODE_e551(void);
void FUN_CODE_ceee(unsigned char on);
void FUN_CODE_cee9(void)
{
    FUN_CODE_e551();
    FUN_CODE_ceee(0);
}

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
