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






13-main.c


#include <stddef.h>

#include <stdio.h>

#include <stdlib.h>

#include "lists.h"


/**

 * main - check the code for

 *

 * Return: Always 0.

 */

int main(void)

{

    listint_t *head;


    head = NULL;

    add_nodeint_end(&head, 1);

    add_nodeint_end(&head, 17);

    add_nodeint_end(&head, 972);

    add_nodeint_end(&head, 50);

    add_nodeint_end(&head, 98);

    add_nodeint_end(&head, 98);

    add_nodeint_end(&head, 50);

    add_nodeint_end(&head, 972);

    add_nodeint_end(&head, 17);

    add_nodeint_end(&head, 1);

    print_listint(head);


    if (is_palindrome(&head) == 1)

        printf("Linked list is a palindrome\n");

    else

        printf("Linked list is not a palindrome\n");


    free_listint(head);


    return (0);

}






2-main.py


#!/usr/bin/python3

replace_in_list = __import__('2-replace_in_list').replace_in_list


my_list = [1, 2, 3, 4, 5]

idx = 3

new_element = 9

new_list = replace_in_list(my_list, idx, new_element)


print(new_list)

print(my_list)







2-replace_in_list.py


#!/usr/bin/python3

def replace_in_list(my_list, idx, element):

    if idx < 0:

        return my_list

    if idx >= len(my_list):

        return my_list

    my_list[idx] = element

    return my_list







3-main.py


#!/usr/bin/python3

print_reversed_list_integer = __import__('3-print_reversed_list_integer').print_reversed_list_integer


my_list = [1, 2, 3, 4, 5]

print_reversed_list_integer(my_list)







3-print_reversed_list_integer.py


#!/usr/bin/python3

def print_reversed_list_integer(my_list=[]):

    if my_list:

        for elm in my_list[::-1]:

            print("{:d}".format(elm))







4-main.py


#!/usr/bin/python3

new_in_list = __import__('4-new_in_list').new_in_list


my_list = [1, 2, 3, 4, 5]

idx = 3

new_element = 9

new_list = new_in_list(my_list, idx, new_element)


print(new_list)

print(my_list)






4-new_in_list.py


#!/usr/bin/python3

def new_in_list(my_list, idx, element):

    if idx < 0:

        return my_list

    elif idx >= len(my_list):

        return my_list

    new_list = list(my_list)

    new_list[idx] = element

    return new_list







5-main.py


#!/usr/bin/env python3

no_c = __import__('5-no_c').no_c


print(no_c("Best School"))

print(no_c("Chicago"))

print(no_c("C is fun!"))





5-no_c.py


#!/usr/bin/python3

def no_c(my_string):

    new_string = ""

    for elements in my_string:

        if elements != "c" and elements != "C":

            new_string += elements

    return new_string







6-main.py


#!/usr/bin/python3

print_matrix_integer = __import__('6-print_matrix_integer').print_matrix_integer


matrix = [

    [1, 2, 3],

    [4, 5, 6],

    [7, 8, 9]

]


print_matrix_integer(matrix)

print("--")

print_matrix_integer()






6-print_matrix_integer.py


#!/usr/bin/python3

def print_matrix_integer(matrix=[[]]):

    if not matrix:

        print()

    else:

        for row in range(len(matrix)):

            for item in range(len(matrix[row])):

                if item != len(matrix[row]) - 1:

                    endspace = ' '

                else:

                    endspace = ''

                print("{:d}".format(matrix[row][item]), end=endspace)

            print()







7-add_tuple.py


#!/usr/bin/python3

def add_tuple(tuple_a=(), tuple_b=()):

    len_a, len_b = len(tuple_a), len(tuple_b)

    new_tuple = ((tuple_a[0] if len_a >= 1 else 0) +

                 (tuple_b[0] if len_b >= 1 else 0),

                 (tuple_a[1] if len_a >= 2 else 0) +

                 (tuple_b[1] if len_b >= 2 else 0))

    return new_tuple







7-main.py


#!/usr/bin/python3

add_tuple = __import__('7-add_tuple').add_tuple


tuple_a = (1, 89)

tuple_b = (88, 11)

new_tuple = add_tuple(tuple_a, tuple_b)

print(new_tuple)


print(add_tuple(tuple_a, (1, )))

print(add_tuple(tuple_a, ()))






8-main.py



#!/usr/bin/python3

multiple_returns = __import__('8-multiple_returns').multiple_returns


sentence = "At school, I learnt C!"

length, first = multiple_returns(sentence)

print("Length: {:d} - First character: {}".format(length, first))








8-multiple_returns.py


#!/usr/bin/python3

def multiple_returns(sentence):

    if not sentence:

        sentence = None

    if sentence:

        sen_len = len(sentence)

    else:

        sen_len = 0

    return (sen_len, sentence if not sentence else sentence[:1])







9-main.py


#!/usr/bin/python3

max_integer = __import__('9-max_integer').max_integer


my_list = [1, 90, 2, 13, 34, 5, -13, 3]

max_value = max_integer(my_list)

print("Max: {}".format(max_value))








9-max_integer.py


#!/usr/bin/python3

def max_integer(my_list=[]):

    new_list = []

    if my_list:

        my_list.sort(reverse=True)

        return (my_list[0])

    return (None)






README.md


Solutions to 0x03. Python - Data Structures: Lists, Tuples tasks.





linked_lists.c


#include <stdio.h>

#include <stdlib.h>

#include "lists.h"


/**

 * print_listint - prints all elements of a listint_t list

 * @h: pointer to head of list

 * Return: number of nodes

 */

size_t print_listint(const listint_t *h)

{

    const listint_t *current;

    unsigned int n; /* number of nodes */


    current = h;

    n = 0;

    while (current != NULL)

    {

        printf("%i\n", current->n);

        current = current->next;

        n++;

    }


    return (n);

}


/**

 * add_nodeint_end - adds a new node at the end of a listint_t list

 * @head: pointer to pointer of first node of listint_t list

 * @n: integer to be included in new node

 * Return: address of the new element or NULL if it fails

 */

listint_t *add_nodeint_end(listint_t **head, const int n)

{

    listint_t *new;

    listint_t *current;


    current = *head;


    new = malloc(sizeof(listint_t));

    if (new == NULL)

        return (NULL);


    new->n = n;

    new->next = NULL;


    if (*head == NULL)

        *head = new;

    else

    {

        while (current->next != NULL)

            current = current->next;

        current->next = new;

    }


    return (new);

}


/**

 * free_listint - frees a listint_t list

 * @head: pointer to list to be freed

 * Return: void

 */

void free_listint(listint_t *head)

{

    listint_t *current;


    while (head != NULL)

    {

        current = head;

        head = head->next;

        free(current);

    }

}



