/* leon2s FUN_a0061864 @ 0xa0061864  MATCH (-mcpu=v8 -Os -g)
 * Byte-swaps (param_2 >> 2) 32-bit words in place starting at param_1 and returns the pointer past the last word.
 * The temporaries t1..t5 give the firmware's order of the mask and shift operations.
 */
unsigned int *FUN_a0061864(unsigned int *param_1, unsigned int param_2)
{
    unsigned int count = param_2 >> 2;
    unsigned int v, t1, t2, t3, t4, t5;
    
    while (count != 0) {
        v = *param_1;
        t1 = v & 0xff0000;
        t2 = v >> 24;
        t3 = v & 0xff00;
        t1 = t1 >> 8;
        t3 = t3 << 8;
        t4 = t2 | t1;
        t4 = t4 | t3;
        t5 = v << 24;
        v = t4 | t5;
        *param_1 = v;
        param_1++;
        count--;
    }
    
    return param_1;
}
