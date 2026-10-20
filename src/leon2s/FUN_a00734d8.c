/* leon2s FUN_a00734d8 @ 0xa00734d8  MATCH (-mcpu=v8 -Os -g)
 * Sets byte 2 of the 0x18-byte entry (param_1 & 0xFF) of the table at 0xA807CC64 to 1.
 */
typedef unsigned int uint;
typedef unsigned char undefined1;
extern undefined1 ARR_a807cc64[];

void FUN_a00734d8(uint param_1)

{
  ARR_a807cc64[(param_1 & 0xff) * 0x18 + 2] = 1;
  return;
}
