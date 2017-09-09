//  libgit_utils.h

#ifndef LIBGIT_UTILS_H
#define LIBGIT_UTILS_H

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

//Output Handling
//----------------------------------------------
//TODO: Make this a macro

//SET_POINTER_OUTPUT(set_repo_output,git_repository)
//SET_POINTER_OUTPUT(set_remote_output,git_remote)


void set_repo_output(mxArray **output, git_repository *repo){   
    //
    //  set_repo_output(&plhs[0],repo);
    //
    
    *output = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);

    int64_t *p;
    p = (int64_t *) mxGetData(*output);
    *p = (int64_t)repo;
}

void set_remote_output(mxArray **output, git_remote *remote){   
    //
    //  set_remote_output(&plhs[0],remote);
    //
    
    *output = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);

    int64_t *p;
    p = (int64_t *) mxGetData(*output);
    *p = (int64_t)remote; 
}

//TODO: Move into c_to_mx
void set_signature_out(mxArray **output, const git_signature *s){
    //
    //  set_signature_out(&plhs[0],signature);
    //
    
// char *	name - full name of the author
// char *	email - email of the author
// git_time	when - time when the action happened
    
    
    //TODO: There might be a memory leak with the signature
    
    const char *fn[3];
    fn[0] = "name";
    fn[1] = "email";
    fn[2] = "when";
    
    *output = mxCreateStructMatrix(1,1,3,fn);
    
    mxSetFieldByNumber(*output,0,0,mxCreateString(s->name));
    mxSetFieldByNumber(*output,0,1,mxCreateString(s->email));
    mxSetFieldByNumber(*output,0,2,git_time__to_mx(s->when));
    
}

//-------------------------------------------------------------------------









void handle_error(int error,const char *caller){
   
    //caller -> like "libgit:remote:lookup_remote"
    if (error < 0){
        mexErrMsgIdAndTxt(caller,"Reported error: %d\n",error);
    }
    
}

#endif