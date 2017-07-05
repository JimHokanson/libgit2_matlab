#ifdef _WIN32
#include "windows/git2.h"
#else
#include "mac_os/git2.h"
#endif

#include <stdint.h>
#include "libgit_utils.h"

void lookup_commit(MEX_DEF_INPUT){
    //
    //  Calling form:
    //  remote = mex(1,22,repo,oid);
    
        
    //int git_commit_lookup(git_commit **commit, git_repository *repo, const git_oid *id);    int error;
    git_repository *repo = get_repo_input(prhs[2]);
    
    
    const char *remote_name = mxArrayToString(prhs[3]);
    
//     git_remote *remote = NULL;
//     error = git_remote_lookup(&remote, repo, remote_name);
//     
//     handle_error(error,"libgit:remote:lookup_remote");
//     
//     set_remote_output(&plhs[0],remote);
//     
//     mxFree((void *)remote_name);
}

void commit(MEX_DEF_INPUT)
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
        case 15:
            //Free Remote
            //mex(1,10,remote_pointer)
            //git_remote_free(get_remote_input(prhs[2]));
            break;
        case 16:
            break;
        case 21:
            //remote_list(MEX_INPUT);
            break;
        case 22:
            //lookup_remote(MEX_INPUT);
            break;
        case 38:
            //get_remote_url(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","commit.h, input sub-type not recognized");
            
    }
}