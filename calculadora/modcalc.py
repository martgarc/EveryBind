def sum(a, b):
    return a + b

def substract(a, b):
    return a - b

def product(a, b):
    return a * b

def division(a, b):
        return a / b

def operate(lst):
    if lst[0] == '-': #si el primer elemento de la lista es un -, lo elimina y le cambia el signo al siguiente elemento
        lst[1] = 0 - lst[1] 
        del lst[0]
    if lst[0] == '+': #si el primer elemento de la lista es un +, sencillamente elimina dicho elemento
        del lst[0]
    for (i, elem) in enumerate(lst):
        if elem == '*' or elem == 'x' or elem == '/' or elem == ':':
           if is_num(lst[i-1]) is True and is_num(lst[i+1]) is True: #comprueba si los elementos contiguos a los operadores son numeros
                if elem == '*' or elem == 'x':
                    lst[i] = product(lst[i-1], lst[i+1]) #sustituye el elemento '*' o 'x' por el resultado de la multiplicacion de los elementos contiguos
                    del lst[i+1] #elimina los elementos contiguos de la lista
                    del lst[i-1]
                    return
                if elem == '/' or elem == ':':
                        lst[i] = division(lst[i-1], lst[i+1])
                        del lst[i+1]
                        del lst[i-1]
                        return
    for (i,elem) in enumerate(lst):
        if elem == '+' or elem == '-':
            if (lst[i-1] == "*" or lst[i-1] == "x" or lst[i-1] == "/" or
                    lst[i-1] == ":"):
                if lst[i] == "+":
                    del lst[i]
                if lst[i] == "-":
                    lst[i+1] = 0 - lst[i+1]
                    del lst[i]
            if i < (len(lst) - 1):
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

def check_syntax(string): #devuelve T si la sintaxis es correcta y F si no lo es
    for (i, char) in enumerate(string):
        if ord(string[i]) < 48 or ord(string[i]) > 57: #si no es un digito
            if ord(string[i]) < 40 or ord(string[i]) > 43: #si no es (, ), *, +
                if ord(string[i]) < 45 or ord(string[i]) > 47: #si no es -, ., /
                    if (string[i] != ' ' and string[i] != ':' and
                        string[i] != 'x'): #si no es un espacio o un :
                            return False
    par = 0
    for (i, char) in enumerate(string):
        if ord(string[i]) == 40:
            par += 1 #por cada '(', suma uno a la variable
        if ord(string[i]) == 41:
            par -= 1 #por cada ')', resta uno a la variable
    if par != 0: #si se cumple, no hay el mismo numero de '(' que de ')'
        return False
    par = 0
    for (i, char) in enumerate(string):
        if par > 1:
            return False #si hay parentesis dentro de parentesis, devuelve False
        else:
            if string[i] == '(':
                par += 1
            elif string[i] == ')':
                par -= 1
    return True

def put_spaces(st, j): #st == string
    for (i, char) in enumerate(st):
        if (char == "+" or char  == "-" or char == "*" or char == "x"
                or char == "/" or char == ":" or char == "(" or char == ")"):
            st = st[:i+j] + ' ' + st[i+j] + ' ' + st[i+1+j:] #introduce espacios a ambos lados de los caracteres incluidos en el if
            j += 2
    return st

def one_space(st): #reduce los bloques de espacios que encuentre a un solo espacio
    for times in range(10):
        for i, char in enumerate(st):
            if i > 0 and i < len(st):
                if st[i] == ' ':
                    if st[i-1] == ' ':
                        st = st[:i-1] + st[i:]
    if st[0] == ' ':
        st = st[1:] #elimina el espacio que ocupa la primera posicion de la string, si lo hubiera
    if st[len(st) - 1] == ' ':
        st = st[:len(st) - 1] #elimina el espacio que ocupa la ultima posicion de la string, si lo hubiera
    return st

def list_atoi(lst):
    for (i, num) in enumerate(lst):
        if num.isdigit():
            lst[i] = int(lst[i])
        elif num.count('.') == 1:
            if num.replace('.','').isdigit():
                lst[i] = float(lst[i])

def check_syntax2(lst): #revisa si la sintaxis es correcta
    for (i, elem) in enumerate(lst):
        if i > 0:
            if is_num(lst[i]):
                if is_num(lst[i-1]):
                    return False 
            if (lst[i] == "*" or lst[i] == "x" or lst[i] == "/"
                or lst[i] == ":"):
                if (lst[i-1] == "+" or lst[i-1]  == "-" or lst[i-1] == "*"
                    or lst[i-1] == "x" or lst[i-1] == "/" or lst[i-1] == ":"):
                    return False
            if (lst[i] == "+" or lst[i] == "-"):
                if (lst[i-1] == "+" or lst[i-1]  == "-"):
                    return False
    return True

def nest_list(lst): #reduce todos los elementos entre parentesis a un solo elemento tipo lista
    for (i, num) in enumerate(lst):
        if lst[i] == '(':
            lst[i] = []
            while lst[i + 1] != ')':
                lst[i].append(lst[i + 1])
                del lst[i + 1]
        if num == ')':
            lst.remove(lst[i])

def is_num(num):
    if type(num) is int or type(num) is float:
        return True
    else:
        return False
