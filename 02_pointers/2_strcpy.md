# What happens if...

```cpp
char *line = nullptr;
strcpy(line, "Dette er en tekst");
```

Since `line` simply points to the address of the nullpointer, it is an unitialized array and there may not be enough memory around it to copy another string to. There sure is _no_ memory that is _meant_ to contain the copied string. This is a rather significantly unsafe operation.

Running this code simply results in an error message:
`fish: “./a.out” terminated by signal SIGSEGV (Address boundary error)`
