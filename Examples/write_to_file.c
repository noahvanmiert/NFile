#include "../src/nfile.h"

int main() 
{
	// create a NFile object
	struct NFile *nf = nf_init("file_to_write.txt", NF_WRITE);
	
	// write to the file
	nf_write_file(nf, "This will be written to the file");
	
	// free all memory
	// nf will not be useable anymore after this.
	nf_end(nf);
}
