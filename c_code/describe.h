#include "mex.h"

//https://libgit2.github.com/libgit2/#HEAD/group/describe
//
//https://git-scm.com/docs/git-describe

//17

void (MEX_DEF_INPUT){
}
void (MEX_DEF_INPUT){
}
void (MEX_DEF_INPUT){
}
void (MEX_DEF_INPUT){
}


void branch(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            describe_commit(MEX_INPUT);
            break;
        case 2:
            describe_format(MEX_INPUT);
            break;
        case 3:
            describe_result_free(MEX_INPUT);
            break;
        case 4:
            describe_workdir(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","branch.h, input sub-type not recognized");
    }
}

//1 git_describe_commit
//2 git_describe_format
//3 git_describe_result_free
//4 git_describe_workdir

