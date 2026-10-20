/* leon2s FUN_a00aa2d0 @ 0xa00aa2d0  MATCH (-mcpu=v8 -Os -g)
 * 
 */
typedef unsigned int uint;
typedef unsigned short ushort;

extern unsigned char DAT_a807d3b9;
extern void FUN_a00a7cc0(uint param_1, ushort param_2, uint param_3);

void FUN_a00aa2d0(void)
{
    if (DAT_a807d3b9 == 0xa0) {
        FUN_a00a7cc0(0, 0x37, 0xa0);
    } else {
        FUN_a00a7cc0(0, 0x37, 0x10);
    }
    return;
}
