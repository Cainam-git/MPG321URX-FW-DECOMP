/* FUN_CODE_c32e, 8051_bank1, range 0xC32E..0xC389 (91 B).
 * Options: OPTIMIZE(8,SPEED) (also MATCH with REGFILE(R.ORC) added). Judge: tools/diff8051.judge (jj.py, scratch
 * copy) MATCH, exact None, 91/91.
 * Code facts: stores its generic pointer parameter p (R3/R2/R1) to 0xA709, copies the generic pointers 0xA721 ->
 * 0xA701, 0xA71E -> 0xA706, 0xA724 -> 0xA6FE (Keil's 3-byte copy: R1, R2, A then XCH A,R1), and the bytes 0xA728 ->
 * 0xA704 and 0xA727 -> 0xA705 (note the swapped order). The 0xA6FE..0xA70B and 0xA71E..0xA728 areas may be records;
 * the bytes only show these scalar copies, so they are declared one by one. Caller: LCALL at 0x7FC7 (outside the
 * functions.json ranges). No aids.
 */
extern unsigned char * xdata DAT_EXTMEM_a709;
extern unsigned char * xdata DAT_EXTMEM_a701;
extern unsigned char * xdata DAT_EXTMEM_a706;
extern unsigned char * xdata DAT_EXTMEM_a6fe;
extern unsigned char xdata DAT_EXTMEM_a704;
extern unsigned char xdata DAT_EXTMEM_a705;
extern unsigned char * xdata DAT_EXTMEM_a721;
extern unsigned char * xdata DAT_EXTMEM_a71e;
extern unsigned char * xdata DAT_EXTMEM_a724;
extern unsigned char xdata DAT_EXTMEM_a727;
extern unsigned char xdata DAT_EXTMEM_a728;
void FUN_CODE_c32e(unsigned char *p)
{
    DAT_EXTMEM_a709 = p;
    DAT_EXTMEM_a701 = DAT_EXTMEM_a721;
    DAT_EXTMEM_a706 = DAT_EXTMEM_a71e;
    DAT_EXTMEM_a6fe = DAT_EXTMEM_a724;
    DAT_EXTMEM_a704 = DAT_EXTMEM_a728;
    DAT_EXTMEM_a705 = DAT_EXTMEM_a727;
}
