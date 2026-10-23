/* leon2m FUN_a01427d4 @ 0xa01427d4..0xa014285c (34 words)  start-up step 2 (FUN_a015266c): resets the 42-byte port
 * table at 0xA802E224.
 * What it does at power-on (code facts): for the 8 entries p = 0xA802E224 + 42*i (i = 0..7): p+0xB = i (port id),
 * p+2 (state) = 1, p+9 = 1, and the flag halfword p+0 loses bit 12 (0x1000) and bit 4 (0x10, the bit FUN_a0142910
 * fills from the timing-entry bit 4). Then entries 0..3 get state 2 (= the state in
 * which FUN_a0142910's per-port sync state machine starts to look for a signal; state 1 = idle).
 * Can it fail or wait? No: two fixed loops of 8 and 4 turns, RAM only, no registers, no calls.
 * It runs before FUN_a0106d64; plain RAM init of input-port state.
 * Exact form: b9 written before state in the source (gcc schedules them reversed); bit 12 and bit 4 as 1-bit fields
 * (two 'and's on one load/store), the u8 loop counters (the 'and 0xff' compares) and the struct indexed by i (smul 42).
 */
struct Port { unsigned short h15_13:3, b12:1, h11_5:7, b4:1, h3_0:4; unsigned char state, type; unsigned char pad4[5]; unsigned char b9, id, b0b; unsigned char rest[30]; };
extern struct Port DAT_a802e224[];

void FUN_a01427d4(void)
{
    unsigned char i;
    for (i = 0; i < 8; i++) {
        DAT_a802e224[i].b0b = i;
        DAT_a802e224[i].b9 = 1;
        DAT_a802e224[i].state = 1;
        DAT_a802e224[i].b12 = 0;
        DAT_a802e224[i].b4 = 0;
    }
    for (i = 0; i < 4; i++)
        DAT_a802e224[i].state = 2;
}
