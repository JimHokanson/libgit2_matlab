#include "mex.h"

//I don't know that we will ever use this 

//https://libgit2.github.com/libgit2/#HEAD/group/giterr

void giterr(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            (MEX_INPUT);
            break;
        case 2:
            (MEX_INPUT);
            break;
        case 3:
            (MEX_INPUT);
            break;
        case 4:
            (MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:giterr","giterr.h, input sub-type not recognized");
    }
}

//1 giterr_clear
//2 giterr_last
//3 giterr_set_oom
//4 giterr_set_str