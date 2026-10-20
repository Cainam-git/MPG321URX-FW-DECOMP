/* leon2s FUN_a00a7468 @ 0xa00a7468  MATCH (-mcpu=v8 -Os -g)
 * The function calls `FUN_a00a7368` with the byte and halfword parameters, then passes that result as the second argument to `FUN_a00a7408`, returning its result via a tail call (the `restore` in the delay slot). The first parameter is passed through unchanged to the second call.
 */
typedef unsigned int uint;

extern uint FUN_a00a7368(uint, uint);
extern uint FUN_a00a7408(uint, int);

uint FUN_a00a7468(uint param_1, unsigned char param_2, unsigned short param_3)
{
    return FUN_a00a7408(param_1, FUN_a00a7368(param_2, param_3));
}
