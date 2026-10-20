/* FUN_a014a6e0: maps the port p through FUN_a0125198, FUN_a0142218 and FUN_a01421c4 (each result used as u8):
 * 0x71 -> index 0, 0x81 -> index 1, anything else -> no index. With an index, r = FUN_a012b22c(index), else
 * r = 0. Logs "-->SYSAPI_GetSystemDPDSCSupport %x,%x" (s_001a6ff8) with p and r and returns r.
 * Callers: FUN_a00d9fdc. Built with -mcpu=v8 -O3 (no -g: the firmware has no nop after the final call).
 */
extern int FUN_a0125198(unsigned char);
extern int FUN_a01421c4(unsigned char);
extern int FUN_a0142218(unsigned char);
extern unsigned char FUN_a012b22c(unsigned char k);
extern int FUN_a00df170();
extern char s_001a6ff8[];       /* "-->SYSAPI_GetSystemDPDSCSupport %x,%x\n" */

unsigned char FUN_a014a6e0(unsigned char p)
{
    unsigned char v, k, r = 0;

    v = FUN_a01421c4(FUN_a0142218(FUN_a0125198(p)));
    switch (v) {
    case 0x71:
        k = 0;
        break;
    case 0x81:
        k = 1;
        break;
    default:
        k = 0xff;
        break;
    }
    if (k != 0xff)
        r = FUN_a012b22c(k);
    FUN_a00df170(s_001a6ff8, p, r);
    return r;
}
