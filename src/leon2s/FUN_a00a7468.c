/* leon2s FUN_a00a7468 @ 0xa00a7468 (-mcpu=v8 -Os -g)
 * Returns FUN_a00a7408(p1, FUN_a00a7368(p2, p3)) (tail call; p1 passed through unchanged).
 */
typedef unsigned int uint;

extern uint FUN_a00a7368(uint, uint);
extern uint FUN_a00a7408(uint, int);

uint FUN_a00a7468(uint param_1, unsigned char param_2, unsigned short param_3)
{
    return FUN_a00a7408(param_1, FUN_a00a7368(param_2, param_3));
}
