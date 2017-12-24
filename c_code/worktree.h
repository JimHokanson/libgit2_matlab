#include "mex.h"
//
//  Worktrees allow using multiple branches simultaenously (I think)

//https://libgit2.github.com/libgit2/#HEAD/group/worktree

void worktree_add(MEX_DEF_INPUT){
    //1 - Add a new working tree
    //  
    //  Add a new working tree for the repository, that is create the 
    //  required data structures inside the repository and check out the 
    //  current HEAD at path
    //
    //int git_worktree_add(git_worktree **out, git_repository *repo, 
    //      const char *name, const char *path, const git_worktree_add_options *opts);
}
void worktree_add_init_options(MEX_DEF_INPUT){
    //2 - Initializes a git_worktree_add_options with default vaules. 
    //  Equivalent to creating an instance with GIT_WORKTREE_ADD_OPTIONS_INIT.
    //
    //int git_worktree_add_init_options(git_worktree_add_options *opts, 
    //      unsigned int version);
}
void worktree_free(MEX_DEF_INPUT){
    //3 - Free a previously allocated worktree
    //
    //void git_worktree_free(git_worktree *wt);


}
void worktree_is_locked(MEX_DEF_INPUT){
    //4 - Check if worktree is locked
    //
    //  int git_worktree_is_locked(git_buf *reason, const git_worktree *wt);
}
void worktree_is_prunable(MEX_DEF_INPUT){
    //5 - Is the worktree prunable with the given options?
    //
    //  A worktree is not prunable in the following scenarios:
    //  - the worktree is linking to a valid on-disk worktree. The valid 
    //  member will cause this check to be ignored. - the worktree is 
    //  locked. The locked flag will cause this check to be ignored.
    //  - If the worktree is not valid and not locked or if the above 
    //  flags have been passed in, this function will return a positive value.
    //
    //int git_worktree_is_prunable(git_worktree *wt, git_worktree_prune_options *opts);


}
void worktree_list(MEX_DEF_INPUT){
    //6 - List names of linked working trees
    //
    //int git_worktree_list(git_strarray *out, git_repository *repo);


}
void worktree_lock(MEX_DEF_INPUT){
    //7 - Lock worktree if not already locked
    //
    //  int git_worktree_lock(git_worktree *wt, char *reason);


}
void worktree_lookup(MEX_DEF_INPUT){
    //8 - Lookup a working tree by its name for a given repository
    //
    //int git_worktree_lookup(git_worktree **out, git_repository *repo, const char *name);

}
void worktree_open_from_repository(MEX_DEF_INPUT){
    //9 - Open a worktree of a given repository
    //
    //  int git_worktree_open_from_repository(git_worktree **out, git_repository *repo);


}
void worktree_prune(MEX_DEF_INPUT){
    //10 - Prune working tree
    //
    //  int git_worktree_prune(git_worktree *wt, git_worktree_prune_options *opts);


    
}
void worktree_prune_init_options(MEX_DEF_INPUT){
    //11 - Initializes a git_worktree_prune_options with default vaules.
    //  Equivalent to creating an instance with GIT_WORKTREE_PRUNE_OPTIONS_INIT.
    //
    //int git_worktree_prune_init_options(git_worktree_prune_options *opts, unsigned int version);
}
void worktree_unlock(MEX_DEF_INPUT){
    //12 - Unlock a locked worktree
    //
    //  int git_worktree_unlock(git_worktree *wt);


    
}
void worktree_validate(MEX_DEF_INPUT){
    //13 - Check if worktree is valid
    //
    //  int git_worktree_validate(const git_worktree *wt);


}

void worktree(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            worktree_add(MEX_INPUT);
            break;
        case 2:
            worktree_add_init_options(MEX_INPUT);
            break;
        case 3:
            worktree_free(MEX_INPUT);
            break;
        case 4:
            worktree_is_locked(MEX_INPUT);
            break;
        case 5:
            worktree_is_prunable(MEX_INPUT);
            break;
        case 6:
            worktree_list(MEX_INPUT);
            break;
        case 7:
            worktree_lock(MEX_INPUT);
            break;
        case 8:
            worktree_lookup(MEX_INPUT);
            break;
        case 9:
            worktree_open_from_repository(MEX_INPUT);
            break;
        case 10:
            worktree_prune(MEX_INPUT);
            break;
        case 11:
            worktree_prune_init_options(MEX_INPUT);
            break;
        case 12:
            worktree_unlock(MEX_INPUT);
            break;
        case 13:
            worktree_validate(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","worktree.h, input sub-type not recognized");
    }
}

//1 git_worktree_add
//2 git_worktree_add_init_options
//3 git_worktree_free
//4 git_worktree_is_locked
//5 git_worktree_is_prunable
//6 git_worktree_list
//7 git_worktree_lock
//8 git_worktree_lookup
//9 git_worktree_open_from_repository
//10 git_worktree_prune
//11 git_worktree_prune_init_options
//12 git_worktree_unlock
//13 git_worktree_validate


