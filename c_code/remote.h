
#include <stdint.h>
#include "libgit_utils.h"


//For callbacks to mark parameters as unused
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
    //
    //TODO: Document usage
    
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

//=========================================================================

void remote_add_fetch(MEX_DEF_INPUT){
    //1
    //
    //Add a fetch refspec to the remote's configuration
    //
    //int git_remote_add_fetch(git_repository *repo, const char *remote, const char *refspec);
}

void remote_add_push(MEX_DEF_INPUT){
    //2
    //
    //Add a push refspec to the remote's configuration
    //
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
    //
    //  mex(1,4,remote,is_fetch)
    //
    //int git_remote_connect(git_remote *remote, git_direction direction, 
    //      const git_remote_callbacks *callbacks, const git_proxy_options *proxy_opts, 
    //      const git_strarray *custom_headers);
    
    //The transport is selected based on the URL. The direction argument is 
    //due to a limitation of the git protocol (over TCP or SSH) which 
    //starts up a specific binary which can only do the one or the other.
    
    //Inputs
    //----------------------
    //remote
    //direction : GIT_DIRECTION_FETCH
    //remote_callbacks : git_remote_callbacks
    //proxy_options : git_proxy_options
    //custom_headers : git_strarray
    
    git_remote *remote = mx_to_git_remote(prhs[2]);
    int error = git_remote_connect(remote,GIT_DIRECTION_FETCH,NULL,NULL,NULL);
    handle_error(error,"libgit:remote:remote_connect");

}

void remote_connected(MEX_DEF_INPUT){
    //5
    //
    // connected = mex(1,5)
    //
    //int git_remote_connected(const git_remote *remote);
    
    git_remote *remote = mx_to_git_remote(prhs[2]);
    int connected = git_remote_connected(remote);
    plhs[0] = int32__to_mx(connected);
}

void remote_create(MEX_DEF_INPUT){
    //6
    //
    //Add a remote with the default fetch refspec to the repository's configuration.
    //
    //int git_remote_create(git_remote **out, git_repository *repo, 
    //          const char *name, const char *url);

}

void remote_create_anonymous(MEX_DEF_INPUT){
    //7
    //
    //Create an anonymous remote
    //
    //int git_remote_create_anonymous(git_remote **out, 
    //              git_repository *repo, const char *url);
}

void remote_create_with_fetchspec(MEX_DEF_INPUT){
    //8
    //
    //Add a remote with the provided fetch refspec (or default if NULL) to 
    //the repository's configuration.
    //
    //int git_remote_create_with_fetchspec(git_remote **out, git_repository *repo, 
    //      const char *name, const char *url, const char *fetch);
}

void remote_default_branch(MEX_DEF_INPUT){
    //9
    //
    //  mex(1,9,remote);
    //
    //Retrieve the name of the remote's default branch
    //
    //int git_remote_default_branch(git_buf *out, git_remote *remote);

    git_remote *remote = mx_to_git_remote(prhs[2]);
    
}

void remote_delete(MEX_DEF_INPUT){
    //10
    //
    //Delete an existing persisted remote.
    //
    //int git_remote_delete(git_repository *repo, const char *name);


}

void remote_disconnect(MEX_DEF_INPUT){
    //11
    //
    //  
    //
    //Disconnect from the remote
    //
    //void git_remote_disconnect(git_remote *remote);
    
    git_remote *remote = mx_to_git_remote(prhs[2]);
    git_remote_disconnect(remote);

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
    //
    //Download and index the packfile
    //
    //int git_remote_download(git_remote *remote, const git_strarray *refspecs, 
    //          const git_fetch_options *opts);


}

void remote_dup(MEX_DEF_INPUT){
    //13
    //
    //  Create a copy of an existing remote. All internal strings are 
    //  also duplicated. 
    //  Callbacks are not duplicated.
    //
    //  int git_remote_dup(git_remote **dest, git_remote *source);


}

