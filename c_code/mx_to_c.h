//  mx_to_c.h

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

//-------------------------------------------------------------------------
git_remote_callbacks  mx_to_git_remote_callbacks(const mxArray *input){
    //
    //  This will be a struct ...
    
}