#ifndef LIBGIT_UTILS_H
#define LIBGIT_UTILS_H

//#include "git2.h" 
#include <stdint.h>
#include <string.h>
#include "c_to_mx.h"


#define MEX_INPUT nlhs, plhs, nrhs, prhs
#define MEX_DEF_INPUT int nlhs, mxArray *plhs[], int nrhs, const mxArray*prhs[]

//  libgit_utils.h

//Input Handling
//-----------------------------------------------
//TODO: Make these macros
git_repository* get_repo_input(const mxArray *input){
    //
    //   git_repository* repo = get_repo_input(prhs[2]);
    //
    
    git_repository **p_repo = (git_repository **)mxGetData(input);
    return *p_repo;
}

git_remote* get_remote_input(const mxArray *input){
    //
    //   git_remote* repo = get_remote_input(prhs[2]);
    //
    
    git_remote **p_remote = (git_remote **)mxGetData(input);
    return *p_remote;
}

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

git_commit* get_commit_input(const mxArray *input){
    //
    //   git_commit* commit = get_commit_input(prhs[2]);
    //
    
    git_commit **p_ref = (git_commit **)mxGetData(input);
    return *p_ref;
}

//Output Handling
//----------------------------------------------
//TODO: Make this a macro

//SET_POINTER_OUTPUT(set_repo_output,git_repository)
//SET_POINTER_OUTPUT(set_remote_output,git_remote)

void set_oid_output(mxArray **output, const git_oid *oid){
    //
    //  set_oid_output(&plhs[0],oid);
    //
    
    *output = mxCreateNumericMatrix(1,sizeof(*oid),mxUINT8_CLASS,mxREAL);
    uint8_t *temp = (uint8_t *)mxGetData(*output);
    memcpy(temp,oid,sizeof(*oid));
}

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

void set_reference_output(mxArray **output, git_reference *ref){   
    //
    //  set_reference_output(&plhs[0],ref);
    //
    
    *output = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);

    int64_t *p;
    p = (int64_t *) mxGetData(*output);
    *p = (int64_t)ref; 
}

void set_commit_output(mxArray **output, git_commit *commit){
    //
    //  set_reference_output(&plhs[0],commit);
    //
    
    *output = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);

    int64_t *p;
    p = (int64_t *) mxGetData(*output);
    *p = (int64_t)commit; 
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