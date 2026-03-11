from setuptools import setup, Extension

# Define the extension module
module = Extension('fast_compute', sources=['fast_compute.c'])

# Run the setup
setup(
    name='FastCompute',
    version='1.0',
    description='Python package with a C extension for performance',
    ext_modules=[module]
)
