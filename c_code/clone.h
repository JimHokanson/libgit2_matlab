#include "mex.h"

//https://libgit2.github.com/libgit2/#HEAD/group/clone

//14

void mx_to_git_clone_options(const mxArray *input,git_clone_options *s){
    
    mxArray *temp;
    
    //version                   unsigned int	
    //checkout_opts             git_checkout_options
    //fetch_opts                git_fetch_options
    //bare                      int
    //local                     git_clone_local_t
    //checkout_branch           const char *
    //repository_cb             git_repository_create_cb	
    //repository_cb_payload     void *
    //remote_cb                 git_remote_create_cb
    //remote_cb_payload         void *
    
//   checkout_opts.checkout_strategy = GIT_CHECKOUT_SAFE;
//   checkout_opts.progress_cb = checkout_progress;
//   checkout_opts.progress_payload = &pd;
//   clone_opts.checkout_opts = checkout_opts;
//   clone_opts.fetch_opts.callbacks.sideband_progress = sideband_progress;
//   clone_opts.fetch_opts.callbacks.transfer_progress = &fetch_progress;
//   clone_opts.fetch_opts.callbacks.credentials = cred_acquire_cb;
//   clone_opts.fetch_opts.callbacks.payload = &pd;
//     
    
}


void clone2(MEX_DEF_INPUT){
    //1 - Clone a remote repository.
    //
    //                0  1 2   3          4
    //  repo = libgit(14,1,url,local_path,options);
    //
    //int git_clone(git_repository **out, const char *url, 
    //      const char *local_path, const git_clone_options *options);    
    
    const git_clone_options *options;
    if (nrhs == 4){
        //convert ...
        options = GIT_CLONE_OPTIONS_INIT;
    }else if (nrhs == 3){
        options = GIT_CLONE_OPTIONS_INIT;
    }else{
        mexErrMsgIdAndTxt("libgit:clone:clone2",
                "Incorrect # of inputs, 3 or 4 expected");
    }
    
    const char *url = mx_to_char(prhs[2]);
    const char *local_path = mx_to_char(prhs[3]);
    
    git_repository *out;
    int response = git_clone(&out,url,local_path,options);
    handle_error(response,"libgit:clone:clone2");
    plhs[0] = git_repository__to_mx(out);
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