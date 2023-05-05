# Continuous Integration with Github Actions
## Codecov
Codecov is an all-in-one code coverage analysis toolkit. We can use it to automatically display code coverage reports with the help of Github actions. As shown in [CI.yml](https://github.com/yaozhenghangma/hybrid_programming/blob/main/.github/workflows/CI.yml) file, we need codecov's codecov-action to upload analysis file:
```yml
- uses: codecov/codecov-action@v3
  with:
    files: ./coverage.xml
```

Besides we need sign up on [Codecov's website]() using our Github account. After logging in, we need to locate the repo we want to set up on Codecov. To set up repo, we need copy the repository secret provided by Codecov, and add it to the GitHub repository as a secret named ```CODECOV_TOKEN```. The Secrets panel can be found in Settings pannel in Github repository. Finally, we need configure Codecov's Github App with one click on [this page](https://github.com/apps/codecov).

After that, the Github action will push code coverage report to Codecov after each successful code testing. We can also display a status badge on README page using
```markdown
[![Coverage](https://codecov.io/gh/{username}/{repository}/branch/main/graph/badge.svg)](https://codecov.io/gh/{username}/{repository})
```
where we need modify the {username} and {repository}.
