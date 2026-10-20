/* leon2s FUN_a00ad684 @ 0xa00ad684  MATCH (-mcpu=v8 -Os -g)
 * The key insight: the target sets up `%i0`, `%i1`, `%i2` *before* the branch (at 0xa00ad698-0xa00ad6a0), then does the `btst`/`bne` test, and only sets `%i3` differently in each branch. The two calls have identical first three arguments; only the fourth differs. This is an if/else with the same call in both branches, where the fourth argument is `(result & 0x10) ? 0 : 1`.
 */
typedef unsigned int uint;

extern uint FUN_a00a6bb8(uint param_1, unsigned short param_2);
extern uint FUN_a00a6c98(uint param_1, unsigned short param_2, int param_3, int param_4);

uint FUN_a00ad684(uint param_1)
{
    uint result;
    uint masked;
    
    masked = param_1 & 0xff;
    result = FUN_a00a6bb8(masked, 0x8f);
    
    if (result & 0x10) {
        return FUN_a00a6c98(masked, 0x22a, 2, 0);
    } else {
        return FUN_a00a6c98(masked, 0x22a, 2, 1);
    }
}
