/* 8051_bank2 module FUN_CODE_8437, BYTE-EXACT under OPTIMIZE(8,SPEED) LARGE.
 * ONE Keil C51 module, 5 functions, in this order: FUN_CODE_8437 (0x8437..0x872D), FUN_CODE_d866 (block 0xD84C +
 * function 0xD866..0xD8C3), FUN_CODE_dc80 (block 0xDC78, 0xDC80..0xDCC8), FUN_CODE_de20 (block 0xDE04, 0xDE20..0xDE4F),
 * FUN_CODE_defd (block 0xDEE4, 0xDEFD..0xDF2C). The 11 "fragments" d84c/d859/d85b, dc78/dc7c, de04/de13/de15,
 * dee4/def0/def2 are Keil OPTIMIZE(8) common-entry code built from 8437's call sites; Keil puts each L? block into the
 * callee's code segment in front of it, so each callee segment = block + function (lengths 26/8/28/25 B = firmware).
 *
 * What it does (code facts; the helper chip's updater, flash record refresh + verify):
 * - XDATA 0x0652: table of 8-byte records, first field a 32-bit flash offset; count at 0x042E. Offsets are relative
 *   to the flash base FUN_CODE_e4e9() (32-bit value at XDATA 0x0717).
 * - XDATA 0x06F7: 32-byte record image. defd(off) = FUN_CODE_abce(image, base + off, 1, 0) (fills the image: d866
 *   compares a buffer filled by the same call); de20(off) = FUN_CODE_b1a9(image, base + off, 1, 0) (the counterpart
 *   called after the image was changed, i.e. the write back). abce / b1a9 are SMALL-model functions (parameter block
 *   ?_FUN_CODE_abce?BYTE / ?_FUN_CODE_b1a9?BYTE at DATA 0x08; n / f at 0x0F / 0x10).
 * - d866(off) reads the record into its own 32-byte buffer (XDATA 0x08FA) and returns bit 1 if any byte differs from
 *   the image (verify failed), 0 if all 32 bytes agree.
 * - dc80(reg, val) stores byte val for register number reg into the image; byte order inside each 4-byte word is
 *   reversed (idx = (reg & ~3) + 3 - (reg & 3)).
 * - FUN_CODE_8437(mode): record 0 and records 1..n-2: read, set byte 0x0C (0 for record 0, else
 *   FUN_CODE_dcc9(FUN_CODE_d64c(0))), byte 0x0D = 1 when XDATA 0x0434 == 0 (records 1..n-2 only), write, verify;
 *   mode 0x11 also handles the last record (word 0 = [0x042F] + ([0x0435] << 12)) and then, for every i below
 *   [0x0433] >> 5, the 4 words j = 0/8/16/24 of record offset rec[n-1] + 1 + i: stop at an erased word 0xFFFFFFFF,
 *   else add [0x0435] * (size / 2) (size = [0x0644] * 0x40000, the flash-size code also used by FUN_CODE_bcb3),
 *   write, verify. Returns the OR of all verify failures (0 = all records verified).
 * Locals: LARGE block 0x08EE (v, res, i, j, size); the callees' blocks start at 0x08F6.
 * Code-relevant declaration facts (no aids, no volatile, no dummy objects):
 * - the record table must be declared with a known size below 256 bytes: Keil then indexes it with 8-bit math
 *   (CLR A / ADDC A,#HIGH, firmware); [] or 32+ records give MOV A,B / ADDC and a different block (765 B). [20] = the
 *   table ends exactly at the next known global, XDATA 0x06F2. 2..31 records all give the same code.
 * - d866 compares 'image[k] != buf[k]' (Keil loads the right operand first); dc80 reuses its parameter reg as the
 *   index (gives the firmware registers R6 = reg >> 2, R4 = reg & 3, R7 = index).
 * - OPTIMIZE(7,SPEED) LARGE builds no common-entry blocks (8437 = 1061 B), so the module is level 8.
 * Judge note: tools/diff8051.py MATCHes FUN_CODE_8437 (its LCALL L?nnnn resolve through common_entry). The 4 callees
 * score low there only because keil_listing pads the L? block in front of the function (same base-offset gap as
 * FUN_CODE_738c); over the real range (block start..callee end, block fixups filled) exact8051 returns None for
 * all 4.
 */
struct rec { unsigned long a; unsigned long b; };
extern struct rec xdata DAT_EXTMEM_0652[20];
extern unsigned char xdata DAT_EXTMEM_06f7[32];
extern unsigned char xdata DAT_EXTMEM_042e, DAT_EXTMEM_0433, DAT_EXTMEM_0434, DAT_EXTMEM_0435, DAT_EXTMEM_0644;
extern unsigned long xdata DAT_EXTMEM_042f;
extern unsigned long FUN_CODE_e4e9(void);
extern unsigned long FUN_CODE_d64c(unsigned char j);
extern unsigned char FUN_CODE_dcc9(unsigned long v);
extern void FUN_CODE_d8c4(unsigned char j, unsigned long v);
extern void FUN_CODE_abce(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char f) small;
extern void FUN_CODE_b1a9(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char f) small;
bit FUN_CODE_d866(unsigned long a);
void FUN_CODE_dc80(unsigned char reg, unsigned char val);
void FUN_CODE_de20(unsigned long a);
void FUN_CODE_defd(unsigned long a);

