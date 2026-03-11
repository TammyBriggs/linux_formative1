# Formative Assessment: Systems Programming & Architecture

This repository contains the source code and execution instructions for the Systems Programming formative assessment.

**Note:** All my detailed evaluations, forensic analyses, performance explanations, and demonstration screenshots are provided in the accompanying formal analysis report.

---

## Project 1: Investigating a Suspicious Binary
**Objective:** Perform static analysis on an unknown ELF binary (`data_sync`) without executing it to determine its functionality.

### Compilation
```bash
gcc data_sync.c -o data_sync
```

### Analysis Commands
Run the following commands to inspect the binary. The outputs and corresponding forensic analysis are documented in the main report.

```bash
# Identify the entry point
objdump -f data_sync

# Inspect the ELF sections
objdump -h data_sync

# Identify imported dynamic library functions
nm -D data_sync
```

---

## Project 2: System Call Monitoring Tool
**Objective:** Trace and categorize how a file backup program interacts with the operating system kernel.

### Compilation
```bash
gcc backup_sim.c -o backup_sim
```

### Execution and Tracing
```bash
# Run the program and capture system calls into a text file
strace -o strace_output.txt ./backup_sim
```

(A complete breakdown of the captured system calls and their categorical purposes is available in the main report).

---

## Project 3: Building a Python Performance Extension
**Objective:** Optimize heavy numeric computation by offloading a Python loop to a compiled C extension.

### Build Instructions
To compile the C extension locally:

```bash
python3 setup.py build_ext --inplace
```

### Running the Benchmark
```bash
python3 benchmark.py
```

(The benchmark script calculates the sum of squares for 1,000,000 integers. The performance comparison and technical explanation are detailed in the main report).

---

## Project 4: Signal-Based Server Controller
**Objective:** Develop a continuous background service that gracefully handles and reacts to asynchronous Unix signals.

### Compilation
```bash
gcc monitor_service.c -o monitor_service
```

### Demonstration Instructions
To test the signal handling, you will need two terminal windows.

**Terminal 1 (Run the service):**

```bash
./monitor_service
```

Take note of the Process ID (PID) printed to the console.

**Terminal 2 (Send signals):**  
Replace `<PID>` with the Process ID from Terminal 1.

```bash
# Request system status (Program catches signal and continues running)
kill -SIGUSR1 <PID>

# Trigger emergency shutdown (Program catches signal and terminates)
kill -SIGTERM <PID>
```

(You can also press Ctrl+C in Terminal 1 to test the SIGINT safe shutdown).
