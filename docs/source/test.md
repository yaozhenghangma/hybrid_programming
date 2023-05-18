# Testing with pytest and catch2

## pytest
The code testing can be easily performed by an `assert` statement. And the pytest can assist us in generating a report.For example, in [test file](https://github.com/yaozhenghangma/hybrid_programming/blob/main/test/test.py), a testing case is executed by the function containing `assert` statement.
```python
def test_return():
    assert a.function() == 1.0
```
To execute the testing code and generate a report, we can utilize the following command
```bash
pytest --cov=./ --cov-report=xml test/*.py
```

## catch2

## Merging reports