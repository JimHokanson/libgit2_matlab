#include "mex.h"
#include "libgit_utils.h"

//https://libgit2.github.com/libgit2/#HEAD/group/revparse

void revparse2(MEX_DEF_INPUT){
    //1
    //
    //Parse a revision string for from, to, and intent.
    //
    //int git_revparse(git_revspec *revspec, git_repository *repo, const char *spec);

}

void revparse_ext(MEX_DEF_INPUT){
    //2
    //
    //Find a single object and intermediate reference by a revision string.
    //
    //  int git_revparse_ext(git_object **object_out, git_reference **reference_out, 
    //          git_repository *repo, const char *spec);

}

void revparse_single(MEX_DEF_INPUT){
    //3
    //
    //Find a single object, as specified by a revision string.
    //
    //int git_revparse_single(git_object **out, git_repository *repo, const char *spec);

}

void revparse(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            revparse2(MEX_INPUT);
            break;
        case 2:
            revparse_ext(MEX_INPUT);
            break;
        case 3:
            revparse_single(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","revparse.h, input sub-type not recognized");
    }
}

//1 git_revparse
//2 git_revparse_ext
//3 git_revparse_single