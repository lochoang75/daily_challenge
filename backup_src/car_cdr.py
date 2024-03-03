def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

def get_first(data0: int, data1: int):
    return data0

def get_last(data0: int, data1: int):
    return data1

def car(pair):
    return pair(get_first)

def cdr(pair):
    return pair(get_last)

if __name__ == "__main__":
    print(car(cons(3, 4)))
    print(cdr(cons(3, 4)))
