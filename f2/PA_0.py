# Importing tkinter libraries 
from tkinter import *
from tkinter.font import Font

# Creating a window object
window = Tk()
window.title("GUI")
window.minsize(width=1200,height=400)
window.maxsize(width=1200,height=400)
window.geometry("1200x400")

# Function to Encipher the plain text
def encipher():
    res = txt1.get("1.0",END)
    s = ""
    for i in res:
        if i>='A' and i<='Z':
            s += chr(ord('Z')-(ord(i)-ord('A')))
        elif i>='a' and i<='z':
            s += chr(ord('z')-(ord(i)-ord('a')))
        else :
            s += i
    
    txt2.delete("1.0",END)
    txt2.insert(END,s)

# Function to Decipher the cipher text
def decipher():
    res = txt2.get("1.0",END)
    s = ""
    for i in res:
        if i>='A' and i<='Z':
            s += chr(ord('A')+(ord('Z')-ord(i)))
        elif i>='a' and i<='z':
            s += chr(ord('a')+(ord('z')-ord(i)))
        else :
            s += i
    txt1.delete("1.0",END)
    txt1.insert(END,s)

# Creating the frames
frame1 = Frame(master=window,width=1200,height=100,bg="blue")
frame2 = Frame(master=window,width=1200,height=300,bg="#90e0ef")

# Creating the labels for plain text and cipher text
lb1 = Label(window,text="PLAIN TEXT",height=2,width=15,font=Font(family='Helvetica',size=14,weight="bold"),bg="#90e0ef")
lb1.place(x=10,y=150)
lb2 = Label(window,text="CIPHER TEXT",height=2,width=15,font=Font(family='Helvetica',size=14,weight="bold"),bg="#90e0ef")
lb2.place(x=620,y=150)

# Generating the text fields for inputing the plain text and cipher text 
txt1 = Text(width=60,height=6,bg="#48cae4",pady=10,padx=10,font=Font(family='Helvetica',size=12,weight="bold"),fg="#023E8A")
txt1.place(x=20,y=200)
txt2 = Text(width=60,height=6,bg="#48cae4",padx=10,pady=10,font=Font(family='Helvetica',size=12,weight="bold"),fg="#023E8A")
txt2.place(x=620,y=200)

# Creating button, Encipher (which will initiate the conversion of plain text into cipher text)
bt1 = Button(window,text="Encipher",fg="blue",height=1,width=12,font=Font(family='Helvetica',size=12,weight="bold"),command=encipher)
bt1.place(x=20,y=350)
# Creating button, Decipher (which will initiate the conversion of encrypted text into decrypted text)
bt2 = Button(window,text="Decipher",fg="blue",height=1,width=12,font=Font(family='Helvetica',size=12,weight="bold"),command=decipher)
bt2.place(x=620,y=350)

frame1.pack(padx=10,pady=10)
frame2.pack(padx=10,pady=10)
window.mainloop()

