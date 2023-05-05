import sys

try:
    from skbuild import setup
except ImportError:
    print(
        "Please update pip, you need pip 10 or greater,\n"
        " or you need to install the PEP 518 requirements in pyproject.toml yourself",
        file=sys.stderr,
    )
    raise

from setuptools import find_packages

setup(
    name="hybrid_example",
    version="0.0.1",
    description="Dynamical mean field theory package for material research.",
    author="Yaozhenghang Ma",
    author_email="Yaozhenghang.Ma@gmail.com",
    license="GNU GPLv3",
    url="https://github.com/yaozhenghangma/hybrid_programming/",
    project_urls={
        "Bug Tracker": "https://github.com/yaozhenghangma/hybrid_programming/issues/",
        "Documentation": "https://hybrid_programming.readthedocs.io/",
    },
    install_requires=[
        "setuptools>=42",
        "pybind11>=2.9.2",
        "cmake>=3.13",
        "scikit-build>=0.14.1",
        "numpy",
    ],
    packages=find_packages(where="src"),
    package_dir={"": "src"},
    cmake_install_dir="src/hybrid_example",
    include_package_data=True,
    extras_require={"test": ["pytest"]},
    python_requires=">=3.8",
)