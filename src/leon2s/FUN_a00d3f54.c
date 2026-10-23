/* FUN_a00d3f54 (leon2s 0xa00d3f54-0xa00d3f70, 28 bytes), flags -mcpu=v8 -Os -g.
 * Stores 1 to the byte DAT_a8078c34, then calls func_0xa0f73950 (a call linked 0xF10000 above FUN_a0063950)
 * as a tail call.
 */
extern unsigned char DAT_a8078c34;
extern void func_0xa0f73950(void);

void FUN_a00d3f54(void)
{
    DAT_a8078c34 = 1;
    func_0xa0f73950();
}
