/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "transfer.h"

char opened_file[MAXLEN];
FILE *ofile;
long long int total = 0;

int *
transf_1_svc(file *argp, struct svc_req *rqstp)
{
	static int  result;
	static char tempName[MAXLEN];
	total += argp->nbytes;

	if (strcmp(opened_file, "") == 0 && ofile == NULL) {
		printf("Receiving new file %s.\n", argp->name);

		strcpy(opened_file, argp->name);
		ofile = fopen(argp->name, "ab+");
	}
	if (strcmp(opened_file, argp->name) == 0) {
		fflush(stdout);

		fwrite(argp->data, 1, argp->nbytes, ofile);

		if (argp->nbytes < MAXLEN) {
			printf("\nFinished receiving %s.\n", argp->name);
			total = 0;
			fclose(ofile);
			ofile = NULL;
			strcpy(opened_file, "");
		}
	}
	return &result;
}
