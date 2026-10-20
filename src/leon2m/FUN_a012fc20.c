/* leon2m FUN_a012fc20 @ 0xa012fc20  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: [walk]; selfassign result#0; local nibble short; drop cast (unsigned int); inline temp offset
 */
extern unsigned char DAT_a802a44c;   // 0xa802a44c
extern unsigned char DAT_a802df30;   // 0xa802df30

unsigned char FUN_a012fc20(void)
{
    unsigned char result;

    result = result;
    unsigned int offset;
    unsigned int value;
    short nibble;
    unsigned char *table;
    
    if (DAT_a802a44c == 0xff) {
        result = 0xff;
    } else {
        value = *(unsigned int *)(&DAT_a802df30 + (DAT_a802a44c * 0x78));
        nibble = (value >> 0xc) & 0xf;
        table = (unsigned char *)0xa802e224;
        result = table[nibble * 0x2a + 0xa];
    }
    return result;
}
