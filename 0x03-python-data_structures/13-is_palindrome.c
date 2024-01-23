0x03-python-data_structures
0x03-python-data_structures




0-main.py


#!/usr/bin/python3

print_list_integer = __import__('0-print_list_integer').print_list_integer


my_list = [1, 2, 3, 4, 5]

print_list_integer(my_list)





0-print_list_integer.py


#!/usr/bin/python3

def print_list_integer(my_list=[]):

    for i in my_list:

        print("{:d}".format(i))





1-element_at.py


#!/usr/bin/python3

def element_at(my_list, idx):

    if idx < 0:

        return None

    elif idx >= len(my_list):

        return None

    return my_list[idx]





1-main.py


#!/usr/bin/python3

element_at = __import__('1-element_at').element_at


my_list = [1, 2, 3, 4, 5]

idx = 3

print("Element at index {:d} is {}".format(idx, element_at(my_list, idx)))






10-main.py


#!/usr/bin/python3

divisible_by_2 = __import__('10-divisible_by_2').divisible_by_2


my_list = [0, 1, 2, 3, 4, 5, 6]

list_result = divisible_by_2(my_list)


i = 0

while i < len(list_result):

    print("{:d} {:s} divisible by 2".format(my_list[i], "is" if list_result[i] else "is not"))

    i += 1






10-divisible_by_2.py


#!/usr/bin/python3

def divisible_by_2(my_list=[]):

    new_list = []

    if my_list:

        for num in my_list:

            new_list.append(False if num % 2 else True)

        return new_list






100-print_python_list_info.c


#include <stdlib.h>

#include <stdio.h>

#include <Python.h>

/**

 * print_python_list_info -  function that prints some basic

 *                                                        info about Python lists

 * @p: python list

 */

void print_python_list_info(PyObject *p)

{

        int elem;


        printf("[*] Size of the Python List = %lu\n", Py_SIZE(p));

        printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);

        for (elem = 0; elem < Py_SIZE(p); elem++)

                printf("Element %d: %s\n", elem, Py_TYPE(PyList_GetItem(p, elem))->tp_name);

}







100-test_lists.py


import ctypes


lib = ctypes.CDLL('./libPyList.so')

lib.print_python_list_info.argtypes = [ctypes.py_object]

l = ['hello', 'World']

lib.print_python_list_info(l)

del l[1]

lib.print_python_list_info(l)

l = l + [4, 5, 6.0, (9, 8), [9, 8, 1024], "My string"]

lib.print_python_list_info(l)

l = []

lib.print_python_list_info(l)

l.append(0)

lib.print_python_list_info(l)

l.append(1)

l.append(2)

l.append(3)

l.append(4)

lib.print_python_list_info(l)

l.pop()

lib.print_python_list_info(l)

julien@ubuntu:~/CPython$ python3 100-test_lists.py

[*] Size of the Python List = 2

[*] Allocated = 2

Element 0: str

Element 1: str

[*] Size of the Python List = 1

[*] Allocated = 2

Element 0: str

[*] Size of the Python List = 7

[*] Allocated = 7

Element 0: str

Element 1: int

Element 2: int

Element 3: float

Element 4: tuple

Element 5: list

Element 6: str

[*] Size of the Python List = 0

[*] Allocated = 0

[*] Size of the Python List = 1

[*] Allocated = 4

Element 0: int

[*] Size of the Python List = 5

[*] Allocated = 8

Element 0: int

Element 1: int

Element 2: int

Element 3: int

Element 4: int

[*] Size of the Python List = 4

[*] Allocated = 8

Element 0: int

Element 1: int

Element 2: int

Element 3: int






11-delete_at.py


#!/usr/bin/python3

def delete_at(my_list=[], idx=0):

    if idx < 0:

        return my_list

    elif idx >= len(my_list):

        return my_list

    del my_list[idx]

    return my_list







11-main.py


#!/usr/bin/python3

delete_at = __import__('11-delete_at').delete_at


my_list = [1, 2, 3, 4, 5]

idx = 3

new_list = delete_at(my_list, idx)

print(new_list)

print(my_list)






12-switch.py


#!/usr/bin/python3

a = 89

b = 10

a, b = b, a

print("a={:d} - b={:d}".format(a, b))






13-is_palindrome.c


#include "lists.h"

#include <stdlib.h>

#include <stdio.h>


/**

*add_nodeint - adds a new node at the beginning of a listint_t list

*@head: head of listint_t

*@n: int to add in listint_t list

*Return: address of the new element, or NULL if it failed

*/

listint_t *add_nodeint(listint_t **head, const int n)

{

        listint_t *new;


        new = malloc(sizeof(listint_t));

        if (new == NULL)

                return (NULL);

        new->n = n;

        new->next = *head;

        *head = new;

        return (new);

}

/**

*is_palindrome - identify if a syngle linked list is palindrome

*@head: head of listint_t

*Return: 1 if it is palindrome else 0

*/

int is_palindrome(listint_t **head)

{

        listint_t *head2 = *head;

        listint_t *aux = NULL, *aux2 = NULL;


        if (*head == NULL || head2->next == NULL)

                return (1);

        while (head2 != NULL)

        {

                add_nodeint(&aux, head2->n);

                head2 = head2->next;

        }

        aux2 = aux;

        while (*head != NULL)

        {

                if ((*head)->n != aux2->n)

                {

                        free_listint(aux);

                        return (0);

                }

                *head = (*head)->next;

                aux2 = aux2->next;

        }

        free_listint(aux);

        return (1);

}



