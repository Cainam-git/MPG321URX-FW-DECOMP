/* leon2m FUN_a013a8ac @ 0xa013a8ac  MATCH (-mcpu=v8 -O2 -g)
 * This function calls the trace/IO function at 0x4008c4d0 with arguments (2, 0x10, &local_c, 1), where local_c is zero-initialized, and returns the value written by the call. The structure matches the worked example exactly, just with different constants (2 instead of 2, 0x10 instead of 0x4c).
 */
extern int func_0x4008c4d0();

unsigned int FUN_a013a8ac(void)
{
    unsigned int local_c;
    
    local_c = 0;
    func_0x4008c4d0(2, 0x10, &local_c, 1);
    return local_c;
}
