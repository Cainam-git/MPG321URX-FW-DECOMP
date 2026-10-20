/* leon2s FUN_a0089f98 @ 0xa0089f98  MATCH (-mcpu=v8 -Os -g)
 * The key fix from Ghidra's version: the call takes `idx` (the loop counter), not `param_1`. The loop also runs until counter reaches 8 inclusive (9 iterations total).
 */
extern int FUN_a0089f84(unsigned char param_1);

unsigned short FUN_a0089f98(unsigned char param_1)
{
    unsigned short result = 0;
    unsigned char counter = 0;
    unsigned char idx;
    
    do {
        idx = counter;
        if ((FUN_a0089f84(idx) & 0xff) == (param_1 & 0xff)) {
            result |= (unsigned short)(1 << idx);
        }
        counter++;
    } while ((counter & 0xff) <= 8);
    
    return result;
}
