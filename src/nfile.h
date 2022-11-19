/*
 *	Made by Noah Van Miert
 *	19/11/2022
 *	nfile - Easy file handling c
*/

#ifndef __NFILE_H_
#define __NFILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#define is_nullptr(ptr) ptr == 0
#define DEFAULT_BUFFER_SIZE 1024


typedef struct NFile NFile;


/*
 *	NFMode   - Mode for opening the file.
 *
 *	NF_WRITE - Opens the file for writing to it.
 *	NF_READ  - Opens the file for reading from it.
*/
enum NFMode {
	NF_WRITE,
	NF_READ
};


/*
 *	NFile	 - Keeps track of the filepath and mode, also contains the ptr to the file object.
 *
 *	filepath - The filepath of the file.
 *	fptr	 - The pointer to the file object, the user is not going to use this.
 *	mode	 - The mode (writing/reading).
*/
struct NFile {
	const char *filepath;
	FILE *fptr;
	unsigned char mode;
};


/*
 *	nf_mode_to_str() - Returns the str variant of a mode (NF_WRITE/NF_READ)
*/
static const char *nf_mode_to_str(unsigned char mode) 
{
	switch (mode) {
		case NF_WRITE: return "w";
		case NF_READ:  return "r";

		default: {
			fprintf(stderr, "NFILE: unkown mode '%d'\n", mode);
			exit(1);
		}
	}
}


/*
 *	nf_init() - Initializes a NFile object.
*/
struct NFile *nf_init(const char *filepath, unsigned char mode)
{
	// allocate memory for the NFile object.
	struct NFile *nf = malloc(sizeof(struct NFile));
	
	// initialize the NFile object.
	nf->filepath = filepath;
	nf->mode = mode;
	nf->fptr = fopen(nf->filepath, nf_mode_to_str(mode));
	
	// check if file could be opened
	if (is_nullptr(nf->fptr)) {
		fprintf(stderr, "NFILE: could not open '%s'\n", nf->filepath);
		exit(1);
	}
	
	return nf;
}


/*
 *	nf_write_file() - Writes a single string to a file.
*/
void nf_write_file(struct NFile *nf, const char *str)
{
	// write the given string to the file
	fputs(str, nf->fptr);
}


/*
 *	nf_read_file() - Reads a file and returns the content.
*/
const char *nf_read_file(struct NFile *nf)
{
	// allocate a buffer with a size of 1024 bytes
	char *buffer = malloc(DEFAULT_BUFFER_SIZE * sizeof(char));

	size_t buffer_size = DEFAULT_BUFFER_SIZE;
	size_t buffer_index = 0;
	char c = ' ';
	
	while (c != EOF) {
		// if buffer is to small, make the buffer bigger with 1024 bytes.
		if (buffer_index >= (buffer_size - 1)) {
			buffer = realloc(buffer, buffer_size + DEFAULT_BUFFER_SIZE);
			buffer_size += DEFAULT_BUFFER_SIZE;
		}

		c = fgetc(nf->fptr);
		buffer[buffer_index] = c;
		buffer_index += 1;
	}
	
	if (buffer_index > 1) {
		// allocate the exact amount of memory for the string.
		buffer = realloc(buffer, (buffer_index - 1) * sizeof(char));
		// set the last character in the string to '\0'
		buffer[buffer_index - 1] = '\0';

		return (const char *) buffer;
	}

	buffer[0] = '\0';

	return (const char *) buffer;
}


/*
 *	nf_create_file() - Creates a file with the given filepath.
*/
int nf_create_file(const char *filepath)
{
	// creates a new file
	FILE *f = fopen(filepath, "w");
	fclose(f);

	return is_nullptr(f) ? 1 : 0;
}


/*
 *	nf_delete_file() - Deletes given file.
 *	This function returns 1 if file could not be deleted.
*/
int nf_delete_file(const char *filepath)
{
	// removes a file
	return remove(filepath);
}


/*
 *	nf_rename_file() - Renames the given file.
 *	This function returns 1 if file could not be renamed.
*/
int nf_rename_file(const char *filepath, const char *new_filepath)
{
	// renames a file
	return rename(filepath, new_filepath);
}


/*
 *	nf_end() - Closes the file and frees the NFile object.
 *
 *	After this function is called the given NFile object 
 *	can't be used anymore.
*/
void nf_end(struct NFile *nf)
{
	// close the file and free the NFile object.
	fclose(nf->fptr);
	free(nf);
}


#endif
