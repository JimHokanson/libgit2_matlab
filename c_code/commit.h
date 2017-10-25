#include <stdint.h>
#include "libgit_utils.h"

//2

void commit_amend(MEX_DEF_INPUT){
    //1 - Amend an existing commit by replacing only non-NULL values.
    //
    //  libgit(2,1,...
    //
    //
    //
    //int git_commit_amend(git_oid *id, const git_commit *commit_to_amend, 
    //      const char *update_ref, const git_signature *author, 
    //      const git_signature *committer, const char *message_encoding, 
    //      const char *message, const git_tree *tree);

}

void commit_author(MEX_DEF_INPUT){
    //2 - DONE
    //
    //  libgit(2,2,commit)
    //
    //const git_signature * git_commit_author(const git_commit *commit);
    
    //TODO: error checking 
    
    git_commit* commit = mx_to_git_commit(prhs[2]);
    const git_signature *s = git_commit_author(commit);
    plhs[0] = git_signature__to_mx(s);
}

void commit_body(MEX_DEF_INPUT){
    //3 - DONE
    //
    //  libgit(2,3,commit)
    //
    //const char * git_commit_body(git_commit *commit);
    
    //TODO: error checking 
    
    git_commit* commit = mx_to_git_commit(prhs[2]);
    const char *body = git_commit_body(commit);
    plhs[0] = string__to_mx(body);
}

void commit_committer(MEX_DEF_INPUT){
    //4
    //
    //const git_signature * git_commit_committer(const git_commit *commit);
    git_commit* commit = mx_to_git_commit(prhs[2]);
    const git_signature *s = git_commit_committer(commit);
    plhs[0] = git_signature__to_mx(s);
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
    //
    //Create a commit and write it into a buffer
    //
    //int git_commit_create_buffer(git_buf *out, git_repository *repo, 
    //      const git_signature *author, const git_signature *committer, 
    //      const char *message_encoding, const char *message, 
    //      const git_tree *tree, size_t parent_count, const git_commit *[] parents);


}

void commit_create_from_callback(MEX_DEF_INPUT){
    //7
    //
    //int git_commit_create_from_callback(git_oid *id, git_repository *repo, 
    //      const char *update_ref, const git_signature *author, 
    //      const git_signature *committer, const char *message_encoding, 
    //      const char *message, const git_oid *tree, 
    //      git_commit_parent_callback parent_cb, void *parent_payload);
}

void commit_create_from_ids(MEX_DEF_INPUT){
    //8
    //
    //Create new commit in the repository from a list of git_oid values.
    //
    //int git_commit_create_from_ids(git_oid *id, git_repository *repo, 
    //  const char *update_ref, const git_signature *author, 
    //  const git_signature *committer, const char *message_encoding, 
    //  const char *message, const git_oid *tree, size_t parent_count, 
    //  const git_oid *[] parents);

}

void commit_create_v(MEX_DEF_INPUT){
    //9
    //
    //Create new commit in the repository using a variable argument list.


}

void commit_create_with_signature(MEX_DEF_INPUT){
    //10
}

void commit_dup(MEX_DEF_INPUT){
    //11
}

void commit_extract_signature(MEX_DEF_INPUT){
    //12
    //
    //Extract the signature from a commit
    //
    //int git_commit_extract_signature(git_buf *signature, git_buf *signed_data, 
    //      git_repository *repo, git_oid *commit_id, const char *field);

}

void commit_free(MEX_DEF_INPUT){
    //13
    //
    //  Calling form:
    //  commit = mex(2,13,commit);
    
    //TODO: Change this calling format
    git_commit *commit = mx_to_git_commit(prhs[2]);
    
    //TODO: Make the actual free call
}

void commit_header_field(MEX_DEF_INPUT){
    //14
    //
    //Get an arbitrary header field
    //
    //int git_commit_header_field(git_buf *out, const git_commit *commit, 
    //  const char *field);

}

void commit_id(MEX_DEF_INPUT){
    //15
    //
    //const git_oid * git_commit_id(const git_commit *commit);
    
    git_commit* commit = mx_to_git_commit(prhs[2]);
    const git_oid *oid = git_commit_id(commit);
    plhs[0] = git_oid__to_mx(oid);
}

void commit_lookup(MEX_DEF_INPUT){
    //16
    //
    //
    //  Calling form:
    //  commit = mex(2,22,repo,oid);
    //  
    //int git_commit_lookup(git_commit **commit, git_repository *repo, 
    //      const git_oid *id);
    
    git_repository *repo = mx_to_git_repo(prhs[2]);
    const git_oid *oid = get_oid_input(prhs[3]);
    git_commit *commit = NULL;
    int error = git_commit_lookup(&commit,repo,oid);
    handle_error(error,"libgit:commit:commit_lookup");    
    plhs[0] = git_commit__to_mx(commit);
}