void remote_fetch(MEX_DEF_INPUT){
    //14 - HALF DONE
    //
    //  Calling Form:
    //  mex(1,14,remote) 
    //
    //  (remote,refspecs,options,reflog_message)
    
    //int git_remote_fetch(git_remote *remote, const git_strarray *refspecs, 
    //      const git_fetch_options *opts, const char *reflog_message);
    git_remote *remote = mx_to_git_remote(prhs[2]);
    
    //TODO: Suport options
    //
    //  refspecs
    //  fetch_options
    //  reflog_message
    
    
    int error = git_remote_fetch(remote,NULL,NULL,NULL);
}

void remote_free(MEX_DEF_INPUT){
    //15 - DONE
    //
  	//  Free Remote
	//  mex(1,15,remote_pointer)
    //
    
	git_remote_free(mx_to_git_remote(prhs[2]));
}

void remote_get_fetch_refspecs(MEX_DEF_INPUT){
    //16
    //
    //  mex(1,16,remote);
    //
    //Get the remote's list of fetch refspecs
    //
    //  int git_remote_get_fetch_refspecs(git_strarray *array, 
    //              const git_remote *remote);
    
    git_remote *remote = mx_to_git_remote(prhs[2]);
    git_strarray array;
    int error = git_remote_get_fetch_refspecs(&array,remote);
    git_strarray__to_mx(&array,true);
}

void remote_get_push_refspecs(MEX_DEF_INPUT){
    //17
    //
    //Get the remote's list of push refspecs
    //
    //  int git_remote_get_push_refspecs(git_strarray *array, 
    //              const git_remote *remote);


}

void remote_get_refspec(MEX_DEF_INPUT){
    //18
    //
    //Get a refspec from the remote
    //
    //  const git_refspec * git_remote_get_refspec(const git_remote *remote, 
    //              size_t n);


}

void remote_init_callbacks(MEX_DEF_INPUT){
    //19
    //
    //      mex(1,19,...)
    //
    //Initializes a git_remote_callbacks with default values. Equivalent to 
    //creating an instance with GIT_REMOTE_CALLBACKS_INIT.
    //
    //int git_remote_init_callbacks(git_remote_callbacks *opts, unsigned int version);

}

void remote_is_valid_name(MEX_DEF_INPUT){
    //20
    //
    //Ensure the remote name is well-formed.
    //
    //  is_valid = mex(1,20,remote_name)
    //
    //int git_remote_is_valid_name(const char *remote_name);

    const char * remote_name = mxArrayToString(prhs[2]);
    int is_valid = git_remote_is_valid_name(remote_name);
    plhs[0] = int32__to_mx(is_valid);
    mxFree((void *)remote_name);

}

void remote_list(MEX_DEF_INPUT){
    //21 - DONE
    //  
    //  list = mex(1,21,repo)
    
    //int git_remote_list(git_strarray *out, git_repository *repo);   
    
    git_repository *repo = mx_to_git_repo(prhs[2]);
    git_strarray remotes = {0};
    int error = git_remote_list(&remotes,repo);
    handle_error(error,"libgit:remote:remote_list");
    plhs[0] = git_strarray__to_mx(&remotes,1);
}

void remote_lookup(MEX_DEF_INPUT){
    //22 - DONE
    //
    //  remote = mex(1,22,repo,remote_name);
    //
    
        
    //int git_remote_lookup(git_remote **out, git_repository *repo, const char *name);
    
    git_repository *repo = mx_to_git_repo(prhs[2]);
    const char *remote_name = mxArrayToString(prhs[3]);
    
    git_remote *remote = NULL;
    int response = git_remote_lookup(&remote, repo, remote_name);
    
    handle_error(response,"libgit:remote:remote_lookup");
    
    //TODO: Change format
    plhs[0] = git_remote__to_mx(remote);
    
    mxFree((void *)remote_name);
}

