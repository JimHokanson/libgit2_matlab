#include "mex.h"

//https://libgit2.github.com/libgit2/#HEAD/group/config

void status_byindex(MEX_DEF_INPUT){
    //1
    //
    //Get a pointer to one of the entries in the status list.
    //
    //const git_status_entry * git_status_byindex(git_status_list *statuslist, size_t idx);

}

void status_file(MEX_DEF_INPUT){
    //2
    //
    //Get file status for a single file.
    //
    //int git_status_file(unsigned int *status_flags, git_repository *repo, const char *path);


}

void status_foreach(MEX_DEF_INPUT){
    //3
    //
    //Gather file statuses and run a callback for each one.
    //
    //int git_status_foreach(git_repository *repo, git_status_cb callback, void *payload);
}

void status_foreach_ext(MEX_DEF_INPUT){
    //4
    //
    //Gather file status information and run callbacks as requested.
    //
    //int git_status_foreach_ext(git_repository *repo, const git_status_options *opts, 
    //  git_status_cb callback, void *payload);

}

void status_init_options(MEX_DEF_INPUT){
    //5
    //
    //  mex(56,5)
    //
    //Initializes a git_status_options with default values. Equivalent to
    //creating an instance with GIT_STATUS_OPTIONS_INIT.
    //
    //int git_status_init_options(git_status_options *opts, 
    //      unsigned int version);
    
    git_status_options opts;
    int error = git_status_init_options(&opts, GIT_STATUS_OPTIONS_VERSION);
    plhs[0] = git_status_options__to_mx(&opts);

}

void status_list_entrycount(MEX_DEF_INPUT){
    //6
    //
    //Gets the count of status entries in this list.
    //
    //size_t git_status_list_entrycount(git_status_list *statuslist);


}

void status_list_free(MEX_DEF_INPUT){
    //7
    //
    //Free an existing status list
    //
    //void git_status_list_free(git_status_list *statuslist);


}

void status_list_get_perfdata(MEX_DEF_INPUT){
    //8
    //
    //Get performance data for diffs from a git_status_list
    //
    //int git_status_list_get_perfdata(git_diff_perfdata *out, 
    //      const git_status_list *status);
    


}

void status_list_new(MEX_DEF_INPUT){
    //9
    //
    //  mex(56,9,repo,*opts)
    //
    //Gather file status information and populate the git_status_list.
    //
    //int git_status_list_new(git_status_list **out, git_repository *repo, 
    //      const git_status_options *opts);
    
    nlhs, plhs, nrhs, prhs
            
    git_status_options opts = NULL;
    if (nrhs == 4){
        
    }else if(nrhs == 3){
        
    }else{
        //Throw error
    }
    
}

void status_should_ignore(MEX_DEF_INPUT){
    //10
    //
    //Test if the ignore rules apply to a given file.
    //
    //int git_status_should_ignore(int *ignored, git_repository *repo, 
    //          const char *path);

}

void status(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            //git_status_byindex
            status_byindex(MEX_INPUT);
            break;
        case 2:
            //git_status_file
            status_file(MEX_INPUT);
            break;
        case 3:
            //git_status_foreach
            status_foreach(MEX_INPUT);
            break;
        case 4:
            //git_status_foreach_ext
            status_foreach_ext(MEX_INPUT);
            break;
        case 5:
            //git_status_init_options
            status_init_options(MEX_INPUT);
            break;
        case 6:
            //git_status_list_entrycount
            status_list_entrycount(MEX_INPUT);
            break;
        case 7:
            //git_status_list_free
            status_list_free(MEX_INPUT);
            break;
        case 8:
            //git_status_list_get_perfdata
            status_list_get_perfdata(MEX_INPUT);
            break;
        case 9:
            //git_status_list_new
            status_list_new(MEX_INPUT);
            break;
        case 10:
            //git_status_should_ignore
            status_should_ignore(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","config.h, input sub-type not recognized");
    }
}

//01 git_status_byindex
//02 git_status_file
//03 git_status_foreach
//04 git_status_foreach_ext
//05 git_status_init_options
//06 git_status_list_entrycount
//07 git_status_list_free
//08 git_status_list_get_perfdata
//09 git_status_list_new
//10 git_status_should_ignore