# sys_write_region_attributes  (fn_4000a9c0): 0x4000a9c0-0x4000aa60 (firmware file offset 0x3a9c0-0x3aa60), 52 instructions
# Name basis: proven - code: witlb then wdtlb loops; also holds pieces of lib_copy_memory
# Called from: sys_set_region_attributes
# Writes the eight 4-bit region attributes of attrs (region k = address k << 29 in bits 4k..4k+3, the
# layout of sys_read_region_attributes) into the instruction-side TLB entries (WITLB) of regions 0..7 and
# then into the data-side entries (WDTLB). The region that holds this code (that of .L4000a9f4) is written
# from the aligned spot .L4000a9e0 and followed at once by ISYNC.
# The file also holds three pieces of lib_copy_memory, placed before its entry point:
# .L4000aa25 copies the last bytes one at a time, .L4000aa34 aligns the destination by one byte,
# .L4000aa48 aligns it by two bytes; they continue at .L4000aa70 in lib_copy_memory.
# a2 = attrs.
# No stack locals (register code): a3 region address, a7 remaining nibbles.
# Returns: nothing.
# Addresses loaded: .L4000a9f4
# Other literal values: 0xe0000000

	.space	12, 0                   # 12 zero bytes after the previous function, 0x4000a9b4-0x4000a9bf
	.type	sys_write_region_attributes, @function
sys_write_region_attributes:            # fn_4000a9c0
	entry	a1, 16                  # 4000a9c0
	# own = .L4000a9f4 & 0xE0000000; addr = 0; rest = attrs;
	l32r	a5, lit_3ffe2384        # 4000a9c3  = 0xe0000000
	l32r	a6, lit_3ffe2388        # 4000a9c6  = .L4000a9f4
	movi.n	a3, 0                   # 4000a9c9
	mov.n	a7, a2                  # 4000a9cb
	and	a6, a6, a5              # 4000a9cd
	j	.L4000a9f4              # 4000a9d0
	.space	13, 0                   # 13 zero bytes, 0x4000a9d3-0x4000a9df
.L4000a9e0:
	# (region of this code) WITLB(rest & 15, addr); ISYNC; addr += 0x20000000; if (addr wrapped to 0) goto data side;
	witlb	a4, a3                  # 4000a9e0
	isync                           # 4000a9e3
	nop.n                           # 4000a9e6
	nop                             # 4000a9e8
	sub	a3, a3, a5              # 4000a9eb
	bltui	a3, 16, .L4000aa06      # 4000a9ee
.L4000a9f1:
	# rest >>= 4;
	srli	a7, a7, 4               # 4000a9f1
.L4000a9f4:
	# for (each region) { a = rest & 15; if (addr == own) goto .L4000a9e0;
	extui	a4, a7, 0, 4            # 4000a9f4
	beq	a3, a6, .L4000a9e0      # 4000a9f7
	#   WITLB(a, addr); addr += 0x20000000; } until addr wraps to 0;
	witlb	a4, a3                  # 4000a9fa
	sub	a3, a3, a5              # 4000a9fd
	bgeui	a3, 16, .L4000a9f1      # 4000aa00
	# ISYNC;
	isync                           # 4000aa03
.L4000aa06:
	# data side: addr = 0; rest = attrs;
	l32r	a5, lit_3ffe2384        # 4000aa06  = 0xe0000000
	movi.n	a3, 0                   # 4000aa09
	mov.n	a7, a2                  # 4000aa0b
.L4000aa0d:
	# do { WDTLB(rest & 15, addr); addr += 0x20000000; rest >>= 4; } while (addr != 0);
	extui	a4, a7, 0, 4            # 4000aa0d
	wdtlb	a4, a3                  # 4000aa10
	sub	a3, a3, a5              # 4000aa13
	srli	a7, a7, 4               # 4000aa16
	bgeui	a3, 16, .L4000aa0d      # 4000aa19
	# DSYNC; return;
	dsync                           # 4000aa1c
	retw.n                          # 4000aa1f
	.space	4, 0                    # 4 zero bytes, 0x4000aa21-0x4000aa24
.L4000aa25:
	# lib_copy_memory piece: for (; n != 0; n--) *d++ = *s++;   (a5 = d, a3 = s, a4 = n) return;
	loopnez	a4, .L4000aa32          # 4000aa25
	l8ui	a6, a3, 0               # 4000aa28
	addi.n	a3, a3, 1               # 4000aa2b
	s8i	a6, a5, 0               # 4000aa2d
	addi.n	a5, a5, 1               # 4000aa30
.L4000aa32:
	retw.n                          # 4000aa32
.L4000aa34:
	# lib_copy_memory piece (d odd): if (n < 7) copy bytewise; *d++ = *s++; n--;
	bltui	a4, 7, .L4000aa25       # 4000aa34
	l8ui	a6, a3, 0               # 4000aa37
	addi.n	a3, a3, 1               # 4000aa3a
	addi	a4, a4, -1              # 4000aa3c
	s8i	a6, a5, 0               # 4000aa3f
	addi	a5, a5, 1               # 4000aa42
	#   if (!(d & 2)) goto .L4000aa70;
	bbci	a5, 1, .L4000aa70       # 4000aa45
.L4000aa48:
	# lib_copy_memory piece (d & 2): if (n < 6) copy bytewise; copy 2 bytes; n -= 2; goto .L4000aa70;
	bltui	a4, 6, .L4000aa25       # 4000aa48
	l8ui	a6, a3, 0               # 4000aa4b
	l8ui	a7, a3, 1               # 4000aa4e
	addi.n	a3, a3, 2               # 4000aa51
	addi	a4, a4, -2              # 4000aa53
	s8i	a6, a5, 0               # 4000aa56
	s8i	a7, a5, 1               # 4000aa59
	addi.n	a5, a5, 2               # 4000aa5c
	j	.L4000aa70              # 4000aa5e
	.size	sys_write_region_attributes, . - sys_write_region_attributes
