#include "mex.h"
#include "libgit_utils.h"

//https://libgit2.github.com/libgit2/#HEAD/group/annotated
//
//https://git-scm.com/docs/git-annotate  ???

void annotated_commit_free(MEX_DEF_INPUT){
    //1
    //void git_annotated_commit_free(git_annotated_commit *commit);
}

void annotated_commit_from_fetchhead(MEX_DEF_INPUT){
    //2
    //int git_annotated_commit_from_fetchhead(git_annotated_commit **out, 
    //git_repository *repo, const char *branch_name, const char *remote_url, const git_oid *id);
}

void annotated_commit_from_ref(MEX_DEF_INPUT){
    //3
    //int git_annotated_commit_from_ref(git_annotated_commit **out, git_repository *repo, const git_reference *ref);
    
}

void annotated_commit_from_revspec(MEX_DEF_INPUT){
    //4
    //int git_annotated_commit_from_revspec(git_annotated_commit **out, 
    //git_repository *repo, const char *revspec);
}

void annotated_commit_id(MEX_DEF_INPUT){
    //5
    //const git_oid * git_annotated_commit_id(const git_annotated_commit *commit);
}

void annotated_commit_lookup(MEX_DEF_INPUT){
    //6
    //int git_annotated_commit_lookup(git_annotated_commit **out, git_repository *repo, const git_oid *id);
}

void annotated(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            //git_annotated_commit_free
            annotated_commit_free(MEX_INPUT);
            break;
        case 2:
            //git_annotated_commit_from_fetchhead
            annotated_commit_from_fetchhead(MEX_INPUT);
            break;
        case 3:
            //git_annotated_commit_from_ref
            annotated_commit_from_ref(MEX_INPUT);
            break;
        case 4:
            //git_annotated_commit_from_revspec
            annotated_commit_from_revspec(MEX_INPUT);
            break;
        case 5:
            //git_annotated_commit_id
            annotated_commit_id(MEX_INPUT);
            break;
        case 6:
            //git_annotated_commit_lookup
            annotated_commit_lookup(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","annotated.h, input sub-type not recognized");
    }
}

//01 git_annotated_commit_free
//02 git_annotated_commit_from_fetchhead
//03 git_annotated_commit_from_ref
//04 git_annotated_commit_from_revspec
//05 git_annotated_commit_id
//06 git_annotated_commit_lookup