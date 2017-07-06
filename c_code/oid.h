#ifdef _WIN32
#include "windows/git2.h"
#else
#include "mac_os/git2.h"
#endif

#include <stdint.h>
#include "libgit_utils.h"




void oid(MEX_DEF_INPUT)
{
    int error;
    int sub_type = (int)mxGetScalar(prhs[1]);
    
    switch (sub_type) {
        case 0:
            //repository
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 7:
            break;
        case 10:
            break;
        case 13:
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","oid.h, input sub-type not recognized");
            
    }
}