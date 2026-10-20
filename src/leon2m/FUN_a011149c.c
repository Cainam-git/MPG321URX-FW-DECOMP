/* leon2m FUN_a011149c @ 0xa011149c  V-by-One (Vx1) transmitter start-up register sequence, link type 0 path
 * (hand; -mcpu=v8 -O3 -g, )
 *
 * Called by the panel power sequencer FUN_a01413d0 (state 4, link type 0). A fixed write sequence to the
 * 0xCF01CCxx..0xCF01CFxx block (same block as the byte-exact FUN_a0121f58), with three 1-unit waits
 * (func_0x4008d1a0(1)) in between; 0xCF00EDE4 = 0x20 when byte 0xA802C988 is set. Finally one value from a 13-entry
 * table {1,2,3,4,5,6,7,8,10,11,12,13,14}, indexed by bits 27..31 of the transformed panel row's word 0, goes to
 * 23 registers 0xCF01CD30..CD4C, CDBC..CDC8, CE58..CE64, CED4..CEF0.
 * Reads the transformed panel row (word 0): a panel-row reader.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern unsigned int *DAT_a802d6a4;
extern unsigned char DAT_a802c988;
extern int func_0x4008d1a0();

void FUN_a011149c(void)
{
    unsigned int v;

    R(0xcf01cf9c) = 0x70;
    R(0xcf01cf10) = 0x70;
    R(0xcf01cf94) = 0x8f;
    R(0xcf01cf08) = 0x8f;
    R(0xcf01cfa0) = 0x22;
    R(0xcf01cf9c) = 0x70;
    R(0xcf01cc98) = 0x30;
    R(0xcf01cc58) = 1;
    R(0xcf01cc6c) = 0x66;
    R(0xcf01cc70) = 0x66;
    R(0xcf01cfa4) = 5;
    R(0xcf01cc64) = 0xe;
    R(0xcf01cc68) = 0x26;
    func_0x4008d1a0(1);
    R(0xcf01cfa8) = 0x80;
    R(0xcf01ccec) = 0x80;
    R(0xcf01cd78) = 0x80;
    R(0xcf01ce90) = 0x80;
    R(0xcf01cf18) = 5;
    R(0xcf01cff8) = 5;
    R(0xcf01cf9c) = 0x71;
    R(0xcf01cf10) = 0x71;
    R(0xcf01cc14) = 0;
    R(0xcf01cc40) = 0;
    R(0xcf01cc20) = 0;
    R(0xcf01cf94) = 0xcf;
    func_0x4008d1a0(1);
    R(0xcf01cf94) = 0x4f;
    R(0xcf01cf08) = 0x4f;
    R(0xcf01cfa0) = 2;
    func_0x4008d1a0(1);
    R(0xcf01cff8) = 1;
    R(0xcf01ccc0) = 8;
    R(0xcf01cfac) = 8;
    R(0xcf01ccc4) = 3;
    R(0xcf01cfb0) = 3;
    R(0xcf01ccf0) = 0x20;
    R(0xcf01cd7c) = 0x20;
    R(0xcf01ce08) = 0x20;
    R(0xcf01ce94) = 0x20;
    R(0xcf01cd28) = 0;
    R(0xcf01cdb4) = 0;
    R(0xcf01ce40) = 0;
    R(0xcf01cecc) = 0;
    R(0xcf01ccf8) = 0xff;
    R(0xcf01cd84) = 0xf;
    R(0xcf01ce10) = 0xf0;
    R(0xcf01ce9c) = 0xff;
    R(0xcf01cd10) = 0xff;
    R(0xcf01cd9c) = 0xf;
    R(0xcf01ce28) = 0xf0;
    R(0xcf01ceb4) = 0xff;
    R(0xcf01cfa8) = 0x80;
    R(0xcf01ccec) = 0x80;
    R(0xcf01cd78) = 0x80;
    R(0xcf01ce04) = 0x80;
    R(0xcf01ce90) = 0x80;
    if (DAT_a802c988 != 0) R(0xcf00ede4) = 0x20;
    {
        unsigned int i = *DAT_a802d6a4 >> 27;
        const unsigned char t[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14 };
        v = t[i];
    }
    R(0xcf01cd30) = v; R(0xcf01cd34) = v; R(0xcf01cd38) = v; R(0xcf01cd3c) = v;
    R(0xcf01cd40) = v; R(0xcf01cd44) = v; R(0xcf01cd48) = v; R(0xcf01cd4c) = v;
    R(0xcf01cdbc) = v; R(0xcf01cdc0) = v; R(0xcf01cdc4) = v; R(0xcf01cdc8) = v;
    R(0xcf01ce58) = v; R(0xcf01ce5c) = v; R(0xcf01ce60) = v; R(0xcf01ce64) = v;
    R(0xcf01ced4) = v; R(0xcf01ced8) = v; R(0xcf01cedc) = v; R(0xcf01cee0) = v;
    R(0xcf01cee4) = v; R(0xcf01cee8) = v; R(0xcf01ceec) = v; R(0xcf01cef0) = v;
}
