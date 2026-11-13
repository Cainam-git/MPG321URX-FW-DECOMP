# sys_set_region_attributes  (fn_4000a890): 0x4000a890-0x4000a990 (firmware file offset 0x3a890-0x3a990), 94 instructions
# Name basis: derived - code: nibble per address>>29, read/write via RDTLB1/WITLB/WDTLB helpers; flags
#   0x100/0x200/0x400/0x1000
# Called from: sys_set_all_regions_attribute_2
# Sets the 4-bit attribute of every 512 MB address region (region = address >> 29) that the range start ..
# start + size - 1 touches: it reads the eight attributes (sys_read_region_attributes), replaces the nibbles of
# the regions in range and writes them back (sys_write_region_attributes). Attribute 1, 4 or 5 is stored as 2.
# Flag bits: 0x200 = range must start and end on region boundaries (else -2); 0x400 = only the regions the
# range covers completely; 0x100 = keep the current attribute where its rank in sys_region_attribute_rank is higher;
# 0x1000 = skip the two empty calls sys_empty_after_tlb_write_a / sys_empty_after_tlb_write_b that follow when a region changed to attribute
# 2 or 6 from another value. Its only caller, sys_set_all_regions_attribute_2, has no caller itself.
# a2 = start: first address. a3 = size: bytes. a4 = attr: new attribute (low 4 bits). a5 = flags.
# No stack locals (register code). Registers: a10 attrs (8 nibbles, region k in bits 4k..4k+3), a6 first
#   region, a3 last region, then changed flag.
# Returns: 0 = done (also for size 0), -1 = no region completely inside (flag 0x400), -2 = not on region
#   boundaries (flag 0x200), -3 = range runs past 0xFFFFFFFF.
# Calls: sys_read_region_attributes, sys_write_region_attributes, sys_empty_after_tlb_write_a,
#        sys_empty_after_tlb_write_b
# Addresses loaded: sys_region_attribute_rank
# Other literal values: 0x1fffffff

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	sys_set_region_attributes, @function
sys_set_region_attributes:              # fn_4000a890
	entry	a1, 32                  # 4000a890
	# if (size == 0) return 0;
	mov.n	a10, a2                 # 4000a893
	beqz	a3, .L4000a984          # 4000a895
	# end = start + size; last = end - 1; if (last < start) return -3;
	add.n	a12, a2, a3             # 4000a898
	addi.n	a11, a12, -1            # 4000a89a
	bgeu	a11, a2, .L4000a8a2     # 4000a89c
	j	.L4000a980              # 4000a89f
.L4000a8a2:
	# first = start >> 29; result = -1; if (end + 1 == 0) last = 0xFFFFFFFF; last_region = last >> 29;
	extui	a6, a10, 29, 3          # 4000a8a2
	extui	a8, a5, 9, 1            # 4000a8a5
	addi.n	a9, a12, 1              # 4000a8a8
	movi	a2, -1                  # 4000a8aa
	l32r	a12, lit_3ffe237c       # 4000a8ad  = 0x1fffffff
	moveqz	a11, a2, a9             # 4000a8b0
	extui	a3, a11, 29, 3          # 4000a8b3
	# if (flags & 0x200) {
	beqz	a8, .L4000a960          # 4000a8b6
	#   if (start & 0x1FFFFFFF) return -2;
	bnone	a10, a12, .L4000a8bf    # 4000a8b9
	j	.L4000a988              # 4000a8bc
.L4000a8bf:
	#   if ((last + 1) & 0x1FFFFFFF) return -2; }
	addi	a10, a11, 1             # 4000a8bf
	bnone	a12, a10, .L4000a8c8    # 4000a8c2
	j	.L4000a988              # 4000a8c5
.L4000a8c8:
	# attrs = sys_read_region_attributes();
	call8	sys_read_region_attributes # 4000a8c8
	# attr &= 15; if (attr == 1 || attr == 4 || attr == 5) attr = 2;
	movi.n	a12, 15                 # 4000a8cb
	extui	a4, a4, 0, 4            # 4000a8cd
	beqi	a4, 1, .L4000a8d9       # 4000a8d0
	beqi	a4, 4, .L4000a8d9       # 4000a8d3
	bnei	a4, 5, .L4000a8db       # 4000a8d6
.L4000a8d9:
	movi.n	a4, 2                   # 4000a8d9
.L4000a8db:
	# if (last_region < first) { changed = 0; goto write; }
	bgeu	a3, a6, .L4000a8e1      # 4000a8db
	j	.L4000a98c              # 4000a8de
