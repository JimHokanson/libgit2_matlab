#include "mex.h"

//https://libgit2.github.com/libgit2/#HEAD/group/cherrypick

void cherrypick(MEX_DEF_INPUT){
    //1
    //
    //Cherry-pick the given commit, producing changes in the index and working directory.
    //
    //int git_cherrypick(git_repository *repo, git_commit *commit, 
    //      const git_cherrypick_options *cherrypick_options);

}

void cherrypick_commit(MEX_DEF_INPUT){
    //2
    //
    //Cherry-picks the given commit against the given "our" commit, 
    //producing an index that reflects the result of the cherry-pick.
    //
    //int git_cherrypick_commit(git_index **out, git_repository *repo, 
    //git_commit *cherrypick_commit, git_commit *our_commit, 
    //unsigned int mainline, const git_merge_options *merge_options);
}

void cherrypick_init_options(MEX_DEF_INPUT){
    //3
    //
    //Initializes a git_cherrypick_options with default values. Equivalent 
    //to creating an instance with GIT_CHERRYPICK_OPTIONS_INIT.
    //
    //int git_cherrypick_init_options(git_cherrypick_options *opts, unsigned int version);
}


void cherrypick(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            //git_cherrypick
            cherrypick(MEX_INPUT);
            break;
        case 2:
            //git_cherrypick_commit
            cherrypick_commit(MEX_INPUT);
            break;
        case 3:
            //git_cherrypick_init_options
            cherrypick_init_options(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","branch.h, input sub-type not recognized");
    }
}

//01 git_cherrypick
//02 git_cherrypick_commit
//03 git_cherrypick_init_options