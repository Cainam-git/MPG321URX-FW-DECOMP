/* pq_auto_level_apply_brightness  (FUN_a012a700)
 *
 * Scale a level to the panel range, let the hook adjust it and send it as brightness.
 * Name basis: derived - v * 0x381 / 0x3FF + 0x7E, optional hook, then SetBrightness; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012a700 @ 0xa012a700-0xa012a774 (29 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the scaled value is written back into the parameter itself, whose address the hook receives (the
 *    firmware keeps it in the parameter's home slot %fp+0x44 and re-reads it for SetBrightness);
 *  - the scaling is unsigned (LEVEL_RANGE written 0x381U; the division becomes a multiply by 0x401005).
 */
extern void (*sys_callback_table_slot13)(unsigned short *);
extern void SetBrightness(unsigned short);

/* Level range of the stepping, and the range handed to SetBrightness (as in pq_auto_level_task). */
#define LEVEL_MAX    0x3ff
#define LEVEL_MIN    0x7e           /* 126 */
#define LEVEL_RANGE  0x381U         /* 897 */

/*
 * Scale a level 0..LEVEL_MAX to LEVEL_MIN..LEVEL_MIN + LEVEL_RANGE, let the slot-13 hook of the callback table
 * adjust it in place when one is set, and write it with SetBrightness.
 *
 * Nothing in the firmware calls this routine; pq_auto_level_task has its own copy of it.
 */
void pq_auto_level_apply_brightness(unsigned short level)
{
    level = level * LEVEL_RANGE / LEVEL_MAX + LEVEL_MIN;
    if (sys_callback_table_slot13 != 0)
        sys_callback_table_slot13(&level);
    SetBrightness(level);
}
