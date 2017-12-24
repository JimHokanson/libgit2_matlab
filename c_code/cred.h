#include "mex.h"

//https://libgit2.github.com/libgit2/#HEAD/group/cred

void cred_default_new(MEX_DEF_INPUT){
    //1
}

void cred_free(MEX_DEF_INPUT){
    //2
}

void cred_has_username(MEX_DEF_INPUT){
    //3
}

void cred_ssh_custom_new(MEX_DEF_INPUT){
    //4
}

void cred_ssh_interactive_new(MEX_DEF_INPUT){
    //5
}

void cred_ssh_key_from_agent(MEX_DEF_INPUT){
    //6
}

void cred_ssh_key_memory_new(MEX_DEF_INPUT){
    //7
}

void cred_ssh_key_new(MEX_DEF_INPUT){
    //8
}

void cred_username_new(MEX_DEF_INPUT){
    //9
}

void cred_userpass(MEX_DEF_INPUT){
    //10
}

void cred_userpass_plaintext_new(MEX_DEF_INPUT){
    //11
}




void cred(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            cred_default_new(MEX_INPUT);
            break;
        case 2:
            cred_free(MEX_INPUT);
            break;
        case 3:
            cred_has_username(MEX_INPUT);
            break;
        case 4:
            cred_ssh_custom_new(MEX_INPUT);
            break;
        case 5:
            cred_ssh_interactive_new(MEX_INPUT);
            break;
        case 6:
            cred_ssh_key_from_agent(MEX_INPUT);
            break;
        case 7:
            cred_ssh_key_memory_new(MEX_INPUT);
            break;
        case 8:
            cred_ssh_key_new(MEX_INPUT);
            break;
        case 9:
            cred_username_new(MEX_INPUT);
            break;
        case 10:
            cred_userpass(MEX_INPUT);
            break;
        case 11:
            cred_userpass_plaintext_new(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","cred.h, input sub-type not recognized");
    }
}

//01 git_cred_default_new
//02 git_cred_free
//03 git_cred_has_username
//04 git_cred_ssh_custom_new
//05 git_cred_ssh_interactive_new
//06 git_cred_ssh_key_from_agent
//07 git_cred_ssh_key_memory_new	
//08 git_cred_ssh_key_new
//09 git_cred_username_new
//10 git_cred_userpass
//11 git_cred_userpass_plaintext_new