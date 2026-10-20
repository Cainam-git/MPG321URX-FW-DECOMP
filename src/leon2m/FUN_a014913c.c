/* leon2m FUN_a014913c @ 0xa014913c-0xa0149178 (15 words), flags -mcpu=v8 -O3 -g.
 * Code facts: byte 0xa802e3d0+0x1c = u8 param; if param != 5: FUN_a011855c() then tail FUN_a014110c(re-read
 * rec+0x1c) (1 arg, restore in the delay slot); else tail FUN_a011855c(). Returns nothing.
 * Source form: the base DAT_a802e3d0 as a struct, one u8 param, FUN_a011855c(void); FUN_a014110c takes one
 * u8 argument. Aids: none.
 */
struct E3D0 { unsigned char pad[0x1c]; unsigned char b1c; };
extern struct E3D0 DAT_a802e3d0;
extern void FUN_a011855c(void);
extern void FUN_a014110c(unsigned char);

void FUN_a014913c(unsigned char param_1)
{
  struct E3D0 *p = &DAT_a802e3d0;

  p->b1c = param_1;
  if (param_1 != 5) {
    FUN_a011855c();
    FUN_a014110c(p->b1c);
    return;
  }
  FUN_a011855c();
}
