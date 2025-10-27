for i in range(1, 101):
    print(f'{"Moo" if (i%3==0 or i%5==0 or i%15==0) else i}, ', end='')
