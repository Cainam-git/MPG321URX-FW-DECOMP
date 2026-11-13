# lib_heap_alloc  (fn_40004210): 0x40004210-0x400042a6 (firmware file offset 0x34210-0x342a6), 68 instructions
# Name basis: derived - code: free-list walk, split from block end; no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
#
# Takes a block from the free list of the pool set up by lib_heap_init (first fit). The size is rounded up to a
# multiple of 8. A free block with at most 31 bytes to spare is taken whole and unlinked; a larger one is shrunk
# and the new block is cut from its end, with its size stored in its header.
# Arguments: a2 size (bytes wanted).
# Locals: a1+0 need (size rounded up to 8), a1+4 prev (block before blk in the list), a1+8 blk (block being
#   looked at), a1+12 spare (blk->size - need), a1+16 result.
# Returns: address of the usable bytes (block header + 8), or 0 when the heap is not ready or no block is large
#   enough.
# Note: nothing calls it and no word holds its address.
# Other literal values: 0x3ffe4220

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	lib_heap_alloc, @function
lib_heap_alloc:                         # fn_40004210
	entry	a1, 80                  # 40004210
	s32i.n	a2, a1, 32              # 40004213
	# if (heap.ready == 0) { result = 0; goto out; }
	movi.n	a5, 0                   # 40004215
	l32r	a4, lit_3ffe1d34        # 40004217  = 0x3ffe4220
	l8ui	a4, a4, 0               # 4000421a
	bne	a4, a5, .L40004227      # 4000421d
	movi.n	a5, 0                   # 40004220
	s32i.n	a5, a1, 16              # 40004222
	j	.L400042a3              # 40004224
.L40004227:
	# need = (size + 7) & ~7; prev = heap.head
	movi.n	a8, -8                  # 40004227
	l32i.n	a7, a1, 32              # 40004229
	addi.n	a7, a7, 7               # 4000422b
	and	a7, a7, a8              # 4000422d
	s32i.n	a7, a1, 0               # 40004230
	l32r	a6, lit_3ffe1d34        # 40004232  = 0x3ffe4220
	l32i.n	a6, a6, 4               # 40004235
	s32i.n	a6, a1, 4               # 40004237
.L40004239:
	# for (;;) { blk = prev->next
	l32i.n	a10, a1, 4              # 40004239
	l32i.n	a10, a10, 0             # 4000423b
	s32i.n	a10, a1, 8              # 4000423d
	# if (blk == 0) { result = 0; goto out; }
	movi.n	a9, 0                   # 4000423f
	l32i.n	a8, a1, 8               # 40004241
	bne	a8, a9, .L4000424d      # 40004243
	movi.n	a11, 0                  # 40004246
	s32i.n	a11, a1, 16             # 40004248
	j	.L400042a3              # 4000424a
.L4000424d:
	# if (blk->size < need) { prev = blk; continue; }
	l32i.n	a13, a1, 0              # 4000424d
	l32i.n	a12, a1, 8              # 4000424f
	l32i.n	a12, a12, 4             # 40004251
	bgeu	a12, a13, .L4000425d    # 40004253
	l32i.n	a13, a1, 8              # 40004256
	s32i.n	a13, a1, 4              # 40004258
	j	.L40004239              # 4000425a
.L4000425d:
	# spare = blk->size - need
	l32i.n	a3, a1, 0               # 4000425d
	l32i.n	a2, a1, 8               # 4000425f
	l32i.n	a2, a2, 4               # 40004261
	sub	a2, a2, a3              # 40004263
	s32i.n	a2, a1, 12              # 40004266
	# if (spare <= 31) { prev->next = blk->next; result = blk + 8; goto out; }
	l32i.n	a15, a1, 12             # 40004268
	movi.n	a14, 31                 # 4000426a
	bltu	a14, a15, .L40004280    # 4000426c
	l32i.n	a5, a1, 4               # 4000426f
	l32i.n	a4, a1, 8               # 40004271
	l32i.n	a4, a4, 0               # 40004273
	s32i.n	a4, a5, 0               # 40004275
	l32i.n	a3, a1, 8               # 40004277
	addi.n	a3, a3, 8               # 40004279
	s32i.n	a3, a1, 16              # 4000427b
	j	.L400042a3              # 4000427d
.L40004280:
	# spare -= 8; blk->size = spare
	l32i.n	a12, a1, 12             # 40004280
	addi	a12, a12, -8            # 40004282
	s32i.n	a12, a1, 12             # 40004285
	l32i.n	a11, a1, 8              # 40004287
	l32i.n	a10, a1, 12             # 40004289
	s32i.n	a10, a11, 4             # 4000428b
	# prev = blk + spare + 8   /* the new block at the end of blk */
	l32i.n	a9, a1, 12              # 4000428d
	l32i.n	a8, a1, 8               # 4000428f
	add.n	a8, a8, a9              # 40004291
	addi.n	a8, a8, 8               # 40004293
	s32i.n	a8, a1, 4               # 40004295
	# prev->size = need; result = prev + 8 }
	l32i.n	a7, a1, 4               # 40004297
	l32i.n	a6, a1, 0               # 40004299
	s32i.n	a6, a7, 4               # 4000429b
	l32i.n	a5, a1, 4               # 4000429d
	addi.n	a5, a5, 8               # 4000429f
	s32i.n	a5, a1, 16              # 400042a1
.L400042a3:
	# out: return result
	l32i.n	a2, a1, 16              # 400042a3
	retw.n                          # 400042a5
	.size	lib_heap_alloc, . - lib_heap_alloc
