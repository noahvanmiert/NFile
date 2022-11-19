# NFile

This is just for fun. I'm not that good at programming, so if you notice any bugs please notify me.

## Example files

---

### To compile the 'read_from_file' example
``` bash
gcc Examples/read_from_file.c -o read_from_file
```

---
### To compile the 'write_to_file' example
``` bash
gcc Examples/write_to_file.c -o write_to_file
```


### Now just run the executable.

---

## NFile functions

``` c
NFile *nf = nf_init(<filepath>, <mode>);
```
### The nf_init() function takes a filepath and mode. This funtion returns a NFile object.
---

``` c
nf_write_file(<NFile object>, <data to write>);
```
### The nf_write_file() function takes a NFile object and a string. This functions will write the string to the file.
---

``` c
const char *data = nf_read_file(<NFile objext>);
```
### The nf_read_file() function takes a NFile object. This function will return the contents of the file.
---

``` c
nf_create_file(<filepath>);
```
### The nf_create_file() function takes a filepath and creates a new file. This function will return 1 if the file could not be created.
---

``` c
nf_rename_file(<filepath>, <new_filepath>);
```
### The nf_rename_file() function takes the filepath and the new name. This function will return 1 if the file could not be renamed.
--- 

``` c
nf_delete_file(<filepath);
```
### The nf_delete_file() function takes the filepath and removes the file. This function will return 1 if the file could not be deleted.
---

``` c
nf_end(<NFile object>);
```
### The nf_end() function takes a NFile object. This function will close the file and free the NFile object. The given NFile object will not be useable anymore after this functions is called.
