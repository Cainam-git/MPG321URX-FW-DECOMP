/* leon2s FUN_a00a2c18 @ 0xa00a2c18  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Finished by hand from mechanical Ghidra C. For both entries (0, 1) of the 52-byte records
 * at 0xa807db00, takes the pointer in the record's first word, adds 8, and passes it to
 * FUN_a00a73ac(0, p) when param_1 is 1 or to FUN_a00a73d4(0, p) when param_1 is 0; any other
 * value does nothing. Returns 0. Likely an on/off switch applied to two units.
 * Still needs a real name and proper types.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern unsigned char DAT_a807db00;
extern int FUN_a00a73ac();
extern int FUN_a00a73d4();

extern unsigned char ARR_a807db00[][0x34];
int FUN_a00a2c18(unsigned char param_1)
{
  uint i = 0;
  do {
    if (param_1 == 1) FUN_a00a73ac(0, *(int *)ARR_a807db00[i & 0xff] + 8);
    else if (param_1 == 0) FUN_a00a73d4(0, *(int *)ARR_a807db00[i & 0xff] + 8);
    i++;
  } while ((i & 0xff) < 2);
  return 0;
}
