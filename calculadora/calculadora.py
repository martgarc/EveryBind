#!/usr/bin/env python3

from modcalc import *

st = input()
while (st != 'exit'):
    st = put_spaces(st, 0)
    st = one_space(st)
    lst = st.split(' ')
    list_atoi(lst)
    try:
        nest_list(lst)
        for (i, elem) in enumerate(lst):
            if type(elem) is list:
                while (len(elem) > 1):
                    operate(elem)
                lst[i] = elem[0]
        while (len(lst)) > 1:
            operate(lst)
        if is_num(lst[0]):
            print(lst[0])
        else:
            print('syntax error')
    except (TypeError, IndexError):
        print('syntax error')
    except ZeroDivisionError:
        print ('Infinity')
    st = input()
