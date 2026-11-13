/* _cleanup_r  (FUN_a015b5c4)
 *
 * Flush and close all open streams of a reentrancy structure.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015b5c4 @ 0xa015b5c4, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's form is kept. libc_fclose_entry is the object at address 0xfe3ec (file offset 0x2063ec);
 * it is named by its address so that the reference follows when the object moves.
 */
typedef unsigned int undefined4;
extern unsigned char libc_fclose_entry[];
extern int _fwalk();

/*
 * Call _fwalk with the state record reent and the routine at libc_fclose_entry, which _fwalk applies to
 * every open stream of the record.
 */
void _cleanup_r(undefined4 reent)

{
  _fwalk(reent,libc_fclose_entry);
  return;
}