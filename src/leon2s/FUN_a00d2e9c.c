/* leon2s FUN_a00d2e9c @ 0xa00d2e9c (-mcpu=v8 -Os -g)
 * By byte 0xA8078C37: 4 -> FUN_a0fb6fc0(0, 5, 8); 5 -> FUN_a0fb6fc0(1, 5, 8); 0..3 and other values: nothing
 * (an if chain testing 0, 1, 2, 3 first).
 */
extern unsigned char DAT_a8078c37;
extern int FUN_a0fb6fc0();

void FUN_a00d2e9c(void)
{
    unsigned char v = DAT_a8078c37;
    
    if (v == 0) return;
    if (v == 1) return;
    if (v == 2) return;
    if (v == 3) return;
    
    if (v == 4) {
        FUN_a0fb6fc0(0, 5, 8);
        return;
    }
    
    if (v == 5) {
        FUN_a0fb6fc0(1, 5, 8);
        return;
    }
}