.L4000a8e1:
	# keep = flags & 0x100; changed = 0;
	l32r	a15, lit_3ffe2380       # 4000a8e1  = sys_region_attribute_rank
	sub	a11, a3, a6             # 4000a8e4
	movi	a14, 0x100              # 4000a8e7
	and	a14, a5, a14            # 4000a8ea
	movi.n	a3, 0                   # 4000a8ed
	# for (n = last_region - first + 1; n != 0; n--) {
	addi.n	a11, a11, 1             # 4000a8ef
	loopnez	a11, .L4000a934         # 4000a8f1
	#   a = attr; shift = first * 4;
	mov.n	a9, a4                  # 4000a8f4
	slli	a11, a6, 2              # 4000a8f6
	#   if (keep) { cur = (attrs >> shift) & 15; if (rank[attr] < rank[cur]) a = cur; }   (rank = sys_region_attribute_rank, signed bytes)
	beqz.n	a14, .L4000a91a         # 4000a8f9
	ssr	a11                     # 4000a8fb
	add.n	a7, a4, a15             # 4000a8fe
	l8ui	a7, a7, 0               # 4000a900
	srl	a13, a10                # 4000a903
	extui	a13, a13, 0, 4          # 4000a906
	add.n	a8, a13, a15            # 4000a909
	l8ui	a8, a8, 0               # 4000a90b
	sext	a7, a7, 7               # 4000a90e
	sext	a8, a8, 7               # 4000a911
	sub	a7, a7, a8              # 4000a914
	movltz	a9, a13, a7             # 4000a917
.L4000a91a:
	#   first++;
	addi.n	a6, a6, 1               # 4000a91a
	#   if (a == 2 || a == 6) goto check;
	beqi	a9, 2, .L4000a948       # 4000a91c
	beqi	a9, 6, .L4000a948       # 4000a91f
.L4000a922:
	#   attrs = (attrs & ~(15 << shift)) | (a << shift);
	ssl	a11                     # 4000a922
	sll	a13, a9                 # 4000a925
	sll	a8, a12                 # 4000a928
	xor	a8, a8, a2              # 4000a92b
	and	a10, a10, a8            # 4000a92e
	or	a10, a10, a13           # 4000a931
.L4000a934:
	# }
	# write: sys_write_region_attributes(attrs);
	call8	sys_write_region_attributes # 4000a934
	# if (changed == 0 || (flags & 0x1000)) return 0;
	beqz	a3, .L4000a984          # 4000a937
	bbsi	a5, 12, .L4000a984      # 4000a93a
	# sys_empty_after_tlb_write_a(); sys_empty_after_tlb_write_b(); return 0;   (both empty)
	call8	sys_empty_after_tlb_write_a # 4000a93d
	call8	sys_empty_after_tlb_write_b # 4000a940
	movi	a2, 0                   # 4000a943
	retw.n                          # 4000a946
.L4000a948:
	# check: cur = (attrs >> shift) & 15; if (cur != 2 && cur != 6) changed = 1; go back to the store;
	ssr	a11                     # 4000a948
	srl	a13, a10                # 4000a94b
	extui	a13, a13, 0, 4          # 4000a94e
	beqi	a13, 2, .L4000a922      # 4000a951
	addi	a13, a13, -6            # 4000a954
	movi.n	a8, 1                   # 4000a957
	movnez	a3, a8, a13             # 4000a959
	j	.L4000a922              # 4000a95c
	.balign	4, 0                    # 1 zero byte up to the 4-byte boundary 0x4000a960
.L4000a960:
	# else if (flags & 0x400) {
	extui	a9, a5, 10, 1           # 4000a960
	beqz	a9, .L4000a8c8          # 4000a963
	#   if (start & 0x1FFFFFFF) first++; if ((last + 1) & 0x1FFFFFFF) last_region--;
	addi.n	a13, a3, -1             # 4000a966
	and	a8, a10, a12            # 4000a968
	addi.n	a15, a6, 1              # 4000a96b
	addi.n	a14, a11, 1             # 4000a96d
	and	a14, a14, a12           # 4000a96f
	movnez	a6, a15, a8             # 4000a972
	movnez	a3, a13, a14            # 4000a975
	#   if (last_region < first) return -1; }
	bltu	a3, a6, .L4000a97e      # 4000a978
	j	.L4000a8c8              # 4000a97b
.L4000a97e:
	retw.n                          # 4000a97e
.L4000a980:
	# return -3;
	movi.n	a2, -3                  # 4000a980
	retw.n                          # 4000a982
.L4000a984:
	# return 0;
	movi.n	a2, 0                   # 4000a984
	retw.n                          # 4000a986
.L4000a988:
	# return -2;
	movi.n	a2, -2                  # 4000a988
	retw.n                          # 4000a98a
.L4000a98c:
	# changed = 0; goto write;
	movi.n	a3, 0                   # 4000a98c
	j	.L4000a934              # 4000a98e
	.size	sys_set_region_attributes, . - sys_set_region_attributes
