#include "mex.h"

//https://libgit2.github.com/libgit2/#HEAD/group/config

void reflog_append(MEX_DEF_INPUT){
    //1
}

void reflog_delete(MEX_DEF_INPUT){
    //2
}

void reflog_drop(MEX_DEF_INPUT){
    //3
}

void reflog_entry_byindex(MEX_DEF_INPUT){
    //4
}

void reflog_entry_committer(MEX_DEF_INPUT){
    //5
}

void reflog_entry_id_new(MEX_DEF_INPUT){
    //6
}

void reflog_entry_id_old(MEX_DEF_INPUT){
    //7
}

void reflog_entry_message(MEX_DEF_INPUT){
    //8
}

void reflog_entrycount(MEX_DEF_INPUT){
    //9
}

void reflog_free(MEX_DEF_INPUT){
    //10
}

void reflog_read(MEX_DEF_INPUT){
    //11
}

void reflog_rename(MEX_DEF_INPUT){
    //12
}

void reflog_write(MEX_DEF_INPUT){
    //13
}



void reflog(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            reflog_append(MEX_INPUT);
            break;
        case 2:
            reflog_delete(MEX_INPUT);
            break;
        case 3:
            reflog_drop(MEX_INPUT);
            break;
        case 4:
            reflog_entry_byindex(MEX_INPUT);
            break;
        case 5:
            reflog_entry_committer(MEX_INPUT);
            break;
        case 6:
            reflog_entry_id_new(MEX_INPUT);
            break;
        case 7:
            reflog_entry_id_old(MEX_INPUT);
            break;
        case 8:
            reflog_entry_message(MEX_INPUT);
            break;
        case 9:
            reflog_entrycount(MEX_INPUT);
            break;
        case 10:
            reflog_free(MEX_INPUT);
            break;
        case 11:
            reflog_read(MEX_INPUT);
            break;
        case 12:
            reflog_rename(MEX_INPUT);
            break;
        case 13:
            reflog_write(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","config.h, input sub-type not recognized");
    }
}

//1 git_reflog_append
//2 git_reflog_delete
//3 git_reflog_drop
//4 git_reflog_entry_byindex
//5 git_reflog_entry_committer
//6 git_reflog_entry_id_new
//7 git_reflog_entry_id_old
//8 git_reflog_entry_message
//9 git_reflog_entrycount
//10 git_reflog_free
//11 git_reflog_read
//12 git_reflog_rename
//13 git_reflog_write