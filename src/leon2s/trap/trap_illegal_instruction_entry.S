! trap_illegal_instruction_entry  (FUN_a0060020)
!
! Trap table slot 0x02 (illegal instruction): reads %psr and %tbr and jumps to the handler at 0xa0060720.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2s FUN_a0060020 @ 0xa0060020  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060020
	.type FUN_a0060020, #function
FUN_a0060020:
! Slot of trap type 0x02, illegal_instruction. The trap has already put the PC and nPC of the
! trapped instruction in %l1 and %l2; the slot adds PSR and TBR and jumps on to
! trap_save_crash_state (0xA0060720): it saves every register at 0xA807FF60 and
! calls the crash hook (trap_dump_crash_and_halt: crash report, then halt).
	rd  %psr, %l0                     ! processor state register (PSR) to %l0
	sethi  %hi(0xa0060400), %l4       ! upper bits of the handler address 0xA0060720
	jmp  %l4 + 0x320                  ! jump to 0xA0060720: save registers, crash report
	rd  %tbr, %l3                     ! delay slot, runs before the jump: TBR (holds the trap type) to %l3
	.size FUN_a0060020, .-FUN_a0060020
