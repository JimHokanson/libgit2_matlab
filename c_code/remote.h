#ifdef _WIN32
#include "windows/git2.h"
#else
#include "mac_os/git2.h"
#endif

#include <stdint.h>
#include "libgit_utils.h"


#ifdef UNUSED
#elif defined(__GNUC__)
# define UNUSED(x) UNUSED_ ## x __attribute__((unused))
#elif defined(__LCLINT__)
# define UNUSED(x) /*@unused@*/ x
#else
# define UNUSED(x) x
#endif

//TODO: Can we make credentials p

static char *remote_username;
static char *remote_password;

int default_remote_callback (git_cred **out,
                    const char * UNUSED(url),
                    const char * UNUSED(username_from_url),
                    unsigned int UNUSED(allowed_types),
                    void * UNUSED(payload))
{
    //This callback is meant to handle the case where the user 
    //specifies their credentials up front.
    
    //https://libgit2.github.com/libgit2/#HEAD/group/cred

	int error;
    
    //TODO: Eventually allow multiple cred options.
	error = git_cred_userpass_plaintext_new(out, remote_username, remote_password);
    
    //TODO: This might be better in fetch or push. I'm not sure if this
    //callback would ever be called twice, in which case the second
    //time the variable would be freed
    mxFree((void *)remote_username);
    mxFree((void *)remote_password);
    
	return error;
}






void remote_add_fetch(MEX_DEF_INPUT){
    //1
    //int git_remote_add_fetch(git_repository *repo, const char *remote, const char *refspec);
}

void remote_add_push(MEX_DEF_INPUT){
    //2
    //int git_remote_add_push(git_repository *repo, const char *remote, const char *refspec);
}

void remote_autotag(MEX_DEF_INPUT){
    //3
    //
    //Retrieve the tag auto-follow setting
    //
    //git_remote_autotag_option_t git_remote_autotag(const git_remote *remote);
}

void remote_connect(MEX_DEF_INPUT){
    //4
    //int git_remote_connect(git_remote *remote, git_direction direction, 
    //const git_remote_callbacks *callbacks, const git_proxy_options *proxy_opts, 
    //const git_strarray *custom_headers);
    
    //The transport is selected based on the URL. The direction argument is 
    //due to a limitation of the git protocol (over TCP or SSH) which 
    //starts up a specific binary which can only do the one or the other.
}

void remote_connected(MEX_DEF_INPUT){
    //5
    //int git_remote_connected(const git_remote *remote);
}

void remote_create(MEX_DEF_INPUT){
    //6
}

void remote_create_anonymous(MEX_DEF_INPUT){
    //7
}

void remote_create_with_fetchspec(MEX_DEF_INPUT){
    //8
}

void remote_default_branch(MEX_DEF_INPUT){
    //9
}

void remote_delete(MEX_DEF_INPUT){
    //10
}

void remote_disconnect(MEX_DEF_INPUT){
    //11
}

void remote_download(MEX_DEF_INPUT){
    //12
    //
    //  => most likely better to use fetch
    //  fetch
    //      - download
    //      - update tips
    //
    //https://stackoverflow.com/questions/27759674/libgit2-fetch-merge-commit
}

void remote_dup(MEX_DEF_INPUT){
    //13
}

void remote_fetch(MEX_DEF_INPUT){
    //
    //  Calling Form:
    //  mex(1,14,remote) 
    //
    //  (remote,refspecs,options,reflog_message)
    
    
    

    //int git_remote_fetch(git_remote *remote, const git_strarray *refspecs, 
    //      const git_fetch_options *opts, const char *reflog_message);
    git_remote *remote = get_remote_input(prhs[2]);
    int error = git_remote_fetch(remote,NULL,NULL,NULL);
}

void remote_list(MEX_DEF_INPUT){
    //
    //  Calling Form:
    //  list = mex(1,21,repo)
    
    //int git_remote_list(git_strarray *out, git_repository *repo);   
    
    git_repository *repo = get_repo_input(prhs[2]);
    git_strarray remotes = {0};
    int error = git_remote_list(&remotes,repo);
    handle_error(error,"libgit:remote:remote_list");
    plhs[0] = git_strarray__to_mx(&remotes,1);
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

void get_fetch_options(MEX_DEF_INPUT){
    //
    // 1,39
    
    git_fetch_options opts;
    git_fetch_init_options(&opts,GIT_FETCH_OPTIONS_VERSION);
    plhs[0] = git_fetch_options__to_mx(&opts);
    
}

void remote(MEX_DEF_INPUT)
{
    int error;
    int sub_type = (int)mxGetScalar(prhs[1]);
    
    switch (sub_type) {
        case 1:
            //git_remote_add_fetch
            break;
        case 2:
            //git_remote_add_push
            break;
        case 3:
            //git_remote_autotag
            break;
        case 4:
            //git_remote_connect
            break;
        case 5:
            //git_remote_connected
            break;
        case 6:
            //git_remote_create
            break;
        case 7:
            //git_remote_create_anonymous
            break;
        case 8:
            //git_remote_create_with_fetchspec
            break;
        case 9:
            //git_remote_default_branch
            break;
        case 10:
            //git_remote_delete
            break;
        case 11:
            //git_remote_disconnect
            break;
        case 12:
            //git_remote_download
            break;
        case 13:
            //git_remote_dup
            break;
        case 14:
            //git_remote_fetch
            remote_fetch(MEX_INPUT);
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
        case 35:
            //git_remote_stop
            //
            //  Only works within network callbacks ...
            break;
        case 38:
            get_remote_url(MEX_INPUT);
            break;
        case 39:
            get_fetch_options(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","remote.h, input sub-type not recognized");
            
    }
}

// %01 git_remote_add_fetch
// %02 git_remote_add_push
// %03 git_remote_autotag
// %04 git_remote_connect - Open a connection to a remote
// %05 git_remote_connected
// %06 git_remote_create
// %07 git_remote_create_anonymous
// %08 git_remote_create_with_fetchspec
// %09 git_remote_default_branch
// %10 git_remote_delete
// %11 git_remote_disconnect
// %12 git_remote_download
// %13 git_remote_dup
// x 14 git_remote_fetch
// x 15 git_remote_free
// %16 git_remote_get_fetch_refspecs
// %17 git_remote_get_push_refspecs
// %18 git_remote_get_refspec
// %19 git_remote_init_callbacks
// %20 git_remote_is_valid_name
// %21 git_remote_list
// %x 22 git_remote_lookup
// %23 git_remote_ls
// %24 git_remote_name
// %25 git_remote_owner
// %26 git_remote_prune
// %27 git_remote_prune_refs
// %28 git_remote_push
// %29 git_remote_refspec_count
// %30 git_remote_rename
// %31 git_remote_set_autotag
// %32 git_remote_set_pushurl
// %33 git_remote_set_url
// %34 git_remote_stats - Get the statistics structure that is filled in by the fetch operation.
// %35 git_remote_stop 
// %36 git_remote_update_tips - update the tips to the new state
// %37 git_remote_upload
// %x 38 git_remote_url