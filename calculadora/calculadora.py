#!/usr/bin/env python3

import sys
from modcalc import *
keyboard_input = input() #el programa espera a que introduzcas una expresion algebraica desde el teclado
while (keyboard_input != 'exit'): #mientras no teclees 'exit' el programa seguira esperando input indefinidamente
    if check_syntax(keyboard_input) is False:
        print('syntax error') #check_syntax devuelve True si la sintaxis es correcta a priori y False si no lo es
    else:
        keyboard_input = put_spaces(keyboard_input, 0) #introduce espacios a ambos lados de cada signo o parenteis
        keyboard_input = one_space(keyboard_input) #reduce los bloques de espacios que encuentre a un solo espacio
        lst = keyboard_input.split(' ') #crea una lista cuyos elementos son los numeros, signos y parentesis de la expresion
        list_atoi(lst) #sustituye los numeros en forma de string por su valor (de string a int o float)
        if check_syntax2(lst): #devuelve True si la sintaxis es correcta definitivamente y False si no lo es
            nest_list(lst) #reduce todos los elementos entre parentesis a un solo elemento tipo lista
            try:
                for (i, elem) in enumerate(lst):
                    if type(elem) is list:
                        while (len(elem) > 1):
                            operate(elem)#opera y resuelve el elemento tipo lista
                        lst[i] = elem[0] #sutituye el elemento tipo lista por el resultado de la expresion de que cobijaba
                while (len(lst)) > 1:
                    operate(lst) #opera y resuelve la expresion completa, con los parentesis ya resueltos
                print(lst[0]) #muestra en pantalla el resultado de la operacion
            except ZeroDivisionError:
                print('oo') #para evitar el error al dividir entre 0, devuelve el resultado de dicha division, infinito
        else:
            print('syntax error')
    keyboard_input = input() #tras imprimir la solucion, el programa vuelve a esperar input
