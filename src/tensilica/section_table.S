# section_table: 0x4000ac38-0x4000acf7 (firmware file offset 0x3ac38-0x3acf7)
# 16 records of three words: RAM start, RAM end, flash source. The reset code (reset_40000400)
# reads it from lit_4000041c and copies each record's source to RAM start..RAM end; a record
# with RAM start, RAM end and source all 0 ends the table. Three records have data: read-only
# data, the literal words of the program code and the initialised data.

	.balign	4, 0                    # 3 zero bytes after the last function
section_table:
	.word	0x3ffc0000, 0x3ffc0000, rodata_start # 4000ac38
	.word	0x3ffc0000, 0x3ffc0000, rodata_start # 4000ac44
	.word	0x3ffc0000, 0x3ffc0000, rodata_start # 4000ac50
	.word	0x3ffe0000, 0x3ffe0000, rodata_start # 4000ac5c
	.word	RODATA_RAM, RODATA_RAM + (rodata_end - rodata_start), rodata_start # 4000ac68
	.word	0x3ffe1a70, 0x3ffe1a70, literals_start # 4000ac74
	.word	LITERALS_RAM, LITERALS_RAM + (literals_end - literals_start), literals_start # 4000ac80
	.word	0x3ffe238c, 0x3ffe238c, literals_end # 4000ac8c
	.word	DATA_RAM, DATA_RAM + (data_end - data_start), data_start # 4000ac98
	.word	0x3ffef000, 0x3ffef000, image_end # 4000aca4
	.word	0x3ffef000, 0x3ffef000, image_end # 4000acb0
	.word	0x3ffef000, 0x3ffef000, image_end # 4000acbc
	.word	0x60000000, 0x60000000, image_end # 4000acc8
	.word	0x60000000, 0x60000000, image_end # 4000acd4
	.word	0x60000000, 0x60000000, image_end # 4000ace0
	.word	0, 0, 0                 # 4000acec
