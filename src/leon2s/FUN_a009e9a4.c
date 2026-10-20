/* leon2s FUN_a009e9a4 @ 0xa009e9a4 (-mcpu=v8 -Os -g)
 * The difference was the base address: the firmware uses `0xa807d650` (the `sethi`/`or` pair computes this exact address), not `0xa807d65a`. The array declaration now points to the correct base, and the byte offset `+0xa` selects the field within the record.
 */
typedef unsigned char undefined1;

extern undefined1 ARR_a807d650[];

void FUN_a009e9a4(unsigned int param_1)
{
  ARR_a807d650[(param_1 & 0xff) * 0x18 + 0xa] = 1;
  return;
}