void commit_lookup_prefix(MEX_DEF_INPUT){
    //17 - Lookup a commit object from a repository, given a prefix of its 
    //identifier (short id).
    //
    //int git_commit_lookup_prefix(git_commit **commit, git_repository *repo, 
    //      const git_oid *id, size_t len);
    //
    //  size_t len - length of the short identifier ...
    //

}

void commit_message(MEX_DEF_INPUT){
    //18 - Get the full message of a commit.
    //
    //  message = mex(2,18,commit);
    //
    //const char * git_commit_message(const git_commit *commit);
    
    if (nrhs != 3){
        mexErrMsgIdAndTxt("libgit:commit:commit_message",
                "Incorrect # of inputs, 3 expected");
    }
    
    git_commit* commit = mx_to_git_commit(prhs[2]);
    const char *body = git_commit_message(commit);    
    plhs[0] = string__to_mx(body);
}

void commit_message_encoding(MEX_DEF_INPUT){
    //19
    //
    //  encoding = mex(2,19,commit);
    //
    //Get the encoding for the message of a commit, as a string 
    //representing a standard encoding name.
    //
    //  If null, then UTF-8
    //
    //const char * git_commit_message_encoding(const git_commit *commit);
    
    git_commit* commit = mx_to_git_commit(prhs[2]);
    const char *encoding = git_commit_message_encoding(commit);
    plhs[0] = string__to_mx(encoding);
}

void commit_message_raw(MEX_DEF_INPUT){
    //20
    //
    //Get the full raw message of a commit.
    //
    //  message = mex(2,20,commit)
    //
    //const char * git_commit_message_raw(const git_commit *commit);
    
    git_commit* commit = mx_to_git_commit(prhs[2]);
    const char *body = git_commit_message_raw(commit);
    plhs[0] = string__to_mx(body);
}

void commit_nth_gen_ancestor(MEX_DEF_INPUT){
    //21 - Get the commit object that is the <nth generation ancestor of the 
    //  named commit object, following only the first parents. The returned 
    //  commit has to be freed by the caller.
    //
    //  ancestor = mex(2,21,commit,n)
    //
    //
    //
    //int git_commit_nth_gen_ancestor(git_commit **ancestor, const git_commit *commit, unsigned int n);
    
    if (nrhs != 4){
        mexErrMsgIdAndTxt("libgit:commit:nth_gen_ancestor",
                "Incorrect # of inputs, 4 expected");
    }
    
    git_commit* commit = mx_to_git_commit(prhs[2]);
    git_commit* ancestor;
    
    if (!mxIsClass(prhs[3],"double")){
    	mexErrMsgIdAndTxt("libgit:commit:nth_gen_ancestor",
                "4th input must be of type double");
    }
    
    double n = mxGetScalar(prhs[3]);
    int error = git_commit_nth_gen_ancestor(&ancestor,commit,(unsigned int)n);
    handle_error(error,"libgit:commit:nth_gen_ancestor");
    plhs[0] = git_commit__to_mx(ancestor);
}

void commit_owner(MEX_DEF_INPUT){
    //22 - Get the repository that contains the commit.
    //
    //  repo = mex(2,22,commit)
    //
    //git_repository * git_commit_owner(const git_commit *commit);

    if (nrhs != 4){
        mexErrMsgIdAndTxt("libgit:commit:commit_owner",
                "Incorrect # of inputs, 4 expected");
    }
    
    git_commit* commit = mx_to_git_commit(prhs[2]);
    
    git_repository* repo = git_commit_owner(commit);
    
    //TODO: Can this throw an error? repo be null?
    plhs[0] = git_repository__to_mx(repo);
}

void commit_parent(MEX_DEF_INPUT){
    //23 - Get the specified parent of the commit.
    //
    //  commit = libgit(2,23,commit,n)
    //
    //
    //  int git_commit_parent(git_commit **out, const git_commit *commit, 
    //      unsigned int n);
    //
    //  n - from 0 to parentcount
    //
    //  Isn't 0 non-functional?
    
    
    if (nrhs != 4){
        mexErrMsgIdAndTxt("libgit:commit:commit_parent","Incorrect # of inputs, 4 expected");
    }
    
    if (!mxIsClass(prhs[3],"double")){
    	mexErrMsgIdAndTxt("libgit:commit:commit_parent","4th input must be of type double");
    }
    
    double n = mxGetScalar(prhs[3]);
    
    git_commit* commit = mx_to_git_commit(prhs[2]);
    git_commit* parent;
    int response = git_commit_parent(&parent, commit, (unsigned int) n);
    handle_error(response,"libgit:commit:commit_parent");
    plhs[0] = git_commit__to_mx(parent);
}

