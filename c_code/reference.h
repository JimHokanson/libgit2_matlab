#ifdef _WIN32
#include "windows/git2.h"
#else
#include "mac_os/git2.h"
#endif

#include <stdint.h>
#include "libgit_utils.h"

void reference_alloc(MEX_DEF_INPUT){
    //
    //  mex(3,1)
    //  Create a new direct reference from an OID.
    //
    //  git_reference * git_reference__alloc(const char *name, const git_oid *oid, const git_oid *peel);
    //
    
}

void reference_alloc_symbolic(MEX_DEF_INPUT){
    //Create a new symbolic reference.
    //
    //  mex(3,2)
    //
    //git_reference * git_reference__alloc_symbolic(const char *name, const char *target);
}

void reference_cmp(MEX_DEF_INPUT){
    //
    //  mex(3,3)

}

void reference_create(MEX_DEF_INPUT){
    //  mex(3,4)

}

void reference_create_matching(MEX_DEF_INPUT){
    //  mex(3,5)

}

void reference_delete(MEX_DEF_INPUT){
    //  mex(3,6)

}

void reference_dup(MEX_DEF_INPUT){
    //  mex(3,7)

}

void reference_dwim(MEX_DEF_INPUT){
    //  mex(3,8)

}

void reference_ensure_log(MEX_DEF_INPUT){
    //  mex(3,9)

}

void reference_foreach(MEX_DEF_INPUT){
    //  mex(3,10)

}

void reference_foreach_glob(MEX_DEF_INPUT){
    //  mex(3,11)

}

void reference_foreach_name(MEX_DEF_INPUT){
    //  mex(3,12)

}

void reference_free(MEX_DEF_INPUT){
    //  mex(3,13,reference)
    //
    //void git_reference_free(git_reference *ref);

    git_reference *ref = get_reference_input(prhs[2]);
    git_reference_free(ref);
}

void reference_has_log(MEX_DEF_INPUT){
    //  out = mex(3,14,repo,ref_name)
    //
    //  Check if a reflog exists for the specified reference.
    //
    //int git_reference_has_log(git_repository *repo, const char *refname);

    git_repository *repo = mx_to_git_repo(prhs[2]);
    const char *ref_name = mxArrayToString(prhs[3]);

    int error;
    error = git_reference_has_log(repo,ref_name);
    handle_error(error,"libgit:reference:reference_has_log");     
    
    plhs[0] = int32__to_mx(error);
    mxFree((void *)ref_name);

}

void reference_is_branch(MEX_DEF_INPUT){
    //  out = mex(3,15,ref)
    //
    //int git_reference_is_branch(const git_reference *ref);

    git_reference *ref = get_reference_input(prhs[2]);

    int error;
    error = git_reference_is_branch(ref);
    handle_error(error,"libgit:reference:reference_is_branch");     

    plhs[0] = int32__to_mx(error);
}

void reference_is_note(MEX_DEF_INPUT){
    //  mex(3,16,ref)
    //
    //int git_reference_is_note(const git_reference *ref);
    
    git_reference *ref = get_reference_input(prhs[2]);

    int error;
    error = git_reference_is_note(ref);
    handle_error(error,"libgit:reference:reference_is_note");     

    plhs[0] = int32__to_mx(error);

}

void reference_is_remote(MEX_DEF_INPUT){
    //  mex(3,17,ref)
    //
    //int git_reference_is_remote(const git_reference *ref);

    git_reference *ref = get_reference_input(prhs[2]);

    int error;
    error = git_reference_is_remote(ref);
    handle_error(error,"libgit:reference:reference_is_remote");     

    plhs[0] = int32__to_mx(error);

}

void reference_is_tag(MEX_DEF_INPUT){
    //  mex(3,18,ref)
    //
    //int git_reference_is_tag(const git_reference *ref);

    git_reference *ref = get_reference_input(prhs[2]);

    int error;
    error = git_reference_is_tag(ref);
    handle_error(error,"libgit:reference:reference_is_tag");     

    plhs[0] = int32__to_mx(error);

}

void reference_is_valid_name(MEX_DEF_INPUT){
    //  mex(3,19,ref_name)
    //
    //int git_reference_is_valid_name(const char *refname);

    const char *ref_name = mxArrayToString(prhs[3]);

    int error;
    error = git_reference_is_valid_name(ref_name);
    handle_error(error,"libgit:reference:reference_is_valid_name");  
    
    plhs[0] = int32__to_mx(error);
    mxFree((void *)ref_name);
}

void reference_iterator_free(MEX_DEF_INPUT){
    //  mex(3,20)
}

void reference_iterator_glob_new(MEX_DEF_INPUT){
    //  mex(3,21)
}

void reference_iterator_new(MEX_DEF_INPUT){
    //  mex(3,22)
}

