/* leon2s FUN_a007ebd0 @ 0xa007ebd0  MATCH (-mcpu=v8 -Os -g)
 * Calls FUN_a0073520(param_1 & 0xFF). When the low byte of the result is non-zero, calls FUN_a00a73ac(0x10,
 * DAT_a807db00[idx * 13 + 1] + 0x34) with idx = 0 for param_1 == 2 and 1 otherwise (13-word records); else calls
 * FUN_a00a67b8(param_1 & 0xFF, 0x136, 1, 0).
 */
typedef unsigned int uint;

extern uint FUN_a0073520(uint param_1);
extern void FUN_a00a67b8(uint param_1, uint param_2, uint param_3, uint param_4);
extern void FUN_a00a73ac(uint param_1, uint param_2);
extern uint DAT_a807db00[];

void FUN_a007ebd0(uint param_1)
{
    uint masked;
    uint result;
    uint idx;
    
    masked = param_1 & 0xff;
    result = FUN_a0073520(masked);
    
    if (result & 0xff) {
        idx = (masked != 2) ? 1 : 0;
        FUN_a00a73ac(0x10, DAT_a807db00[idx * 13 + 1] + 0x34);
        return;
    }
    
    FUN_a00a67b8(masked, 0x136, 1, 0);
}
