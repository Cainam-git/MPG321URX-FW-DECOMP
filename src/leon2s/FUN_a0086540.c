/* leon2s FUN_a0086540 @ 0xa0086540  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: [walk]; mask->cast param_3#3; cast->mask local_10#1; cast (char) short; local local_10 unsigned char; param param_3 char; mask->cast param_3#0
 */
extern unsigned char FUN_a00863d4(unsigned int param_1, unsigned int param_2, unsigned int param_3, char param_4, unsigned int param_5);

unsigned int FUN_a0086540(unsigned int param_1, unsigned int param_2, char param_3, unsigned char param_4)
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
