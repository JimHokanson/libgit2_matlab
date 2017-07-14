#include "mex.h"

//https://libgit2.github.com/libgit2/#HEAD/group/checkout

void checkout_head(MEX_DEF_INPUT){
    //1
    //
    //Updates files in the index and the working tree to match the content of the commit pointed at by HEAD.
    //
    //int git_checkout_head(git_repository *repo, const git_checkout_options *opts);

}

void checkout_index(MEX_DEF_INPUT){
    //2
    //
    //Updates files in the working tree to match the content of the index.
    //
    //int git_checkout_index(git_repository *repo, git_index *index, const git_checkout_options *opts);

    
}

void checkout_init_options(MEX_DEF_INPUT){
    //3
    //
    //Initializes a git_checkout_options with default values. Equivalent to 
    //creating an instance with GIT_CHECKOUT_OPTIONS_INIT.
    //
    //int git_checkout_init_options(git_checkout_options *opts, unsigned int version);
    
}

void checkout_tree(MEX_DEF_INPUT){
    //4
    //
    //Updates files in the index and working tree to match the content of 
    //      the tree pointed at by the treeish.
    //
    //int git_checkout_tree(git_repository *repo, const git_object *treeish, 
    //      const git_checkout_options *opts);

    
}


void branch(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            //01 git_checkout_head
            checkout_head(MEX_INPUT);
            break;
        case 2:
            //02 git_checkout_index
            checkout_index(MEX_INPUT);
            break;
        case 3:
            //03 git_checkout_init_options
            checkout_init_options(MEX_INPUT);
            break;
        case 4:
            //04 git_checkout_tree
            checkout_tree(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","branch.h, input sub-type not recognized");
    }
}

//01 git_checkout_head
//02 git_checkout_index
//03 git_checkout_init_options
//04 git_checkout_tree