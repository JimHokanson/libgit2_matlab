#include "mex.h"

void diff_blob_to_buffer(MEX_DEF_INPUT){
    //1
    //
    //  Directly run a diff between a blob and a buffer.
    //
    //int git_diff_blob_to_buffer(const git_blob *old_blob, const char *old_as_path,
    //  const char *buffer, size_t buffer_len, const char *buffer_as_path, 
    //  const git_diff_options *options, git_diff_file_cb file_cb, git_diff_binary_cb binary_cb, 
    //  git_diff_hunk_cb hunk_cb, git_diff_line_cb line_cb, void *payload);
    //
    //
    //As with git_diff_blobs, comparing a blob and buffer lacks some context, 
    //so the git_diff_file parameters to the callbacks will be faked a la the 
    //rules for git_diff_blobs().
    //
    //Passing NULL for old_blob will be treated as an empty blob 
    //(i.e. the file_cb will be invoked with GIT_DELTA_ADDED and the diff 
    //will be the entire content of the buffer added). Passing NULL to the 
    //buffer will do the reverse, with GIT_DELTA_REMOVED and blob content removed.


}

void diff_blobs(MEX_DEF_INPUT){
    //2
    //
    //Directly run a diff on two blobs.
    //
    //int git_diff_blobs(const git_blob *old_blob, const char *old_as_path, 
    //const git_blob *new_blob, const char *new_as_path, const git_diff_options *options, 
    //git_diff_file_cb file_cb, git_diff_binary_cb binary_cb, git_diff_hunk_cb hunk_cb,
    //git_diff_line_cb line_cb, void *payload);
    //
    //https://libgit2.github.com/libgit2/#HEAD/group/diff/git_diff_blobs

}

void diff_buffers(MEX_DEF_INPUT){
    //3
    //
    //Directly run a diff between two buffers.


}

void diff_commit_as_email(MEX_DEF_INPUT){
    //4
    //
    //Create an e-mail ready patch for a commit.


}

void diff_find_init_options(MEX_DEF_INPUT){
    //5
    //
    //Initializes a git_diff_find_options with default values. Equivalent 
    //to creating an instance with GIT_DIFF_FIND_OPTIONS_INIT.
}

void diff_find_similar(MEX_DEF_INPUT){
    //6
    //
    //Transform a diff marking file renames, copies, etc.


}

void git_diff_foreach(MEX_DEF_INPUT){
    //7
    //
    //Loop over all deltas in a diff issuing callbacks.


}

void diff_format_email(MEX_DEF_INPUT){
    //8
}

void diff_format_email_init_options(MEX_DEF_INPUT){
    //9
}

void diff_free(MEX_DEF_INPUT){
    //10
}

void diff_from_buffer(MEX_DEF_INPUT){
    //11
}

void diff_get_delta(MEX_DEF_INPUT){
    //12
}

void diff_get_perfdata(MEX_DEF_INPUT){
    //13
}

void diff_get_stats(MEX_DEF_INPUT){
    //14
}

void diff_index_to_index(MEX_DEF_INPUT){
    //15
}

void diff_index_to_workdir(MEX_DEF_INPUT){
    //16
}

void diff_init_options(MEX_DEF_INPUT){
    //17
}

void diff_is_sorted_icase(MEX_DEF_INPUT){
    //18
}

void diff_merge(MEX_DEF_INPUT){
    //19
}

void diff_num_deltas(MEX_DEF_INPUT){
    //20
}

void diff_num_deltas_of_type(MEX_DEF_INPUT){
    //21
}

void diff_print(MEX_DEF_INPUT){
    //22
}

void diff_print_callback__to_buf(MEX_DEF_INPUT){
    //23
}

void diff_print_callback__to_file_handle(MEX_DEF_INPUT){
    //24
}

void diff_stats_deletions(MEX_DEF_INPUT){
    //25
}

void diff_stats_files_changed(MEX_DEF_INPUT){
    //26
}

void diff_stats_free(MEX_DEF_INPUT){
    //27
}

void diff_stats_insertions(MEX_DEF_INPUT){
    //28
}

void diff_stats_to_buf(MEX_DEF_INPUT){
    //29
}

void diff_status_char(MEX_DEF_INPUT){
    //30
}

void diff_to_buf(MEX_DEF_INPUT){
    //31
}

void diff_tree_to_index(MEX_DEF_INPUT){
    //32
}

void diff_tree_to_tree(MEX_DEF_INPUT){
    //33
}

void diff_tree_to_workdir(MEX_DEF_INPUT){
    //34
}

void diff_tree_to_workdir_with_index(MEX_DEF_INPUT){
    //35
}





