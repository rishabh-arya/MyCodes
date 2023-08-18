from os import *
from sys import *
from collections import *
from math import *



class ComplexNumbers:
    
    def __init__(self,re,im):
        self.re = re
        self.im = im

    def Add(self,obj):
        a = self.re + obj.re
        b = self.im + obj.im 
        self.re = a 
        self.im = b
    def Multiply(self,obj):
        a =  self.re*obj.re - self.im*obj.im
        b = self.re*obj.im + self.im*obj.re 
        self.re = a 
        self.im = b

    def Print(self):
        print("{} + i{}".format(self.re,self.im))


class Fraction:
    def __init__(self,num,deno):
        self.num = num
        self.deno = deno
    def add(self,c):
        new_deno = self.deno * c.deno
        self.num *= int(new_deno/self.deno)
        c.num *= int(new_deno/c.deno)

        new_num = self.num + c.num
        g = gcd(new_num,new_deno)

        self.num = int(new_num/g)
        self.deno = int(new_deno/g)

    def mul(self,c):
        self.num *= c.num
        self.deno *= c.deno
        g = gcd(self.num,self.deno)
        self.num = int(self.num/g)
        self.deno = int(self.deno/g)

    def Print(self):
        print("{}/{}".format(self.num,self.deno))
    
    
    
    
    
# a1,b1 = list(map(int,input().split()))
# a2,b2 = list(map(int,input().split()))
# op = int(input())
# c1 = ComplexNumbers(a1,b1)
# c2 = ComplexNumbers(a2,b2)
# if op == 1:
#     c1.Add(c2)
#     c1.Print()
# elif op == 2:
#     c1.Multiply(c2)
#     c1.Print()
    
    
    
    
    
    
    
    
    
