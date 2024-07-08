def Test(init_n):
    n = init_n

    def get_n():
        nonlocal n
        return n

    def set_n(new_n):
        nonlocal n
        n = new_n

    return {'get_n':get_n, 'set_n': set_n}

D = Test(100)
print(D['get_n']())
D['set_n'](200)
print(D['get_n']())
    
#------------------------------------------------

