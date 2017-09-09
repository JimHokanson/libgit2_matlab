#include "mex.h"

//https://libgit2.github.com/libgit2/#HEAD/group/config

void worktree(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
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


