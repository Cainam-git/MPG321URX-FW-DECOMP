/* leon2s FUN_a00dcc80 @ 0xa00dcc80-0xa00dccd8 (22 words), flags -mcpu=v8 -Os -g.
 * v = byte 0xa807953d; FUN_a00dcc50(v); tail ROM call func_0xa0f834c4(string) with s_9f1cec38 / s_9f1cec50 /
 * s_9f1cec68 for v 0 / 2 / 3, else s_9f1cec80 (each string has its own sethi/or into %i0, then one shared
 * 'call; restore'). void(void).
 * The strings are symbols passed to separate tail calls.
 */
extern unsigned char DAT_a807953d;
extern char s_9f1cec38[], s_9f1cec50[], s_9f1cec68[], s_9f1cec80[];
extern void FUN_a00dcc50(unsigned char);
extern void func_0xa0f834c4(char *);

void FUN_a00dcc80(void)
{
  unsigned char v = DAT_a807953d;

  FUN_a00dcc50(v);
  if (v == 0)
    func_0xa0f834c4(s_9f1cec38);
  else if (v == 2)
    func_0xa0f834c4(s_9f1cec50);
  else if (v == 3)
    func_0xa0f834c4(s_9f1cec68);
  else
    func_0xa0f834c4(s_9f1cec80);
}
