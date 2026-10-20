/* leon2m FUN_a015ea68 @ 0xa015ea68  MATCH (-mcpu=v8 -O2 -g)
 * 
 */
extern int (*_DAT_a802cfe0)(int);
extern int FUN_a015ea68(int param_1);

int FUN_a015ea68(int param_1)
{
    int result = 0;
    if (_DAT_a802cfe0 != 0) {
        result = _DAT_a802cfe0(param_1);
    }
    return result;
}
