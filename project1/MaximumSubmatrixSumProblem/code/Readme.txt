## file structure
| head file | source file   |
| --------- | --------------|
| head.h    | main.c file.c |

## compile by yourself
if you are using IDEs, just add head.h, main.h and file.c into your project and compile them
if you are using gcc, input this in sudo command `gcc main.c file.c -o out`, at the same time make sure the `head.h` is in the same path

## executable file, test examples and test results
executable file be found in the bin folder, note that when you run the executable file make sure the test example fils you use is in the same path
test results can be found in the test_result folder
test examples can be found in the test_example folder