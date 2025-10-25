

### How to Test

1.  **Compile the code:**
    ```shell
    make
    ```


2.  **Create a test file (`test.txt`):**
    ```
    hello world, hello universe.
    The word is hello.
    This line has no matches.
    hellohellohello
    hello
    ```


3.  **Run the tests:**

    *   **Test Case 1: Standard replacement**
        ```shell
        ./replace test.txt hello goodbye
		# Replaced 7 occurences in test.txt
		# Output is saved in test.txt.replace

        ```
        **Expected `test.txt.replace` content:**
        ```
        goodbye world, goodbye universe.
        The word is goodbye.
        This line has no matches.
        goodbyegoodbyegoodbye
        goodbye
        ```


    *   **Test Case 2: Replacing with an empty string**
        ```shell
        ./replace test.txt hello ""
		# Replaced 7 occurences in test.txt
		# Output is saved in test.txt.replace
        ```
        **Expected `test.txt.replace` content:**
        ```
         world,  universe.
        The word is .
        This line has no matches.

        ```


    *   **Test Case 3: No occurrences found**
        ```shell
        ./replace test.txt nonexistent_word replacement
		# Replaced 0 occurences in test.txt
		# Output is saved in test.txt.replace
        ```
        The content of `test.txt.replace` should be identical to `test.txt`.


    *   **Test Case 4: Error handling - wrong number of arguments**
        ```shell
        ./replace test.txt hello
		# Error: Invalid number of arguments.
		# Usage: ./replace <filename> <string_to_find> <string_to_replace>

    *   **Test Case 5: Error handling - file not found**
        ```shell
        ./replace non_existent_file.txt hello goodbye
		# Could not open input file: non_existent_file.txt
        ```


    *   **Test Case 6: Error handling - string to be replaced is null-string**
        ```shell
        ./replace test.txt "" hello
		# Error: The string to find cannot be empty.
        ```

