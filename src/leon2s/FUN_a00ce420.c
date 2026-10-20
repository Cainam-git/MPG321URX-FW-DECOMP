/* leon2s FUN_a00ce420 @ 0xa00ce420-0xa00ce4cc (43 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 * Code facts: port = arg & 0xff; word at 0xa8078bb0 + port*0x18: clear bits 16..17 (andn 0x30000),
 * set 0x10000; FUN_a00c87e8(port, 5, 0x8000); for i = 0..31 (u8, bleu 0x1f) byte table
 * 0xa807ce50[i] = FUN_a00c7770(port, 1); then func_0xa0f963d4(0, 0x80, 0x692a0, 0xf, table) and
 * tail func_0xa0f963d4(0, 0x80, 0x692b0, 0xf, table + 0x10).
 * Fix vs the autoc draft (97.67, one word: stb [%l0+%i4] vs fw [%i4+%l0]): the store goes through a
 * local pointer 'unsigned char *p = &DAT_a807ce50;' declared in the loop body, which gives the fw
 * base+index operand order. Integer address forms and &b[i] all gave index+base. Aids: none.
 */
extern unsigned int DAT_a8078bb0;
extern unsigned char DAT_a807ce50;
extern int FUN_a00c7770();
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern int func_0xa0f963d4();

void FUN_a00ce420(unsigned char param_1)

{
  unsigned char i;
  unsigned char tmp;
  
  param_1 = param_1 & 0xff;
  *(unsigned int *)((unsigned char *)&DAT_a8078bb0 + param_1 * 0x18) =
       (*(unsigned int *)((unsigned char *)&DAT_a8078bb0 + param_1 * 0x18) & 0xfffcffff) | 0x10000;
  FUN_a00c87e8(param_1, 5, 0x8000);
  i = 0;
  do {
    unsigned char *p = &DAT_a807ce50;
    tmp = i;
    p[tmp] = FUN_a00c7770(param_1, 1);
    i = i + 1;
  } while (i <= 0x1f);
  func_0xa0f963d4(0, 0x80, 0x692a0, 0xf, &DAT_a807ce50);
  func_0xa0f963d4(0, 0x80, 0x692b0, 0xf, &DAT_a807ce50 + 0x10);
}
