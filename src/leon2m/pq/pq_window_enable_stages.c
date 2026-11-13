/* pq_window_enable_stages  (FUN_a00f6b34)
 *
 * Switch on the picture stages named by a mask.
 * Name basis: derived - sets bits of 0xCF00EF00 / 0xCF00EF30
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6b34 @ 0xa00f6b34-0xa00f6c38 (260 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: an unsigned int parameter `stage_mask`; each bit is tested with an if and a read-modify-write on the register.
 */
#define REG_CF00EF00 (*(volatile unsigned int *)0xcf00ef00)
#define REG_CF00EF30 (*(volatile unsigned int *)0xcf00ef30)

/*
 * Switch on the picture stages named by a mask.
 *
 * For each bit set in stage_mask, a corresponding bit is set in one of two registers:
 * bits 0..4 set bits 6,5,4,3,2 of REG_CF00EF00; bits 5,6,7 set 0x81,0x41,0x11 into REG_CF00EF30.
 * Callers: pq_fga_handle_command, input_channel_bring_up_task. pq_window_disable_stages undoes it.
 */
void pq_window_enable_stages(unsigned int stage_mask)
{
    /* bits 0..4 of the mask map to bits 6..2 of REG_CF00EF00 */
    if (stage_mask & 1)
        REG_CF00EF00 |= 0x40;
    if (stage_mask & 2)
        REG_CF00EF00 |= 0x20;
    if (stage_mask & 4)
        REG_CF00EF00 |= 0x10;
    if (stage_mask & 8)
        REG_CF00EF00 |= 8;
    if (stage_mask & 0x10)
        REG_CF00EF00 |= 4;
    /* bits 5..7 of the mask map to the given values in REG_CF00EF30 */
    if (stage_mask & 0x20)
        REG_CF00EF30 |= 0x81;
    if (stage_mask & 0x40)
        REG_CF00EF30 |= 0x41;
    if (stage_mask & 0x80)
        REG_CF00EF30 |= 0x11;
}
