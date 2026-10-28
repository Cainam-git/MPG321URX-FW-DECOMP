# fn_400086a4: 0x400086a4-0x400089e6 (firmware file offset 0x386a4-0x389e6), 303 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_40008300, fn_400099bc
# Text loaded: "[ERR] gpio_set_input: gpio index out of range (%bu)\n"
# Addresses loaded: ro_3ffe1410
# Other literal values: 0x000014e0, 0x000014f4, 0x000014f8, 0x000014f0, 0x000014e8, 0x000014e4, 0x000014fc

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400086a4, @function
fn_400086a4:
	entry	a1, 64                  # 400086a4
	s32i.n	a2, a1, 16              # 400086a7
	l32i.n	a10, a1, 16             # 400086a9
	call8	fn_40008300             # 400086ab
	l32i.n	a12, a1, 16             # 400086ae
	s32i.n	a12, a1, 0              # 400086b0
	l32i.n	a11, a1, 0              # 400086b2
	s32i.n	a11, a1, 4              # 400086b4
	bltui	a11, 32, .L400086bc     # 400086b6
	j	.L400089da              # 400086b9
.L400086bc:
	l32r	a14, lit_3ffe21ec       # 400086bc  = ro_3ffe1410
	l32i.n	a13, a1, 4              # 400086bf
	addx4	a13, a13, a14           # 400086c1
	l32i.n	a13, a13, 0             # 400086c4
	jx	a13                     # 400086c6
.L400086c9:
	l32r	a2, lit_3ffe21f0        # 400086c9  = 0x000014e0
	movi	a3, 247                 # 400086cc
	l32r	a15, lit_3ffe21f0       # 400086cf  = 0x000014e0
	memw                            # 400086d2
	l32i.n	a15, a15, 0             # 400086d5
	and	a15, a15, a3            # 400086d7
	memw                            # 400086da
	s32i.n	a15, a2, 0              # 400086dd
	j	.L400089e5              # 400086df
.L400086e2:
	l32r	a3, lit_3ffe21f4        # 400086e2  = 0x000014f4
	movi	a4, 223                 # 400086e5
	l32r	a2, lit_3ffe21f4        # 400086e8  = 0x000014f4
	memw                            # 400086eb
	l32i.n	a2, a2, 0               # 400086ee
	and	a2, a2, a4              # 400086f0
	memw                            # 400086f3
	s32i.n	a2, a3, 0               # 400086f6
	j	.L400089e5              # 400086f8
.L400086fb:
	l32r	a4, lit_3ffe21f4        # 400086fb  = 0x000014f4
	movi	a5, 239                 # 400086fe
	l32r	a3, lit_3ffe21f4        # 40008701  = 0x000014f4
	memw                            # 40008704
	l32i.n	a3, a3, 0               # 40008707
	and	a3, a3, a5              # 40008709
	memw                            # 4000870c
	s32i.n	a3, a4, 0               # 4000870f
	j	.L400089e5              # 40008711
.L40008714:
	l32r	a5, lit_3ffe21f4        # 40008714  = 0x000014f4
	movi	a6, 247                 # 40008717
	l32r	a4, lit_3ffe21f4        # 4000871a  = 0x000014f4
	memw                            # 4000871d
	l32i.n	a4, a4, 0               # 40008720
	and	a4, a4, a6              # 40008722
	memw                            # 40008725
	s32i.n	a4, a5, 0               # 40008728
	j	.L400089e5              # 4000872a
.L4000872d:
	l32r	a6, lit_3ffe21f4        # 4000872d  = 0x000014f4
	movi	a7, 251                 # 40008730
	l32r	a5, lit_3ffe21f4        # 40008733  = 0x000014f4
	memw                            # 40008736
	l32i.n	a5, a5, 0               # 40008739
	and	a5, a5, a7              # 4000873b
	memw                            # 4000873e
	s32i.n	a5, a6, 0               # 40008741
	j	.L400089e5              # 40008743
.L40008746:
	l32r	a7, lit_3ffe21f4        # 40008746  = 0x000014f4
	movi	a8, 253                 # 40008749
	l32r	a6, lit_3ffe21f4        # 4000874c  = 0x000014f4
	memw                            # 4000874f
	l32i.n	a6, a6, 0               # 40008752
	and	a6, a6, a8              # 40008754
	memw                            # 40008757
	s32i.n	a6, a7, 0               # 4000875a
	j	.L400089e5              # 4000875c
