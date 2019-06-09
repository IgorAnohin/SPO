native 'and', and
  pop rdx
  pop rax
  and rax, rdx
  push rax
  jmp next

native 'or', or
  pop rax
  or [rsp], rax
  jmp next


native 'not', not
  pop rax
  test rax, rax
  jz .setone
  xor rax, rax
  push rax
  jmp next
  .setone:
    xor rax, rax
    mov rax, 1
    push rax
    jmp next

native 'lor', lor
  pop rax
  pop rdx
  test rax, rax
  jnz .yes
  push rdx
  jmp next
  .yes:
    push rax
    jmp next

native "land", land
  pop rax
  pop rdx
  test rax, rax
  jz .no
  push rdx
  jmp next
  .no:
    push rax
    jmp next

native '=', equals
  pop rdx
  pop rax
  cmp rax, rdx
  jne .nequals
  xor rax, rax
  mov rax, 1
  push rax
  jmp next
  .nequals:
  xor rax, rax
  push rax
  jmp next
