# Midterm: Tymur Krasnianskyi
Variant: 4

4. Написати програму, яка запускається та чекає на сигнали POSIX. По приходу сигналу SIGUSR1 виводить «Hello!», а по сигналу SIGUSR2 – завершується. Написати іншу програму, яка передає випадкову кількість SIGUSR1, а потім SIGUSR2 процесу, PID якого їй передається.

## How to use
1. Compile both programs:
```bash
mkdir build
cd build
cmake ..
make
```

2. Run first program:
```bash
./task4
```

3. Run second program:
```bash
./load $(pidof task4)
```

## Analysis
UTM (Virtual Machine) ARM64
Ubuntu 22.04

### Strace
```bash
strace -o strace.txt ./task4
```
strace_active_anotated.txt - annotated strace.txt file. 

### Pmap
In one terminal:
```bash
./task4
```
In another terminal:
```bash
pmap -X $(pidof task4) > pmap.txt
```

Task4_Analysis_Krasnianskyi.docs - analysis of the address space. The document can be found in the project directory or accessed online at <a href="https://docs.google.com/document/d/1jrtkZN_62Zm6LDJPzSrNztE2LpvOZrmV9c3Ri5IZCBA/">Google Docs.</a>
