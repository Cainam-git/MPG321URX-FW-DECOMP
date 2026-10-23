/* leon2s FUN_a00865b8 @ 0xa00865b8 (-mcpu=v8 -Os -g)
 * c = 1 when (b & 0xff) == 1, else 2. Up to 5 times: FUN_a0086360(a & 0xff, 0x80, 0x600, c); a result with low byte 0
 * returns 1. After 5 non-zero results returns 0. Source form: the counter is an unsigned char.
 */
extern int FUN_a0086360(int, int, int, int);

int FUN_a00865b8(int a, int b)
{
    unsigned char i = 0;
    unsigned char c;
    
    if ((unsigned char)b == 1)
        c = 1;
    else
        c = 2;
    
    do {
        int r = FUN_a0086360((unsigned char)a, 0x80, 0x600, c);
        i++;
        if ((r & 0xff) == 0)
            return 1;
    } while (i <= 4);
    
    return 0;
}
