# CHECKER TO DO:
## Input validator
	-Error if bigger than integer - Atoll compare to max_int and strlen  
	-Argument not integer -issign and isdigit after  
	-Duplicate values -comparison to existing list (or array for speed)  
	-Given instruction doesnt exist -strncmp doesnt match with the instruct  
## How to store the stacks?  
	-Linked list? Double linked?  
## Functions to handle the swap arguments  
	-sa swap top 2 elements of stack A  
	-sb swap top 2 elemnts of stack B  
	-ss sa and sb same time  
	-pa Top element from B to A  
	-pb Top element from A to B  
	-ra Rotate A, shifts all elements up by one. first becomes last  
	-rb Rotate B, shifts all elements up by one, first becomes last  
	-rr ra and rb same time  
	-rra reverse rotate a, all elements down by one.  
	-rrb reverse rotate b  
	-rrr rra and rrb the same time  
## Functions to libft  
	atol / atoll  
## Functions to this project:  
	create node,  
	swap two nodes  
	add node to the end of the list  