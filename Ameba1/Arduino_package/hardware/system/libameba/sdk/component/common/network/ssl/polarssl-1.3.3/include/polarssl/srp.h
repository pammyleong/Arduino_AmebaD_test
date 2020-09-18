#ifndef POLARSSL_SRP_H
#define POLARSSL_SRP_H

#include "bignum.h"

/**
 * \brief          SRP context structure
 */
typedef struct
{
    mpi N;                          /*!<  prime                  */
    mpi g;                          /*!<  generator              */
    mpi s;                          /*!<  salt                   */
    mpi v;                          /*!<  verifier               */
    mpi B;                          /*!<  server's public value  */
    mpi b;                          /*!<  server's private value */
    mpi A;                          /*!<  client's public value  */
    mpi a;                          /*!<  client's private value */
}
srp_context;

#endif
