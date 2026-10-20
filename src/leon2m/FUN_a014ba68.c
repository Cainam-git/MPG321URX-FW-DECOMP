/* leon2m FUN_a014ba68 @ 0xa014ba68-0xa014bac4 (23 words), flags -mcpu=v8 -O3 -g (-Os gives other code).
 * Code facts: maps the u8 FUN_a0138e5c() result 0..3 to itself and every other value to 4 (signed case tree
 * rooted at 1); returns u8 (the extension 'and 0xff' is reduced to 'and 7' by combine, nonzero bits of 0..4).
 * Source form: a plain switch with a u8 result. Aids: none.
 */
extern unsigned char FUN_a0138e5c(void);

unsigned char FUN_a014ba68(void)
{
  unsigned char r;

  switch (FUN_a0138e5c()) {
  case 0:
    r = 0;
    break;
  case 1:
    r = 1;
    break;
  case 2:
    r = 2;
    break;
  case 3:
    r = 3;
    break;
  default:
    r = 4;
    break;
  }
  return r;
}
