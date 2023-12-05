<h1 align="center">
AbstractVM - Epitech 2023 - Bonus program
</h1>

</br>

## Bonus program for this project 📝

### What is the difference between the bonus program and the main program? 🤔

The bonus program opens a GUI instead of a CLI. It is written in C++ and uses the SFML library.

### How to use the bonus program? 📚

Once compiled, using `make bonus`, you can run the program with `./abstractVM`.
Once you open it, you will see a window with a text field. You can type your commands in there and press enter to execute them.
Everytime you add a command, it will be added to the history.

You can see your 15 registries on the right side of the window. On the left, you can see the first 15 elements of the stack.

In the Terminal, everytime you enter in a new command, the history and dump will be shown.

When entering an unknown command, the command will be removed, and the error will be shown on the Terminal.

### Special commands 📜

- **`restart`**: Restart from the beginning. Clear your history and the text field.
- **`back`**: Go back to the previous command. This will remove the last command from the history and put it in the text field.
