/* 8051_bank1 FUN_CODE_cfe7 @ 0xcfe7  MATCH (OPTIMIZE(7,SPEED))
 * Sends DAT_INTMEM_50 bytes from the XDATA buffer at 0xA2E8 to the port at XDATA 0xF037. Before each byte it waits
 * while bit 3 of XDATA 0xF036 is set (busy), with a 100-iteration delay loop per poll. Afterwards it clears the
 * count at IDATA 0x50 and writes 0x55 to XDATA 0xF00A.
 *
 * DAT_INTMEM_50 is defined (not declared extern) as `unsigned char idata ... _at_ 0x50`; Keil rejects an extern
 * declaration with `_at_`. This definition produces `MOV R0,#0x50` for the count accesses.
 */
unsigned char idata DAT_INTMEM_50 _at_ 0x50;
extern unsigned char xdata DAT_EXTMEM_f036;
extern unsigned char xdata DAT_EXTMEM_f037;
extern unsigned char xdata DAT_EXTMEM_f00a;

void FUN_CODE_cfe7(void) 
{
    unsigned char i;
    unsigned char j;
    
    for (i = 0; i < DAT_INTMEM_50; i++) {
        while ((DAT_EXTMEM_f036 & 0x08) != 0) {
            for (j = 0; j < 100; j++) {
                // empty delay loop
            }
        }
        DAT_EXTMEM_f037 = ((unsigned char xdata *)0xA2E8)[i];
    }
    DAT_INTMEM_50 = 0;
    DAT_EXTMEM_f00a = 0x55;
}
