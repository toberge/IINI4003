# Speedrun score

Completion of a task is defined as _meeting the criteria_.
Documentation and cleanup might be done afterwards.

| Split             | Timestamp | Elapsed time |
| ----------------- | --------- | ------------ |
| Tasks 1,3,5       | 09:53     | 00:53        |
| Tasks 4           | 10:11     | 01:11        |
| Task 2            | 10:23     | 01:23        |
| Comment task 4    | 10:33     | 01:33        |
| Comment task 1    | 10:47     | 01:47        |
| Extra testing     | 11:01     | 02:01        |
| Nitpicks          | 11:19     | 02:19        |
| **Total**         | 11:19     | 02:19        |
| **Minimal total** | 10:23     | 01:23        |

I would have passed this exam with what I had written at 10:23, less that one and a half hours in. For comparison: The time limit was **four** hours.

# All tests are green

See [the test suite](exam.bats).

```
$ bats exam.bats
 ✓ Task 1
 ✓ Task 2
 ✓ Task 4
 ✓ Task 6

4 tests, 0 failures
```
