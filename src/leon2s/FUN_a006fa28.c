/* FUN_a006fa28 (leon2s 0xa006fa28-0xa006faa8, 128 bytes), flags -mcpu=v8 -Os -g.
 * Calls FUN_a006d4e0(), then passes the 20-byte records 0..5 of DAT_a807a824 with their indices to
 * LINK_STANDBY (records 0, 1), LINK_STANDBY_2 (records 2, 3) and DP_GetClrSpace (records 4, 5, third argument 0 and
 * 4), and tail-calls FUN_a008c8b0().
 */
struct Rec20 { unsigned char state; unsigned char rest[19]; };
extern struct Rec20 DAT_a807a824[];
extern void FUN_a006d4e0(void);
extern void LINK_STANDBY(struct Rec20 *, unsigned char);
extern void LINK_STANDBY_2(struct Rec20 *, unsigned char);
extern void DP_GetClrSpace(struct Rec20 *, unsigned char, unsigned int);
extern void FUN_a008c8b0(void);

void FUN_a006fa28(void)
{
    FUN_a006d4e0();
    LINK_STANDBY(&DAT_a807a824[0], 0);
    LINK_STANDBY(&DAT_a807a824[1], 1);
    LINK_STANDBY_2(&DAT_a807a824[2], 0);
    LINK_STANDBY_2(&DAT_a807a824[3], 1);
    DP_GetClrSpace(&DAT_a807a824[4], 0, 0);
    DP_GetClrSpace(&DAT_a807a824[5], 1, 4);
    FUN_a008c8b0();
}
