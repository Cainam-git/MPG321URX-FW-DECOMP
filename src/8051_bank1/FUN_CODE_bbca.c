/* 8051_bank1 FUN_CODE_bbca @ 0xbbca  MATCH (OPTIMIZE(7,SPEED))
 * The function takes two byte parameters: a mask and a value. For each of the 7 low bits set in the mask, it sets bit 7 of the corresponding high register (0xF181, 0xF183, ..., 0xF18D) and writes the value byte to the adjacent low register (0xF180, 0xF182, ..., 0xF18C). The structure is a sequence of independent if-blocks in ascending bit order, each performing a read-modify-write on the high register followed by a write to the low register. The mask is kept in R6 (matching the target's `MOV R6,R7` at entry) and the value in R5, matching the register usage in the firmware's byte pattern.
 */
extern unsigned char xdata DAT_EXTMEM_f180 _at_ 0xf180;
extern unsigned char xdata DAT_EXTMEM_f181 _at_ 0xf181;
extern unsigned char xdata DAT_EXTMEM_f182 _at_ 0xf182;
extern unsigned char xdata DAT_EXTMEM_f183 _at_ 0xf183;
extern unsigned char xdata DAT_EXTMEM_f184 _at_ 0xf184;
extern unsigned char xdata DAT_EXTMEM_f185 _at_ 0xf185;
extern unsigned char xdata DAT_EXTMEM_f186 _at_ 0xf186;
extern unsigned char xdata DAT_EXTMEM_f187 _at_ 0xf187;
extern unsigned char xdata DAT_EXTMEM_f188 _at_ 0xf188;
extern unsigned char xdata DAT_EXTMEM_f189 _at_ 0xf189;
extern unsigned char xdata DAT_EXTMEM_f18a _at_ 0xf18a;
extern unsigned char xdata DAT_EXTMEM_f18b _at_ 0xf18b;
extern unsigned char xdata DAT_EXTMEM_f18c _at_ 0xf18c;
extern unsigned char xdata DAT_EXTMEM_f18d _at_ 0xf18d;

void FUN_CODE_bbca(unsigned char mask, unsigned char value)
{
    if (mask & 0x01) {
        DAT_EXTMEM_f181 |= 0x80;
        DAT_EXTMEM_f180 = value;
    }
    if (mask & 0x02) {
        DAT_EXTMEM_f183 |= 0x80;
        DAT_EXTMEM_f182 = value;
    }
    if (mask & 0x04) {
        DAT_EXTMEM_f185 |= 0x80;
        DAT_EXTMEM_f184 = value;
    }
    if (mask & 0x08) {
        DAT_EXTMEM_f187 |= 0x80;
        DAT_EXTMEM_f186 = value;
    }
    if (mask & 0x10) {
        DAT_EXTMEM_f189 |= 0x80;
        DAT_EXTMEM_f188 = value;
    }
    if (mask & 0x20) {
        DAT_EXTMEM_f18b |= 0x80;
        DAT_EXTMEM_f18a = value;
    }
    if (mask & 0x40) {
        DAT_EXTMEM_f18d |= 0x80;
        DAT_EXTMEM_f18c = value;
    }
}
