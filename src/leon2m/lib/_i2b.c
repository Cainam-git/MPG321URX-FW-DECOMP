/* _i2b  (FUN_a015d048)
 *
 * Make a big number from an integer (number formatting).
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015d048 @ 0xa015d048, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's form is kept.
 */
typedef unsigned int uint, undefined4;
extern int _Balloc();

/*
 * Make a big number holding the single value value.
 *   reent  the C library state record, passed on to _Balloc
 *   value  stored at +0x14 of the new buffer; +0x10 is set to 1
 * Returns the address of the buffer from _Balloc(reent, 1).
 */
uint _i2b(int reent,uint value)

{
  uint buffer;
  
  buffer = _Balloc((uint *)reent,1);
  *(uint *)(buffer + 0x14) = value;
  *(undefined4 *)(buffer + 0x10) = 1;
  return buffer;
}
