/* FUN_a013d0ec (leon2m 0xa013d0ec-0xa013d178, 140 bytes), flags -mcpu=v8 -O3 -g.
 * For c = 0: calls the function pointer at DAT_a802cc1c + 0x28 when set, otherwise clears bit 26 of the word
 * DAT_a802e3d0; then calls the pointer at DAT_a802cc1c + 0x24 when set, otherwise clears bit 27 of DAT_a802e3d0.
 */
struct Cb { unsigned char p0[0x24]; void (*f24)(void); void (*f28)(void); };
extern struct Cb DAT_a802cc1c;
extern unsigned int DAT_a802e3d0;

void FUN_a013d0ec(unsigned char c)
{
    if (c == 0) {
        if (DAT_a802cc1c.f28)
            DAT_a802cc1c.f28();
        else
            DAT_a802e3d0 &= ~0x4000000u;
        if (DAT_a802cc1c.f24)
            DAT_a802cc1c.f24();
        else
            DAT_a802e3d0 &= ~0x8000000u;
    }
}
