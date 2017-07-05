#ifdef _WIN32
#include "windows/git2.h"
#else
#include "mac_os/git2.h"
#endif

#include <stdint.h>
#include "libgit_utils.h"

void open_repo(MEX_DEF_INPUT){
    
    int error;
    git_repository *repo = NULL;
    
    const char *file_path = mxArrayToString(prhs[2]);
    error = git_repository_open(&repo,file_path);
    handle_error(error,"libgit:repo:open_repo");

    
    mxFree((void *)file_path);    
    set_repo_output(&plhs[0],repo);
  
}

void repo(MEX_DEF_INPUT)
{
        
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
            //  Free repository
            //  (0,7,repo_pointer)
            
            //git_repository_free(git_repository *repo)
            git_repository_free(get_repo_input(prhs[2]));
            break;
        case 26:
            //int git_repository_open(git_repository **out, const char *path);
            
            //TODO: Verify file_path
            
            //Calling Form
            //
            //  repo = mex(0,26,file_path)
            open_repo(nlhs, plhs, nrhs, prhs);            
            
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","repo.h, input sub-type not recognized");
    }
    
}

