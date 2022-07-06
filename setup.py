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
    name="matfield",
    version="0.0.1",
    description="Dynamical mean field theory package for material research.",
    author="Yaozhenghang Ma",
    author_email="Yaozhenghang.Ma@gmail.com",
    license="GNU GPLv3",
    url="https://github.com/yaozhenghangma/matfield/",
    project_urls={
        "Bug Tracker": "https://github.com/yaozhenghangma/matfield/issues/",
        "Documentation": "https://matfield.readthedocs.io/",
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
    cmake_install_dir="src/matfield",
    include_package_data=True,
    extras_require={"test": ["pytest"]},
    python_requires=">=3.8",
)