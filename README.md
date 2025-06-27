
> [!WARNING]  
> This is NOT a production ready library, but is somethings that could be usefull in multiple parsing context. 


## LXER 

This library provide a simple and configurable lexer for parsing expressions or phrases with a simple combination of functions.
This can be usefull to implements simple parser to pretty complex compiler, but to be usefull need to be adapted first to the desired 
usecase. For example this does not support any type of line tracking, it only switch to the following token regardless of the space 
between the previous one and the target one, it does not support "invalid" syntax or something like that. 

For example if you want to implement a compiler I suggest to create a dedicated function to load the lxer output on a local 
array that is linked to a specific line, and by doing so you can switch from a "global token processing" to a "line token processing" or a 
"contenx token processing" where for each line you can have multiple tokens, and by doing so you can identify empty lines ( lines where there 
is no token or general content ) from trashy lines ( lines where there is not token but there is a content of some sort ). 


To cut short if you have a very specific target use case this library is NOT somethings that i suggest to use, as I stated is a general lexer 
library and  by the fact that is simple as shit is possible to work around the implementation and adapt it to the desired usecases if you want 
something simple and functional.
