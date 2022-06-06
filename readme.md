# CHECKER TO DO:
## Input validator
	-Error if bigger than integer - Atoll compare to max_int [DONE]
	-Argument not integer -issign and isdigit after  [DONE]
	-Duplicate values -comparison to existing list (or array for speed)  [DONE]
	-Given instruction doesnt exist -strncmp doesnt match with the instruct
	-Does the checker need usage msg with argc < 2? 
## Function to handle the stacks
	-Create node [DONE]
	-Swap two nodes [DONE] 
	-Add the given node as a head to given head [DONE, UNTESTED]
	-Add the given node to the tail [DONE, UNTESTED]
	-Function to add stack tail to other stack head	
		-Remove tail and update previous links and pointer in struct

## Functions to handle the swap arguments  
	-sa swap top 2 elements of stack A  [PREREQ OK]
	-sb swap top 2 elemnts of stack B  [PREREQ OK]
	-ss sa and sb same time  [PREREQ OK]
	-pa Top element from B to A  [DONE]
	-pb Top element from A to B  [DONE]
	-ra Rotate A, shifts all elements up by one. first becomes last  
	-rb Rotate B, shifts all elements up by one, first becomes last  
	-rr ra and rb same time  
	-rra reverse rotate a, all elements down by one.  
	-rrb reverse rotate b  
	-rrr rra and rrb the same time 
## Functions to libft  
	atol / atoll  [DONE]
## Functions to this project:
	initializer to utils
	create node [DONE]
	swap two nodes values [DONE]
	wincondition checker
	nodecounter to verify stack counts / node traverser ?