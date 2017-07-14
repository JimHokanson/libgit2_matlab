#ifdef _WIN32
#include "windows/git2.h"
#else
#include "mac_os/git2.h"
#endif

#include <stdint.h>
#include "libgit_utils.h"

void commit_amend(MEX_DEF_INPUT){
    //1
    //
    //Amend an existing commit by replacing only non-NULL values.
    //
    //int git_commit_amend(git_oid *id, const git_commit *commit_to_amend, 
    //      const char *update_ref, const git_signature *author, 
    //      const git_signature *committer, const char *message_encoding, 
    //      const char *message, const git_tree *tree);

}

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
    //4
    //
    //const git_signature * git_commit_committer(const git_commit *commit);
    git_commit* commit = get_commit_input(prhs[2]);
    const git_signature *s = git_commit_committer(commit);
    set_signature_out(&plhs[0],s);
}

void commit_create(MEX_DEF_INPUT){
    //5
    //
    //int git_commit_create(git_oid *id, git_repository *repo, 
    //  const char *update_ref, const git_signature *author, 
    //  const git_signature *committer, const char *message_encoding, 
    //  const char *message, const git_tree *tree, 
    //  size_t parent_count, const git_commit *[] parents);
}

void commit_create_buffer(MEX_DEF_INPUT){
    //6
}

void commit_create_from_callback(MEX_DEF_INPUT){
    //7
}

void commit_create_from_ids(MEX_DEF_INPUT){
    //8
}

void commit_create_v(MEX_DEF_INPUT){
    //9
}

void commit_create_with_signature(MEX_DEF_INPUT){
    //10
}

void commit_dup(MEX_DEF_INPUT){
    //11
}

void commit_extract_signature(MEX_DEF_INPUT){
    //12
}

void commit_free(MEX_DEF_INPUT){
    //13
    //
    //  Calling form:
    //  commit = mex(2,13,repo,oid);
    git_commit *commit = get_commit_input(prhs[2]);
}

void commit_header_field(MEX_DEF_INPUT){
    //14
}

void commit_id(MEX_DEF_INPUT){
    //15
    //
    //const git_oid * git_commit_id(const git_commit *commit);
    git_commit* commit = get_commit_input(prhs[2]);
    const git_oid *oid = git_commit_id(commit);
    plhs[0] = git_oid__to_mx(oid);
}

void commit_lookup(MEX_DEF_INPUT){
    //16
    //
    //
    //  Calling form:
    //  commit = mex(2,22,repo,oid);
    
        
    //int git_commit_lookup(git_commit **commit, git_repository *repo, const git_oid *id);    int error;
    git_repository *repo = mx_to_git_repo(prhs[2]);
    const git_oid *oid = get_oid_input(prhs[3]);
    git_commit *commit = NULL;
    int error = git_commit_lookup(&commit,repo,oid);
    
    handle_error(error,"libgit:remote:lookup_remote");
    set_commit_output(&plhs[0],commit);
}

void commit_lookup_prefix(MEX_DEF_INPUT){
    //17
}

void commit_message(MEX_DEF_INPUT){
    //18
    //
    //const char * git_commit_message(const git_commit *commit);
    git_commit* commit = get_commit_input(prhs[2]);
    const char *body = git_commit_message(commit);
    plhs[0] = mxCreateString(body);
}

void commit_message_encoding(MEX_DEF_INPUT){
    //19
    //
    //const char * git_commit_message_encoding(const git_commit *commit);
    git_commit* commit = get_commit_input(prhs[2]);
    const char *body = git_commit_message_encoding(commit);
    plhs[0] = mxCreateString(body);
}

void commit_message_raw(MEX_DEF_INPUT){
    //20
    //
    //const char * git_commit_message_raw(const git_commit *commit);
    git_commit* commit = get_commit_input(prhs[2]);
    const char *body = git_commit_message_raw(commit);
    plhs[0] = mxCreateString(body);
}

void commit_nth_gen_ancestor(MEX_DEF_INPUT){
    //21
}