void remote_ls(MEX_DEF_INPUT){
    //23
    //
    //  ? = mex(1,23,remote);
    //
    //Get the remote repository's reference advertisement list
       
    //Get the list of references with which the server responds to a new connection.
    //
    //The remote (or more exactly its transport) must have connected to the 
    //remote repository. This list is available as soon as the connection 
    //to the remote is initiated and it remains available after disconnecting.
    //
    //The memory belongs to the remote. The pointer will be valid as long 
    //as a new connection is not initiated, but it is recommended that you 
    //make a copy in order to make use of the data.
    
    git_remote *remote = mx_to_git_remote(prhs[2]);
    
    const git_remote_head **out;
    size_t size;
    
    //int git_remote_ls(const git_remote_head ***out, size_t *size, git_remote *remote);
    int error = git_remote_ls(&out, &size, remote);
    
    handle_error(error,"libgit:remote:remote_ls");
    
    plhs[0] = git_remote_head__to_mx(out, size);

}

void remote_name(MEX_DEF_INPUT){
    //24
    //
    //      name = (1,24,remote)
    //
    //      Get the remote's name
    //
    //const char * git_remote_name(const git_remote *remote);

    git_remote *remote = mx_to_git_remote(prhs[2]);
    const char * remote_name = git_remote_name(remote);
    plhs[0] = mxCreateString(remote_name);
}

void remote_owner(MEX_DEF_INPUT){
    //25
    //
    //  repo = mex(1,25,remote)
    //
    //      Get the remote's repository
    //
    //      git_repository * git_remote_owner(const git_remote *remote);

    git_repository *repo;
    git_remote *remote = mx_to_git_remote(prhs[2]);
    repo = git_remote_owner(remote);


}

void remote_prune(MEX_DEF_INPUT){
    //26
    //
    //Prune tracking refs that are no longer present on remote
    //
    //int git_remote_prune(git_remote *remote, const git_remote_callbacks *callbacks);


}

void remote_prune_refs(MEX_DEF_INPUT){
    //27
    //
    //Retrieve the ref-prune setting
    //
    //int git_remote_prune_refs(const git_remote *remote);


}

void remote_push(MEX_DEF_INPUT){
    //28
    //
    //Perform a push
    //
    //int git_remote_push(git_remote *remote, const git_strarray *refspecs, 
    //      const git_push_options *opts);

}

void remote_refspec_count(MEX_DEF_INPUT){
    //29
    //
    //Get the number of refspecs for a remote
    //
    //size_t git_remote_refspec_count(const git_remote *remote);


}

void remote_rename(MEX_DEF_INPUT){
    //30
    //
    //Give the remote a new name
    //
    //int git_remote_rename(git_strarray *problems, git_repository *repo, 
    //  const char *name, const char *new_name);

}

void remote_set_autotag(MEX_DEF_INPUT){
    //31
    //
    //Set the remote's tag following setting.
    //
    //int git_remote_set_autotag(git_repository *repo, const char *remote, 
    //          git_remote_autotag_option_t value);

}

void remote_set_pushurl(MEX_DEF_INPUT){
    //32
    //
    //Set the remote's url for pushing in the configuration.
    //
    //int git_remote_set_pushurl(git_repository *repo, const char *remote, const char *url);

}

void remote_set_url(MEX_DEF_INPUT){
    //33
    //
    //Set the remote's url in the configuration
    //
    //int git_remote_set_url(git_repository *repo, const char *remote, const char *url);
         

}

void remote_stats(MEX_DEF_INPUT){
    //34
    //
    //Get the statistics structure that is filled in by the fetch operation.
    //
    //const git_transfer_progress * git_remote_stats(git_remote *remote);

    git_remote *remote = mx_to_git_remote(prhs[2]);
    
    const git_transfer_progress * git_remote_stats(git_remote *remote);
    
}

// void (MEX_DEF_INPUT){
//     //35
// }

void remote_update_tips(MEX_DEF_INPUT){
    //36
    //
    //Update the tips to the new state
    //
    //int git_remote_update_tips(git_remote *remote, const git_remote_callbacks *callbacks, 
    //int update_fetchhead, git_remote_autotag_option_t download_tags, 
    //const char *reflog_message);

}

void remote_upload(MEX_DEF_INPUT){
    //37
    //
    //Create a packfile and send it to the server
    //
    //int git_remote_upload(git_remote *remote, const git_strarray *refspecs,
    //  const git_push_options *opts);


}

