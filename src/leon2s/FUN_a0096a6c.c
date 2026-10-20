/* leon2s FUN_a0096a6c @ 0xa0096a6c  MATCH (-mcpu=v8 -Os -g)
 * This function clears two 4-byte words at 0xa807d650 and 0xa807d668 (24 bytes apart), which are the first two entries of a table of 24-byte records.
 */
extern unsigned int DAT_a807d650[];

void FUN_a0096a6c(void)
{
    unsigned char i = 0;
    unsigned int j;
    
    do {
        j = i * 24;
        i = i + 1;
        DAT_a807d650[j / 4] = 0;
    } while (i <= 1);
}
