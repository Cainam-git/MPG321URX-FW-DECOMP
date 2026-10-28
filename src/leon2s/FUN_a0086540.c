/* leon2s FUN_a0086540 @ 0xa0086540 (-mcpu=v8 -Os -g)
 * c = p3, or p3 | 4 when (unsigned char)p3 > 2; d = p4, or p4 | 4 when p4 > 2; b = (d << 3) | c. Fills a 4-byte stack
 * buffer with b and returns 1 when FUN_a00863d4(p1 & 0xff, 0x80, 0x103, (short)((p2 & 0xf) - 1), buffer) is non-zero,
 * else 0.
 */
extern unsigned char FUN_a00863d4(unsigned int param_1, unsigned int param_2, unsigned int param_3, char param_4, unsigned int param_5);

unsigned char FUN_a0086540(unsigned int param_1, unsigned int param_2, char param_3, unsigned char param_4)
{
    unsigned char buffer[4];
    unsigned char local_10;
    
    if ((unsigned char)param_3 <= 2) {
        // do nothing
    } else {
        param_3 |= 4;
    }
    
    if ((param_4 & 0xff) <= 2) {
        // do nothing
    } else {
        param_4 |= 4;
    }
    
    local_10 = ((param_4 & 0xff) << 3) | (unsigned char)param_3;
    buffer[0] = (local_10 & 0xff);
    buffer[1] = (unsigned char)local_10;
    buffer[2] = (unsigned char)local_10;
    buffer[3] = (unsigned char)local_10;
    
    return (FUN_a00863d4(param_1 & 0xff, 0x80, 0x103, (short)((param_2 & 0xf) - 1), (unsigned int)buffer) != 0) ? 1 : 0;
}
