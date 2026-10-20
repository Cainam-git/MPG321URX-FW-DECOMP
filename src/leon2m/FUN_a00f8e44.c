/* leon2m FUN_a00f8e44 @ 0xa00f8e44  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: [walk]; temp arg FUN_a00f1d48#2; selfassign t02_#2; return char; swap param_2 + 1; return unsigned short; local t02_ short; local t02_ unsigned short
 */
extern int FUN_a00f1a90();
extern int FUN_a00f1d48();
extern volatile unsigned short ARR_a802b7d8[];

unsigned short FUN_a00f8e44(unsigned char param_1, unsigned short param_2)
{
    unsigned short t02_;
    unsigned short local_2;
    
    if ((unsigned char)(param_1 - 6) <= 1) {
        if ((FUN_a00f1a90(param_1, 3) & 0x30) == 0) {
            if ((FUN_a00f1a90(param_1, 4) & 0xf) < 2) {
                if ((FUN_a00f1a90(param_1, 0x5c) & 1) == 0) {
                    param_2 = 1 + param_2;
                }
            }
        }
    }
    
    t02_ = ARR_a802b7d8[param_1] + param_2;
    
    FUN_a00f1d48(param_1, 0xe, t02_);
    
    t02_ = t02_;
    FUN_a00f1d48(param_1, 0xc, param_2);
}
