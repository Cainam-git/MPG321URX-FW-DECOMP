/* leon2m FUN_a00d1f20, flags -mcpu=v8 -O3 (no -g: with -g a nop follows the final call). No direct callers (reached through a table).
 * Command handler taking a pointer to a received frame: byte 7 of the frame, limited to 100, is stored in byte
 * 0xa802d29a (0xa802d290+0xa); then FUN_a00d7de0() runs. Returns 0xe0.
 * Source form: the structure at 0xa802d290 is accessed through a pointer local (a direct access lets GCC merge the
 * two stores into one conditional move).
 */
struct R290 { unsigned char p000[9]; unsigned char b009; unsigned char b00a; };
extern struct R290 DAT_a802d290;
extern void FUN_a00d7de0(void);

int FUN_a00d1f20(unsigned char *p)
{
    struct R290 *r = &DAT_a802d290;

    if (p[7] > 100)
        r->b00a = 100;
    else
        r->b00a = p[7];
    FUN_a00d7de0();
    return 0xe0;
}
