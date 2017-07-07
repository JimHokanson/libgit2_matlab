#ifdef _WIN32
#include "windows/git2.h"
#else
#include "mac_os/git2.h"
#endif

#include <stdint.h>
#include "libgit_utils.h"

void commit_author(MEX_DEF_INPUT){
    //const git_signature * git_commit_author(const git_commit *commit);
    git_commit* commit = get_commit_input(prhs[2]);
    const git_signature *s = git_commit_author(commit);
    set_signature_out(&plhs[0],s);
}

void commit_body(MEX_DEF_INPUT){
    //const char * git_commit_body(git_commit *commit);
    git_commit* commit = get_commit_input(prhs[2]);
    const char *body = git_commit_body(commit);
    plhs[0] = mxCreateString(body);
}

void commit_committer(MEX_DEF_INPUT){
    //const git_signature * git_commit_committer(const git_commit *commit);
    git_commit* commit = get_commit_input(prhs[2]);
    const git_signature *s = git_commit_committer(commit);
    set_signature_out(&plhs[0],s);
}

void commit_message(MEX_DEF_INPUT){
    //const char * git_commit_message(const git_commit *commit);
    git_commit* commit = get_commit_input(prhs[2]);
    const char *body = git_commit_message(commit);
    plhs[0] = mxCreateString(body);
}

void commit_message_encoding(MEX_DEF_INPUT){
    //const char * git_commit_message_encoding(const git_commit *commit);
    git_commit* commit = get_commit_input(prhs[2]);
    const char *body = git_commit_message_encoding(commit);
    plhs[0] = mxCreateString(body);
}

void commit_message_raw(MEX_DEF_INPUT){
    //const char * git_commit_message_raw(const git_commit *commit);
    git_commit* commit = get_commit_input(prhs[2]);
    const char *body = git_commit_message_raw(commit);
    plhs[0] = mxCreateString(body);
}

void commit_summary(MEX_DEF_INPUT){
    //const char * git_commit_summary(git_commit *commit);
    git_commit* commit = get_commit_input(prhs[2]);
    const char *summary = git_commit_summary(commit);
    plhs[0] = mxCreateString(summary);
}

void commit_id(MEX_DEF_INPUT){
    //const git_oid * git_commit_id(const git_commit *commit);
    git_commit* commit = get_commit_input(prhs[2]);
    const git_oid *oid = git_commit_id(commit);
    set_oid_output(&plhs[0],oid);
}



void lookup_commit(MEX_DEF_INPUT){
    //
    //  Calling form:
    //  commit = mex(2,22,repo,oid);
    
        
    //int git_commit_lookup(git_commit **commit, git_repository *repo, const git_oid *id);    int error;
    git_repository *repo = get_repo_input(prhs[2]);
    const git_oid *oid = get_oid_input(prhs[3]);
    git_commit *commit = NULL;
    int error = git_commit_lookup(&commit,repo,oid);
    
    handle_error(error,"libgit:remote:lookup_remote");
    set_commit_output(&plhs[0],commit);
}

void commit_free(MEX_DEF_INPUT){
    //
    //  Calling form:
    //  commit = mex(2,13,repo,oid);
    git_commit *commit = get_commit_input(prhs[2]);
}

void commit(MEX_DEF_INPUT)
{
    int error;
    int sub_type = (int)mxGetScalar(prhs[1]);
    
    switch (sub_type) {
        case 1:
            //amend
            break;
        case 2:
            //author
            commit_author(MEX_INPUT);
            break;
        case 3:
            //body
            commit_body(MEX_INPUT);
            break;
        case 4:
            //commiter
            break;
        case 5:
            //create
            break;
        case 6:
            //create_buffer
            break;
        case 7:
            //git_commit_create_from_callback
            break;
        case 8:
            //git_commit_create_from_ids
            break;
        case 9:
            //git_commit_create_v
            break;
        case 10:
            //git_commit_create_with_signature
            break;
        case 11:
            //git_commit_dup
            break;
        case 12:
            //signature
            break;
        case 13:
            commit_free(MEX_INPUT);
            break;
        case 14:
            //git_commit_header_field
            break;
        case 15:
            //git_commit_id
            commit_id(MEX_INPUT);
            break;
        case 16:
            //git_commit_lookup
            lookup_commit(MEX_INPUT);
            break;
        case 17:
            break;
        case 18:
            // %18 git_commit_message
            commit_message(MEX_INPUT);
            break;
        case 19:
            // %19 git_commit_message_encoding
            commit_message_encoding(MEX_INPUT);
            break;
        case 20:
            // %20 git_commit_message_raw
            commit_message_raw(MEX_INPUT);
            break;
        case 21:
            //git_commit_nth_gen_ancestor
            break;
        case 22:
            //git_commit_owner
            break;
        case 23:
            //git_commit_parent  
            break;
        case 24:
            //git_commit_parent_id
            break;
     	case 25:
            //git_commit_parentcount
            break;
      	case 26:
            //git_commit_raw_header
            break;
       	case 27:
            //git_commit_summary
            commit_summary(MEX_INPUT);
            break;
     	case 28:
            //git_commit_time
            break;
      	case 29:
            //git_commit_time_offset
            break;
    	case 30:
            //git_commit_tree
            break;
        case 31:
            //git_commit_tree_id
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","commit.h, input sub-type not recognized");
            
    }
}

// %01 git_commit_amend
// %02 git_commit_author
// %03 git_commit_body
// %04 git_commit_committer
// %05 git_commit_create
// %06 git_commit_create_buffer
// %07 git_commit_create_from_callback
// %08 git_commit_create_from_ids
// %09 git_commit_create_v
// %10 git_commit_create_with_signature
// %11 git_commit_dup
// %12 git_commit_extract_signature
// %x 13 git_commit_free
// %14 git_commit_header_field
// %15 git_commit_id
// %x 16 git_commit_lookup
// %17 git_commit_lookup_prefix
// %18 git_commit_message
// %19 git_commit_message_encoding
// %20 git_commit_message_raw
// %21 git_commit_nth_gen_ancestor
// %22 git_commit_owner
// %23 git_commit_parent
// %24 git_commit_parent_id
// %25 git_commit_parentcount
// %26 git_commit_raw_header
// %27 git_commit_summary
// %28 git_commit_time
// %29 git_commit_time_offset
// %30 git_commit_tree
// %31 git_commit_tree_id