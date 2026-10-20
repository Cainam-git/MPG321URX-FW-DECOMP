/* leon2s FUN_a0087734 @ 0xa0087734  MATCH (-mcpu=v8 -Os -g)
 * All three parameters are masked to bytes. For param_1 == 0 calls FUN_a00aa5e8(param_1, param_2, DAT_a807cd02, 1),
 * else for param_1 == param_3 FUN_a00aa5e8(param_1, param_2, DAT_a807cd2c, 1); then always
 * FUN_a00a78fc(param_1, 2, param_2).
 */
typedef unsigned int uint;

extern volatile unsigned char DAT_a807cd02;
extern unsigned char DAT_a807cd2c;
extern void FUN_a00a78fc(uint param_1, unsigned short param_2, uint param_3);
extern void FUN_a00aa5e8();

void FUN_a0087734(uint param_1, unsigned char param_2, uint param_3)
{
    param_1 &= 0xff;
    param_2 &= 0xff;
    param_3 &= 0xff;
    
    if (param_1 == 0) {
        FUN_a00aa5e8(param_1, param_2, DAT_a807cd02, 1);
    } else if (param_1 == param_3) {
        FUN_a00aa5e8(param_1, param_2, DAT_a807cd2c, 1);
    }
    FUN_a00a78fc(param_1, 2, param_2);
}
