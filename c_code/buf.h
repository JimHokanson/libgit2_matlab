#include "mex.h"

//https://libgit2.github.com/libgit2/#HEAD/group/buf
    

void buf_contains_nul(MEX_DEF_INPUT){
    //1
    //
    //Check quickly if buffer contains a NUL byte
    //
    //int git_buf_contains_nul(const git_buf *buf);

}

void buf_free(MEX_DEF_INPUT){
    //2
    //
    //Free the memory referred to by the git_buf.
    //
    //void git_buf_free(git_buf *buffer);

}

void buf_grow(MEX_DEF_INPUT){
    //3
    //
    //Resize the buffer allocation to make more space.
    //
    //int git_buf_grow(git_buf *buffer, size_t target_size);


}

void buf_is_binary(MEX_DEF_INPUT){
    //4
    //
    //Check quickly if buffer looks like it contains binary data
    //
    //int git_buf_is_binary(const git_buf *buf);

}

void buf_set(MEX_DEF_INPUT){
    //5
    //
    //Set buffer to a copy of some raw data.
    //
    //int git_buf_set(git_buf *buffer, const void *data, size_t datalen);

}

void branch(MEX_DEF_INPUT)
{   
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            //01 git_buf_contains_nul
            buf_contains_nul(MEX_INPUT);
            break;
        case 2:
            //02 git_buf_free
            buf_free(MEX_INPUT);
            break;
        case 3:
            //03 git_buf_grow
            buf_grow(MEX_INPUT);
            break;
        case 4:
            //04 git_buf_is_binary
            buf_is_binary(MEX_INPUT);
            break;
        case 5:
            //05 git_buf_set
            buf_set(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","branch.h, input sub-type not recognized");
    }
}

//01 git_buf_contains_nul
//02 git_buf_free
//03 git_buf_grow
//04 git_buf_is_binary
//05 git_buf_set