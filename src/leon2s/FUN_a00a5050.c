/* leon2s FUN_a00a5050 @ 0xa00a5050 (-mcpu=v8 -Os -g)
 * 
 */
extern unsigned int DAT_a807dc10[];

void FUN_a00a5050(void)
{
    unsigned char i = 0;
    do {
        DAT_a807dc10[i * 2] = 0;
        i++;
    } while (i == 0);
}
