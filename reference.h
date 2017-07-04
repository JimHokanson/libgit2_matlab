#include "git2.h"
#include <stdint.h>
#include "libgit_utils.h"

void lookup_reference(MEX_DEF_INPUT){
    //
    //  Calling form:
    //  ref = mex(1,22,repo,ref_name);
    
    //int git_reference_lookup(git_reference **out, git_repository *repo, const char *name);
    git_repository *repo = get_repo_input(prhs[2]);
    const char *ref_name = mxArrayToString(prhs[3]);
    
    git_reference *ref = NULL;
    int error = git_reference_lookup(&ref, repo, ref_name);
    
    handle_error(error,"libgit:reference:lookup_reference");
    
    set_reference_output(&plhs[0],ref);
    mxFree((void *)ref_name);
}

void reference(MEX_DEF_INPUT)
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
            //Free Remote
            //mex(3,13,ref_pointer)
            git_reference_free(get_reference_input(prhs[2]));
            break;
        case 15:
            break;
        case 16:
            break;
        case 21:
            //remote_list(MEX_INPUT);
            break;
        case 22:
            //lookup_remote(MEX_INPUT);
            break;
        case 24:
            lookup_reference(MEX_INPUT);
            break;
        case 38:
            //get_remote_url(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","commit.h, input sub-type not recognized");
            
    }
}