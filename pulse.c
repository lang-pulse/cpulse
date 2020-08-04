#include <stdio.h>
#include <stdlib.h>

static char* readFile(const char* path) {
  /*
  Reads a file and returns the contents as a string

  Params
  ======
  path (const char*)
    : Path to file which is to be read

  Returns
  =======
  buffer (char *)
    : Contents of the file
  */

  // Create file pointer and open the file in read mode
  FILE* file = fopen(path, "rb");

  // If file cannot be opened
  if(file == NULL) {
    fprintf(stderr, "Could not open \"%s\".\n", path);
    exit(74);
  }

  // Compute file size
  fseek(file, 0L, SEEK_END);
  size_t file_size = ftell(file);
  rewind(file);

  // Allocate memory to read file contents
  char* buffer = (char *)malloc(file_size + 1);

  // If memory allocation fails
  if(buffer == NULL) {
    fprintf(stderr, "Not enough memory to read \"%s\".\n", path);
    exit(74);
  }

  // Read the contents of file
  size_t bytes_read = fread(buffer, sizeof(char), file_size, file);

  // If entire file could not be read
  if(bytes_read < file_size) {
    fprintf(stderr, "Could not read file \"%s\".\n", path);
    exit(74);
  }

  // Add a EOF token to end of source code
  buffer[bytes_read] = '\0';

  fclose(file);

  return buffer;
}

int main(int argc, char* argv[]) {
  // Read file path from command line
  char* file_path = argv[1];

  // Get the source code form code file
  char* source_code = readFile(file_path);

  // TODO: Pass source code to lexical analyzer

  // TODO: Pass tokens into parser and compiler

  // TODO: Pass bytecode into VM for execution

  return 0;
}
