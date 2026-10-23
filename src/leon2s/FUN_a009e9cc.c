/* leon2s FUN_a009e9cc @ 0xa009e9cc (-mcpu=v8 -Os -g)
 * Entry i = p & 0xff of the 24-byte records at 0xA807D650: byte +5 = 0xf, word +0 = 5. Same form as FUN_a009e9a4.
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
