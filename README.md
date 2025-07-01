
> [!WARNING]  
> This is NOT a production ready library, but is somethings that could be usefull in multiple parsing context. 


## LXER 

This library provide a simple and configurable lexer for parsing expressions or phrases with a simple combination of functions.
This can be usefull to implements things from simple parser to pretty complex compiler, but to be usefull it need to be adapted first to the desired 
usecase. For example this library does not support any type of line tracking, it only switch to the following token regardless of the space 
between the previous one and the target one, it does not support "invalid" syntax or something like that. 

For example if you want to implement a compiler I suggest to create a dedicated function to load the lxer output on a local 
array that is linked to a specific line, and by doing so you can switch from a "global token processing" to a "line token processing" or a 
"contenx token processing" where for each line you may have an array of tokens, an empty array with no tokens or an array with no tokens but with 
some text in it.


To cut short if you have a very specific target use case and you need a lexer this library is NOT somethings that i suggest to use, as I stated is a general lexer 
library and  by the fact that is simple as shit it require a bit of adaptation for more complex things, but by the fact that is still simple with a limited amount 
of moving part you can easilly understand the overhall structure and start working on a wrapper to adapt this lexer with your project
