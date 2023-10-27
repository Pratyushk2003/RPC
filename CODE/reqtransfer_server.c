#include "reqtransfer.h"

response *transf2_1_svc(get_request *argp, struct svc_req *rqstp)
{
    static response result;
    FILE *ofile;

    ofile = fopen(argp->name, "rb");
    long long int total = 0;
    long long int chunk = 0;

    if (ofile == NULL)
    {
        printf("File not found.\n");
        exit(1);
    }

    printf("Sending file %s.\n", argp->name);
    strcpy(result.name, argp->name);
    result.response_type = PUT;
    fseek(ofile, argp->start, SEEK_SET);
    result.data.nbytes = fread(result.data.data, 1, MAXLEN, ofile);
    total += argp->start + result.data.nbytes;
    chunk = total / MAXLEN;

    printf("\rChunk %lld and Total %lld bytes of %s sent to Client.", chunk, total, argp->name);
    fflush(stdout);
    fclose(ofile);

    return &result;
}
