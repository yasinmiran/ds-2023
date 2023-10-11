# Compiling a CPP file with MPI

`./main.cpp` is your entry point to the source file. And `-o app` is your executable's identifier and the path.

`main.cpp` can be anything. It could be `yourfile.cpp` but it expects either a relative
or an absolute path. `./` is the current directory relative to `pwd`.

```bash
mpic++ ./main.cpp -o ~/Desktop/sample
```

# Running an executable

Your identifier should match the compiled identifier.

```bash
mpiexec ~/Desktop/sample
```