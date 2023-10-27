#include "reqtransfer.h"
#include <time.h>

void receive_file(char *host, char *file_to_receive, char *remote_file)
{
    CLIENT *clnt;
    FILE *ofile;
    response *result_2;
    get_request transf2_1_arg;
    char opened_file[MAXLEN];
    long long int total = 0;
    long long int chunk = 0;

    clnt = clnt_create(host, FILE_TRANSFER, FILE_TRANSFER_1, "tcp");
    if (clnt == NULL)
    {
        clnt_pcreateerror(host);
        exit(1);
    }
    if (strcmp(opened_file, "") == 0 && ofile == NULL)
    {
        printf("Receiving new file %s.\n", file_to_receive);
        strcpy(opened_file, file_to_receive);
        ofile = fopen(file_to_receive, "ab+");
        strcpy(transf2_1_arg.name, remote_file);
        transf2_1_arg.request_type = GET;
        transf2_1_arg.start = total;
    }
    clock_t begin = clock();
    while (1)
    {
        result_2 = (response *)transf2_1(&transf2_1_arg, clnt);
        if (result_2 == (response *)NULL)
        {
            clnt_perror(clnt, "call failed");
        }
        chunk++;

        if (strcmp(remote_file, result_2->name) == 0)
        {
            printf("\rChunk %lld and Total %lld bytes of file %s were received.", chunk, total, result_2->data.name);
            fflush(stdout);
            total += result_2->data.nbytes;
            //printf("total : %lld", total);
            fwrite(result_2->data.data, 1, result_2->data.nbytes, ofile);
            transf2_1_arg.start = total;
            if (result_2->data.nbytes < MAXLEN)
            {
                printf("\nFinished receiving %s.\n", result_2->name);
                total = 0;
                ofile = NULL;
                strcpy(opened_file, "");
                break;
            }
        }
    }

    clock_t end = clock();
    double download_time = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Download time: %lf\n", download_time);

    clnt_destroy(clnt);
    fclose(ofile);
}

int main(int argc, char *argv[])
{
    char *host;
    char *local_file;
    char *remote_file;
    int utility;

    if (argc < 4)
    {
        printf("usage: %s <server_host> <local_file> <remote_file> <Utility [send=1] / [Receive=0]>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    local_file = argv[2];
    remote_file = argv[3];
    utility = atoi(argv[4]);
    if (utility == 0)
    {
        receive_file(host, local_file, remote_file);
    }
    else if (utility == 1)
    {
        // The client will not send files in this case.
        printf("Sending files is not supported by this client.\n");
    }
    else
    {
        printf("Incorrect command\n");
        printf("usage: %s <server_host> <local_file> <remote_file> <Utility [send=1] / [Receive=0]>\n", argv[0]);
    }
    return 0;
}
