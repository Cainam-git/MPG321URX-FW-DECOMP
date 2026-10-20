/* leon2m FUN_a0080bd8 @ 0xa0080bd8  MATCH (-mcpu=v8 -O2 -g)
 * Sets bit 3 (0x08) of the byte at 0xA802AF41 if the low byte of the parameter equals 1, otherwise clears it. The
 * parameter is declared unsigned int and masked with 0xff in the compare; both arms use compound assignment.
 */
extern unsigned char DAT_a802af41; /* 0xa802af41 */

void FUN_a0080bd8(unsigned int param_1)
{
    if ((param_1 & 0xff) == 1)
        DAT_a802af41 |= 8;
    else
        DAT_a802af41 &= ~8;
}
