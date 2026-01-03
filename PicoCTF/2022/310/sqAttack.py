#!/usr/bin/env python3

from decimal import *

e = 65537
c = 9278173516578431997880064779343178955209041085950649006761882406919480446548484048297746046169398378347003565901396909214767639919525204479182178950973893854214493663094791356431702037759145748094709219752767153964298128180779114221371406719209912843631220869991911883034243218367832866570766467833669949503446032136976624632491421620711890936280110668377532256028533088294598885271864460615079960919404679955451835969410511981264687427878333961897608650541435320684269093732631129457090523414461579612563147320873328024968983867156385188107690835686332964037803362790415052677118392808216696282685130540055268450854
i = 100

while i < 2000:
    # set precision
    getcontext().prec = i

    # calculate cube root with values wrapped in decimal
    # it is then rounded off using Decimal.to_integral_exact()
    cube_root = int((Decimal(c) ** (Decimal(1) / Decimal(e))).to_integral_exact())
    cube_root = 38251710328773353864633064751392504756093
    # remove 0x from start of string
    hex_str = hex(cube_root)[2:]
    dehex = bytes.fromhex(hex_str).decode()
    print(dehex)
    flag = bytes.fromhex(dehex).decode()
    print(flag)
    try:
        dehex = bytes.fromhex(hex_str).decode()
        flag = bytes.fromhex(dehex).decode()
        if flag.startswith('picoCTF{') and flag.endswith('}'):
            print('Precision :', i)
            print('FLAG      :', flag)
            break
    except UnicodeDecodeError:
        pass
    except ValueError:
        pass
    i += 1
