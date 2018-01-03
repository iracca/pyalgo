
try:
    from setuptools import setup, Extension
except ImportError:
    from distutils.core import setup, Extension


include_dirs = [
    "usr/local/include",
    "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1",
    "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/9.0.0/include",
    "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include",
    "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/usr/include",
]

ext = Extension(
    "pyalgos", 
    [
        "pyalgos/_pyalgos.cpp", 
        "pyalgos/countDict.cpp", 
        "pyalgos/matrixtocsv.cpp",
    ],
    extra_compile_args=["-std=c++11", "-stdlib=libstdc++", "-Wall", "-Wextra"],
)

setup(
    name="pyalgos",
    version="0.0.6",
    description="c++ implementation of common operation in my day job",
    author="Shun Endo",
    author_email="shnend@gmail.com",
    ext_modules=[ext,],
    include_dirs=include_dirs,
    setup_requires=['pytest-runner'],
    tests_require=['pytest', 'pytest-cov', 'mock'],
)
