# push_swap
data sorting project 
Introduction to sorting algorithms : https://www.youtube.com/watch?v=rbbTd-gkajw


# Introduction to the stack Abstract Data type (ADT)


https://runestone.academy/ns/books/published/pythonds/BasicDS/TheStackAbstractDataType.html#tbl-stackops

# Linked lists manipulations:

https://www.youtube.com/watch?v=R9PTBwOzceo&list=PLBlnK6fEyqRi3-lvwLGzcaquOs5OBTCww

# Illustrating the mid value algorithm (chunks algo) with examples

first we take a stack a initalized with non repeated integer values : 

1- put it into an array and sort the array

2- get the mid index value and the mid size as well(as shown in the picture)

![image](https://github.com/user-attachments/assets/94a1a121-630a-4fc3-8fd7-6c825065a674)

the same algorithm until a has the big values in ascending order:

![image](https://github.com/user-attachments/assets/1ac03f46-45c7-4a76-865a-f1d1cd0f789f)

![image](https://github.com/user-attachments/assets/3c12c629-5497-4a4f-8ade-85866d3f5bc8)

![image](https://github.com/user-attachments/assets/ca3879f7-1d31-4922-94d0-b761c065257d)

using the chunks I have I should be able to sort the stack b in descending way (top of the stack / head of the stack has the biggest number and so on)

![image](https://github.com/user-attachments/assets/8955b2ac-1828-430c-ad60-34ad3440cf3e)

![image](https://github.com/user-attachments/assets/aa5ca9c4-4a79-4416-a41b-743aa5af44b1)

![image](https://github.com/user-attachments/assets/0df97f6c-2686-4507-bf37-f28e9046a6ff)

edge cases where we use rr and rrr are:

stack a->next is already in ascending order but the head value is the highest value , and stack b->next is already in descending order but the lowest value on head we use here : rr (rotation a and b and push all the b elements to a)

now if a in ascending order and the lowest value is at last and  stack b in descending order and the highest value in the last node so we use : rrr (reverse rotation to a and b and push all the elements of b to a)





