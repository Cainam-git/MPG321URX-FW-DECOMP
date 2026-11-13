# sys_read_region_attributes  (fn_4000a994): 0x4000a994-0x4000a9b3 (firmware file offset 0x3a994-0x3a9b3), 12 instructions
# Name basis: proven - code: rdtlb1 loop over 0xE0000000..0
# Called from: sys_set_region_attributes
# Reads the data-side TLB entry (RDTLB1) of each 512 MB region, from 0xE0000000 down to 0x00000000, and
# packs the low 4 bits of each into one word: region k (address k << 29) in bits 4k..4k+3.
# No arguments, no stack locals.
# Returns: the eight attribute nibbles.
# Other literal values: 0xe0000000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	sys_read_region_attributes, @function
sys_read_region_attributes:             # fn_4000a994
	entry	a1, 16                  # 4000a994
	# attrs = 0; addr = 0;
	l32r	a5, lit_3ffe2384        # 4000a997  = 0xe0000000
	movi.n	a2, 0                   # 4000a99a
	movi.n	a3, 0                   # 4000a99c
.L4000a99e:
	# do { addr -= 0x20000000; attrs = (attrs << 4) | (RDTLB1(addr) & 15); } while (addr >= 16);
	add.n	a3, a3, a5              # 4000a99e
	rdtlb1	a4, a3                  # 4000a9a0
	dsync                           # 4000a9a3
	slli	a2, a2, 4               # 4000a9a6
	extui	a4, a4, 0, 4            # 4000a9a9
	or	a2, a2, a4              # 4000a9ac
	bgeui	a3, 16, .L4000a99e      # 4000a9af
	# return attrs;
	retw.n                          # 4000a9b2
	.size	sys_read_region_attributes, . - sys_read_region_attributes
