/* FUN_a008ff08 (leon2s 0xa008ff08-0xa008ff58, 80 bytes), flags -mcpu=v8 -Os -g.
 * Reads register 0x146 of port (arg & 0xff) through FUN_a00a657c and classifies bits 4..6:
 * returns 1 when they equal 5 (0x50), otherwise reads the register again and returns 2 when they
 * equal 6 (0x60), else 0.
 */
extern unsigned int FUN_a00a657c(unsigned int, unsigned short);

unsigned int FUN_a008ff08(unsigned char port)
{
    if ((FUN_a00a657c(port, 0x146) & 0x70) == 0x50)
        return 1;
    return ((FUN_a00a657c(port, 0x146) & 0x70) == 0x60) * 2;
}
