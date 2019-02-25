def sum(a, b):
    return a + b

def substract(a, b):
    return a - b

def product(a, b):
    return a * b

def division(a, b):
    return a / b
def operate(lst):
    for (i, elem) in enumerate(lst):
        if elem == '*' or elem == 'x' or elem == '/' or elem == ':':
            if elem == '*' or elem == 'x':
                lst[i] = product(lst[i-1], lst[i+1])
                del lst[i+1]
                del lst[i-1]
                return
            if elem == '/' or elem == ':':
                lst[i] = division(lst[i-1], lst[i+1])
                del lst[i+1]
                del lst[i-1]
                return
    for (i,elem) in enumerate(lst):
        if elem == '+' or elem == '-':
            if i == 0:
                lst.insert(0, 0)
                i += 1
            if elem == '+':
                lst[i] = sum(lst[i-1], lst[i+1])
                del lst[i+1]
                del lst[i-1]
                return
            if elem == '-':
                lst[i] = substract(lst[i-1], lst[i+1])
                del lst[i+1]
                del lst[i-1]
                return

def put_spaces(st, j):
    for (i, char) in enumerate(st):
        if (char == "+" or char  == "-" or char == "*" or char == "x"
            or char =="/" or char == ":" or char == "(" or char == ")"):
            st = st[:i+j] + ' ' + st[i+j] + ' ' + st[i+1+j:]
            j += 2
    return st

def one_space(st):
    for times in range(10):
        for i, char in enumerate(st):
            if i > 0 and i < len(st):
                if st[i] == ' ':
                    if st[i-1] == ' ':
                        st = st[:i-1] + st[i:]
    if st[0] == ' ':
        st = st[1:]
    if st[len(st) - 1] == ' ':
        st = st[:len(st) - 1]
    return st

def list_atoi(lst):
    for (i, num) in enumerate(lst):
        if num.isdigit():
            lst[i] = int(lst[i])
        elif num.count('.') == 1:
            if num.replace('.','').isdigit():
                lst[i] = float(lst[i])

def nest_list(lst):
    for (i, num) in enumerate(lst):
        if lst[i] == '(':
            lst[i] = []
            while (lst[i + 1] != ')'):
                lst[i].append(lst[i + 1])
                del lst[i + 1]
        if num == ')':
            lst.remove(lst[i])

def is_num(num):
    if type(num) is str:
        return False
    if type(num) is int or type(num) is float:
        return True
