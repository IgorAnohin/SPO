native '+', plus
  pop rdx
  pop rax
  add rax, rdx
  push rax
  jmp next

native '-', minus
  pop rdx
  pop rax
  sub rax, rdx
  push rax
  jmp next

native '*', mul
  pop rdx
  pop rax
  imul rdx
  push rax
  jmp next

native '/', div
  pop rax
  pop rcx
  cqo
  idiv rcx
  push rax
  jmp next

native "%", mod
  pop rcx
  pop rax
  cqo
  idiv rcx
  push rdx
  jmp next

native '<', less
  pop rdx
  pop rax
  cmp rax, rdx
  setl al
  movzx rax, al
  push rax
  jmp next
