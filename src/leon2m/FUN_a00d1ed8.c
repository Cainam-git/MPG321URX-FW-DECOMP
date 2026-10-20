/* leon2m FUN_a00d1ed8, flags -mcpu=v8 -O3 -g. No direct callers (reached through a table).
 * Command handler taking a pointer to a received frame: byte 7 of the frame, limited to 100, is stored in byte
 * 0xa802d299 (0xa802d290+9); then FUN_a00d8cd4() runs and bit 2 (0x04) of byte 0xa802b08e is set. Returns 0xe0.
 * Source form: the structure at 0xa802d290 is accessed through a pointer local (a direct access lets GCC merge the
 * two stores into one conditional move).
 */
struct R290 { unsigned char p000[9]; unsigned char b009; unsigned char b00a; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern void FUN_a00d8cd4(void);

int FUN_a00d1ed8(unsigned char *p)
{
    struct R290 *r = &DAT_a802d290;

    if (p[7] > 100)
        r->b009 = 100;
    else
        r->b009 = p[7];
    FUN_a00d8cd4();
    DAT_a802b08e |= 4;
    return 0xe0;
}
