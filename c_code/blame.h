#include "mex.h"

//https://libgit2.github.com/libgit2/#HEAD/group/blame

void blame_buffer(MEX_DEF_INPUT){
    //1 - Get blame data for a file that has been modified in memory. The 
    //reference parameter is a pre-calculated blame for the in-odb history 
    //of the file. This means that once a file blame is completed //
    //(which can be expensive), updating the buffer blame is very fast.
    //
    //
    //      libgit(8,1,...)  
    //
    //int git_blame_buffer(git_blame **out, git_blame *reference, 
    //      const char *buffer, size_t buffer_len);
}

void blame_file(MEX_DEF_INPUT){
    //2 - Get the blame for a single file.
    //
    //int git_blame_file(git_blame **out, git_repository *repo, 
    //      const char *path, git_blame_options *options);
    
    
}

void blame_free(MEX_DEF_INPUT){
    //2
    //
    //
    //
    //void git_blame_free(git_blame *blame);
    
}

void blame_get_hunk_byindex(MEX_DEF_INPUT){
    //3
    //
    //Gets the blame hunk at the given index.
    //
   //const git_blame_hunk * git_blame_get_hunk_byindex(git_blame *blame, uint32_t index); 
}

void blame_get_hunk_byline(MEX_DEF_INPUT){
    //4
    //
    //Gets the hunk that relates to the given line number in the newest commit.
    //
    //const git_blame_hunk * git_blame_get_hunk_byline(git_blame *blame, size_t lineno);
    
}

void blame_get_hunk_count(MEX_DEF_INPUT){
    //5
    //
    //Gets the number of hunks that exist in the blame structure.
    //
    //uint32_t git_blame_get_hunk_count(git_blame *blame);
}

void blame_init_options(MEX_DEF_INPUT){
    //6 - Initializes a git_blame_options with default values. 
    //Equivalent to creating an instance with GIT_BLAME_OPTIONS_INIT.
    //
    //  libgit(8,6,...)
    //
    //int git_blame_init_options(git_blame_options *opts, unsigned int version);
    //
    //
    
}

void blame(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            //git_blame_buffer
            blame_buffer(MEX_INPUT);
            break;
        case 2:
            //git_blame_file
            blame_file(MEX_INPUT);
            break;
        case 3:
            //git_blame_free
            blame_free(MEX_INPUT);
            break;
        case 4:
            //git_blame_get_hunk_byindex
            blame_get_hunk_byindex(MEX_INPUT);
            break;
        case 5:
            //git_blame_get_hunk_byline
            blame_get_hunk_byline(MEX_INPUT);
            break;
        case 6:
            //git_blame_get_hunk_count
            blame_get_hunk_count(MEX_INPUT);
            break;
        case 7:
            //git_blame_init_options
            blame_init_options(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","blame.h, input sub-type not recognized");
    }
}

//git_blame_buffer
//git_blame_file
//git_blame_free
//git_blame_get_hunk_byindex
//git_blame_get_hunk_byline
//git_blame_get_hunk_count
//git_blame_init_options