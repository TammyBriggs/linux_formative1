import time
import fast_compute

# Pure Python implementation
def python_sum_of_squares(data):
    total = 0
    for num in data:
        total += num * num
    return total

# Generate a large dataset: 10 million numbers
print("Generating dataset...")
data = list(range(1_000_000))

print("Starting benchmark...\n")

# Benchmark Pure Python
start_time = time.time()
py_result = python_sum_of_squares(data)
py_duration = time.time() - start_time
print(f"Pure Python result: {py_result}")
print(f"Pure Python time:   {py_duration:.4f} seconds\n")

# Benchmark C Extension
start_time = time.time()
c_result = fast_compute.sum_of_squares(data)
c_duration = time.time() - start_time
print(f"C Extension result: {c_result}")
print(f"C Extension time:   {c_duration:.4f} seconds\n")

# Calculate performance gain
if c_duration > 0:
    speedup = py_duration / c_duration
    print(f"The C extension is {speedup:.2f}x faster!")
