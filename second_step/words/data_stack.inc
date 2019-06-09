native 'buf', buf
  push qword user_buf
  jmp next

native 'drop', drop
  add rsp, 8
  jmp next

native 'swap', swap
    pop rdx
    pop rax
    push rdx
    push rax
    jmp next

native 'dup', dup
  push qword [rsp]
  jmp next

native 'rot', rot
  pop rax
  pop rdx
  pop rcx
  push rdx
  push rcx
  push rax
  jmp next

native '.', dot
  pop rdi
  call print_int
  jmp next

native '.S', show_stack
  mov rcx, rsp
  .loop:
    cmp rcx, [stack_start]
    jae next
    mov rdi, [rcx]
    push rcx
    call print_int
    call print_newline
    pop rcx
    add rcx, 8
    jmp .loop

native '!', write
  pop rax
  pop rdx
  mov [rax], rdx
  jmp next

native '@', fetch
  pop rax
  push qword[rax]
  jmp next

native 'c!', write_char
  pop rax
  pop rdx
  mov [rax], dl
  jmp next

native 'c@', fetch_char
  pop rax
  movzx rax, byte [rax]
  push rax
  jmp next

native 'pushmode_addr', pushmode_addr
  xor eax, eax
  mov rax, mode
  push rax
  jmp next

native 'isimmediate', isimmediate
  pop rax
  push rax
  xor rdx, rdx
  mov dl, byte[rax - 1]
  push rdx
  jmp next

native 'initcmd', initcmd
  pop rax
  push pc
  mov [program_stub], rax
  mov pc, program_stub
  mov w, [pc]
  pop pc
  jmp [w]