void diff(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            //01 git_diff_blob_to_buffer
                diff_blob_to_buffer(MEX_INPUT);
            break;
        case 2:
            //02 git_diff_blobs
                diff_blobs(MEX_INPUT);
            break;
        case 3:
            //03 git_diff_buffers
                diff_buffers(MEX_INPUT);
            break;
        case 4:
            //04 git_diff_commit_as_email
                diff_commit_as_email(MEX_INPUT);
            break;
        case 5:
            //05 git_diff_find_init_options
            diff_find_init_options(MEX_INPUT);
            break;
        case 6:
            //06 git_diff_find_similar
            diff_find_similar(MEX_INPUT);
            break;
        case 7:
            //07 git_diff_foreach
            git_diff_foreach(MEX_INPUT);
            break;
        case 8:
            //08 git_diff_format_email
                diff_format_email(MEX_INPUT);
            break;
        case 9:
            //09 git_diff_format_email_init_options
            diff_format_email_init_options(MEX_INPUT);
            break;
        case 10:
            //10 git_diff_free
            diff_free(MEX_INPUT);
            break;
        case 11:
            //11 git_diff_from_buffer
            diff_from_buffer(MEX_INPUT);
            break;
        case 12:
            //12 git_diff_get_delta
            (MEX_INPUT);
            break;
        case 13:
            //13 git_diff_get_perfdata
            diff_get_perfdata(MEX_INPUT);
            break;
        case 14:
            //14 git_diff_get_stats
            diff_get_stats(MEX_INPUT);
            break;
        case 15:
            //15 git_diff_index_to_index
            diff_index_to_index(MEX_INPUT);
            break;
        case 16:
            //16 git_diff_index_to_workdir
                diff_index_to_workdir(MEX_INPUT);
            break;
        case 17:
            //17 git_diff_init_options
                diff_init_options(MEX_INPUT);
            break;
        case 18:
            //18 git_diff_is_sorted_icase
                diff_is_sorted_icase(MEX_INPUT);
            break;
        case 19:
            //19 git_diff_merge
                diff_merge(MEX_INPUT);
            break;
        case 20:
            //20 git_diff_num_deltas
                diff_num_deltas(MEX_INPUT);
            break;
        case 21:
            //21 git_diff_num_deltas_of_type
                diff_num_deltas_of_type(MEX_INPUT);
            break;
        case 22:
            //22 git_diff_print
                diff_print(MEX_INPUT);
            break;
        case 23:
            //23 git_diff_print_callback__to_buf
                diff_print_callback__to_buf(MEX_INPUT);
            break;
        case 24:
            //24 git_diff_print_callback__to_file_handle
                diff_print_callback__to_file_handle(MEX_INPUT);
            break;
        case 25:
            //25 git_diff_stats_deletions
                diff_stats_deletions(MEX_INPUT);
            break;
        case 26:
            //26 git_diff_stats_files_changed
                diff_stats_files_changed(MEX_INPUT);
            break;
        case 27:
            //27 git_diff_stats_free
                diff_stats_free(MEX_INPUT);
            break;
        case 28:
            //28 git_diff_stats_insertions
                diff_stats_insertions(MEX_INPUT);
            break;
        case 29:
            //29 git_diff_stats_to_buf
                diff_stats_to_buf(MEX_INPUT);
            break;
        case 30: 
            //30 git_diff_status_char
                diff_status_char(MEX_INPUT);
            break;
        case 31:
            //31 git_diff_to_buf
                diff_to_buf(MEX_INPUT);
            break;
        case 32:
            //32 git_diff_tree_to_index
                diff_tree_to_index(MEX_INPUT);
            break;
        case 33:
            //33 git_diff_tree_to_tree
                diff_tree_to_tree(MEX_INPUT);
            break;
        case 34:
            //34 git_diff_tree_to_workdir
                diff_tree_to_workdir(MEX_INPUT);
            break;
        case 35:
            //35 git_diff_tree_to_workdir_with_index
                diff_tree_to_workdir_with_index(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","diff.h, input sub-type not recognized");
    }
}

//01 git_diff_blob_to_buffer
//02 git_diff_blobs
//03 git_diff_buffers
//04 git_diff_commit_as_email
//05 git_diff_find_init_options
//06 git_diff_find_similar
//07 git_diff_foreach
//08 git_diff_format_email
//09 git_diff_format_email_init_options
//10 git_diff_free
//11 git_diff_from_buffer
//12 git_diff_get_delta
//13 git_diff_get_perfdata
//14 git_diff_get_stats
//15 git_diff_index_to_index
//16 git_diff_index_to_workdir
//17 git_diff_init_options
//18 git_diff_is_sorted_icase
//19 git_diff_merge
//20 git_diff_num_deltas
//21 git_diff_num_deltas_of_type
//22 git_diff_print
//23 git_diff_print_callback__to_buf
//24 git_diff_print_callback__to_file_handle
//25 git_diff_stats_deletions
//26 git_diff_stats_files_changed
//27 git_diff_stats_free
//28 git_diff_stats_insertions
//29 git_diff_stats_to_buf
//30 git_diff_status_char
//31 git_diff_to_buf
//32 git_diff_tree_to_index
//33 git_diff_tree_to_tree
//34 git_diff_tree_to_workdir
//35 git_diff_tree_to_workdir_with_index


















