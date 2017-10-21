#include "mex.h"

//tree - directory listing of a commit

//https://libgit2.github.com/libgit2/#HEAD/group/tree
    
void tree_create_updated(MEX_DEF_INPUT){
    //1
    //
    //Create a tree based on another one with the specified modifications
    //
    //int git_tree_create_updated(git_oid *out, git_repository *repo, 
    //      git_tree *baseline, size_t nupdates, const git_tree_update *updates);
    
}

void tree_dup(MEX_DEF_INPUT){
    //2
    //
    //Create an in-memory copy of a tree. The copy must be explicitly free'd or it will leak.
    //
    //int git_tree_dup(git_tree **out, git_tree *source);
    
    
}

void tree_entry_byid(MEX_DEF_INPUT){
    //3
    //
    //Lookup a tree entry by SHA value.
    //
    //const git_tree_entry * git_tree_entry_byid(const git_tree *tree, const git_oid *id);
    
}

void tree_entry_byindex(MEX_DEF_INPUT){
    //4
    //
    //Lookup a tree entry by its position in the tree
    //
    //const git_tree_entry * git_tree_entry_byindex(const git_tree *tree, size_t idx);
    
}

void tree_entry_byname(MEX_DEF_INPUT){
    //5
    //
    //Lookup a tree entry by its filename
    //
    //const git_tree_entry * git_tree_entry_byname(const git_tree *tree, const char *filename);
    
}

void tree_entry_bypath(MEX_DEF_INPUT){
    //6
    //
    //Retrieve a tree entry contained in a tree or in any of its subtrees, given its relative path.
    //
    //int git_tree_entry_bypath(git_tree_entry **out, const git_tree *root, const char *path);
    
}

void tree_entry_cmp(MEX_DEF_INPUT){
    //7
    //
    //Compare two tree entries
    //
    //int git_tree_entry_cmp(const git_tree_entry *e1, const git_tree_entry *e2);
    
}

void tree_entry_dup(MEX_DEF_INPUT){
    //8
    //
    //Duplicate a tree entry
    //
    //int git_tree_entry_dup(git_tree_entry **dest, const git_tree_entry *source);
    
}

void tree_entry_filemode(MEX_DEF_INPUT){
    //9
    //
    //Get the UNIX file attributes of a tree entry
    //
    //git_filemode_t git_tree_entry_filemode(const git_tree_entry *entry);
    
    
}

void tree_entry_filemode_raw(MEX_DEF_INPUT){
    //10
    //
    //Get the raw UNIX file attributes of a tree entry
    //
    //git_filemode_t git_tree_entry_filemode_raw(const git_tree_entry *entry);
    
    
}

void tree_entry_free(MEX_DEF_INPUT){
    //11
    //
    //Free a user-owned tree entry
    //
    //void git_tree_entry_free(git_tree_entry *entry);
    
}

void tree_entry_id(MEX_DEF_INPUT){
    //12
    //
    //Get the id of the object pointed by the entry
    //
    //const git_oid * git_tree_entry_id(const git_tree_entry *entry);
    
}

void tree_entry_name(MEX_DEF_INPUT){
    //13
    //
    //Get the filename of a tree entry
    //
    //const char * git_tree_entry_name(const git_tree_entry *entry);
    
}

void tree_entry_to_object(MEX_DEF_INPUT){
    //14
    //
    //Convert a tree entry to the git_object it points to.
    //
    //int git_tree_entry_to_object(git_object **object_out, git_repository *repo, const git_tree_entry *entry);
    
}

void tree_entry_type(MEX_DEF_INPUT){
    //15
    //
    //Get the type of the object pointed by the entry
    //
    //git_otype git_tree_entry_type(const git_tree_entry *entry);
    
    
}

void tree_entrycount(MEX_DEF_INPUT){
    //16
    //
    //Get the number of entries listed in a tree
    //
    //size_t git_tree_entrycount(const git_tree *tree);
    
}

void tree_free(MEX_DEF_INPUT){
    //17
    //
    //Close an open tree
    //
    //void git_tree_free(git_tree *tree);
    
    
}

void tree_id(MEX_DEF_INPUT){
    //18
    //
    //Get the id of a tree.
    //
    //const git_oid * git_tree_id(const git_tree *tree);
    
    
}

void tree_lookup(MEX_DEF_INPUT){
    //19
    //
    //Lookup a tree object from the repository.
    //
    //int git_tree_lookup(git_tree **out, git_repository *repo, const git_oid *id);
    
    
}

void tree_lookup_prefix(MEX_DEF_INPUT){
    //20
    //
    //Lookup a tree object from the repository, given a prefix of its identifier (short id).
    //
    //int git_tree_lookup_prefix(git_tree **out, git_repository *repo, const git_oid *id, size_t len);
    
}

void tree_owner(MEX_DEF_INPUT){
    //21
    //
    //Get the repository that contains the tree.
    //
    //git_repository * git_tree_owner(const git_tree *tree);
    
    
    
}

void tree_walk(MEX_DEF_INPUT){
    //22
    //
    //Traverse the entries in a tree and its subtrees in post or pre order.
    //
    //  int git_tree_walk(const git_tree *tree, git_treewalk_mode mode,
    //      callback, void *payload);
    
}

void tree(MEX_DEF_INPUT)
{
    
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            tree_create_updated(MEX_INPUT);
            break;
        case 2:
            tree_dup(MEX_INPUT);
            break;
        case 3:
            tree_entry_byid(MEX_INPUT);
            break;
        case 4:
            tree_entry_byindex(MEX_INPUT);
            break;
        case 5:
            tree_entry_byname(MEX_INPUT);
            break;
        case 6:
            tree_entry_bypath(MEX_INPUT);
            break;
        case 7:
            tree_entry_cmp(MEX_INPUT);
            break;
        case 8:
            tree_entry_dup(MEX_INPUT);
            break;
        case 9:
            tree_entry_filemode(MEX_INPUT);
            break;
        case 10:
            tree_entry_filemode_raw(MEX_INPUT);
            break;
        case 11:
            tree_entry_free(MEX_INPUT);
            break;
        case 12:
            tree_entry_id(MEX_INPUT);
            break;
        case 13:
            tree_entry_name(MEX_INPUT);
            break;
        case 14:
            tree_entry_to_object(MEX_INPUT);
            break;
        case 15:
            tree_entry_type(MEX_INPUT);
            break;
        case 16:
            tree_entrycount(MEX_INPUT);
            break;
        case 17:
            tree_free(MEX_INPUT);
            break;
        case 18:
            tree_id(MEX_INPUT);
            break;
        case 19:
            tree_lookup(MEX_INPUT);
            break;
        case 20:
            tree_lookup_prefix(MEX_INPUT);
            break;
        case 21:
            tree_owner(MEX_INPUT);
            break;
        case 22:
            tree_walk(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","tree.h, input sub-type not recognized");
    }
}

//1 git_tree_create_updated
//2 git_tree_dup
//3 git_tree_entry_byid
//4 git_tree_entry_byindex
//5 git_tree_entry_byname
//6 git_tree_entry_bypath
//7 git_tree_entry_cmp
//8 git_tree_entry_dup
//9 git_tree_entry_filemode
//10 git_tree_entry_filemode_raw
//11 git_tree_entry_free
//12 git_tree_entry_id
//13 	git_tree_entry_name
//14 git_tree_entry_to_object
//15 git_tree_entry_type
//16 git_tree_entrycount
//17 git_tree_free
//18 git_tree_id
//19 git_tree_lookup
//20 git_tree_lookup_prefix
//21 git_tree_owner
//22 git_tree_walk
