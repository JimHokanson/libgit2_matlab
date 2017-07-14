#include "mex.h"

//https://libgit2.github.com/libgit2/#HEAD/group/branch

void attr_add_macro(MEX_DEF_INPUT){
    //1
    //
    //
    //
    //int git_attr_add_macro(git_repository *repo, const char *name, const char *values);
}

void attr_cache_flush(MEX_DEF_INPUT){
    //2
    //
    //
    //
    //void git_attr_cache_flush(git_repository *repo);
    
}

void attr_foreach(MEX_DEF_INPUT){
    //3
    //
    //
    //
    //int git_attr_foreach(git_repository *repo, uint32_t flags, const char *path, git_attr_foreach_cb callback, void *payload);
}

void attr_get(MEX_DEF_INPUT){
    //4
    //
    //
    //
    //int git_attr_get(const char **value_out, git_repository *repo, uint32_t flags, const char *path, const char *name);
}

void attr_get_many(MEX_DEF_INPUT){
    //5
    //
    //
    //
    //int git_attr_get_many(const char **values_out, git_repository *repo, uint32_t flags, const char *path, size_t num_attr, const char **names);
}

void attr_value(MEX_DEF_INPUT){
    //6
    //
    //
    //
    //git_attr_t git_attr_value(const char *attr);
}

void attr(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            //git_attr_add_macro
            attr_add_macro(MEX_INPUT);
            break;
        case 2:
            //git_attr_cache_flush
            attr_cache_flush(MEX_INPUT);
            break;
        case 3:
            //git_attr_foreach
            attr_foreach(MEX_INPUT);
            break;
        case 4:
            //git_attr_get
            attr_get(MEX_INPUT);
            break;
        case 5:
            //git_attr_get_many
            attr_get_many(MEX_INPUT);
            break;
        case 6:
            //git_attr_value
            attr_value(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","attr.h, input sub-type not recognized");
    }
}

//git_attr_add_macro
//git_attr_cache_flush
//git_attr_foreach
//git_attr_get
//git_attr_get_many
//git_attr_value