/* leon2m FUN_a015cd28 @ 0xa015cd28  MATCH (-mcpu=v8 -O2 -g)
 * Pushes the node param_2 onto the head of a list in a table: with idx = node word 1 and table = the pointer at
 * byte offset 0x4C of param_1, the node's word 0 (next) receives table[idx] and table[idx] receives the node. A
 * NULL node does nothing. param_1 is an int base address with a fixed byte displacement, which gives ld [%o0 +
 * 0x4c].
 */
void FUN_a015cd28(int param_1, int *param_2)
{
    if (param_2 != 0) {
        int idx = param_2[1];
        int *base = *(int **)(param_1 + 0x4c);
        *param_2 = base[idx];
        base[idx] = param_2;
    }
}
