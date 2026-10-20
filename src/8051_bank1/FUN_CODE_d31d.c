/* 8051_bank1 FUN_CODE_d31d @ 0xd31d  MATCH (OPTIMIZE(8,SPEED), hand)
 *
 * "Update FE2P Addr": stores the new 32-bit FE2P address (the flash window base the LEON cores use to see the
 * flash, see "FE2P_SetLeon2BaseAddress" in the image) at XDATA 0xA4B3..0xA4B6, prints "Update FE2P Addr %08lx\r\n"
 * (bank 1 string 0x54CB, printf = FUN_CODE_2820 with its XDATA parameter block at 0xA517), sets the flag byte at
 * 0xA4BF to 1 and hands the 4-byte value to FUN_CODE_b228(0xB4, &value).
 * Boot/update path: part of the update code that moves the LEON flash window.
 */
extern unsigned long xdata DAT_EXTMEM_a4b3;
extern unsigned char xdata DAT_EXTMEM_a4bf;
extern void FUN_CODE_2820(void *fmt, ...) large;
extern void FUN_CODE_b228(unsigned char n, void *p);

void FUN_CODE_d31d(unsigned long addr)
{
    void *p;
    DAT_EXTMEM_a4b3 = addr;
    FUN_CODE_2820((void code *)0x54cb, DAT_EXTMEM_a4b3);
    p = (void *)&DAT_EXTMEM_a4b3;
    DAT_EXTMEM_a4bf = 1;
    FUN_CODE_b228(0xb4, p);
}
