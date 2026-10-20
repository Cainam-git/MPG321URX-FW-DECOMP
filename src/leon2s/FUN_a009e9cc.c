/* leon2s FUN_a009e9cc @ 0xa009e9cc (-mcpu=v8 -Os -g)
 * This function takes a byte parameter, computes `index = (param_1 & 0xff) * 0x18` (24 bytes per entry), then writes a byte `0xf` at offset +5 and a word `5` at offset +0 of the table at 0xa807d650. It follows the exact same idiom as the already-matched FUN_a009e9a4 (same array, same index computation, same return style). The main uncertainty is whether the compiler will CSE the duplicated `(param_1 & 0xff) * 0x18` expression into a single multiplication, but GCC 3.4 at -Os should do so since the result is used twice with no intervening side effects. The two stores are ordered byte-first then wo
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;

extern undefined1 ARR_a807d650[];

void FUN_a009e9cc(unsigned int param_1)
{
  ARR_a807d650[(param_1 & 0xff) * 0x18 + 5] = 0xf;
  *(undefined4 *)(ARR_a807d650 + (param_1 & 0xff) * 0x18) = 5;
  return;
}
