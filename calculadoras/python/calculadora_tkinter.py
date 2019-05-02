#! /usr/bin/env python3


from tkinter import *
from modcalc import *

root = Tk()
root.title("Calculadora")
root.resizable(0,0)

frame = Frame(root)
frame.pack()
frame.config(bg='#2e2f3d')

#------pantalla-----------

OnScreenNumber=StringVar()

pantalla = Entry(frame, width=11, font="Arial 40", text=OnScreenNumber)
pantalla.config(highlightbackground='#2e2f3d')
pantalla.grid(row=0, column=0, ipady=5, columnspan=4)
pantalla.config(background='#2E2F3D', fg='white', justify='right')

def tecla(num):
    OnScreenNumber.set(OnScreenNumber.get() + num)

def result():
    OnScreenNumber.set(calc(OnScreenNumber.get()))


#------fila 0------------

botonAC = Button(frame, text='AC', font="Arial 20", width=3)
botonAC.grid(row=1, column=0, ipadx=12, ipady=9, pady=1)

botonC = Button(frame, text="C", font="Arial 20", width=3)
botonC.grid(row=1, column=1, ipadx=12, ipady=9, pady=1)

botonOpenpar = Button(frame, text='(', font="Arial 20", width=3, command=lambda:tecla('('))
botonOpenpar.grid(row=1, column=2, ipadx=12, ipady=9, pady=1)

botonClosingpar = Button(frame, text=')', font="Arial 20", width=3, command=lambda:tecla(')'))
botonClosingpar.grid(row=1, column=3, ipadx=12, ipady=9, pady=1)

#-------fila 1------------
#696A6E
boton7 = Button(frame, text='7', font="Arial 20", width=3, command=lambda:tecla('7'))
boton7.grid(row=2, column=0, ipadx=12, ipady=9, pady=1)

boton8 = Button(frame, text='8', font="Arial 20", width=3, command=lambda:tecla('8'))
boton8.grid(row=2, column=1, ipadx=12, ipady=9)

boton9 = Button(frame, text='9', font="Arial 20",  width=3, command=lambda:tecla('9'))
boton9.grid(row=2, column=2, ipadx=12, ipady=9)

botonProduct = Button(frame, text='x', font="Arial 20", width=3, command=lambda:tecla('x'))
botonProduct.grid(row=2, column=3, ipadx=12, ipady=9)


#-------fila 2------------

boton4 = Button(frame, text='4', width=3, font="Arial 20", command=lambda:tecla('4'))
boton4.grid(row=3, column=0, ipadx=12, ipady=9, pady=1)

boton5 = Button(frame, text='5', width=3, font="Arial 20", command=lambda:tecla('5'))
boton5.grid(row=3, column=1, ipadx=12, ipady=9)

boton6 = Button(frame, text='6', width=3, font="Arial 20", command=lambda:tecla('6'))
boton6.grid(row=3, column=2, ipadx=12, ipady=9)

botonSubstract = Button(frame, text='-', width=3, font="Arial 20", command=lambda:tecla('-'))
botonSubstract.grid(row=3, column=3, ipadx=12, ipady=9)



#------fila 3--------------

boton1 = Button(frame, text='1', width=3, font="Arial 20", command=lambda:tecla('1'))
boton1.grid(row=4, column=0, ipadx=12, ipady=9, pady=1)

boton2 = Button(frame, text='2', width=3, font="Arial 20", command=lambda:tecla('2'))
boton2.grid(row=4, column=1, ipadx=12, ipady=9)

boton3 = Button(frame, text='3', width=3, font="Arial 20", command=lambda:tecla('3'))
boton3.grid(row=4, column=2, ipadx=12, ipady=9)

botonAddition = Button(frame, text='+', width=3, font="Arial 20", command=lambda:tecla('+'))
botonAddition.grid(row=4, column=3, ipadx=12, ipady=9)


#------fila 4--------------

botonDot = Button(frame, text=',', width=3, font="Arial 20", command=lambda:tecla('.'))
botonDot.grid(row=5, column=0, ipadx=12, ipady=9, pady=1)

boton0 = Button(frame, text='0', width=3, font="Arial 20", command=lambda:tecla('0'))
boton0.grid(row=5, column=1, ipadx=12, ipady=9)

botonEqual = Button(frame, text='=', width=3, font="Arial 20", command=lambda:result())
botonEqual.grid(row=5, column=3, ipadx=12, ipady=9)

botonDivide = Button(frame, text='/', width=3, font="Arial 20", command=lambda:tecla('/'))
botonDivide.grid(row=5, column=2, ipadx=12, ipady=9)



root.mainloop()
