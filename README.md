# MooshakTools
Mooshak contest manager tools include:

1. [evaluate](evaluate.md) (completed)\
Evalution of mooshak test on command line.

2. [submissions](submissions.md) (completed)\
Get submissions state date from a contest and present some statistics.

3. report (still in initial stage of development)\
Make mooshak evaluation reports available to users.\
(completed version is in bash, not included in these repository)

Compiled versions of Apps 1 and 2 are in bin folder, with format:\
*ELF 64-bit LSB shared object, x86-64, version 1 (GNU/Linux), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2*

**Note:** to compile this code in a local system it is required that an updated version of the source code of libs:

`https://github.com/helderdaniel/cpplib`

be present in the local system.

Then the local path for that libs should be set in CMakeLists.txt file at line:

`set(CPPLIB "/home/hdaniel/Dropbox/01-libs/cpp")`