unsigned char FUN_CODE_8437(unsigned char mode)
{
    unsigned char v;
    unsigned char res;
    unsigned char i;
    unsigned char j;
    unsigned long size;

    if (mode == 0x11) {
        FUN_CODE_defd(DAT_EXTMEM_0652[0].a);
        v = 0;
        FUN_CODE_dc80(0x0c, v);
        FUN_CODE_de20(DAT_EXTMEM_0652[0].a);
        res = FUN_CODE_d866(DAT_EXTMEM_0652[0].a);
        for (i = 1; i < DAT_EXTMEM_042e - 1; i++) {
            FUN_CODE_defd(DAT_EXTMEM_0652[i].a);
            v = FUN_CODE_dcc9(FUN_CODE_d64c(0));
            FUN_CODE_dc80(0x0c, v);
            if (DAT_EXTMEM_0434 == 0) FUN_CODE_dc80(0x0d, 1);
            FUN_CODE_de20(DAT_EXTMEM_0652[i].a);
            res |= FUN_CODE_d866(DAT_EXTMEM_0652[i].a);
        }
        size = DAT_EXTMEM_0644 * 0x40000UL;
        FUN_CODE_defd(DAT_EXTMEM_0652[DAT_EXTMEM_042e - 1].a);
        FUN_CODE_d8c4(0, DAT_EXTMEM_042f + ((unsigned int)DAT_EXTMEM_0435 << 12));
        v = FUN_CODE_dcc9(FUN_CODE_d64c(0));
        FUN_CODE_dc80(0x0c, v);
        FUN_CODE_de20(DAT_EXTMEM_0652[DAT_EXTMEM_042e - 1].a);
        res |= FUN_CODE_d866(DAT_EXTMEM_0652[DAT_EXTMEM_042e - 1].a);
        for (i = 0; i < (DAT_EXTMEM_0433 >> 5); i++) {
            for (j = 0; j < 0x20; j += 8) {
                FUN_CODE_defd(DAT_EXTMEM_0652[DAT_EXTMEM_042e - 1].a + 1 + i);
                if (FUN_CODE_d64c(j) == 0xffffffff) break;
                FUN_CODE_d8c4(j, FUN_CODE_d64c(j) + DAT_EXTMEM_0435 * (size / 2));
                FUN_CODE_de20(DAT_EXTMEM_0652[DAT_EXTMEM_042e - 1].a + 1 + i);
                res |= FUN_CODE_d866(DAT_EXTMEM_0652[DAT_EXTMEM_042e - 1].a + 1 + i);
            }
        }
    } else {
        FUN_CODE_defd(DAT_EXTMEM_0652[0].a);
        v = 0;
        FUN_CODE_dc80(0x0c, v);
        FUN_CODE_de20(DAT_EXTMEM_0652[0].a);
        res = FUN_CODE_d866(DAT_EXTMEM_0652[0].a);
        for (i = 1; i < DAT_EXTMEM_042e - 1; i++) {
            FUN_CODE_defd(DAT_EXTMEM_0652[i].a);
            v = FUN_CODE_dcc9(FUN_CODE_d64c(0));
            FUN_CODE_dc80(0x0c, v);
            if (DAT_EXTMEM_0434 == 0) FUN_CODE_dc80(0x0d, 1);
            FUN_CODE_de20(DAT_EXTMEM_0652[i].a);
            res |= FUN_CODE_d866(DAT_EXTMEM_0652[i].a);
        }
    }
    return res;
}

bit FUN_CODE_d866(unsigned long a)
{
    unsigned char buf[32];
    unsigned char k;
    bit e;
    FUN_CODE_abce(buf, a + FUN_CODE_e4e9(), 1, 0);
    for (k = 0; k < 0x20; k++) {
        if (DAT_EXTMEM_06f7[k] != buf[k]) { e = 1; break; }
        if (k == 0x1f) e = 0;
    }
    return e;
}

void FUN_CODE_dc80(unsigned char reg, unsigned char val)
{
    unsigned char w;
    w = reg >> 2;
    if ((reg & 3) == 0) reg = w * 4 + 3;
    else if ((reg & 3) == 1) reg = w * 4 + 2;
    else if ((reg & 3) == 2) reg = w * 4 + 1;
    else if ((reg & 3) == 3) reg = w * 4;
    DAT_EXTMEM_06f7[reg] = val;
}

void FUN_CODE_de20(unsigned long a)
{
    FUN_CODE_b1a9(DAT_EXTMEM_06f7, a + FUN_CODE_e4e9(), 1, 0);
}

void FUN_CODE_defd(unsigned long a)
{
    FUN_CODE_abce(DAT_EXTMEM_06f7, a + FUN_CODE_e4e9(), 1, 0);
}
