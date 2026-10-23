/* leon2s FUN_a00d378c @ 0xa00d378c-0xa00d38a8.
 * Reads register 0xb7091090 through func_0xa0f71528 as index a, and register 0xb70803a0 masked with 0x3ff as
 * index b. When DAT_a80769d8[b] * DAT_a8076844[a] / 100 is at most 0x400, reads 0xb70803a0 twice more and stores
 * (DAT_a80769d8[b] * DAT_a8076844[a] / 100 * 100) >> 10 in _DAT_a8078c3c, with b taken from the second read;
 * otherwise stores 100. Then sets _DAT_a80785e4 = DAT_a80766b0[0] * 100 / DAT_a80766b0[_DAT_a8078c3c] and
 * _DAT_a8078c40 = _DAT_a80783dc * _DAT_a80785e4 / 100, and calls FUN_a00d3704(_DAT_a8078c40, 1) (tail call).
 * Source form: _DAT_a8078c3c is declared unsigned long and written through an unsigned long pointer. That type
 * gives the store a different alias set from the unsigned int tables, so it does not order the later table loads
 * and the scheduler places the sethi of DAT_a80766b0 before it, as in the firmware.
 */
extern unsigned int func_0xa0f71528(unsigned int);
extern unsigned int DAT_a80769d8[];
extern unsigned int DAT_a8076844[];
extern unsigned int DAT_a80766b0[];
extern unsigned long _DAT_a8078c3c;
extern unsigned int _DAT_a8078c40;
extern unsigned int _DAT_a80785e4;
extern unsigned short _DAT_a80783dc;
extern void FUN_a00d3704(unsigned int, int);

void FUN_a00d378c(void)
{
    unsigned int a;
    unsigned int v;
    unsigned long *p = &_DAT_a8078c3c;

    a = func_0xa0f71528(0xb7091090);
    if (DAT_a80769d8[func_0xa0f71528(0xb70803a0) & 0x3ff] * DAT_a8076844[a] / 100 <= 0x400) {
        func_0xa0f71528(0xb70803a0);
        v = DAT_a80769d8[func_0xa0f71528(0xb70803a0) & 0x3ff] * DAT_a8076844[a] / 100 * 100 >> 10;
    } else
        v = 100;
    *p = v;
    _DAT_a80785e4 = DAT_a80766b0[0] * 100 / DAT_a80766b0[_DAT_a8078c3c];
    _DAT_a8078c40 = _DAT_a80783dc * _DAT_a80785e4 / 100;
    FUN_a00d3704(_DAT_a8078c40, 1);
}
