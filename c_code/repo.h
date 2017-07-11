#ifdef _WIN32
#include "windows/git2.h"
#else
#include "mac_os/git2.h"
#endif

#include <stdint.h>
#include "libgit_utils.h"


//We won't call this directly
//- needs sys/repository
//
// void repository_cleanup(MEX_DEF_INPUT){
//     //1
//     //  mex(0,1,repo)
//     //Reset all the internal state in a repository.
//     //void git_repository__cleanup(git_repository *repo);
//     
//     //TODO: Add on # inputs check 
//     git_repository__cleanup(mx_to_git_repo(prhs[2]));
// }

void repository_commondir(MEX_DEF_INPUT){
    //2
    //
    //  dir = mex(0,2,repo)
    //
    //Get the path of the shared common directory for this repository
    //const char * git_repository_commondir(git_repository *repo);
    
    git_repository *repo = mx_to_git_repo(prhs[2]);
    plhs[0] = mxCreateString(git_repository_commondir(repo));
}

void repository_config(MEX_DEF_INPUT){
    //3
    //
    //  config = mex(0,3,repo)
    //
    //Get the configuration file for this repository.
    //
    //int git_repository_config(git_config **out, git_repository *repo);
}

void repository_config_snapshot(MEX_DEF_INPUT){
    //4
    //
    //Get a snapshot of the repository's configuration
    //
    //int git_repository_config_snapshot(git_config **out, git_repository *repo);
}

void repository_detach_head(MEX_DEF_INPUT){
    //5
    //
	//Detach the HEAD.
    //
    //int git_repository_detach_head(git_repository *repo);
}


void repository_discover(MEX_DEF_INPUT){
    //6
    //
    //Look for a git repository and copy its path in the given buffer. The 
    //lookup start from base_path and walk across parent directories if 
    //nothing has been found. The lookup ends when the first repository 
    //is found, or when reaching a directory referenced in ceiling_dirs or 
    //when the filesystem changes (in case across_fs is true).
    //
    //int git_repository_discover(git_buf *out, const char *start_path, 
    //      int across_fs, const char *ceiling_dirs);
}


void repository_fetchhead_foreach(MEX_DEF_INPUT){
    //7
    //
    //  Invoke 'callback' for each entry in the given FETCH_HEAD file.
    //
    //int git_repository_fetchhead_foreach(git_repository *repo, 
    //      git_repository_fetchhead_foreach_cb callback, void *payload);
}

void repository_free(MEX_DEF_INPUT){
    //8
    //  Free repository
            //  mex(0,8,repo_pointer)
            //TODO: Verify repo pointer
            //TODO: Check for input not being zero
            //git_repository_free(git_repository *repo)
    git_repository_free(mx_to_git_repo(prhs[2]));
}

void repository_get_namespace(MEX_DEF_INPUT){
    //9
    //
    //Get the currently active namespace for this repository
    //
    //const char * git_repository_get_namespace(git_repository *repo);
}

void repository_hashfile(MEX_DEF_INPUT){
    //10
    //
    //Calculate hash of file using repository filtering rules.
    //
    //int git_repository_hashfile(git_oid *out, git_repository *repo, 
    //          const char *path, git_otype type, const char *as_path);
}

void repository_head(MEX_DEF_INPUT){
    //11
    //
    //Retrieve and resolve the reference pointed at by HEAD.
    //
    //int git_repository_head(git_reference **out, git_repository *repo);
}

void repository_head_detached(MEX_DEF_INPUT){
    //12
    //
    //Check if a repository's HEAD is detached
    //
    //int git_repository_head_detached(git_repository *repo);
}

void repository_head_for_worktree(MEX_DEF_INPUT){
    //13
    //
    //Retrieve the referenced HEAD for the worktree
    //
    //int git_repository_head_for_worktree(git_reference **out, 
    //          git_repository *repo, const char *name);
}

void repository_head_unborn(MEX_DEF_INPUT){
    //14
    //
    //Check if the current branch is unborn
    //
    //int git_repository_head_unborn(git_repository *repo);
}

void repository_ident(MEX_DEF_INPUT){
    //15
    //
    //Retrieve the configured identity to use for reflogs
    //
    //int git_repository_ident(const char **name, const char **email,
    //      const git_repository *repo);
}

void repository_index(MEX_DEF_INPUT){
    //16
    //
    //Get the Index file for this repository.
    //
    //int git_repository_index(git_index **out, git_repository *repo);
}

void repository_init(MEX_DEF_INPUT){
    //17
    //
    //Creates a new Git repository in the given folder.
    //
    //int git_repository_init(git_repository **out, const char *path, 
    //      unsigned int is_bare);
}

void repository_init_ext(MEX_DEF_INPUT){
    //18
    //
    //Create a new Git repository in the given folder with extended controls.
    //
    //int git_repository_init_ext(git_repository **out, const char *repo_path, 
    //      git_repository_init_options *opts);
}

