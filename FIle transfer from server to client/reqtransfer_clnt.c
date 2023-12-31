/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "reqtransfer.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

response *
transf2_1(get_request *argp, CLIENT *clnt)
{
	static response clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, TRANSF2,
		(xdrproc_t) xdr_get_request, (caddr_t) argp,
		(xdrproc_t) xdr_response, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
