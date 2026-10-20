/* leon2m FUN_a0125294 @ 0xa0125294 (-mcpu=v8 -O2 -g)
 * Reads the 22-byte (0x16) per-port record at 0x001A42A8 indexed by the low byte of the parameter: returns record
 * byte +0x12 if record byte +1 equals 2, otherwise 0x0F.
 *
 * The table lies in constant (ROM) space; the base is a local pointer initialised with the constant address, which
 * gives the sethi/or of the base before the multiplication as in the target.
 */
extern unsigned char DAT_001a42a9;  // 0x001a42a9
extern unsigned char DAT_001a42ba;  // 0x001a42ba

unsigned char FUN_a0125294(unsigned int param_1)
{
    int result;
    unsigned char *base = (unsigned char *)0x001a42a8;
    unsigned int index = (param_1 & 0xff) * 0x16;

    result = 0xf;
    if (base[index + 1] == 2) {
        result = base[index + 0x12];
    }
    return result;
}
