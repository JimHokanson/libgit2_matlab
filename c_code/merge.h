#include "mex.h"

//https://libgit2.github.com/libgit2/#HEAD/group/config

void merge(MEX_DEF_INPUT){
    //1 - Merges the given commit(s) into HEAD, writing the results into 
    //the working directory. Any changes are staged for commit and any 
    //conflicts are written to the index. Callers should inspect the 
    //repository's index after this completes, resolve any conflicts 
    //and prepare a commit.
    //
    //  For compatibility with git, the repository is put into a merging state. 
    //  Once the commit is done (or if the uses wishes to abort), you should 
    //  clear this state by calling git_repository_state_cleanup().
    //
    //  int git_merge(git_repository *repo, const git_annotated_commit **their_heads, 
    //      size_t their_heads_len, const git_merge_options *merge_opts, 
    //      const git_checkout_options *checkout_opts);
}

void merge_analysis(MEX_DEF_INPUT){
    //2 - Analyzes the given branch(es) and determines the opportunities 
    //  for merging them into the HEAD of the repository.
    //
    //  int git_merge_analysis(git_merge_analysis_t *analysis_out, 
    //          git_merge_preference_t *preference_out, git_repository *repo, 
    //          const git_annotated_commit **their_heads, size_t their_heads_len);

}

void merge_base(MEX_DEF_INPUT){
    //3 - Find a merge base between two commits
    //
    //  int git_merge_base(git_oid *out, git_repository *repo, 
    //              const git_oid *one, const git_oid *two);

}

void merge_base_many(MEX_DEF_INPUT){
    //4 - Find a merge base given a list of commits
    //
    //  int git_merge_base_many(git_oid *out, git_repository *repo, 
    //          size_t length, const git_oid [] input_array);

}


void merge_base_octopus(MEX_DEF_INPUT){
    //5 - Find a merge base in preparation for an octopus merge
    //
    //  int git_merge_base_octopus(git_oid *out, git_repository *repo, 
    //          size_t length, const git_oid [] input_array);

}


void merge_bases(MEX_DEF_INPUT){
    //6 - Find merge bases between two commits
    //
    //  int git_merge_bases(git_oidarray *out, git_repository *repo, 
    //              const git_oid *one, const git_oid *two);

}


void merge_bases_many(MEX_DEF_INPUT){
    //7 - Find all merge bases given a list of commits
    //
    //  int git_merge_bases_many(git_oidarray *out, git_repository *repo, 
    //          size_t length, const git_oid [] input_array);

    
}


void merge_commits(MEX_DEF_INPUT){
    //8 - Merge two commits, producing a git_index that reflects the result 
    //  of the merge. The index may be written as-is to the working directory 
    //  or checked out. If the index is to be converted to a tree, the 
    //  caller should resolve any conflicts that arose as part of the merge.
    //
    //int git_merge_commits(git_index **out, git_repository *repo, 
    //      const git_commit *our_commit, const git_commit *their_commit, 
    //      const git_merge_options *opts);
}



void merge_file(MEX_DEF_INPUT){
    //9 - Merge two files as they exist in the in-memory data structures, 
    //  using the given common ancestor as the baseline, producing a 
    //  git_merge_file_result that reflects the merge result. The 
    //  git_merge_file_result must be freed with git_merge_file_result_free.
    //
    //  Note that this function does not reference a repository and any 
    //  configuration must be passed as git_merge_file_options.
    //
    //int git_merge_file(git_merge_file_result *out, 
    //      const git_merge_file_input *ancestor, const git_merge_file_input *ours, 
    //      const git_merge_file_input *theirs, const git_merge_file_options *opts);
}


void merge_file_from_index(MEX_DEF_INPUT){
    //10 - Merge two files as they exist in the index, using the given common
    //ancestor as the baseline, producing a git_merge_file_result that 
    //reflects the merge result. The git_merge_file_result must be freed 
    //with git_merge_file_result_free.
    //
    //int git_merge_file_from_index(git_merge_file_result *out, git_repository *repo, 
    //      const git_index_entry *ancestor, const git_index_entry *ours, 
    //      const git_index_entry *theirs, const git_merge_file_options *opts);
}


void merge_file_init_input(MEX_DEF_INPUT){
    //11 - Initializes a git_merge_file_input with default values. Equivalent
    //  to creating an instance with GIT_MERGE_FILE_INPUT_INIT.
    //
    //int git_merge_file_init_input(git_merge_file_input *opts, unsigned int version);

}


void merge_file_init_options(MEX_DEF_INPUT){
    //12
}


void merge_file_result_free(MEX_DEF_INPUT){
    //13
}


void merge_init_options(MEX_DEF_INPUT){
    //14
}


void merge_trees(MEX_DEF_INPUT){
    //15
}



void merge(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            merge(MEX_INPUT);
            break;
        case 2:
            merge_analysis(MEX_INPUT);
            break;
        case 3:
            merge_base(MEX_INPUT);
            break;
        case 4:
            merge_base_many(MEX_INPUT);
            break;
        case 5:
            merge_base_octopus(MEX_INPUT);
            break;
        case 6:
            merge_bases(MEX_INPUT);
            break;
        case 7:
            merge_bases_many(MEX_INPUT);
            break;
        case 8:
            merge_commits(MEX_INPUT);
            break;
        case 9:
            merge_file(MEX_INPUT);
            break;
        case 10:
            merge_file_from_index(MEX_INPUT);
            break;
        case 11:
            merge_file_init_input(MEX_INPUT);
            break;
        case 12:
            merge_file_init_options(MEX_INPUT);
            break;
        case 13:
            merge_file_result_free(MEX_INPUT);
            break;
        case 14:
            merge_init_options(MEX_INPUT);
            break;
        case 15:
            merge_trees(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:merge","merge.h, input sub-type not recognized");
    }
}


//1 git_merge
//2 git_merge_analysis
//3 git_merge_base
//4 git_merge_base_many
//5 git_merge_base_octopus
//6 git_merge_bases
//7 git_merge_bases_many
//8 git_merge_commits
//9 git_merge_file
//10 git_merge_file_from_index
//11 git_merge_file_init_input
//12 git_merge_file_init_options
//13 git_merge_file_result_free
//14 git_merge_init_options
//15 git_merge_trees
