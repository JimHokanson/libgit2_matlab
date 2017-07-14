#include "mex.h"

//https://libgit2.github.com/libgit2/#HEAD/group/clone

void clone2(MEX_DEF_INPUT){
    //1
    //
    //Clone a remote repository.
    //
    //int git_clone(git_repository **out, const char *url, 
    //      const char *local_path, const git_clone_options *options);
    
    
}

void clone_init_options(MEX_DEF_INPUT){
    //
    //Initializes a git_clone_options with default values. Equivalent to 
    //creating an instance with GIT_CLONE_OPTIONS_INIT.
    //
    //int git_clone_init_options(git_clone_options *opts, unsigned int version);

}

void clone(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            clone2(MEX_INPUT);
            break;
        case 2:
            clone_init_options(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","branch.h, input sub-type not recognized");
    }
}

//01 git_clone
//02 git_clone_init_options