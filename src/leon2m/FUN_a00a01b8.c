/* leon2m FUN_a00a01b8 @ 0xa00a01b8-0xa00a01fc (17 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a00b0f48(); word 0xa802afec = 0x116; byte 0xa802b08e |= 2; byte 0xa802d43a = 0 (clrb in the call
 * delay slot); u16 0xa802d03c = func_0x4008d588() (ROM ms tick, u16, no argument). void(void).
 * func_0x4008d588 takes no argument: the 'sethi %hi(0xa802d400), %o0' before the call is only the HIGH of
 * DAT_a802d43a for the clrb. Its prototype is 'unsigned short func_0x4008d588(void)' as elsewhere in src/.
 * Compiler aids: none.
 */
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a802d43a;
extern unsigned short DAT_a802d03c;
extern unsigned int _DAT_a802afec;
extern void FUN_a00b0f48(void);
extern unsigned short func_0x4008d588(void);

void FUN_a00a01b8(void)
{
  FUN_a00b0f48();
  _DAT_a802afec = 0x116;
  DAT_a802b08e |= 2;
  DAT_a802d43a = 0;
  DAT_a802d03c = func_0x4008d588();
}
