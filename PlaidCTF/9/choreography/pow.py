import sys
import string
import random
import hashlib

# gets 10 random letters & numbers
prefix = ''.join(random.choice(string.ascii_letters + string.digits) for i in range(10))

print("Give me a string starting with {} of length {} so its sha256sum ends in ffffff.".format(prefix, len(prefix)+8))

l = input().strip()

# we're trying to mine bitcoin (hash collisions)
hashed = hashlib.sha256(l.encode('ascii')).hexdigest()
print(hashed)

if len(l) != len(prefix)+8 or not l.startswith(prefix) or hashed[-6:] != "ffffff":
    print("Nope.")
    sys.exit(1)

