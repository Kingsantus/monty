#include "monty.h"

monty_t mont = {NULL, NULL, NULL, 0};
/**
 * process_file - Function to process the contents of a file
 * @filename: The name of the file to process
 * Returns: None
 */
void process_file(const char* filename)
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	file = fopen(filename, 'r');
	mont.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		mont.content = content;
		line_number++;

		if (read_line > 0)
		{
			execute(content, &stack, line_number, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
}

/**
 * main - validates the command-line arguments, extracts and calls a function
 * @argc: Number of command-line arguments
 * @argv: Array of command-line
 *
 * Returns: 0 on successful execution
 */
int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	const char* filename = argv[1];
	process_file(filename);

	return (0);
}
