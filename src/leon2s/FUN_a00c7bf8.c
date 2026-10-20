/* leon2s FUN_a00c7bf8 @ 0xa00c7bf8-0xa00c7ccc (53 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 * Code facts: port = arg & 0xff. Loop 1: FUN_a00c7b60(port); v = FUN_a0fb7fd8(port, 0, 0xf2); repeat
 * while (v & 0x10) and the u8 count <= 4. Loop 2: FUN_a00c7b90(port); v = FUN_a0fb7fd8(port, 0, 0xf5);
 * repeat while (v & 0x1f) and count <= 4. Then FUN_a00c7bc4(port); FUN_a0fc1794(1); status 0xf2 bit
 * 0x10 set -> 0xe, else status 0xf5 & 0x1f -> 0xf, else 0; returns that & 0xf.
 * Fix vs the autoc draft (96.23): BEHAVIOUR, both retry tests were inverted (the loops repeat while
 * the status bits are SET; fw 'btst; be exit'). Aids: none.
 */
typedef unsigned int uint;

extern void FUN_a00c7b60(uint);
extern void FUN_a00c7b90(uint);
extern void FUN_a00c7bc4(uint);
extern int FUN_a0fb7fd8(uint, uint, uint);
extern void FUN_a0fc1794(uint);

uint FUN_a00c7bf8(unsigned char param_1)
{
  unsigned char ret;
  uint i;
  uint val;
  
  ret = 0;
  i = 0;
  param_1 &= 0xff;
  
  do {
    FUN_a00c7b60(param_1);
    val = FUN_a0fb7fd8(param_1, 0, 0xf2);
    i++;
    if ((val & 0x10) != 0 && (i & 0xff) <= 4) {
      continue;
    }
    break;
  } while (1);
  
  i = 0;
  do {
    FUN_a00c7b90(param_1);
    val = FUN_a0fb7fd8(param_1, 0, 0xf5);
    i++;
    if ((val & 0x1f) != 0 && (i & 0xff) <= 4) {
      continue;
    }
    break;
  } while (1);
  
  FUN_a00c7bc4(param_1);
  FUN_a0fc1794(1);
  val = FUN_a0fb7fd8(param_1, 0, 0xf2);
  if ((val & 0x10) != 0) {
    ret = 0xe;
  } else {
    val = FUN_a0fb7fd8(param_1, 0, 0xf5);
    if ((val & 0x1f) != 0) {
      ret = 0xf;
    }
  }
  return ret & 0xf;
}
