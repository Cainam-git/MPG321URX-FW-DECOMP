/* leon2s FUN_a00aa7cc @ 0xa00aa7cc (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
extern int FUN_a00a7acc();

unsigned char FUN_a00aa7cc(unsigned char param_1)
{
    unsigned char result;
    unsigned char val;
    
    result = 7;
    param_1 = param_1 & 0xff;
    if (param_1 == 0) {
        val = (unsigned char)(FUN_a00a7acc(0, 10) & 0xff);
        if (val == 0x11) {
            result = 0;
        } else if (val == 0x22) {
            result = 1;
        } else if (val == 0x66) {
            result = 2;
        } else if (val == 0x44) {
            result = 4;
        } else if (val == 0x33) {
            result = 5;
        }
    } else {
        val = (unsigned char)(FUN_a00a7acc(param_1, 99) & 0x70);
        if (val == 0x10) {
            result = 0;
        } else if (val == 0x20) {
            result = 1;
        } else if (val == 0x60) {
            result = 2;
        } else if (val == 0x40) {
            result = 4;
        } else if (val == 0x30) {
            result = 5;
        }
    }
    return (unsigned char)(result & 7);
}
