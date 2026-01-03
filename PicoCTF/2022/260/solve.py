import os
import string

for x in string.printable:
    print "Testing:" + x
    os.system("python -c 'print \"33\\n\"+\"a\"*32+\""+x+"\"' | ./vuln | grep -B 5 -A 3 OK")