void reference_list(MEX_DEF_INPUT){
    //  
    //  list = mex(3,23,repo)
    //
    //Fill a list with all the references that can be found in a repository.
    //
    //int git_reference_list(git_strarray *array, git_repository *repo);

    git_repository *repo = mx_to_git_repo(prhs[2]);
    git_strarray array;
    int error = git_reference_list(&array,repo);
    handle_error(error,"libgit:reference:reference_list");
    
    plhs[0] = git_strarray__to_mx(&array,1);
}

void reference_lookup(MEX_DEF_INPUT){
    //
    //  Calling form:
    //  ref = mex(1,24,repo,ref_name);
    
    //int git_reference_lookup(git_reference **out, git_repository *repo, const char *name);
    git_repository *repo = mx_to_git_repo(prhs[2]);
    const char *ref_name = mxArrayToString(prhs[3]);
    
    git_reference *ref = NULL;
    int error = git_reference_lookup(&ref, repo, ref_name);
    mxFree((void *)ref_name);
    handle_error(error,"libgit:reference:reference_lookup");
    
    plhs[0] = git_reference__to_mx(ref);
}

void reference_name(MEX_DEF_INPUT){
    //
    //  mex(3,25,ref)
    //
    //  Get the full name of a reference.
    //
    //  const char * git_reference_name(const git_reference *ref);

    git_reference *ref = get_reference_input(prhs[2]);
    const char *str = git_reference_name(ref);
    plhs[0] = string__to_mx(str);

}

void reference_name_to_id(MEX_DEF_INPUT){
    //Lookup a reference by name and resolve immediately to OID.
    //
    //  id = mex(3,26,repo,ref_name)
    //  
    //  int git_reference_name_to_id(git_oid *out, git_repository *repo, const char *name);
    
    git_repository *repo = mx_to_git_repo(prhs[2]);
    const char *ref_name = mxArrayToString(prhs[3]);
    
    //int git_reference_name_to_id(git_oid *out, git_repository *repo, const char *name);
    git_oid oid;
    int error = git_reference_name_to_id(&oid,repo,ref_name);
    handle_error(error,"libgit:reference:ref_to_id");
    
    //oid is type: unsigned char [20]
    //TODO: I think we might need a memcpy ...?
    
    plhs[0] = git_oid__to_mx(&oid);
    
    mxFree((void *)ref_name);
}

void reference_next(MEX_DEF_INPUT){
    //27
}

void reference_next_name(MEX_DEF_INPUT){
    //28
}

void reference_normalize_name(MEX_DEF_INPUT){

}

void reference_owner(MEX_DEF_INPUT){

}

void reference_peel(MEX_DEF_INPUT){

}

void reference_remove(MEX_DEF_INPUT){

}

void reference_rename(MEX_DEF_INPUT){

}

void reference_resolve(MEX_DEF_INPUT){

}

void reference_set_target(MEX_DEF_INPUT){

}

void reference_shorthand(MEX_DEF_INPUT){
    //
    //
    //
    
    git_reference *ref = get_reference_input(prhs[2]);
    
    //const char * git_reference_shorthand(const git_reference *ref);   
    
    const char *shorthand = git_reference_shorthand(ref);
    
    plhs[0] = mxCreateString(shorthand);
}

void reference_symbolic_create(MEX_DEF_INPUT){

}
void reference_symbolic_create_matching(MEX_DEF_INPUT){

}
void reference_symbolic_set_target(MEX_DEF_INPUT){

}
void reference_symbolic_target(MEX_DEF_INPUT){

}
void reference_target(MEX_DEF_INPUT){

}
void reference_target_peel(MEX_DEF_INPUT){

}
void reference_type(MEX_DEF_INPUT){

}


