/* ipc_copy_words_bytewise  (FUN_a0134834)
 *
 * Copy a buffer in groups of four bytes, storing each byte on its own.
 * Name basis: descriptive - length rounded up to a multiple of 4; unused
 *
 * Matching notes
 * --------------
 * FUN_a0134834, flags -mcpu=v8 -O3 -g. Source form: the Ghidra shape is kept: the destination bytes are stored one
 * by one from a byte load, a halfword load and two word loads of the same source word (byte 3 and byte 2 come from
 * the word load, byte 1 from the halfword load); the loop counter is held in an unsigned int and its low byte is
 * compared with the group count.
 */


/*
 * Copy length bytes, rounded up to whole groups of four, from src to dst. Each group is stored byte by byte (a
 * byte load, a halfword load and two word loads read the source). Returns dst. No call to this
 * routine is found in the code.
 *   dst, src: addresses of the destination and the source
 *   length:   byte count; (length + 3) / 4, at most 255, groups are copied
 */
int ipc_copy_words_bytewise(int dst,int src, unsigned short length)

{
  unsigned char groups;
  unsigned int done;
  int group_dst;
  unsigned char group;
  int offset;
  
  groups = (length & 0xffff) + 3 >> 2 & 0xff;
  done = 0;
  if (groups != 0) {
    group = 0;
    do {
      offset = group * 4;
      *(unsigned char *)(dst + offset) = *(unsigned char *)(src + offset);
      group_dst = offset + dst;
      *(char *)(group_dst + 1) = (char)*(unsigned short *)(src + offset);
      *(char *)(group_dst + 2) = (char)(*(unsigned int *)(src + offset) >> 8);
      done = done + 1;
      group = done & 0xff;
      *(char *)(group_dst + 3) = (char)*(unsigned int *)(src + offset);
    } while (group < groups);
  }
  return dst;
}