void repository_init_init_options(MEX_DEF_INPUT){
    //19
    //
    //Initializes a git_repository_init_options with default values. 
    //Equivalent to creating an instance with GIT_REPOSITORY_INIT_OPTIONS_INIT.
    //
    //int git_repository_init_init_options(git_repository_init_options *opts, 
    //      unsigned int version);
}

void repository_is_bare(MEX_DEF_INPUT){
    //20
    //
    //Check if a repository is bare
    //
    //int git_repository_is_bare(git_repository *repo);
}

void repository_is_empty(MEX_DEF_INPUT){
    //21
    //
    //Check if a repository is empty
    //
    //int git_repository_is_empty(git_repository *repo);
}

void repository_is_shallow(MEX_DEF_INPUT){
    //22
    //
    //Determine if the repository was a shallow clone
    //
    //int git_repository_is_shallow(git_repository *repo);
}

void repository_is_worktree(MEX_DEF_INPUT){
    //23
    //
    //Check if a repository is a linked work tree
    //
    //int git_repository_is_worktree(git_repository *repo);
}

void repository_item_path(MEX_DEF_INPUT){
    //24
    //
    //Get the location of a specific repository file or directory
    //
    //int git_repository_item_path(git_buf *out, git_repository *repo, 
    //          git_repository_item_t item);
}

void repository_mergehead_foreach(MEX_DEF_INPUT){
    //25
    //
    //If a merge is in progress, invoke 'callback' for each commit ID in 
    //the MERGE_HEAD file.
    //
    //int git_repository_mergehead_foreach(git_repository *repo, 
    //      git_repository_mergehead_foreach_cb callback, void *payload);
}

void repository_message(MEX_DEF_INPUT){
    //26
    //
    //Retrieve git's prepared message
    //
    //int git_repository_message(git_buf *out, git_repository *repo);
}

void repository_message_remove(MEX_DEF_INPUT){
    //27
    //
    //Remove git's prepared message
    //
    //int git_repository_message_remove(git_repository *repo);
}

void repository_new(MEX_DEF_INPUT){
    //28
    //
    //Create a new repository with neither backends nor config object
    //
    //int git_repository_new(git_repository **out);

}

void repository_odb(MEX_DEF_INPUT){
    //29
    //
    //Get the Object Database for this repository.
    //
    //int git_repository_odb(git_odb **out, git_repository *repo);
}

void repository_open(MEX_DEF_INPUT){
    //30
    //
    //  repo = mex(0,30,file_path)
    
    //TODO: Verify file_path
    int error;
    git_repository *repo = NULL;
    
    const char *file_path = mxArrayToString(prhs[2]);
    error = git_repository_open(&repo,file_path);
    handle_error(error,"libgit:repo:open_repo");

    mxFree((void *)file_path);    
    set_repo_output(&plhs[0],repo);
}

void repository_open_bare(MEX_DEF_INPUT){
    //31
    //
    //Open a bare repository on the serverside.
    //
    //int git_repository_open_bare(git_repository **out, const char *bare_path);
}

void repository_open_ext(MEX_DEF_INPUT){
    //32
    //
    //Find and open a repository with extended controls.
    //
    //int git_repository_open_ext(git_repository **out, const char *path, 
    //      unsigned int flags, const char *ceiling_dirs);
}

void repository_open_from_worktree(MEX_DEF_INPUT){
    //33
    //
    //Open working tree as a repository
    //
    //int git_repository_open_from_worktree(git_repository **out, git_worktree *wt);

}

void repository_path(MEX_DEF_INPUT){
    //34
    //
    //Get the path of this repository
    //
    //const char * git_repository_path(git_repository *repo);
    
}

void repository_refdb(MEX_DEF_INPUT){
    //35
    //
    //Get the Reference Database Backend for this repository.
    //
    //int git_repository_refdb(git_refdb **out, git_repository *repo);


}

void repository_reinit_filesystem(MEX_DEF_INPUT){
    //36
    //
    //Update the filesystem config settings for an open repository
    //
    //int git_repository_reinit_filesystem(git_repository *repo, 
    //              int recurse_submodules);
}

void repository_set_bare(MEX_DEF_INPUT){
    //37
    //
    //Set a repository to be bare.
    //
    //int git_repository_set_bare(git_repository *repo);
}

void repository_set_config(MEX_DEF_INPUT){
    //38
    //
    //Set the configuration file for this repository
    //
    //void git_repository_set_config(git_repository *repo, git_config *config);
}

void repository_set_head(MEX_DEF_INPUT){
    //39
    //
    //Make the repository HEAD point to the specified reference.
    //
    //int git_repository_set_head(git_repository *repo, const char *refname);
}

