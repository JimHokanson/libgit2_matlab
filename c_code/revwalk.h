#include "mex.h"

//Status - nearly complete but it needs error checking


//https://stackoverflow.com/questions/42347428/how-can-i-check-if-pull-is-needed-using-libgit2-in-c
//https://libgit2.github.com/docs/guides/101-samples/#revwalk
//https://libgit2.github.com/libgit2/#HEAD/group/revwalk

// git_revwalk *walker;
// git_revwalk_new(&walker, repo);
// git_revwalk_push_ref(walker, "refs/remotes/origin/master");
// git_revwalk_hide_ref(walker, "refs/heads/master");
// 
// git_oid id;
// int count = 0;
// while (!git_revwalk_next(&id, walker))
//     ++count;


//pushing - marks starting points
//hiding - marks stopping points

void revwalk_add_hide_cb(MEX_DEF_INPUT){
    //1
    //
    //  mex(52,1)
    //
    //  Adds a callback function to hide a commit and its parents
    //
    //int git_revwalk_add_hide_cb(git_revwalk *walk, git_revwalk_hide_cb hide_cb, void *payload);

}

void revwalk_free(MEX_DEF_INPUT){
    //2 - DONE
    //
    //  mex(52,2,walk)
    //
    //  Free a revision walker previously allocated.
    //
    //  void git_revwalk_free(git_revwalk *walk);
    
    git_revwalk * walk = mx_to_git_revwalk(prhs[2]);
    git_revwalk_free(walk);
}
void revwalk_hide(MEX_DEF_INPUT){
    //3 - DONE
    //
    //  mex(52,3,walk,commit_oid)
    //
    //  Mark a commit (and its ancestors) uninteresting for the output.
    //
    //  int git_revwalk_hide(git_revwalk *walk, const git_oid *commit_id);
    
    git_revwalk * walk = mx_to_git_revwalk(prhs[2]);
    const git_oid * commit_id = mx_to_git_oid(prhs[3]);
    int response = git_revwalk_hide(walk,commit_id);
    handle_error(response,"libgit:revwalk:revwalk_hide");
}
void revwalk_hide_glob(MEX_DEF_INPUT){
    //4 - DONE
    //
    //  mex(52,4,walk,glob)
    //
    //  Hide matching references.
    //
    //  int git_revwalk_hide_glob(git_revwalk *walk, const char *glob);

    //error = git_revwalk_push_glob(walker, "tags/*");

    git_revwalk * walk = mx_to_git_revwalk(prhs[2]);
    const char * glob = mx_to_char(prhs[3]);
    int response = git_revwalk_hide_glob(walk,glob);
    handle_error(response,"libgit:revwalk:revwalk_hide_glob");
    mxFree((void *)glob);

}
void revwalk_hide_head(MEX_DEF_INPUT){
    //5 - DONE
    //
    //  mex(52,5,rev_walk)
    //
    //  Hide the repository's HEAD
    //
    //  int git_revwalk_hide_head(git_revwalk *walk);
    
    git_revwalk * walk = mx_to_git_revwalk(prhs[2]);
    int response = git_revwalk_hide_head(walk);
    handle_error(response,"libgit:revwalk:revwalk_hide_head");
}
void revwalk_hide_ref(MEX_DEF_INPUT){
    //6 - DONE
    //
    //  mex(52,6,rev_walk,ref_name)
    //
    //Hide the OID pointed to by a reference
    //
    //int git_revwalk_hide_ref(git_revwalk *walk, const char *refname);

    
    git_revwalk * walk = mx_to_git_revwalk(prhs[2]);
    const char * ref_name = mx_to_char(prhs[3]);
    int response = git_revwalk_hide_ref(walk,ref_name);
    handle_error(response,"libgit:revwalk:revwalk_hide_ref"); 
    mxFree((void *)ref_name);
}
void revwalk_new(MEX_DEF_INPUT){
    //7 - DONE
    //
    //    libgit(52,7,repo)
    //
    //Allocate a new revision walker to iterate through a repo.
    //
    //int git_revwalk_new(git_revwalk **out, git_repository *repo);
    //
    //  int: 0 or an error code

    git_repository* repo = mx_to_git_repo(prhs[2]);
    git_revwalk *out;
    int response = git_revwalk_new(&out,repo);  
    handle_error(response,"libgit:revwalk:revwalk_new"); 
    plhs[0] = git_revwalk__to_mx(out);
}
void revwalk_next(MEX_DEF_INPUT){
    //8 - DONE
    //
    //  oid = mex(52,8,walk)
    //
    //  Get the next commit from the revision walk.
    //
    //int git_revwalk_next(git_oid *out, git_revwalk *walk);
    //
    //  The output may be null, which we indicate by an empty array.
            
    git_revwalk * walk = mx_to_git_revwalk(prhs[2]);
    git_oid out;
    int response = git_revwalk_next(&out, walk);
    plhs[0] = git_oid_or_null__to_mx(&out);
}
void revwalk_push(MEX_DEF_INPUT){
    //9 - DONE
    //
    //  libgit(52,9,walk,id)
    //
    //Add a new root for the traversal
    //
    //int git_revwalk_push(git_revwalk *walk, const git_oid *id);
    
    //This is is throwing a warning with parameters
    
    git_revwalk * walk = mx_to_git_revwalk(prhs[2]);
    const git_oid * commit_id = mx_to_git_oid(prhs[3]);
    int response = git_revwalk_push(walk, commit_id);
    handle_error(response,"libgit:revwalk:revwalk_push");
}
void revwalk_push_glob(MEX_DEF_INPUT){
    //10
    //
    //  mex(52,10,walk,glob)
    //
    //Push matching references
    //
    //int git_revwalk_push_glob(git_revwalk *walk, const char *glob);


    git_revwalk * walk = mx_to_git_revwalk(prhs[2]);
    const char * glob = mx_to_char(prhs[3]);
    int response = git_revwalk_push_glob(walk, glob);
    handle_error(response,"libgit:revwalk:revwalk_push");
    mxFree((void *)glob);

}
void revwalk_push_head(MEX_DEF_INPUT){
    //11 - DONE
    //
    //  mex(52,11,walk)
    //
    //Push the repository's HEAD
    //
    //int git_revwalk_push_head(git_revwalk *walk);

    git_revwalk * walk = mx_to_git_revwalk(prhs[2]);
    int response = git_revwalk_push_head(walk);
    handle_error(response,"libgit:revwalk:revwalk_push_head"); 
    

}
void revwalk_push_range(MEX_DEF_INPUT){
    //12 - DONE
    //
    //  mex(52,12,walk,range)
    //
    //Push and hide the respective endpoints of the given range.
    //
    //int git_revwalk_push_range(git_revwalk *walk, const char *range);

    //Example usage code:
    //------------------------
    // git_revwalk *walker;
    // int error = git_revwalk_new(&walker, repo);
    // error = git_revwalk_push_range(walker, "HEAD~20..HEAD");
    // git_oid oid;
    // while (!git_revwalk_next(&oid, walker)) {
    //   /* ? */
    // }    

    git_revwalk * walk = mx_to_git_revwalk(prhs[2]);
    const char * range = mx_to_char(prhs[3]);
    int response = git_revwalk_push_range(walk,range);
    handle_error(response,"libgit:revwalk:revwalk_push_range"); 
    mxFree((void *)range);    
}
void revwalk_push_ref(MEX_DEF_INPUT){
    //13 - DONE
    //
    //  mex(52,13,walk,refname)
    //
    //Push the OID pointed to by a reference
    //
    //int git_revwalk_push_ref(git_revwalk *walk, const char *refname);

    if (nrhs != 4){
        mexErrMsgIdAndTxt("libgit:revwalk:revwalk_push_ref","Incorrect # of inputs, 4 expected");
    }
    
    git_revwalk * walk = mx_to_git_revwalk(prhs[2]);
    const char * ref_name = mx_to_char(prhs[3]);
    int response = git_revwalk_push_ref(walk,ref_name);
    handle_error(response,"libgit:revwalk:revwalk_push_ref"); 
    mxFree((void *)ref_name);
}
void revwalk_repository(MEX_DEF_INPUT){
    //14 - DONE
    //
    //  mex(52,14,walk)
    //
    //Return the repository on which this walker is operating.
    //
    //git_repository * git_revwalk_repository(git_revwalk *walk);
    //
    
    git_revwalk * walk = mx_to_git_revwalk(prhs[2]);
    git_repository * repo = git_revwalk_repository(walk);
    plhs[0] = git_repository__to_mx(repo);

}
void revwalk_reset(MEX_DEF_INPUT){
    //15 - Done
    //
    //  libgit(52,15,walk)
    //
    //  Reset the revision walker for reuse.
    //
    //  void git_revwalk_reset(git_revwalk *walker);

    git_revwalk * walk = mx_to_git_revwalk(prhs[2]);
    git_revwalk_reset(walk);
    

}
void revwalk_simplify_first_parent(MEX_DEF_INPUT){
    //16
    //
    //  mex(52,16,walk)
    //
    //  Simplify the history by first-parent
    //
    //  void git_revwalk_simplify_first_parent(git_revwalk *walk);
    
    git_revwalk * walk = mx_to_git_revwalk(prhs[2]);
    git_revwalk_simplify_first_parent(walk);
}
void revwalk_sorting(MEX_DEF_INPUT){
    //17
    //
    //  mex(52,17,walk,sort_mode)
    //
    //  Change the sorting mode when iterating through the repository's contents.
    //
    //  void git_revwalk_sorting(git_revwalk *walk, unsigned int sort_mode);
    
    git_revwalk * walk = mx_to_git_revwalk(prhs[2]);
    unsigned int sort_mode = (unsigned int) mxGetScalar(prhs[3]);
    git_revwalk_sorting(walk, sort_mode);

}