.L4000875f:
	l32r	a8, lit_3ffe21f4        # 4000875f  = 0x000014f4
	movi	a9, 254                 # 40008762
	l32r	a7, lit_3ffe21f4        # 40008765  = 0x000014f4
	memw                            # 40008768
	l32i.n	a7, a7, 0               # 4000876b
	and	a7, a7, a9              # 4000876d
	memw                            # 40008770
	s32i.n	a7, a8, 0               # 40008773
	j	.L400089e5              # 40008775
.L40008778:
	l32r	a9, lit_3ffe21f8        # 40008778  = 0x000014f8
	l32r	a8, lit_3ffe21f8        # 4000877b  = 0x000014f8
	memw                            # 4000877e
	l32i.n	a8, a8, 0               # 40008781
	extui	a8, a8, 0, 7            # 40008783
	memw                            # 40008786
	s32i.n	a8, a9, 0               # 40008789
	j	.L400089e5              # 4000878b
.L4000878e:
	l32r	a10, lit_3ffe21f8       # 4000878e  = 0x000014f8
	movi	a11, 191                # 40008791
	l32r	a9, lit_3ffe21f8        # 40008794  = 0x000014f8
	memw                            # 40008797
	l32i.n	a9, a9, 0               # 4000879a
	and	a9, a9, a11             # 4000879c
	memw                            # 4000879f
	s32i.n	a9, a10, 0              # 400087a2
	j	.L400089e5              # 400087a4
.L400087a7:
	l32r	a11, lit_3ffe21fc       # 400087a7  = 0x000014f0
	movi	a12, 251                # 400087aa
	l32r	a10, lit_3ffe21fc       # 400087ad  = 0x000014f0
	memw                            # 400087b0
	l32i.n	a10, a10, 0             # 400087b3
	and	a10, a10, a12           # 400087b5
	memw                            # 400087b8
	s32i.n	a10, a11, 0             # 400087bb
	j	.L400089e5              # 400087bd
.L400087c0:
	l32r	a12, lit_3ffe21fc       # 400087c0  = 0x000014f0
	movi	a13, 253                # 400087c3
	l32r	a11, lit_3ffe21fc       # 400087c6  = 0x000014f0
	memw                            # 400087c9
	l32i.n	a11, a11, 0             # 400087cc
	and	a11, a11, a13           # 400087ce
	memw                            # 400087d1
	s32i.n	a11, a12, 0             # 400087d4
	j	.L400089e5              # 400087d6
.L400087d9:
	l32r	a13, lit_3ffe21fc       # 400087d9  = 0x000014f0
	movi	a14, 254                # 400087dc
	l32r	a12, lit_3ffe21fc       # 400087df  = 0x000014f0
	memw                            # 400087e2
	l32i.n	a12, a12, 0             # 400087e5
	and	a12, a12, a14           # 400087e7
	memw                            # 400087ea
	s32i.n	a12, a13, 0             # 400087ed
	j	.L400089e5              # 400087ef
.L400087f2:
	l32r	a14, lit_3ffe21f4       # 400087f2  = 0x000014f4
	l32r	a13, lit_3ffe21f4       # 400087f5  = 0x000014f4
	memw                            # 400087f8
	l32i.n	a13, a13, 0             # 400087fb
	extui	a13, a13, 0, 7          # 400087fd
	memw                            # 40008800
	s32i.n	a13, a14, 0             # 40008803
	j	.L400089e5              # 40008805
.L40008808:
	l32r	a15, lit_3ffe21f4       # 40008808  = 0x000014f4
	movi	a2, 191                 # 4000880b
	l32r	a14, lit_3ffe21f4       # 4000880e  = 0x000014f4
	memw                            # 40008811
	l32i.n	a14, a14, 0             # 40008814
	and	a14, a14, a2            # 40008816
	memw                            # 40008819
	s32i.n	a14, a15, 0             # 4000881c
	j	.L400089e5              # 4000881e
.L40008821:
	l32r	a2, lit_3ffe2200        # 40008821  = 0x000014e8
	l32r	a15, lit_3ffe2200       # 40008824  = 0x000014e8
	memw                            # 40008827
	l32i.n	a15, a15, 0             # 4000882a
	extui	a15, a15, 0, 7          # 4000882c
	memw                            # 4000882f
	s32i.n	a15, a2, 0              # 40008832
	j	.L400089e5              # 40008834
