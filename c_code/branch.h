#include "mex.h"
#include "libgit_utils.h"

//https://libgit2.github.com/libgit2/#HEAD/group/branch

void branch_create(MEX_DEF_INPUT){
    //1
    //
    //Create a new branch pointing at a target commit
    //
    //int git_branch_create(git_reference **out, git_repository *repo, 
    //  const char *branch_name, const git_commit *target, int force);
}

void branch_create_from_annotated(MEX_DEF_INPUT){
    //2
    //
    //Create a new branch pointing at a target commit
    //
    //int git_branch_create_from_annotated(git_reference **ref_out, 
    //     git_repository *repository, const char *branch_name, 
    //      const git_annotated_commit *commit, int force);
}

void branch_delete(MEX_DEF_INPUT){
    //3
    //
    //  mex(10,3,branch)
    //
    //Delete an existing branch reference.
    //
    //int git_branch_delete(git_reference *branch);
    
    //Start of code 
    //git_reference* ref = mx_to_git_ref(prhs[2]);

}

void branch_is_head(MEX_DEF_INPUT){
    //4
    //
    //  head = mex(10,4,branch)
    //
    //Determine if the current local branch is pointed at by HEAD.
    //
    //int git_branch_is_head(const git_reference *branch);
    
    git_reference* ref = mx_to_git_ref(prhs[2]);
    
    int error = git_branch_is_head(mx_to_git_ref(prhs[2]));
    handle_error(error,"libgit:branch:branch_is_head"); 
    plhs[0] = int32__to_mx(error);

}

void branch_iterator_free(MEX_DEF_INPUT){
    //5
    //
    //  mex(10,5,iter)
    //
    //Free a branch iterator
    //
    //void git_branch_iterator_free(git_branch_iterator *iter);
    
    //DONE
    git_branch_iterator_free(mx_to_git_branch_iterator(prhs[2]));
    
}

void branch_iterator_new(MEX_DEF_INPUT){
    //6
    //
    //  mex(10,6,repo,flags)
    //
    //Create an iterator which loops over the requested branches.
    //
    //int git_branch_iterator_new(git_branch_iterator **out, git_repository *repo, git_branch_t list_flags);
    //
    //https://libgit2.github.com/libgit2/#HEAD/group/branch/git_branch_iterator_new
    //
    //Filtering flags for the branch listing. Valid values are 
    //  GIT_BRANCH_LOCAL, 
    //  GIT_BRANCH_REMOTE or 
    //  GIT_BRANCH_ALL.
    
    git_branch_t list_flags;
    
    if (nrhs == 3){
        list_flags = GIT_BRANCH_ALL;
    }else{
        switch((int)mxGetScalar(prhs[3])){
            case 0:
                list_flags = GIT_BRANCH_LOCAL;
                break;
            case 1:
                list_flags = GIT_BRANCH_REMOTE;
                break;
            case 2:
                list_flags = GIT_BRANCH_ALL;
                break;
            default:
                mexErrMsgIdAndTxt("branch_iterator_new:unrecognized_option","option not found");
        }
    }
    
    git_branch_iterator *out;
    git_repository *repo = mx_to_git_repo(prhs[2]);
    int error = git_branch_iterator_new(&out,repo,list_flags);
    handle_error(error,"libgit:branch:branch_iterator_new"); 
    plhs[0] = git_branch_iterator__to_mx(out);
    
}

void branch_lookup(MEX_DEF_INPUT){
    //7
    //
    //Lookup a branch by its name in a repository.
    //
    //int git_branch_lookup(git_reference **out, git_repository *repo, 
    //      const char *branch_name, git_branch_t branch_type);
}

void branch_move(MEX_DEF_INPUT){
    //8
    //
    //Move/rename an existing local branch reference.
    //
    //int git_branch_move(git_reference **out, git_reference *branch, 
    //      const char *new_branch_name, int force);


}

void branch_name(MEX_DEF_INPUT){
    //9
    //
    //Return the name of the given local or remote branch.
    //
    //int git_branch_name(const char **out, const git_reference *ref);

}

void branch_next(MEX_DEF_INPUT){
    //10
    //
    //  [ref,out_type] = mex(10,10,iter)
    //
    //Retrieve the next branch from the iterator
    //
    //int git_branch_next(git_reference **out, git_branch_t *out_type, git_branch_iterator *iter);  
    //
    //0 on success, GIT_ITEROVER if there are no more branches or an error code.
    //
    //  ?? - don't we already know outtype - I guess not if we do all
    //out_type => 
    //GIT_BRANCH_LOCAL
    //GIT_BRANCH_REMOTE
    //GIT_BRANCH_ALL
    
}

void branch_set_upstream(MEX_DEF_INPUT){
    //11
    //
    //Set the upstream configuration for a given local branch
    //
    //int git_branch_set_upstream(git_reference *branch, const char *upstream_name);


}

void branch_upstream(MEX_DEF_INPUT){
    //12
    //
    //Return the reference supporting the remote tracking branch, given a local branch reference.
    //
    //int git_branch_upstream(git_reference **out, const git_reference *branch);


}

//=========================================================================

//TODO: is_checked_out

void branch(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            //01 git_branch_create
            branch_create(MEX_INPUT);
            break;
        case 2:
            //02 git_branch_create_from_annotated
            branch_create_from_annotated(MEX_INPUT);
            break;
        case 3:
            //03 git_branch_delete
            branch_delete(MEX_INPUT);
            break;
        case 4:
            //04 git_branch_is_head
            branch_is_head(MEX_INPUT);
            break;
        case 5:
            //05 git_branch_iterator_free
            branch_iterator_free(MEX_INPUT);
            break;
        case 6:
            //06 git_branch_iterator_new
            branch_iterator_new(MEX_INPUT);
            break;
        case 7:
            //07 git_branch_lookup
            branch_lookup(MEX_INPUT);
            break;
        case 8:
            //08 git_branch_move
            branch_move(MEX_INPUT);
            break;
        case 9:
            //09 git_branch_name
            branch_name(MEX_INPUT);
            break;
        case 10:
            //10 git_branch_next
            branch_next(MEX_INPUT);
            break;
        case 11:
            //11 git_branch_set_upstream
            branch_set_upstream(MEX_INPUT);
            break;
        case 12:
            //12 git_branch_upstream
            branch_upstream(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","branch.h, input sub-type not recognized");
    }
}

//01 git_branch_create
//02 git_branch_create_from_annotated
//03 git_branch_delete
//04 git_branch_is_head
//05 git_branch_iterator_free
//06 git_branch_iterator_new
//07 git_branch_lookup
//08 git_branch_move
//09 git_branch_name
//10 git_branch_next
//11 git_branch_set_upstream
//12 git_branch_upstream