void commit_parent_id(MEX_DEF_INPUT){
    //24 - Get the oid of a specified parent for a commit. This is different 
    //from git_commit_parent, which will attempt to load the parent commit 
    //from the ODB.
    //
    //  id = mex(2,24,commit,n);  
    //
    //
    //const git_oid * git_commit_parent_id(const git_commit *commit, unsigned int n);

    if (nrhs != 4){
        mexErrMsgIdAndTxt("libgit:commit:commit_parent_id","Incorrect # of inputs, 4 expected");
    }
    
    git_commit* commit = mx_to_git_commit(prhs[2]);

    
    if (!mxIsClass(prhs[3],"double")){
    	mexErrMsgIdAndTxt("libgit:commit:commit_parent_id","4th input must be of type double");
    }
    
    double n = mxGetScalar(prhs[3]);
    
    const git_oid* id = git_commit_parent_id(commit,(unsigned int)n);
    
    if (!id){
        mexErrMsgIdAndTxt("libgit:commit:commit_parent_id","Error detected in retrieving parent id, null id returned");
    }
    
    plhs[0] = git_oid__to_mx(id);
}

void commit_parentcount(MEX_DEF_INPUT){
    //25 - Get the number of parents of this commit
    //
    //  count = mex(2,25,commit);
    //
    //unsigned int git_commit_parentcount(const git_commit *commit);
    
    if (nrhs != 3){
        mexErrMsgIdAndTxt("libgit:commit:commit_parentcount","Incorrect # of inputs, 3 expected");
    }
    
    git_commit* commit = mx_to_git_commit(prhs[2]);
    
    unsigned int count = git_commit_parentcount(commit);

    plhs[0] = uint32__to_mx((uint32_t)count);

}

void commit_raw_header(MEX_DEF_INPUT){
    //26 - Get the full raw text of the commit header.
    //
    //const char * git_commit_raw_header(const git_commit *commit);
    
    
}

void commit_summary(MEX_DEF_INPUT){
    //27
    //
    //const char * git_commit_summary(git_commit *commit);
    git_commit* commit = mx_to_git_commit(prhs[2]);
    const char *summary = git_commit_summary(commit);
    plhs[0] = string__to_mx(summary);
}

void commit_time(MEX_DEF_INPUT){
    //28 - Get the commit time (i.e. committer time) of a commit.
    //
    //git_time_t git_commit_time(const git_commit *commit);


}

void commit_time_offset(MEX_DEF_INPUT){
    //29 - Get the commit timezone offset (i.e. committer's preferred timezone) of a commit.
    //
    //int git_commit_time_offset(const git_commit *commit);
    //
    
    if (nrhs != 3){
        mexErrMsgIdAndTxt("libgit:commit:commit_time_offset","Incorrect # of inputs, 3 expected");
    }
    
    git_commit* commit = mx_to_git_commit(prhs[2]);
    
    int response = git_commit_time_offset(commit);
    //What about an error?
    
    plhs[0] = int32__to_mx(response);

}

void commit_tree(MEX_DEF_INPUT){
    //30 - Get the tree pointed to by a commit.
    //
    //  tree = mex(2,30,commit); 
    //
    //int git_commit_tree(git_tree **tree_out, const git_commit *commit);

    if (nrhs != 3){
        mexErrMsgIdAndTxt("libgit:commit:commit_tree","Incorrect # of inputs, 3 expected");
    }
    
    git_commit* commit = mx_to_git_commit(prhs[2]);
    
    git_tree *tree_out;
    
    int response =  git_commit_tree(&tree_out, commit);
    handle_error(response,"libgit:commit:commit_tree");

    plhs[0] = git_tree_list__to_mx(tree_out);
}

void commit_tree_id(MEX_DEF_INPUT){
    //31 - Get the id of the tree pointed to by a commit. This differs from 
    //git_commit_tree in that no attempts are made to fetch an object 
    //from the ODB.
    //
    //  tree_id = mex(2,31,commit); 
    //
    //const git_oid * git_commit_tree_id(const git_commit *commit);
    
    if (nrhs != 3){
        mexErrMsgIdAndTxt("libgit:commit:commit_tree_id","Incorrect # of inputs, 3 expected");
    }
    
    git_commit* commit = mx_to_git_commit(prhs[2]);
    
    const git_oid * tree_id = git_commit_tree_id(commit);
    
    //How is an error indicated?
    
    plhs[0] = git_oid__to_mx(tree_id);

}







void commit(MEX_DEF_INPUT)
{
    int response;
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