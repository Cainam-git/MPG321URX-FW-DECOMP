/* leon2s FUN_a0072c6c @ 0xa0072c6c  MATCH (-mcpu=v8 -Os -g)
 * Ring-buffer dequeue on the 128-byte buffer at 0xA80788E8 (write index at +0x80, read index at +0x81). Returns 0
 * when the two indices are equal; otherwise stores the byte at the read index to *param_1, advances the read index
 * (wrapping to 0 at 0x80) and returns 1. The read index is read from memory at each use, as in the firmware.
 */
extern unsigned char DAT_a80788e8[];

int FUN_a0072c6c(unsigned char *param_1)
{
    if (DAT_a80788e8[0x80] == DAT_a80788e8[0x81])
        return 0;
    
    *param_1 = DAT_a80788e8[DAT_a80788e8[0x81]];
    
    {
        unsigned char t = DAT_a80788e8[0x81] + 1;
        DAT_a80788e8[0x81] = t;
        if (t & 0x80)
            DAT_a80788e8[0x81] = 0;
    }
    
    return 1;
}
