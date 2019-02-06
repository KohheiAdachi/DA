# -*- coding:utf-8 -*- 
list = []
def add_tree(n):
    list.append(n)

if __name__ == "__main__":
    add_tree(1)
    add_tree(2)
    for a in list:
        print(a)
    