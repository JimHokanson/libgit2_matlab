//  mx_to_c.h

int mx_to_int32(const mxArray *input){
    
    int *data = (int *)mxGetData(input);
    return data[0];
}

unsigned int mx_to_uint32(const mxArray *input){
    
    unsigned int *data = (unsigned int *)mxGetData(input);
    return data[0];
}

const char * mx_to_char(const mxArray *input){
     //mx_to_char(prhs[2]);

    if(!mxIsClass(input,"char")){
        mexErrMsgIdAndTxt("libgit:mx_to_c:mx_to_char","Input is not a string as expected");
    }
    
    
     return mxArrayToString(input);
     //Also be sure to call:
     //mxFree((void *)string);   

}

git_branch_iterator* mx_to_git_branch_iterator(const mxArray *input){
    //
    //  git_branch_iterator* i = mx_to_git_branch_iterator(prhs[2]);
    //
    
    git_branch_iterator **i = (git_branch_iterator **)mxGetData(input);
    return *i;
}

git_branch_t mx_to_git_branch_type(const mxArray *input){
    
    if(!mxIsClass(input,"double")){
        mexErrMsgIdAndTxt("libgit:mx_to_c:mx_to_git_branch_type","Branch type must be a double");
    }
    
    int branch_type = (int) mxGetScalar(input);
    git_branch_t return_value = -1;
    
    if (branch_type == 0){
        return_value = GIT_BRANCH_LOCAL;
    }else if (branch_type == 1){
        return_value = GIT_BRANCH_REMOTE;
    }else{
        mexErrMsgIdAndTxt("libgit:mx_to_c:mx_to_git_branch_type","Unrecognized branch type option");
    }
    
    return return_value;
}

git_config * mx_to_git_config(const mxArray *input){
    //
    //  git_config* cfg = mx_to_git_config(prhs[2]);
    //
    
    git_config **p_cfg = (git_config **)mxGetData(input);
    return *p_cfg;
}

git_config_iterator * mx_to_git_config_iterator(const mxArray *input){
    //
    //  git_config_iterator * oter = mx_to_git_config_iterator(prhs[2]);
    //
    
    git_config_iterator **p_iter = (git_config_iterator **)mxGetData(input);
    return *p_iter;
}

git_oid* mx_to_git_oid(const mxArray *input){
    //oid is a byte array
    
    git_oid *data = (git_oid *)mxGetData(input);
    git_oid *temp;
    temp = mxMalloc(sizeof(*temp));
    memcpy(temp,data,sizeof(*temp));
    return temp;
}
    
git_reference* mx_to_git_ref(const mxArray *input){
    //
    //  git_reference* ref = mx_to_git_ref(prhs[2]);
    //
    
    git_reference **p_ref = (git_reference **)mxGetData(input);
    return *p_ref;    
}

git_remote* mx_to_git_remote(const mxArray *input){
    //  git_remote* remote = mx_to_git_remote(prhs[2]);
    git_remote **p_remote = (git_remote **)mxGetData(input);
    return *p_remote;  
}

git_revwalk* mx_to_git_revwalk(const mxArray *input){
    //  git_revwalk* remote = mx_to_git_revwalk(prhs[2]);
    git_revwalk **p_rev = (git_revwalk **)mxGetData(input);
    return *p_rev;  
}

git_repository* mx_to_git_repo(const mxArray *input){
    //
    //   git_repository* repo = mx_to_git_repo(prhs[2]);
    //
    
    //TODO: Add pointer check (not 0)
    
    git_repository **p_repo = (git_repository **)mxGetData(input);
    return *p_repo;
}

git_status_list* mx_to_status_list(const mxArray *input){
    //
    //   git_status_list* list = mx_to_status_list(prhs[2]);
    //
    
    //TODO: Add pointer check (not 0)
    
    git_status_list **p_list = (git_status_list **)mxGetData(input);
    return *p_list;
}

git_strarray mx_to_git_strarray(const mxArray *input){
    
//     typedef struct git_strarray {
//          char **strings;
//          size_t count;
//     } git_strarray;
    
    //TODO: check that input is a cell
    
    git_strarray s;
    mxArray *temp;
    
    size_t count = mxGetNumberOfElements(input);
        
    char **strings = mxMalloc(count*sizeof(char *));
    
    for (size_t i = 0; i < count; i++){
        temp = mxGetCell(input,i);
        //TODO: check that temp is a string
        strings[i] = mxArrayToString(temp);
    }
    
    s.strings = strings;
    s.count = count;
    
    return s; 
}

git_otype mx_to_git_otype(const mxArray *input){

    //verify double
    
    if (~mxIsClass(input,"double")){
        mexErrMsgIdAndTxt("libgit2:mx_to_git_otype",
                "Input type for object type was not double as expected");
    }
    
    return (git_otype)mxGetScalar(input);
}

git_commit* mx_to_git_commit(const mxArray *input){
    //
    //   git_commit* commit = mx_to_git_commit(prhs[2]);
    //
    
    git_commit **p_ref = (git_commit **)mxGetData(input);
    return *p_ref;
}



void mx_to_git_status_options(const mxArray *input,git_status_options *s){
   
    //unsigned int      version;
	//git_status_show_t show;
	//unsigned int      flags;
	//git_strarray      pathspec;
    
    //mxArray *mxGetFieldByNumber(const mxArray *pm, mwIndex index, int fieldnumber);
    
    mxArray *temp;
    
    temp = mxGetFieldByNumber(input,0,0);
    s->version = mx_to_uint32(temp);
    temp = mxGetFieldByNumber(input,0,1);
    s->show = mx_to_int32(temp);
    temp = mxGetFieldByNumber(input,0,2);
    s->flags = mx_to_uint32(temp);
    temp = mxGetFieldByNumber(input,0,3);
    s->pathspec = mx_to_git_strarray(temp);
    
}

//-------------------------------------------------------------------------
// git_remote_callbacks  mx_to_git_remote_callbacks(const mxArray *input){
//     //
//     //  This will be a struct ...
//     
// }