void repository_set_head_detached(MEX_DEF_INPUT){
    //40
    //
    //Make the repository HEAD directly point to the Commit.
    //
    //int git_repository_set_head_detached(git_repository *repo, 
    //              const git_oid *commitish);
}

void repository_set_head_detached_from_annotated(MEX_DEF_INPUT){
    //41
    //
    //Make the repository HEAD directly point to the Commit.
    //
    //int git_repository_set_head_detached_from_annotated(git_repository *repo, 
    //              const git_annotated_commit *commitish);
}

void repository_set_ident(MEX_DEF_INPUT){
    //42
    //
    //Set the identity to be used for writing reflogs
    //
    //int git_repository_set_ident(git_repository *repo, const char *name, 
    //                  const char *email);
}

void repository_set_index(MEX_DEF_INPUT){
    //43
    //
    //Set the index file for this repository
    //
    //void git_repository_set_index(git_repository *repo, git_index *index);
}

void repository_set_namespace(MEX_DEF_INPUT){
    //44
    //
    //Sets the active namespace for this Git Repository
    //
    //int git_repository_set_namespace(git_repository *repo, const char *nmspace);
}

void repository_set_odb(MEX_DEF_INPUT){
    //45
    //
    //Set the Object Database for this repository
    //
    //void git_repository_set_odb(git_repository *repo, git_odb *odb);
}

void repository_set_refdb(MEX_DEF_INPUT){
    //46
    //
    //Set the Reference Database Backend for this repository
    //
    //void git_repository_set_refdb(git_repository *repo, git_refdb *refdb);
}

void repository_set_workdir(MEX_DEF_INPUT){
    //47
    //
    //Set the path to the working directory for this repository
    //
    //int git_repository_set_workdir(git_repository *repo, 
    //          const char *workdir, int update_gitlink);
}

void repository_state(MEX_DEF_INPUT){
    //48
    //
    //Determines the status of a git repository - ie, whether an operation 
    //(merge, cherry-pick, etc) is in progress.
    //
    //int git_repository_state(git_repository *repo);
        
}

void repository_state_cleanup(MEX_DEF_INPUT){
    //49
    //
    //Remove all the metadata associated with an ongoing command like merge,
    //revert, cherry-pick, etc. For example: MERGE_HEAD, MERGE_MSG, etc.
    //
    //int git_repository_state_cleanup(git_repository *repo);
}

void repository_submodule_cache_all(MEX_DEF_INPUT){
    //50
    //
    //Load and cache all submodules.
    //
    //int git_repository_submodule_cache_all(git_repository *repo);
}

void repository_submodule_cache_clear(MEX_DEF_INPUT){
    //51
    //
    //Clear the submodule cache.
    //
    //int git_repository_submodule_cache_clear(git_repository *repo);
}

void repository_workdir(MEX_DEF_INPUT){
    //52
    //
    //Get the path of the working directory for this repository
    //
    //const char * git_repository_workdir(git_repository *repo);
}

void repository_wrap_odb(MEX_DEF_INPUT){
    //53
    //
    //Create a "fake" repository to wrap an object database
    //
    //int git_repository_wrap_odb(git_repository **out, git_odb *odb);
}

