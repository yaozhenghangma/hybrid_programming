# Register Package on PyPI
In this section, we will provide a concise tutorial about registering Python package on PyPI. Before registering the package, it's necessary to create an account on PyPI, and obtain an [API token](https://pypi.org/help/#apitoken). The API token should be added to Github repository as a secret named `PYPI_API_TOKEN`.

Subsequently, we can register package when publishing a release with the aid of Github actions. An [example action](https://github.com/yaozhenghangma/hybrid_programming/blob/main/.github/workflows/python-publish.yml) can be found in this repository. In the provided example, the action first packages the code with Scikit-Build, and then conducts a building test with pytest. If the test passes successfully, the action `gh-action-pypi-publish` will take charge of publishing the release to PyPI.