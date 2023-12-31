/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _REQTRANSFER_H_RPCGEN
#define _REQTRANSFER_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define MAXLEN 262144
#define REQUEST_VALUE 1000
#define RESPONSE_VALUE 1000
#define GET 1
#define PUT 2
#define ERROR 0

typedef char filebytes[MAXLEN];

struct file {
	char name[MAXLEN];
	filebytes data;
	int nbytes;
};
typedef struct file file;

struct send_ {
	char value[REQUEST_VALUE];
	char name[REQUEST_VALUE];
	struct file data;
	int request_type;
	int total;
};
typedef struct send_ send_;

typedef send_ put_req;

struct request_ {
	char value[REQUEST_VALUE];
	char name[REQUEST_VALUE];
	int request_type;
	int recieved;
	int start;
};
typedef struct request_ request_;

typedef request_ get_request;

struct response {
	char value[REQUEST_VALUE];
	char name[REQUEST_VALUE];
	struct file data;
	int response_type;
};
typedef struct response response;


#define FILE_TRANSFER 0x31230000
#define FILE_TRANSFER_1 1

#if defined(__STDC__) || defined(__cplusplus)
#define TRANSF2 1
extern  response * transf2_1(get_request *, CLIENT *);
extern  response * transf2_1_svc(get_request *, struct svc_req *);
extern int file_transfer_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define TRANSF2 1
extern  response * transf2_1();
extern  response * transf2_1_svc();
extern int file_transfer_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_filebytes (XDR *, filebytes);
extern  bool_t xdr_file (XDR *, file*);
extern  bool_t xdr_send_ (XDR *, send_*);
extern  bool_t xdr_put_req (XDR *, put_req*);
extern  bool_t xdr_request_ (XDR *, request_*);
extern  bool_t xdr_get_request (XDR *, get_request*);
extern  bool_t xdr_response (XDR *, response*);
extern  bool_t xdr_response (XDR *, response*);

#else /* K&R C */
extern bool_t xdr_filebytes ();
extern bool_t xdr_file ();
extern bool_t xdr_send_ ();
extern bool_t xdr_put_req ();
extern bool_t xdr_request_ ();
extern bool_t xdr_get_request ();
extern bool_t xdr_response ();
extern bool_t xdr_response ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_REQTRANSFER_H_RPCGEN */
