/*
 * Copyright (c) 2004 - 2007 Kungliga Tekniska H�gskolan
 * (Royal Institute of Technology, Stockholm, Sweden). 
 * All rights reserved. 
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met: 
 *
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright 
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the distribution. 
 *
 * 3. Neither the name of the Institute nor the names of its contributors 
 *    may be used to endorse or promote products derived from this software 
 *    without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND 
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS 
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY 
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF 
 * SUCH DAMAGE. 
 */

/* $Id$ */

typedef struct hx509_cert_attribute_data *hx509_cert_attribute;
typedef struct hx509_cert_data *hx509_cert;
typedef struct hx509_certs_data *hx509_certs;
typedef struct hx509_context_data *hx509_context;
typedef struct hx509_crypto_data *hx509_crypto;
typedef struct hx509_lock_data *hx509_lock;
typedef struct hx509_name_data *hx509_name;
typedef struct hx509_private_key *hx509_private_key;
typedef struct hx509_validate_ctx_data *hx509_validate_ctx;
typedef struct hx509_verify_ctx_data *hx509_verify_ctx;
typedef struct hx509_revoke_ctx_data *hx509_revoke_ctx;
typedef struct hx509_query_data hx509_query;
typedef void * hx509_cursor;
typedef struct hx509_request_data *hx509_request;
typedef struct hx509_error_data *hx509_error;
typedef struct hx509_peer_info *hx509_peer_info;
typedef struct hx509_ca_tbs *hx509_ca_tbs;
typedef struct hx509_env *hx509_env;

typedef void (*hx509_vprint_func)(void *, const char *, va_list);

enum {
    HX509_VALIDATE_F_VALIDATE = 1,
    HX509_VALIDATE_F_VERBOSE = 2
};

struct hx509_cert_attribute_data {
    heim_oid oid;
    heim_octet_string data;
};

typedef enum {
    HX509_PROMPT_TYPE_PASSWORD		= 0x1,	/* password, hidden */
    HX509_PROMPT_TYPE_QUESTION		= 0x2,	/* question, not hidden */
    HX509_PROMPT_TYPE_INFO		= 0x4	/* infomation, reply doesn't matter */
} hx509_prompt_type;

typedef struct hx509_prompt {
    const char *prompt;
    hx509_prompt_type type;
    heim_octet_string reply;
} hx509_prompt;

typedef int (*hx509_prompter_fct)(void *, const hx509_prompt *);

typedef struct hx509_octet_string_list {
    size_t len;
    heim_octet_string *val;
} hx509_octet_string_list;

/*
 * Options passed to hx509_query_match_option.
 */
typedef enum {
    HX509_QUERY_OPTION_PRIVATE_KEY = 1,
    HX509_QUERY_OPTION_KU_ENCIPHERMENT = 2,
    HX509_QUERY_OPTION_KU_DIGITALSIGNATURE = 3,
    HX509_QUERY_OPTION_KU_KEYCERTSIGN = 4,
    HX509_QUERY_OPTION_END = 0xffff
} hx509_query_option;

/* flags to hx509_certs_init */
#define HX509_CERTS_CREATE				0x01

/* flags to hx509_set_error_string */
#define HX509_ERROR_APPEND				0x01

/* flags to hx509_cms_unenvelope */
#define HX509_CMS_UE_DONT_REQUIRE_KU_ENCIPHERMENT	0x01

/* selectors passed to hx509_crypto_select and hx509_crypto_available */
#define HX509_SELECT_ALL 0
#define HX509_SELECT_DIGEST 1
#define HX509_SELECT_PUBLIC_SIG 2
#define HX509_SELECT_PUBLIC_ENC 3

/* flags to hx509_ca_tbs_set_template */
#define HX509_CA_TEMPLATE_SUBJECT 1
#define HX509_CA_TEMPLATE_SERIAL 2
#define HX509_CA_TEMPLATE_NOTBEFORE 4
#define HX509_CA_TEMPLATE_NOTAFTER 8
#define HX509_CA_TEMPLATE_SPKI 16
#define HX509_CA_TEMPLATE_KU 32
#define HX509_CA_TEMPLATE_EKU 64

/* flags hx509_cms_create_signed* */
#define HX509_CMS_SIGATURE_DETACHED 1

#include <hx509-protos.h>
