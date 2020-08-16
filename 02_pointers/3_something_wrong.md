(since a markdown/pdf file was requested, here you go)
(I wrote a bit more in the c++ file)

The while loop will enter unallocated memory if the character 'e' is not found in the *five* chars of input text.

The statements inside will end up replacing input _and_ garbage values with 'e' until an 'e' is found, which might never happen. That is, if the program isn't terminated by runtime checks.

In my case, it aborts with this error msg:  
`*** stack smashing detected ***: terminated`  
which is entirely appropriate.
