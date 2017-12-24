#include "mex.h"

//https://libgit2.github.com/libgit2/#HEAD/group/config

void treebuilder_clear(MEX_DEF_INPUT){
    //1 - Clear all the entires in the builder
    //
    //  void git_treebuilder_clear(git_treebuilder *bld);

}
void treebuilder_entrycount(MEX_DEF_INPUT){
    //2 - Get the number of entries listed in a treebuilder
    //
    //  unsigned int git_treebuilder_entrycount(git_treebuilder *bld);

}
void treebuilder_filter(MEX_DEF_INPUT){
    //3 - Selectively remove entries in the tree
    //
    //void git_treebuilder_filter(git_treebuilder *bld, 
    //      git_treebuilder_filter_cb filter, void *payload);
}
void treebuilder_free(MEX_DEF_INPUT){
    //4 - Free a tree builder
    //
    //void git_treebuilder_free(git_treebuilder *bld);


}
void treebuilder_get(MEX_DEF_INPUT){
    //5 - Get an entry from the builder from its filename
    //
    //  const git_tree_entry * git_treebuilder_get(git_treebuilder *bld, 
    //          const char *filename);

}
void treebuilder_insert(MEX_DEF_INPUT){
    //6 - Add or update an entry to the builder
    //
    //Insert a new entry for filename in the builder with the given attributes.
    //If an entry named filename already exists, its attributes will be 
    //updated with the given ones.
    //
    //The optional pointer out can be used to retrieve a pointer to the 
    //newly created/updated entry. Pass NULL if you do not need it. The 
    //pointer may not be valid past the next operation in this builder.
    //Duplicate the entry if you want to keep it.
    //
    //No attempt is being made to ensure that the provided oid points to
    //an existing git object in the object database, nor that the attributes 
    //make sense regarding the type of the pointed at object.
    //
    //  int git_treebuilder_insert(const git_tree_entry **out, 
    //          git_treebuilder *bld, const char *filename, const git_oid *id, 
    //          git_filemode_t filemode);

}
void treebuilder_new(MEX_DEF_INPUT){
    //7 - Create a new tree builder.
    //
    //The tree builder can be used to create or modify trees in memory and 
    //write them as tree objects to the database.
    //
    //If the source parameter is not NULL, the tree builder will be 
    //initialized with the entries of the given tree.
    //
    //If the source parameter is NULL, the tree builder will start with 
    //no entries and will have to be filled manually.
    //
    //int git_treebuilder_new(git_treebuilder **out, git_repository *repo, 
    //          const git_tree *source);

}
void treebuilder_remove(MEX_DEF_INPUT){
    //8 - Remove an entry from the builder by its filename
    //
    //int git_treebuilder_remove(git_treebuilder *bld, const char *filename);


}
void treebuilder_write(MEX_DEF_INPUT){
    //9 - Write the contents of the tree builder as a tree object using a shared git_buf.
    //
    //int git_treebuilder_write_with_buffer(git_oid *oid, 
    //          git_treebuilder *bld, git_buf *tree);

}
void treebuilder_write_with_buffer(MEX_DEF_INPUT){
    //10 - Write the contents of the tree builder as a tree object using a shared git_buf.
    //
    //int git_treebuilder_write_with_buffer(git_oid *oid, 
    //          git_treebuilder *bld, git_buf *tree);

}


void treebuilder(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            treebuilder_clear(MEX_INPUT);
            break;
        case 2:
            treebuilder_entrycount(MEX_INPUT);
            break;
        case 3:
            treebuilder_filter(MEX_INPUT);
            break;
        case 4:
            treebuilder_free(MEX_INPUT);
            break;
        case 5:
            treebuilder_get(MEX_INPUT);
            break;
        case 6:
            treebuilder_insert(MEX_INPUT);
            break;
        case 7:
            treebuilder_new(MEX_INPUT);
            break;    
        case 8:
            treebuilder_remove(MEX_INPUT);
            break;
        case 9:
            treebuilder_write(MEX_INPUT);
            break;
        case 10:
            treebuilder_write_with_buffer(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","config.h, input sub-type not recognized");
    }
}

//1 git_treebuilder_clear
//2 git_treebuilder_entrycount
//3 git_treebuilder_filter
//4 git_treebuilder_free
//5 git_treebuilder_get
//6 git_treebuilder_insert
//7 git_treebuilder_new
//8 git_treebuilder_remove
//9 git_treebuilder_write
//10 git_treebuilder_write_with_buffer