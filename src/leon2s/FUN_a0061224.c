/* FUN_a0061224 (leon2s 0xa0061224-0xa006122c, 8 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Endless loop ('b .'). Its address is the word at 0xa00b6080 and is also loaded by FUN_a0060350.
 * Source form: 'for (;;) ;' compiles to 'b .' with a nop in the delay slot; with -g no return code follows.
 */
void FUN_a0061224(void)
{
    for (;;)
        ;
}
