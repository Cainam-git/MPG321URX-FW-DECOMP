/* leon2m FUN_a009e91c @ 0xa009e91c-0xa009e9a8 (35 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * When FUN_a0143c14(0) returns 10, or bit 9 (0x200) of word 0xa802d290 is set, or word 0xa802afec is not 0xfe, and
 * in all these cases the signed word 0xa802e1a0 is negative: sets word 0xa802afec to 0x10d, clears byte 0xa802cff5
 * and tail-calls FUN_a00b867c.
 */
extern unsigned int DAT_a802d290;
extern unsigned int DAT_a802afec;
extern int DAT_a802e1a0;
extern unsigned char DAT_a802cff5;
extern unsigned char FUN_a0143c14(unsigned char);
extern void FUN_a00b867c(void);

void FUN_a009e91c(void)
{
    if ((FUN_a0143c14(0) == 10 || (DAT_a802d290 & 0x200) || DAT_a802afec != 0xfe) && DAT_a802e1a0 < 0) {
        DAT_a802afec = 0x10d;
        DAT_a802cff5 = 0;
        FUN_a00b867c();
    }
}
