//  mx_to_c.h

int mx_to_int32(const mxArray *input){
    
    int *data = (int *)mxGetData(input);
    return data[0];
}

unsigned int mx_to_uint32(const mxArray *input){
    
    unsigned int *data = (unsigned int *)mxGetData(input);
    return data[0];
}

git_branch_iterator* mx_to_git_branch_iterator(const mxArray *input){
    //
    //  git_branch_iterator* i = mx_to_git_branch_iterator(prhs[2]);
    //
    
    git_branch_iterator **i = (git_branch_iterator **)mxGetData(input);
    return *i;
}
    
git_reference* mx_to_git_ref(const mxArray *input){
    //
    //  git_reference* ref = mx_to_git_ref(prhs[2]);
    //
    
    git_reference **p_ref = (git_reference **)mxGetData(input);
    return *p_ref;    
}

git_remote* mx_to_git_remote(const mxArray *input){
    //
    //  git_remote* remote = mx_to_git_remote(prhs[2]);
    //
    
    git_remote **p_remote = (git_remote **)mxGetData(input);
    return *p_remote;  
}

git_repository* mx_to_git_repo(const mxArray *input){
    //
    //   git_repository* repo = mx_to_git_repo(prhs[2]);
    //
    
    //TODO: Add pointer check (not 0)
    
    git_repository **p_repo = (git_repository **)mxGetData(input);
    return *p_repo;
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
    
    s->pathspec = NULL;
    
}

//-------------------------------------------------------------------------
// git_remote_callbacks  mx_to_git_remote_callbacks(const mxArray *input){
//     //
//     //  This will be a struct ...
//     
// }