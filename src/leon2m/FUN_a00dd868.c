/* FUN_a00dd868 (leon2m 0xa00dd868-0xa00dd8ac, 68 bytes), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp (rawcmp.py) 0 mismatches of 17 words.
 * Code facts: a strcmp-style compare of two strings with SIGNED char elements. Each pass loads one
 * byte from each string (ldub + sll/sra 24 sign extension), d = a[i] - b[i], both pointers step by 1,
 * and the loop repeats while d == 0 and the a byte is non-zero (branch-free subx/addx/btst form).
 * Returns the last difference d. Called from FUN_a00dcec4.
 * Aids: none. Lever: the two char locals are loaded first and the pointer increments come BEFORE
 * 'd = c1 - c2'; then the QI loads keep ldub + shift extension like the fw (an int local or the
 * increments after the subtraction give ldsb, 2 words shorter).
 */
int FUN_a00dd868(const char *a, const char *b)
{
  char c1, c2;
  int d;

  do {
    c1 = *a;
    c2 = *b;
    a++;
    b++;
    d = c1 - c2;
  } while (!d && c1);
  return d;
}
