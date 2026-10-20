/* leon2m FUN_a00991ec @ 0xa00991ec-0xa0099244 (22 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table). Toggles bit 22 of the word 0xa802d33c (0xa802d290 + 0xac), calls FUN_a00a5420(5, new bit) and
 * sets bit 1 (0x02) of byte 0xa802b08e. The bit is a 1-bit bit-field written as 'f = 1 - f'. Same form as
 * FUN_a009934c (bit 7 of 0xa802d290 + 0x1ec).
 */
struct R290 { unsigned char pad[0xac]; unsigned int hi : 9, f22 : 1, lo : 22; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern void FUN_a00a5420(int, unsigned char);

void FUN_a00991ec(void)
{
    struct R290 *p = &DAT_a802d290;

    p->f22 = 1 - p->f22;
    FUN_a00a5420(5, p->f22);
    DAT_a802b08e |= 2;
}
