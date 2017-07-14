#include "mex.h"

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
    //Delete an existing branch reference.
    //
    //int git_branch_delete(git_reference *branch);

}

void branch_is_head(MEX_DEF_INPUT){
    //4
    //
    //Determine if the current local branch is pointed at by HEAD.
    //
    //int git_branch_is_head(const git_reference *branch);

}

void branch_iterator_free(MEX_DEF_INPUT){
    //5
    //
    //Free a branch iterator
    //
    //void git_branch_iterator_free(git_branch_iterator *iter);
}

void branch_iterator_new(MEX_DEF_INPUT){
    //6
    //
    //Create an iterator which loops over the requested branches.
    //
    //int git_branch_iterator_new(git_branch_iterator **out, git_repository *repo, git_branch_t list_flags);
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
    //Retrieve the next branch from the iterator
    //
    //int git_branch_next(git_reference **out, git_branch_t *out_type, git_branch_iterator *iter);  

    
}

void branch_set_upstream(MEX_DEF_INPUT){
    //11
    //
    //Set the upstream configuration for a given local branch
    //
    //int git_branch_set_upstream(git_reference *branch, const char *upstream_name);


}

void (MEX_DEF_INPUT){
    //12
    //
    //Return the reference supporting the remote tracking branch, given a local branch reference.
    //
    //int git_branch_upstream(git_reference **out, const git_reference *branch);


}


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
            (MEX_INPUT);
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



