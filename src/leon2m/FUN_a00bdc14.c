/* leon2m FUN_a00bdc14 @ 0xa00bdc14-0xa00bdc60 (19 words), flags -mcpu=v8 -O3 -g.
 * Family of src/leon2m/FUN_a00bdcb0.c.
 * Code facts: text bytes DAT_a802d078[7], [8] = '0' (0x30) and [9] = 0x32 - byte 0xa802d290+0x31, all three stored
 * BEFORE FUN_a00bac3c(0x38); then FUN_a00ba950(param_1) (u8); tail FUN_a00babe4(param_1, 0xb). void.
 * Source form: the record bases DAT_a802d078[] / DAT_a802d290; the stores in ascending index order; u8 prototypes.
 * Compiler aids: none.
 */
struct R290 { unsigned char pad[0x31]; unsigned char b31; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c(unsigned char);
extern unsigned char FUN_a00ba950(unsigned char);
extern void FUN_a00babe4(unsigned char, unsigned char);

void FUN_a00bdc14(unsigned char param_1)
{
  DAT_a802d078[7] = 0x30;
  DAT_a802d078[8] = 0x30;
  DAT_a802d078[9] = 0x32 - DAT_a802d290.b31;
  FUN_a00bac3c(0x38);
  FUN_a00ba950(param_1);
  FUN_a00babe4(param_1, 0xb);
}