.L40008837:
	l32r	a3, lit_3ffe2200        # 40008837  = 0x000014e8
	movi	a4, 191                 # 4000883a
	l32r	a2, lit_3ffe2200        # 4000883d  = 0x000014e8
	memw                            # 40008840
	l32i.n	a2, a2, 0               # 40008843
	and	a2, a2, a4              # 40008845
	memw                            # 40008848
	s32i.n	a2, a3, 0               # 4000884b
	j	.L400089e5              # 4000884d
.L40008850:
	l32r	a4, lit_3ffe2200        # 40008850  = 0x000014e8
	movi	a5, 223                 # 40008853
	l32r	a3, lit_3ffe2200        # 40008856  = 0x000014e8
	memw                            # 40008859
	l32i.n	a3, a3, 0               # 4000885c
	and	a3, a3, a5              # 4000885e
	memw                            # 40008861
	s32i.n	a3, a4, 0               # 40008864
	j	.L400089e5              # 40008866
.L40008869:
	l32r	a5, lit_3ffe21f0        # 40008869  = 0x000014e0
	l32r	a4, lit_3ffe21f0        # 4000886c  = 0x000014e0
	memw                            # 4000886f
	l32i.n	a4, a4, 0               # 40008872
	extui	a4, a4, 0, 7            # 40008874
	memw                            # 40008877
	s32i.n	a4, a5, 0               # 4000887a
	j	.L400089e5              # 4000887c
.L4000887f:
	l32r	a6, lit_3ffe21f0        # 4000887f  = 0x000014e0
	movi	a7, 253                 # 40008882
	l32r	a5, lit_3ffe21f0        # 40008885  = 0x000014e0
	memw                            # 40008888
	l32i.n	a5, a5, 0               # 4000888b
	and	a5, a5, a7              # 4000888d
	memw                            # 40008890
	s32i.n	a5, a6, 0               # 40008893
	j	.L400089e5              # 40008895
.L40008898:
	l32r	a7, lit_3ffe21f0        # 40008898  = 0x000014e0
	movi	a8, 254                 # 4000889b
	l32r	a6, lit_3ffe21f0        # 4000889e  = 0x000014e0
	memw                            # 400088a1
	l32i.n	a6, a6, 0               # 400088a4
	and	a6, a6, a8              # 400088a6
	memw                            # 400088a9
	s32i.n	a6, a7, 0               # 400088ac
	j	.L400089e5              # 400088ae
.L400088b1:
	l32r	a8, lit_3ffe2204        # 400088b1  = 0x000014e4
	movi	a9, 247                 # 400088b4
	l32r	a7, lit_3ffe2204        # 400088b7  = 0x000014e4
	memw                            # 400088ba
	l32i.n	a7, a7, 0               # 400088bd
	and	a7, a7, a9              # 400088bf
	memw                            # 400088c2
	s32i.n	a7, a8, 0               # 400088c5
	j	.L400089e5              # 400088c7
.L400088ca:
	l32r	a9, lit_3ffe2204        # 400088ca  = 0x000014e4
	l32r	a8, lit_3ffe2204        # 400088cd  = 0x000014e4
	memw                            # 400088d0
	l32i.n	a8, a8, 0               # 400088d3
	extui	a8, a8, 0, 7            # 400088d5
	memw                            # 400088d8
	s32i.n	a8, a9, 0               # 400088db
	j	.L400089e5              # 400088dd
.L400088e0:
	l32r	a10, lit_3ffe2204       # 400088e0  = 0x000014e4
	movi	a11, 223                # 400088e3
	l32r	a9, lit_3ffe2204        # 400088e6  = 0x000014e4
	memw                            # 400088e9
	l32i.n	a9, a9, 0               # 400088ec
	and	a9, a9, a11             # 400088ee
	memw                            # 400088f1
	s32i.n	a9, a10, 0              # 400088f4
	j	.L400089e5              # 400088f6
.L400088f9:
	l32r	a11, lit_3ffe2204       # 400088f9  = 0x000014e4
	movi	a12, 239                # 400088fc
	l32r	a10, lit_3ffe2204       # 400088ff  = 0x000014e4
	memw                            # 40008902
	l32i.n	a10, a10, 0             # 40008905
	and	a10, a10, a12           # 40008907
	memw                            # 4000890a
	s32i.n	a10, a11, 0             # 4000890d
	j	.L400089e5              # 4000890f
