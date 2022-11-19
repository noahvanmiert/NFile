/*
 *	Made by Noah Van Miert
 *	19/11/2022
 *	nfile - Easy file handling c
*/

#ifndef __NFILE_H_
#define __NFILE_H_

#include <stdio.h>


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
 *	nf_init() - Initializes a NFile object.
*/
struct NFile *nf_init(const char *filepath, unsigned char mode);


/*
 *	nf_write_file() - Writes a single string to a file.
*/
void nf_write_file(struct NFile *nf, const char *str);


/*
 *	nf_read_file() - Reads a file and returns the content.
*/
const char *nf_read_file(struct NFile *nf);


/*
 *	nf_create_file() - Creates a file with the given filepath.
*/
int nf_create_file(const char *filepath);


/*
 *	nf_delete_file() - Deletes given file.
 *	This function returns 1 if file could not be deleted.
*/
int nf_delete_file(const char *filepath);


/*
 *	nf_rename_file() - Renames the given file.
 *	This function returns 1 if file could not be renamed.
*/
int nf_rename_file(const char *filepath, const char *new_filepath);


/*
 *	nf_end() - Closes the file and frees the NFile object.
 *
 *	After this function is called the given NFile object 
 *	can't be used anymore.
*/
void nf_end(struct NFile *nf);


#endif
