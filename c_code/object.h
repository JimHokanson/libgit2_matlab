#include "mex.h"

//https://libgit2.github.com/libgit2/#HEAD/group/config

void object__size(MEX_DEF_INPUT){
    //1   
    //
    //Get the size in bytes for the structure which acts as an in-memory representation of any given object type.
    //
    //size_t git_object__size(git_otype type);


}

void object_dup(MEX_DEF_INPUT){
    //2   
    //
    //Create an in-memory copy of a Git object. The copy must be explicitly free'd or it will leak.
    //
    //int git_object_dup(git_object **dest, git_object *source);

}

void object_free(MEX_DEF_INPUT){
    //3  
    //
    //Close an open object
    //
    //void git_object_free(git_object *object);



}

void object_id(MEX_DEF_INPUT){
    //4   
    //
    //Get the id (SHA1) of a repository object
    //
    //const git_oid * git_object_id(const git_object *obj);


}

void object_lookup(MEX_DEF_INPUT){
    //5   
    //
    //  object = mex(32,5,repo,oid,type)
    //
    //Lookup a reference to one of the objects in a repository.
    //
    //  int git_object_lookup(git_object **object, git_repository *repo, 
    //              const git_oid *id, git_otype type);
    //
    //The 'type' parameter must match the type of the object in the odb; 
    //the method will fail otherwise. The special value 'GIT_OBJ_ANY' may be 
    //passed to let the method guess the object's type.
    
    git_repository *repo = mx_to_git_repo(prhs[2]);
    const git_oid *id = mx_to_git_oid(prhs[3]);
    git_otype type = mx_to_git_otype(prhs[4]);
    
    git_object *obj;
    
    int response = git_object_lookup(&obj,repo,id,type);
    handle_error(response,"libgit:object:object_lookup");     

    plhs[0] = git_object__to_mx(obj);
}

void object_lookup_bypath(MEX_DEF_INPUT){
    //6   
    //
    //Lookup an object that represents a tree entry.
    //
    //int git_object_lookup_bypath(git_object **out, const git_object *treeish, 
    //      const char *path, git_otype type);

}

void object_lookup_prefix(MEX_DEF_INPUT){
    //7   
    //
    //Lookup a reference to one of the objects in a repository, given a prefix of its identifier (short id).
    //
    //int git_object_lookup_prefix(git_object **object_out, git_repository *repo, 
    //      const git_oid *id, size_t len, git_otype type);

}

void object_owner(MEX_DEF_INPUT){
    //8  
    //
    //Get the repository that owns this object
    //
    //git_repository * git_object_owner(const git_object *obj);


}

void object_peel(MEX_DEF_INPUT){
    //9   
    //
    //Recursively peel an object until an object of the specified type is met.
    //
    //int git_object_peel(git_object **peeled, const git_object *object, 
    //      git_otype target_type);

}

void object_short_id(MEX_DEF_INPUT){
    //10   
    //
    //Get a short abbreviated OID string for the object
    //
    //int git_object_short_id(git_buf *out, const git_object *obj);



}

void object_string2type(MEX_DEF_INPUT){
    //11   
    //
    //Convert a string object type representation to it's git_otype.
    //
    //git_otype git_object_string2type(const char *str);


}

void object_type(MEX_DEF_INPUT){
    //12  
    //
    //Get the object type of an object
    //
    //git_otype git_object_type(const git_object *obj);


}

void object_type2string(MEX_DEF_INPUT){
    //13   
    //
    //Convert an object type to its string representation.
    //
    //const char * git_object_type2string(git_otype type);


}

void object_typeisloose(MEX_DEF_INPUT){
    //14   
    //
    //Determine if the given git_otype is a valid loose object type.
    //
    //int git_object_typeisloose(git_otype type);


}

void object(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            object__size(MEX_INPUT);
            break;
        case 2:
            object_dup(MEX_INPUT);
            break;
        case 3:
            object_free(MEX_INPUT);
            break;
        case 4:
            object_id(MEX_INPUT);
            break;
        case 5:
            object_lookup(MEX_INPUT);
            break;
        case 6:
            object_lookup_bypath(MEX_INPUT);
            break;
        case 7:
            object_lookup_prefix(MEX_INPUT);
            break;
        case 8:
            object_owner(MEX_INPUT);
            break;
        case 9:
            object_peel(MEX_INPUT);
            break;
        case 10:
            object_short_id(MEX_INPUT);
            break;
        case 11:
            object_string2type(MEX_INPUT);
            break;
        case 12:
            object_type(MEX_INPUT);
            break;
        case 13:
            object_type2string(MEX_INPUT);
            break;
        case 14:
            object_typeisloose(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","object.h, input sub-type not recognized");
    }
}

//1 git_object__size
//2 git_object_dup
//3 git_object_free
//4 git_object_id
//5 git_object_lookup
//6 git_object_lookup_bypath
//7 git_object_lookup_prefix
//8 git_object_owner
//9 git_object_peel
//10 git_object_short_id
//11 git_object_string2type
//12 git_object_type
//13 git_object_type2string
//14 git_object_typeisloose