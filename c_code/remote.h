#ifdef _WIN32
#include "windows/git2.h"
#else
#include "mac_os/git2.h"
#endif

#include <stdint.h>
#include "libgit_utils.h"

void remote_list(MEX_DEF_INPUT){
    //
    //  Calling Form:
    //  list = mex(1,21,repo)
    
    //int git_remote_list(git_strarray *out, git_repository *repo);   
    
    git_repository *repo = get_repo_input(prhs[2]);
    git_strarray remotes = {0};
    int error = git_remote_list(&remotes,repo);
    handle_error(error,"libgit:remote:remote_list");
    set_strarray_out(&plhs[0],&remotes);
}

void lookup_remote(MEX_DEF_INPUT){
    //
    //  Calling form:
    //  remote = mex(1,22,repo,remote_name);
    
        
    //int git_remote_lookup(git_remote **out, git_repository *repo, const char *name);
    int error;
    git_repository *repo = get_repo_input(prhs[2]);
    const char *remote_name = mxArrayToString(prhs[3]);
    
    git_remote *remote = NULL;
    error = git_remote_lookup(&remote, repo, remote_name);
    
    handle_error(error,"libgit:remote:lookup_remote");
    
    set_remote_output(&plhs[0],remote);
    
    mxFree((void *)remote_name);
}

void get_remote_url(MEX_DEF_INPUT){
    //
    //  Calling form:
    //  url = mex(1,#,remote)
    //
    //const char * git_remote_url(const git_remote *remote);
    
    const git_remote *remote = get_remote_input(prhs[2]);
    const char *url = git_remote_url(remote);
    plhs[0] = mxCreateString(url);
}

void remote(MEX_DEF_INPUT)
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
            git_remote_free(get_remote_input(prhs[2]));
            break;
        case 21:
            remote_list(MEX_INPUT);
            break;
        case 22:
            lookup_remote(MEX_INPUT);
            break;
        case 38:
            get_remote_url(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","remote.h, input sub-type not recognized");
            
    }
}