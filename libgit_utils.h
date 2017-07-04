#ifndef LIBGIT_UTILS_H
#define LIBGIT_UTILS_H

#include "git2.h" 
#include <stdint.h>
#include "libgit_utils.h"


#define MEX_INPUT nlhs, plhs, nrhs, prhs
#define MEX_DEF_INPUT int nlhs, mxArray *plhs[], int nrhs, const mxArray*prhs[]

//  libgit_utils.h

//Input Handling
//-----------------------------------------------
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

void set_remote_output(mxArray **output,git_remote *remote){   
    //
    //  set_remote_output(&plhs[0],remote);
    //
    
    *output = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);

    int64_t *p;
    p = (int64_t *) mxGetData(*output);
    *p = (int64_t)remote; 
 }

void handle_error(int error,const char *caller){
   
    //caller -> like "libgit:remote:lookup_remote"
    if (error < 0){
        mexErrMsgIdAndTxt(caller,"Reported error: %d\n",error);
    }
    
}

#endif