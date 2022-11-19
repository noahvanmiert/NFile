#include "../src/nfile.h"

#include <stdio.h>

int main()
{
	// create a NFile object
	NFile *nf = nf_init("Examples/read_from_file.txt", NF_READ);
	
	// prints the content of the file
	printf("%s\n", nf_read_file(nf));
	
	// free all memory
	// nf will not be useable anymore after this.
	nf_end(nf);
}
