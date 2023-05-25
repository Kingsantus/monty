#include "monty.h"

/*
* input_arg - Processes an input argument and extracts the operation code.
* @arg: Input argument string.
*
* Returns: extracted operation code or NULL if no input.
*/
char *input_arg(char *arg)
{
	char *op_code;

	op_code = strtok(arg, "\n ");
	if (op_code == NULL)
		return (NULL);

	return (op_code);
}

/*
* read_file - Reads instructions from a file, processes, and performs operations
* @filename: Name of the file to be read.
* @stack: Pointer to the stack.
*
* Returns: None.
*/

void read_file(char *filename, stack_t **stack)
{
	char *buf = NULL;
	char *arg;
	size_t i = 0;
	int count_arg = 1;
	int check;
	int read;
	instructions s;
	FILE *file = fopen(filename, 'r');

	if (!file)
	{
		printf("Error: Can't open file %s \n", filename);
		error_exit(stack);
	}
	while ((read = getline(&buf, &i, file) != -1))
	{
		arg = input_arg(buf);
		if (arg == NULL || arg[0] == '#')
		{
			count_arg++;
			continue;
		}
		s = get_ops_func(arg);

		if (s == NULL)
		{
			printf("L%d: unknown instruction %s\n", count_arg, arg);
			error_exit(stack);
		}
		s(stack, count_arg);
		count_arg++;
	}
	free(buffer);
	check = fclose(file);
	if (check == -1)
		exit(-1);
}

/*
* get_ops_func - Retrieves the instruction function for op code
* @str: Operation code string.
*
* Returns: instruction function pointer corresponding to the op code.
*/

instructions get_ops_func(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}