void remote_url(MEX_DEF_INPUT){
    //
    //  Calling form:
    //  url = mex(1,38,remote)
    //
    //const char * git_remote_url(const git_remote *remote);
    
    const git_remote *remote = mx_to_git_remote(prhs[2]);
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
            remote_add_fetch(MEX_INPUT);
            break;
        case 2:
            //git_remote_add_push
            remote_add_push(MEX_INPUT);
            break;
        case 3:
            //git_remote_autotag
            remote_autotag(MEX_INPUT);
            break;
        case 4:
            //git_remote_connect
            remote_connect(MEX_INPUT);
            break;
        case 5:
            //git_remote_connected
            remote_connected(MEX_INPUT);
            break;
        case 6:
            //git_remote_create
            remote_create(MEX_INPUT);
            break;
        case 7:
            //git_remote_create_anonymous
            remote_create_anonymous(MEX_INPUT);
            break;
        case 8:
            //git_remote_create_with_fetchspec
            remote_create_with_fetchspec(MEX_INPUT);
            break;
        case 9:
            //git_remote_default_branch
            remote_default_branch(MEX_INPUT);
            break;
        case 10:
            //git_remote_delete
            remote_delete(MEX_INPUT);
            break;
        case 11:
            //git_remote_disconnect
            remote_disconnect(MEX_INPUT);
            break;
        case 12:
            //git_remote_download
            remote_download(MEX_INPUT);
            break;
        case 13:
            //git_remote_dup
            remote_dup(MEX_INPUT);
            break;
        case 14:
            //git_remote_fetch
            remote_fetch(MEX_INPUT);
            break;
        case 15:
            //git_remote_free
            remote_free(MEX_INPUT);
            break;
        case 16:
            //git_remote_get_fetch_refspecs
            remote_get_fetch_refspecs(MEX_INPUT);
            break;
        case 17:
            //git_remote_get_push_refspecs
            remote_get_push_refspecs(MEX_INPUT);
            break;
        case 18:
            //git_remote_get_refspec
            remote_get_refspec(MEX_INPUT);
            break;
        case 19:
            //git_remote_init_callbacks
            remote_init_callbacks(MEX_INPUT);
            break;
        case 20:
            //git_remote_is_valid_name
            remote_is_valid_name(MEX_INPUT);
            break;
        case 21:
            //git_remote_list
            remote_list(MEX_INPUT);
            break;
        case 22:
            remote_lookup(MEX_INPUT);
            break;
        case 23:
            //git_remote_ls
            remote_ls(MEX_INPUT);
            break;
        case 24:
            //git_remote_name
            remote_name(MEX_INPUT);
            break;
        case 25:
            //git_remote_owner
            remote_owner(MEX_INPUT);
            break;
        case 26:
            //git_remote_prune
            remote_prune(MEX_INPUT);
            break;
        case 27:
            //git_remote_prune_refs
            remote_prune_refs(MEX_INPUT);
            break;
        case 28:
            //git_remote_push
            remote_push(MEX_INPUT);
            break;
        case 29:
            //git_remote_refspec_count
            remote_refspec_count(MEX_INPUT);
            break;
        case 30:
            //git_remote_rename
            remote_rename(MEX_INPUT);
            break;
        case 31:
            //git_remote_set_autotag
            remote_set_autotag(MEX_INPUT);
            break;
        case 32:
            //git_remote_set_pushurl
            remote_set_pushurl(MEX_INPUT);
            break;
        case 33:
            //git_remote_set_url
            remote_set_url(MEX_INPUT);
            break;
        case 34:
            //git_remote_stats
            remote_stats(MEX_INPUT);
            break;
        case 35:
            //git_remote_stop
            //
            //  Only works within network callbacks ...
            break;
        case 36:
            //git_remote_update_tips
            remote_update_tips(MEX_INPUT);
            break;
        case 37:
            //git_remote_upload
            remote_upload(MEX_INPUT);
            break;
        case 38:
            remote_url(MEX_INPUT);
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