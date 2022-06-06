# CHECKER TO DO:
## Input validator
	-Error if bigger than integer - Atoll compare to max_int [DONE]
	-Argument not integer -issign and isdigit after  [DONE]
	-Duplicate values -comparison to existing list (or array for speed)  [DONE]
	-Given instruction doesnt exist -strncmp doesnt match with the instruct
	-Does the checker need usage msg with argc < 2? 
## How to store the stacks?  
	-Linked list? [X] Double linked?  
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
	atol / atoll  [DONE]
## Functions to this project:  
	create node [DONE]
	swap two nodes values [DONE]
		add node to the end of the list - adds a node to the next node of the given node, and changes the pointer to point to itself (current = current->next) and adds to nodecount, also new nodes prev pointing to the previous current.
	wincondition checker
	nodecounter to verify stack counts / node traverser ?