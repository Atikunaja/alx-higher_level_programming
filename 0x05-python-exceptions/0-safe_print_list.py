#!/usr/bin/python3
def safe_print_list(my_list=[], x=0):
    try:
        if len(my_list) < x:
            print("".join(my_list))
            return x - len(my_list)
    except IndexError:
        print("The list doesn't have enough elements")
