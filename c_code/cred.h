#include "mex.h"

//https://libgit2.github.com/libgit2/#HEAD/group/cred

void config(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            //git_cred_default_new
            break;
        case 2:
            //git_cred_free
            break;
        case 3:
            //git_cred_has_username
            break;
        case 4:
            //git_cred_ssh_custom_new
            break;
        case 5:
            //git_cred_ssh_interactive_new
            break;
        case 6:
            //git_cred_ssh_key_from_agent
            break;
        case 7:
            //git_cred_ssh_key_memory_new
            break;
        case 8:
            //git_cred_ssh_key_new
            break;
        case 9:
            //git_cred_username_new
            break;
        case 10:
            //git_cred_userpass
            break;
        case 11:
            //git_cred_userpass_plaintext_new
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","config.h, input sub-type not recognized");
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