.L40008912:
	l32r	a12, lit_3ffe2204       # 40008912  = 0x000014e4
	movi	a13, 251                # 40008915
	l32r	a11, lit_3ffe2204       # 40008918  = 0x000014e4
	memw                            # 4000891b
	l32i.n	a11, a11, 0             # 4000891e
	and	a11, a11, a13           # 40008920
	memw                            # 40008923
	s32i.n	a11, a12, 0             # 40008926
	j	.L400089e5              # 40008928
.L4000892b:
	l32r	a13, lit_3ffe21f0       # 4000892b  = 0x000014e0
	movi	a14, 251                # 4000892e
	l32r	a12, lit_3ffe21f0       # 40008931  = 0x000014e0
	memw                            # 40008934
	l32i.n	a12, a12, 0             # 40008937
	and	a12, a12, a14           # 40008939
	memw                            # 4000893c
	s32i.n	a12, a13, 0             # 4000893f
	j	.L400089e5              # 40008941
.L40008944:
	l32r	a14, lit_3ffe2208       # 40008944  = 0x000014fc
	movi	a15, 247                # 40008947
	l32r	a13, lit_3ffe2208       # 4000894a  = 0x000014fc
	memw                            # 4000894d
	l32i.n	a13, a13, 0             # 40008950
	and	a13, a13, a15           # 40008952
	memw                            # 40008955
	s32i.n	a13, a14, 0             # 40008958
	j	.L400089e5              # 4000895a
.L4000895d:
	l32r	a15, lit_3ffe2208       # 4000895d  = 0x000014fc
	movi	a2, 251                 # 40008960
	l32r	a14, lit_3ffe2208       # 40008963  = 0x000014fc
	memw                            # 40008966
	l32i.n	a14, a14, 0             # 40008969
	and	a14, a14, a2            # 4000896b
	memw                            # 4000896e
	s32i.n	a14, a15, 0             # 40008971
	j	.L400089e5              # 40008973
.L40008976:
	l32r	a2, lit_3ffe2208        # 40008976  = 0x000014fc
	movi	a3, 254                 # 40008979
	l32r	a15, lit_3ffe2208       # 4000897c  = 0x000014fc
	memw                            # 4000897f
	l32i.n	a15, a15, 0             # 40008982
	and	a15, a15, a3            # 40008984
	memw                            # 40008987
	s32i.n	a15, a2, 0              # 4000898a
	j	.L400089e5              # 4000898c
.L4000898f:
	l32r	a3, lit_3ffe2208        # 4000898f  = 0x000014fc
	movi	a4, 253                 # 40008992
	l32r	a2, lit_3ffe2208        # 40008995  = 0x000014fc
	memw                            # 40008998
	l32i.n	a2, a2, 0               # 4000899b
	and	a2, a2, a4              # 4000899d
	memw                            # 400089a0
	s32i.n	a2, a3, 0               # 400089a3
	j	.L400089e5              # 400089a5
.L400089a8:
	l32r	a4, lit_3ffe2208        # 400089a8  = 0x000014fc
	movi	a5, 239                 # 400089ab
	l32r	a3, lit_3ffe2208        # 400089ae  = 0x000014fc
	memw                            # 400089b1
	l32i.n	a3, a3, 0               # 400089b4
	and	a3, a3, a5              # 400089b6
	memw                            # 400089b9
	s32i.n	a3, a4, 0               # 400089bc
	j	.L400089e5              # 400089be
.L400089c1:
	l32r	a5, lit_3ffe2208        # 400089c1  = 0x000014fc
	movi	a6, 223                 # 400089c4
	l32r	a4, lit_3ffe2208        # 400089c7  = 0x000014fc
	memw                            # 400089ca
	l32i.n	a4, a4, 0               # 400089cd
	and	a4, a4, a6              # 400089cf
	memw                            # 400089d2
	s32i.n	a4, a5, 0               # 400089d5
	j	.L400089e5              # 400089d7
.L400089da:
	l32r	a10, lit_3ffe220c       # 400089da  = ro_3ffe13d0 "[ERR] gpio_set_input: gpio index out of range (%bu)\n"
	l32i.n	a11, a1, 16             # 400089dd
	call8	fn_400099bc             # 400089df
	j	.L400089e5              # 400089e2
.L400089e5:
	retw.n                          # 400089e5
	.size	fn_400086a4, . - fn_400086a4