void revwalk(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            revwalk_add_hide_cb(MEX_INPUT);
            break;
        case 2:
            revwalk_free(MEX_INPUT);
            break;
        case 3:
            revwalk_hide(MEX_INPUT);
            break;
        case 4:
            revwalk_hide_glob(MEX_INPUT);
            break;
        case 5:
            revwalk_hide_head(MEX_INPUT);
            break;
        case 6:
            revwalk_hide_ref(MEX_INPUT);
            break;
        case 7:
            revwalk_new(MEX_INPUT);
            break;
        case 8:
            revwalk_next(MEX_INPUT);
            break;
        case 9:
            revwalk_push(MEX_INPUT);
            break;
        case 10:
            revwalk_push_glob(MEX_INPUT);
            break;
        case 11:
            revwalk_push_head(MEX_INPUT);
            break;
        case 12:
            revwalk_push_range(MEX_INPUT);
            break;
        case 13:
            revwalk_push_ref(MEX_INPUT);
            break;
        case 14:
            revwalk_repository(MEX_INPUT);
            break;
        case 15:
            revwalk_reset(MEX_INPUT);
            break;
        case 16:
            revwalk_simplify_first_parent(MEX_INPUT);
            break;
        case 17:
            revwalk_sorting(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","config.h, input sub-type not recognized");
    }
}

//1  git_revwalk_add_hide_cb
//2  git_revwalk_free
//3  git_revwalk_hide
//4  git_revwalk_hide_glob
//5  git_revwalk_hide_head
//6  git_revwalk_hide_ref
//7  git_revwalk_new
//8  git_revwalk_next
//9  git_revwalk_push
//10 git_revwalk_push_glob
//11 git_revwalk_push_head
//12 git_revwalk_push_range
//13 git_revwalk_push_ref
//14 git_revwalk_repository
//15 git_revwalk_reset
//16 git_revwalk_simplify_first_parent
//17 git_revwalk_sorting


