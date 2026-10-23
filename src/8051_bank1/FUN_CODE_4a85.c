/* 8051_bank1 FUN_CODE_4a85 @ 0x4a85  Leon2 Main core set-up (byte-exact with OPTIMIZE(8,SPEED) LARGE;
 * real size 0x234: Ghidra had cut it at an inline ?C?LSTKXDATA constant).
 *
 * Called once by the helper chip's start-up FUN_CODE_0b0d as FUN_CODE_4a85(&XDATA 0xA48B), the Main record built from
 * the boot loader's share structure. Every write goes over the AHB bridge (FUN_CODE_beb5, inputs at 0xA4EC / 0xA4F0):
 *  1. the 8 fixed (register, value) pairs at CODE 0x8252: 0x9F0000E0 = 5, 0x9F020000 = 0xA0028000 (Main boot / trap base),
 *     0x9F020008 = 0x1001 (core control: held, see the RUN routine FUN_CODE_8e61), 0x9F02000C = 0x50000000,
 *     0x9F01010C = 0x9F010110 = 0x9F010108 = 0xFFFFFFFF, 0x9F010104 = 0x72310CAD;
 *  2. 0x9F020200 = record +0x18 and 0x9F020204 = record +0x1C (from the partition table via the share structure);
 *  3. prints "Leon2 vs AHB clk is 3:1\r\n" (CODE 0x81D6); 0x9F0000E0 = 5; 0x9F02000C = 0x50000000;
 *  4. XDATA 0xD511 == 0x1A: 0x9F020308 = 0x723105A5, 0x9F020300 = 0x25.
 * The Big chip's boot address 0xA0028000 is a constant here, in the 8051 code.
 */
typedef union { unsigned long l; unsigned char b[4]; } DW;
struct CoreCfg { unsigned char pad[0x18]; unsigned long f18; unsigned long f1c; };
extern volatile unsigned char xdata DAT_EXTMEM_d511;
extern DW xdata DAT_EXTMEM_a72d;
extern DW xdata DAT_EXTMEM_a731;
extern DW xdata DAT_EXTMEM_a4ec;
extern DW xdata DAT_EXTMEM_a4f0;
extern void FUN_CODE_beb5(void);   /* parameters in its overlay: addr = 0xA4EC, val = 0xA4F0 */
extern void FUN_CODE_2820(void *fmt, ...) large;
void FUN_CODE_4a85(struct CoreCfg *c)
{
    int i;
    for (i = 0; i < 16; ) {
        DAT_EXTMEM_a72d.l = ((unsigned long code *)0x8252)[i++];
        DAT_EXTMEM_a731.l = ((unsigned long code *)0x8252)[i++];
        DAT_EXTMEM_a4ec = DAT_EXTMEM_a72d; DAT_EXTMEM_a4f0 = DAT_EXTMEM_a731; FUN_CODE_beb5();
    }
    DAT_EXTMEM_a72d.l = 0x9F020200;
    DAT_EXTMEM_a731.l = c->f18;
    DAT_EXTMEM_a4ec = DAT_EXTMEM_a72d; DAT_EXTMEM_a4f0 = DAT_EXTMEM_a731; FUN_CODE_beb5();
    DAT_EXTMEM_a72d.l = 0x9F020204;
    DAT_EXTMEM_a731.l = c->f1c;
    DAT_EXTMEM_a4ec = DAT_EXTMEM_a72d; DAT_EXTMEM_a4f0 = DAT_EXTMEM_a731; FUN_CODE_beb5();
    FUN_CODE_2820((void code *)0x81d6);   /* "Leon2 vs AHB clk is 3:1\r\n" */
    DAT_EXTMEM_a72d.l = 0x9F0000E0;
    DAT_EXTMEM_a731.l = 0x00000005;
    DAT_EXTMEM_a4ec = DAT_EXTMEM_a72d; DAT_EXTMEM_a4f0 = DAT_EXTMEM_a731; FUN_CODE_beb5();
    DAT_EXTMEM_a72d.l = 0x9F02000C;
    DAT_EXTMEM_a731.l = 0x50000000;
    DAT_EXTMEM_a4ec = DAT_EXTMEM_a72d; DAT_EXTMEM_a4f0 = DAT_EXTMEM_a731; FUN_CODE_beb5();
    if (DAT_EXTMEM_d511 == 0x1A) {
        DAT_EXTMEM_a72d.l = 0x9F020308;
        DAT_EXTMEM_a731.l = 0x723105A5;
        DAT_EXTMEM_a4ec = DAT_EXTMEM_a72d; DAT_EXTMEM_a4f0 = DAT_EXTMEM_a731; FUN_CODE_beb5();
        DAT_EXTMEM_a72d.l = 0x9F020300;
        DAT_EXTMEM_a731.l = 0x00000025;
        DAT_EXTMEM_a4ec = DAT_EXTMEM_a72d; DAT_EXTMEM_a4f0 = DAT_EXTMEM_a731; FUN_CODE_beb5();
    }
}