void commit_owner(MEX_DEF_INPUT){
    //22
}

void commit_parent(MEX_DEF_INPUT){
    //23
}

void commit_parent_id(MEX_DEF_INPUT){
    //24
}

void commit_parentcount(MEX_DEF_INPUT){
    //25
}

void commit_raw_header(MEX_DEF_INPUT){
    //26
}

void commit_summary(MEX_DEF_INPUT){
    //27
    //
    //const char * git_commit_summary(git_commit *commit);
    git_commit* commit = get_commit_input(prhs[2]);
    const char *summary = git_commit_summary(commit);
    plhs[0] = mxCreateString(summary);
}

void commit_time(MEX_DEF_INPUT){
    //28
}

void commit_time_offset(MEX_DEF_INPUT){
    //29
}

void commit_tree(MEX_DEF_INPUT){
    //30
}

void commit_tree_id(MEX_DEF_INPUT){
    //31
}







void commit(MEX_DEF_INPUT)
{
    int error;
    int sub_type = (int)mxGetScalar(prhs[1]);
    
    switch (sub_type) {
        case 1:
            //git_commit_amend
            commit_amend(MEX_INPUT);
            break;
        case 2:
            //git_commit_author
            commit_author(MEX_INPUT);
            break;
        case 3:
            //git_commit_body
            commit_body(MEX_INPUT);
            break;
        case 4:
            //git_commit_committer
            commit_committer(MEX_INPUT);
            break;
        case 5:
            //git_commit_create
            //
            //Create new commit in the repository from a list of 
            //git_object pointers
            
            commit_create(MEX_INPUT);
            break;
        case 6:
            //git_commit_create_buffer
            //Create a commit as with git_commit_create() but instead of 
            //writing it to the objectdb, write the contents of the object 
            //into a buffer.
            commit_create_buffer(MEX_INPUT);
            break;
        case 7:
            //git_commit_create_from_callback
            commit_create_from_callback(MEX_INPUT);
            break;
        case 8:
            //git_commit_create_from_ids
            commit_create_from_ids(MEX_INPUT);
            break;
        case 9:
            //git_commit_create_v
            commit_create_v(MEX_INPUT);
            break;
        case 10:
            //git_commit_create_with_signature
            commit_create_with_signature(MEX_INPUT);
            break;
        case 11:
            //git_commit_dup
            commit_dup(MEX_INPUT);
            break;
        case 12:
            //git_commit_extract_signature
            commit_extract_signature(MEX_INPUT);
            break;
        case 13:
            commit_free(MEX_INPUT);
            break;
        case 14:
            //git_commit_header_field
            commit_header_field(MEX_INPUT);
            break;
        case 15:
            //git_commit_id
            commit_id(MEX_INPUT);
            break;
        case 16:
            //git_commit_lookup
            commit_lookup(MEX_INPUT);
            break;
        case 17:
            //git_commit_lookup_prefix
            commit_lookup_prefix(MEX_INPUT);
            break;
        case 18:
            //git_commit_message
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
            commit_nth_gen_ancestor(MEX_INPUT);
            break;
        case 22:
            //git_commit_owner
            commit_owner(MEX_INPUT);
            break;
        case 23:
            //git_commit_parent  
            commit_parent(MEX_INPUT);
            break;
        case 24:
            //git_commit_parent_id
            commit_parent_id(MEX_INPUT);
            break;
     	case 25:
            //git_commit_parentcount
            commit_parentcount(MEX_INPUT);
            break;
      	case 26:
            //git_commit_raw_header
            commit_raw_header(MEX_INPUT);
            break;
       	case 27:
            //git_commit_summary
            commit_summary(MEX_INPUT);
            break;
     	case 28:
            //git_commit_time
            commit_time(MEX_INPUT);
            break;
      	case 29:
            //git_commit_time_offset
            commit_time_offset(MEX_INPUT);
            break;
    	case 30:
            //git_commit_tree
            commit_tree(MEX_INPUT);
            break;
        case 31:
            //git_commit_tree_id
            commit_tree_id(MEX_INPUT);
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