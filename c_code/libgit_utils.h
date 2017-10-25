//  libgit_utils.h

#ifndef LIBGIT_UTILS_H
#define LIBGIT_UTILS_H

//https://stackoverflow.com/questions/22265610/why-ssize-t-in-visual-studio-2010-is-defined-as-unsigned
#if defined(_MSC_VER)
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;
#endif

#ifdef _WIN32
#include "windows/git2.h"
#else
#include "mac_os/git2.h"
#endif

#include <stdint.h>
#include <string.h>
#include "c_to_mx.h"
#include "mx_to_c.h"


#define MEX_INPUT nlhs, plhs, nrhs, prhs
#define MEX_DEF_INPUT int nlhs, mxArray *plhs[], int nrhs, const mxArray*prhs[]

//  libgit_utils.h

//Input Handling
//-----------------------------------------------


git_reference* get_reference_input(const mxArray *input){
    //
    //   git_repository* repo = get_reference_input(prhs[2]);
    //
    
    git_reference **p_ref = (git_reference **)mxGetData(input);
    return *p_ref;
}

git_oid* get_oid_input(const mxArray *input){
    //
    //  Input is Matlab managed byte array of oid
    
    return (git_oid *)mxGetData(input);
    
}


//-------------------------------------------------------------------------









void handle_error(int error,const char *caller){
   
    //caller -> like "libgit:remote:lookup_remote"
    if (error < 0){
        mexErrMsgIdAndTxt(caller,"Reported error: %d\n",error);
    }
    
    //https://github.com/libgit2/libgit2/blob/13c1bf0718363960c1867f35c9ce3ebc7bf74729/include/git2/errors.h
}

#endif