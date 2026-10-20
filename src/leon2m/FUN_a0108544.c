/* leon2m FUN_a0108544 @ 0xa0108544  MATCH (-mcpu=v8 -O2 -g)
 * Calls FUN_a00df170(0x19ABE8, 4, 0) and discards its result, clears bit 4 of the registers 0xCF011BF8, 0xCF011A00
 * and 0xCF011800 (in that order), and writes 1 to 0xCF011CC0. Returns nothing.
 */
extern int FUN_a00df170(unsigned int, unsigned int, unsigned int);

#define _DAT_cf011800 (*(volatile unsigned int *)0xcf011800)
#define _DAT_cf011a00 (*(volatile unsigned int *)0xcf011a00)
#define _DAT_cf011bf8 (*(volatile unsigned int *)0xcf011bf8)
#define _DAT_cf011cc0 (*(volatile unsigned int *)0xcf011cc0)

void FUN_a0108544(void)
{
    FUN_a00df170(0x19abe8, 4, 0);
    _DAT_cf011bf8 = _DAT_cf011bf8 & 0xffffffef;
    _DAT_cf011a00 = _DAT_cf011a00 & 0xffffffef;
    _DAT_cf011800 = _DAT_cf011800 & 0xffffffef;
    _DAT_cf011cc0 = 1;
}
