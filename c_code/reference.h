#ifdef _WIN32
#include "windows/git2.h"
#else
#include "mac_os/git2.h"
#endif

#include <stdint.h>
#include "libgit_utils.h"

void lookup_reference(MEX_DEF_INPUT){
    //
    //  Calling form:
    //  ref = mex(1,22,repo,ref_name);
    
    //int git_reference_lookup(git_reference **out, git_repository *repo, const char *name);
    git_repository *repo = get_repo_input(prhs[2]);
    const char *ref_name = mxArrayToString(prhs[3]);
    
    git_reference *ref = NULL;
    int error = git_reference_lookup(&ref, repo, ref_name);
    
    handle_error(error,"libgit:reference:lookup_reference");
    
    set_reference_output(&plhs[0],ref);
    mxFree((void *)ref_name);
}

void reference_shorthand(MEX_DEF_INPUT){
    
    git_reference *ref = get_reference_input(prhs[2]);
    
    //const char * git_reference_shorthand(const git_reference *ref);   
    
    const char *shorthand = git_reference_shorthand(ref);
    
    plhs[0] = mxCreateString(shorthand);
}

void reference_name_to_id(MEX_DEF_INPUT){
    
    git_repository *repo = get_repo_input(prhs[2]);
    const char *ref_name = mxArrayToString(prhs[3]);
    
    //int git_reference_name_to_id(git_oid *out, git_repository *repo, const char *name);
    git_oid oid;
    int error = git_reference_name_to_id(&oid,repo,ref_name);
    handle_error(error,"libgit:reference:ref_to_id");
    
    //oid is type: unsigned char [20]
    //TODO: I think we might need a memcpy ...?
    
    set_oid_output(&plhs[0],oid);
    
    mxFree((void *)ref_name);
}

void reference(MEX_DEF_INPUT)
{
    int error;
    int sub_type = (int)mxGetScalar(prhs[1]);
    
    switch (sub_type) {
        case 0:
            //repository
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 7:
            break;
        case 10:
            break;
        case 13:
            //Free Remote
            //mex(3,13,ref_pointer)
            git_reference_free(get_reference_input(prhs[2]));
            break;
        case 14:
            //has_log
            //int git_reference_has_log(git_repository *repo, const char *refname);
            break;
        case 15:
            //is_branch
            //int git_reference_is_branch(const git_reference *ref);
            break;
        case 16:
            //is_note
            //int git_reference_is_note(const git_reference *ref);
            break;
        case 17:
            //int git_reference_is_remote(const git_reference *ref);
            break;
        case 18:
            //int git_reference_is_tag(const git_reference *ref);
            break;
        case 19:
            //int git_reference_is_valid_name(const char *refname);
            break;
        case 20:
            //void git_reference_iterator_free(git_reference_iterator *iter);
            break;
        case 21:
            //int git_reference_iterator_glob_new(git_reference_iterator **out, 
            //git_repository *repo, const char *glob);
            break;
        case 22:
            break;
        case 23:
            break;
        case 24:
            lookup_reference(MEX_INPUT);
            break;
        case 25:
            break;
        case 26:
            reference_name_to_id(MEX_INPUT);
            break;
        case 36:
            //reference_shorthand
            reference_shorthand(MEX_INPUT);
            break;
        case 37:
            break;
        case 38:
            //get_remote_url(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","commit.h, input sub-type not recognized");
            
    }
}