void repo(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
//         case 1:
//             //git_repository_cleanup
//             repository_cleanup(MEX_INPUT);
//             break;
        case 2:
            //git_repository_commondir
            break;
        case 3:
            //git_repository_config
            break;
        case 4:
            //git_repository_config_snapshot
            break;
        case 5:
            //git_repository_detach_head
            break;
        case 6:
            //git_repository_discover
            break;
        case 7:
            //git_repository_fetchhead_foreach
            break;
        case 8:
            //git_repository_free
            repository_free(MEX_INPUT);
            break;
        case 9:
            //git_repository_get_namespace
            break;
        case 10:
            //git_repository_hashfile
            break;
        case 11:
            //git_repository_head
            break;
        case 12:
            //git_repository_head_detached
            break;
        case 13:
            //git_repository_head_for_worktree
            break;
        case 14:
            //git_repository_head_unborn
            break;
        case 15:
            //git_repository_ident
            break;
        case 16:
            //git_repository_index
            break;
        case 17:
            //git_repository_init
            break;
        case 18:
            //git_repository_init_ext
            break;
        case 19:
            //git_repository_init_init_options
            break;
        case 20:
            //git_repository_is_bare
            break;
        case 21:
            //git_repository_is_empty
            break;
        case 22:
            //git_repository_is_shallow
            repository_is_shallow(MEX_INPUT);
            break;
        case 23:
            //git_repository_is_worktree
            repository_is_worktree(MEX_INPUT);
            break;
        case 24:
            //git_repository_item_path
            repository_item_path(MEX_INPUT);
            break;
        case 25:
            //git_repository_mergehead_foreach
            repository_mergehead_foreach(MEX_INPUT);
            break;
        case 26:
            //git_repository_message
            repository_message(MEX_INPUT);
            break;
        case 27:
            //git_repository_message_remove
            repository_message_remove(MEX_INPUT);
            break;
        case 28:
            //git_repository_new
            repository_new(MEX_INPUT);
            break;
        case 29:
            //git_repository_odb
            repository_odb(MEX_INPUT);
            break;
        case 30:
            //git_repository_open
            repository_open(MEX_INPUT);            
            break;
        case 31:
            //git_repository_open_bare
            repository_open_bare(MEX_INPUT);
            break;
        case 32:
            //git_repository_open_ext
            repository_open_ext(MEX_INPUT);
            break;
        case 33:
            //git_repository_open_from_worktree
            repository_open_from_worktree(MEX_INPUT);
            break;
        case 34:
            //git_repository_path
            repository_path(MEX_INPUT);
            break;
        case 35:
            //git_repository_refdb
            repository_refdb(MEX_INPUT);
            break;
        case 36:
            //git_repository_reinit_filesystem
            repository_reinit_filesystem(MEX_INPUT);
            break;
        case 37:
            //git_repository_set_bare
            repository_set_bare(MEX_INPUT);
            break;
        case 38:
            //git_repository_set_config
            repository_set_config(MEX_INPUT);
            break;
        case 39:
            //git_repository_set_head
            repository_set_head(MEX_INPUT);
            break;
        case 40:
            //git_repository_set_head_detached
            (MEX_INPUT);
            break;
        case 41:
            //git_repository_set_head_detached_from_annotated
            (MEX_INPUT);
            break;
        case 42:
            //git_repository_set_ident
            repository_set_ident(MEX_INPUT);
            break;
        case 43:
            //git_repository_set_index
            repository_set_index(MEX_INPUT);
            break;
        case 44:
            //git_repository_set_namespace
            repository_set_namespace(MEX_INPUT);
            break;
        case 45:
            //git_repository_set_odb
            repository_set_odb(MEX_INPUT);
            break;
        case 46:
            //git_repository_set_refdb
            repository_set_refdb(MEX_INPUT);
            break;
        case 47:
            //git_repository_set_workdir
            repository_set_workdir(MEX_INPUT);
            break;
        case 48:
            //git_repository_state
            repository_state(MEX_INPUT);
            break;
        case 49:
            //git_repository_state_cleanup
            repository_state_cleanup(MEX_INPUT);
            break;
        case 50:
            //git_repository_submodule_cache_all
            repository_submodule_cache_all(MEX_INPUT);
            break;
        case 51:
            //git_repository_submodule_cache_clear
            repository_submodule_cache_clear(MEX_INPUT);
            break;
        case 52:
            //git_repository_workdir
            repository_workdir(MEX_INPUT);
            break;
        case 53:
            //git_repository_wrap_odb
            repository_wrap_odb(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","repo.h, input sub-type not recognized");
    }
}

// %01  git_repository__cleanup
// %02  git_repository_commondir
// %03  git_repository_config
// %04  git_repository_config_snapshot
// %05  git_repository_detach_head
// %06  git_repository_discover
// %07  git_repository_fetchhead_foreach
// %08  git_repository_free
// %09  git_repository_get_namespace
// %10  git_repository_hashfile
// %11  git_repository_head
// %12  git_repository_head_detached
// %13  git_repository_head_for_worktree
// %14  git_repository_head_unborn
// %15  git_repository_ident
// %16  git_repository_index
// %17  git_repository_init
// %18  git_repository_init_ext
// %19  git_repository_init_init_options
// %20  git_repository_is_bare
// %21  git_repository_is_empty
// %22  git_repository_is_shallow
// %23  git_repository_is_worktree
// %24  git_repository_item_path
// %25  git_repository_mergehead_foreach
// %26  git_repository_message
// %27  git_repository_message_remove
// %28  git_repository_new
// %29  git_repository_odb
// %30  git_repository_open
// %31  git_repository_open_bare
// %32  git_repository_open_ext
// %33  git_repository_open_from_worktree
// %34  git_repository_path
// %35  git_repository_refdb
// %36  git_repository_reinit_filesystem
// %37  git_repository_set_bare
// %38  git_repository_set_config
// %39  git_repository_set_head
// %40  git_repository_set_head_detached
// %41  git_repository_set_head_detached_from_annotated
// %42  git_repository_set_ident
// %43  git_repository_set_index
// %44  git_repository_set_namespace
// %45  git_repository_set_odb
// %46  git_repository_set_refdb
// %47  git_repository_set_workdir
// %48  git_repository_state
// %49  git_repository_state_cleanup
// %50  git_repository_submodule_cache_all
// %51  git_repository_submodule_cache_clear
// %52  git_repository_workdir
// %53  git_repository_wrap_odb