void reference(MEX_DEF_INPUT)
{
    int error;
    int sub_type = (int)mxGetScalar(prhs[1]);
    
    switch (sub_type) {
        case 1:
            //git_reference__alloc
            reference_alloc(MEX_INPUT);
            break;
        case 2:
            //git_reference__alloc_symbolic
            reference_alloc_symbolic(MEX_INPUT);
            break;
        case 3:
            //git_reference_cmp
            reference_cmp(MEX_INPUT);
            break;
        case 4:
            //git_reference_create
            reference_create(MEX_INPUT);
            break;
        case 5:
            //git_reference_create_matching
            reference_create_matching(MEX_INPUT);
            break;
        case 6:
            //git_reference_delete
            reference_delete(MEX_INPUT);
            break;
        case 7:
            //git_reference_dup
            reference_dup(MEX_INPUT);
            break;
        case 8:
            //git_reference_dwim
            reference_dwim(MEX_INPUT);
            break;
        case 9:
            //git_reference_ensure_log
            reference_ensure_log(MEX_INPUT);
            break;
        case 10:
            //git_reference_foreach
            reference_foreach(MEX_INPUT);
            break;
        case 11:
            //git_reference_foreach_glob
            reference_foreach_glob(MEX_INPUT);
            break;
        case 12:
            //git_reference_foreach_name
            reference_foreach_name(MEX_INPUT);
            break;
        case 13:
            //Free Remote
            //mex(3,13,ref_pointer)
            reference_free(MEX_INPUT);
            break;
        case 14:
            //git_reference_has_log
            reference_has_log(MEX_INPUT);
            break;
        case 15:
            //git_reference_is_branch
            reference_is_branch(MEX_INPUT);
            break;
        case 16:
            //git_reference_is_note
            reference_is_note(MEX_INPUT);
            break;
        case 17:
            //git_reference_is_remote
            reference_is_remote(MEX_INPUT);
            break;
        case 18:
            //git_reference_is_tag
            reference_is_tag(MEX_INPUT);
            break;
        case 19:
            //git_reference_is_valid_name
            reference_is_valid_name(MEX_INPUT);
            break;
        case 20:
            //git_reference_iterator_free
            reference_iterator_free(MEX_INPUT);
            break;
        case 21:
            //git_reference_iterator_glob_new
            reference_iterator_glob_new(MEX_INPUT);
            break;
        case 22:
            //git_reference_iterator_new
            reference_iterator_new(MEX_INPUT);
            break;
        case 23:
            //git_reference_list
            reference_list(MEX_INPUT);
            break;
        case 24:
            //git_reference_lookup
            reference_lookup(MEX_INPUT);
            break;
        case 25:
            //git_reference_name
            reference_name(MEX_INPUT);
            break;
        case 26:
            //git_reference_name_to_id
            reference_name_to_id(MEX_INPUT);
            break;
        case 27:
            //git_reference_next
            reference_next(MEX_INPUT);
            break;
        case 28:
            //git_reference_next_name
            reference_next_name(MEX_INPUT);
            break;
        case 29:
            //git_reference_normalize_name
            reference_normalize_name(MEX_INPUT);
            break;
        case 30:
            //git_reference_owner
            reference_owner(MEX_INPUT);
            break;
        case 31:
            //git_reference_peel
            reference_peel(MEX_INPUT);
            break;
        case 32:
            //git_reference_remove
            reference_remove(MEX_INPUT);
            break;
        case 33:
            //git_reference_rename
            reference_rename(MEX_INPUT);
            break;
        case 34:
            //git_reference_resolve
            reference_resolve(MEX_INPUT);
            break;
        case 35:
            //git_reference_set_target
            reference_set_target(MEX_INPUT);
            break;
        case 36:
            //reference_shorthand
            reference_shorthand(MEX_INPUT);
            break;
        case 37:
            //git_reference_symbolic_create
            reference_symbolic_create(MEX_INPUT);
            break;
        case 38:
            //git_reference_symbolic_create_matching
            reference_symbolic_create_matching(MEX_INPUT);
            break;
        case 39:
            //git_reference_symbolic_set_target
            reference_symbolic_set_target(MEX_INPUT);
            break;
        case 40:
            //git_reference_symbolic_target
            reference_symbolic_target(MEX_INPUT);
            break;
        case 41:
            //git_reference_target
            reference_target(MEX_INPUT);
            break;
        case 42:
            //git_reference_target_peel
            reference_target_peel(MEX_INPUT);
            break;
        case 43:
            //git_reference_type
            reference_type(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","commit.h, input sub-type not recognized");
            
    }
}

// %01 git_reference__alloc
// %02 git_reference__alloc_symbolic
// %03 git_reference_cmp
// %04 git_reference_create
// %05 git_reference_create_matching
// %06 git_reference_delete
// %07 git_reference_dup
// %08 git_reference_dwim
// %09 git_reference_ensure_log
// %10 git_reference_foreach
// %11 git_reference_foreach_glob
// %12 git_reference_foreach_name
// %13 git_reference_free
// 
// %x 14 git_reference_has_log
// %x 15 git_reference_is_branch
// %x 16 git_reference_is_note
// %x 17 git_reference_is_remote
// %x 18 git_reference_is_tag
// %x 19 git_reference_is_valid_name
// %x 20 git_reference_iterator_free
// %x 21 git_reference_iterator_glob_new
// %22 git_reference_iterator_new
// %23 git_reference_list
// %x 24 git_reference_lookup
// %25 git_reference_name
// %x 26 git_reference_name_to_id
// %27 git_reference_next
// %28 git_reference_next_name
// %29 git_reference_normalize_name
// %30 git_reference_owner
// %31 git_reference_peel
// %32 git_reference_remove
// %33 git_reference_rename
// %34 git_reference_resolve
// %35 git_reference_set_target
// %36 git_reference_shorthand
// %37 git_reference_symbolic_create
// %38 git_reference_symbolic_create_matching
// %39 git_reference_symbolic_set_target
// %40 git_reference_symbolic_target
// %41 git_reference_target - Get the OID pointed to by a direct reference
// %42 git_reference_target_peel
// %43 git_reference_type