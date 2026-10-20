/* 8051_bank1 FUN_CODE_5dcb @ 0x5dcb  Leon2 Sub core set-up (byte-exact with OPTIMIZE(8,SPEED) LARGE)
 *
 * Twin of FUN_CODE_4a85 for the Small chip (Leon2 Sub); called by FUN_CODE_0b0d as FUN_CODE_5dcb(&XDATA 0xA4AF). Writes
 * over the AHB bridge (FUN_CODE_beb5): the 8 fixed pairs at CODE 0x8292: 0x9F1000E0 = 5, 0x9F120000 = 0xA0060000 (Sub
 * boot / trap base, matching the Small chip image base), 0x9F120008 = 0x1001 (core control, held), 0x9F12000C =
 * 0x50000000, 0x9F120210 = 0x9F120214 = 0xFFFFFFFF, 0x9F120218 = 0x8000000F, 0x9F010104 = 0x72310CAD; then
 * 0x9F120200 = record +0x1C and 0x9F120204 = record +0x20 (share structure), 0x9F1000E0 = 5, 0x9F12000C = 0x50000000.
 * Part of the start-up path.
 */
typedef union { unsigned long l; unsigned char b[4]; } DW;
struct SubCfg { unsigned char pad[0x1c]; unsigned long f1c; unsigned long f20; };
extern DW xdata DAT_EXTMEM_a72d;
extern DW xdata DAT_EXTMEM_a731;
extern DW xdata DAT_EXTMEM_a4ec;
extern DW xdata DAT_EXTMEM_a4f0;
extern void FUN_CODE_beb5(void);   /* parameters in its overlay: addr = 0xA4EC, val = 0xA4F0 */
void FUN_CODE_5dcb(struct SubCfg *c)
{
    int i;
    for (i = 0; i < 16; ) {
        DAT_EXTMEM_a72d.l = ((unsigned long code *)0x8292)[i++];
        DAT_EXTMEM_a731.l = ((unsigned long code *)0x8292)[i++];
        DAT_EXTMEM_a4ec = DAT_EXTMEM_a72d; DAT_EXTMEM_a4f0 = DAT_EXTMEM_a731; FUN_CODE_beb5();
    }
    DAT_EXTMEM_a72d.l = 0x9F120200;
    DAT_EXTMEM_a731.l = c->f1c;
    DAT_EXTMEM_a4ec = DAT_EXTMEM_a72d; DAT_EXTMEM_a4f0 = DAT_EXTMEM_a731; FUN_CODE_beb5();
    DAT_EXTMEM_a72d.l = 0x9F120204;
    DAT_EXTMEM_a731.l = c->f20;
    DAT_EXTMEM_a4ec = DAT_EXTMEM_a72d; DAT_EXTMEM_a4f0 = DAT_EXTMEM_a731; FUN_CODE_beb5();
    DAT_EXTMEM_a72d.l = 0x9F1000E0;
    DAT_EXTMEM_a731.l = 0x00000005;
    DAT_EXTMEM_a4ec = DAT_EXTMEM_a72d; DAT_EXTMEM_a4f0 = DAT_EXTMEM_a731; FUN_CODE_beb5();
    DAT_EXTMEM_a72d.l = 0x9F12000C;
    DAT_EXTMEM_a731.l = 0x50000000;
    DAT_EXTMEM_a4ec = DAT_EXTMEM_a72d; DAT_EXTMEM_a4f0 = DAT_EXTMEM_a731; FUN_CODE_beb5();
}
