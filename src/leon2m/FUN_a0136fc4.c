/* leon2m FUN_a0136fc4 @ 0xa0136fc4  MATCH (-mcpu=v8 -O2 -g)
 * The function clears a local word, calls the same helper as its neighbors (func_0x4008c4d0) with arguments (1, 0, &local, 1), then reads the third byte (offset +3) of that local, masks with 1, and returns it. The only difference from the nearest match FUN_a0136ff0 is the byte offset (+3 instead of +0) and the second call argument (0 instead of 0xc). The byte offset +3 follows from the target's `ldub [%fp-9]` (fp-12 + 3 = fp-9), so the byte access must be at offset +3 of the 4-byte local.
 */
// FUN_a0136fc4 at 0xa0136fc4
extern int func_0x4008c4d0();

int FUN_a0136fc4(void)
{
    unsigned int local_c;
    
    local_c = 0;
    func_0x4008c4d0(1, 0, &local_c, 1);
    return *((unsigned char *)&local_c + 3) & 1;
}
