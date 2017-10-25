#include "mex.h"

//https://libgit2.github.com/libgit2/#HEAD/group/index

//https://stackoverflow.com/questions/3689838/whats-the-difference-between-head-working-tree-and-index-in-git

//25


void index_add(MEX_DEF_INPUT){
    //1 - Add or update an index entry from an in-memory struct
    //
    //  libgit(25,1,...
    //
    //  int git_index_add(git_index *index, const git_index_entry *source_entry);


}

void index_add_all(MEX_DEF_INPUT){
    //2 - Add or update index entries matching files in the working directory.
    //
    //int git_index_add_all(git_index *index, const git_strarray *pathspec, 
    //      unsigned int flags, git_index_matched_path_cb callback, void *payload);

}

void index_add_bypath(MEX_DEF_INPUT){
    //3 - Add or update an index entry from a file on disk
    //
    //  libgit(25,3,...
    //
    //int git_index_add_bypath(git_index *index, const char *path);
    

}

void index_add_frombuffer(MEX_DEF_INPUT){
    //4 - Add or update an index entry from a buffer in memory
    //
    //  libgit(25,4,...
    //
    //int git_index_add_frombuffer(git_index *index, const git_index_entry *entry, 
    //      const void *buffer, size_t len);

    
}

void index_caps(MEX_DEF_INPUT){
    //5 - Read index capabilities flags.
    //
    //  libgit(25,5,...
    //
    //int git_index_caps(const git_index *index);


}

void index_checksum(MEX_DEF_INPUT){
    //6 - Get the checksum of the index
    //
    //  libgit(25,6,...
    //
    //const git_oid * git_index_checksum(git_index *index);

}

void index_clear(MEX_DEF_INPUT){
    //7 - Clear the contents (all the entries) of an index object.
    //
    //int git_index_clear(git_index *index);
    
}

void index_conflict_add(MEX_DEF_INPUT){
    //8 - Add or update index entries to represent a conflict. Any staged 
    //    entries that exist at the given paths will be removed.
    //
    //int git_index_conflict_add(git_index *index, const git_index_entry *ancestor_entry, 
    //      const git_index_entry *our_entry, const git_index_entry *their_entry);
}

void index_conflict_cleanup(MEX_DEF_INPUT){
    //9 - Remove all conflicts in the index (entries with a stage greater than 0).
    //
    //int git_index_conflict_cleanup(git_index *index);

}

void index_conflict_get(MEX_DEF_INPUT){
    //10 - Get the index entries that represent a conflict of a single file.
    //
    //  int git_index_conflict_get(const git_index_entry **ancestor_out, 
    //      const git_index_entry **our_out, const git_index_entry **their_out, 
    //      git_index *index, const char *path);

}

void index_conflict_iterator_free(MEX_DEF_INPUT){
    //11 - Frees a git_index_conflict_iterator.
    //
    //  void git_index_conflict_iterator_free(git_index_conflict_iterator *iterator);

}

void index_conflict_iterator_new(MEX_DEF_INPUT){
    //12 - Returns the current conflict (ancestor, ours and theirs entry) 
    //    and advance the iterator internally to the next value.
    //
    //  int git_index_conflict_next(const git_index_entry **ancestor_out, 
    //          const git_index_entry **our_out, const git_index_entry **their_out, 
    //          git_index_conflict_iterator *iterator);


}

void index_conflict_next(MEX_DEF_INPUT){
    //13 - Returns the current conflict (ancestor, ours and theirs entry) 
    //  and advance the iterator internally to the next value.
    //
    //  int git_index_conflict_next(const git_index_entry **ancestor_out, 
    //      const git_index_entry **our_out, const git_index_entry **their_out, 
    //      git_index_conflict_iterator *iterator);

}

void index_conflict_remove(MEX_DEF_INPUT){
    //14 - Removes the index entries that represent a conflict of a single file.
    //
    //  int git_index_conflict_remove(git_index *index, const char *path);


}

void index_entry_is_conflict(MEX_DEF_INPUT){
    //15 - Return whether the given index entry is a conflict (has a high 
    //      stage entry). This is simply shorthand for git_index_entry_stage > 0.
    //
    //  int git_index_entry_is_conflict(const git_index_entry *entry);

}

void index_entry_stage(MEX_DEF_INPUT){
    //16 - Return the stage number from a git index entry
    //
    //  int git_index_entry_stage(const git_index_entry *entry);


}

void index_entrycount(MEX_DEF_INPUT){
    //17 - Get the count of entries currently in the index
    //
    //  libgit(25,17,index)
    //
    //  size_t git_index_entrycount(const git_index *index);

	git_index * index = mx_to_git_index(prhs[2]);
    size_t count = git_index_entrycount(index);
    plhs[0] = sizet__to_mx(count);

}

void index_find(MEX_DEF_INPUT){
    //18 - Find the first position of any entries which point to given 
    //  path in the Git index.
    //
    //int git_index_find(size_t *at_pos, git_index *index, const char *path);



}

void index_find_prefix(MEX_DEF_INPUT){
    //19 - Find the first position of any entries matching a prefix. To 
    //  find the first position of a path inside a given folder, suffix 
    //  the prefix with a '/'.
    //
    //  int git_index_find_prefix(size_t *at_pos, git_index *index, 
    //      const char *prefix);

}

void index_free(MEX_DEF_INPUT){
    //20 - Free an existing index object.
    //
    //  libgit(25,20,index)
    
    git_index * index = mx_to_git_index(prhs[2]);
    git_index_free(index);
}

void index_get_byindex(MEX_DEF_INPUT){
    //21 - Get a pointer to one of the entries in the index
    //
    //  const git_index_entry * git_index_get_byindex(git_index *index, size_t n);


    
}

void index_get_bypath(MEX_DEF_INPUT){
    //22
}

void index_has_conflicts(MEX_DEF_INPUT){
    //23
}

void index_new(MEX_DEF_INPUT){
    //24 - Create an in-memory index object.
    //
    //  libgit(25,24)
    //
    //int git_index_new(git_index **out);
    
    git_index *out;
    int response = git_index_new(&out);
   	handle_error(response,"libgit:index:index_new");    
    plhs[0] = git_index__to_mx(out);

}

void index_open(MEX_DEF_INPUT){
    //25
}

void index_owner(MEX_DEF_INPUT){
    //26
}

void index_path(MEX_DEF_INPUT){
    //27
}

void index_read(MEX_DEF_INPUT){
    //28
}

void index_read_tree(MEX_DEF_INPUT){
    //29
}

void index_remove(MEX_DEF_INPUT){
    //30
}

void index_remove_all(MEX_DEF_INPUT){
    //31
}

void index_remove_bypath(MEX_DEF_INPUT){
    //32
}

void index_remove_directory(MEX_DEF_INPUT){
    //33
}

void index_set_caps(MEX_DEF_INPUT){
    //34
}

void index_set_version(MEX_DEF_INPUT){
    //35
}

void index_update_all(MEX_DEF_INPUT){
    //36
}

void index_version(MEX_DEF_INPUT){
    //37
}

void index_write(MEX_DEF_INPUT){
    //38
}

void index_write_tree(MEX_DEF_INPUT){
    //39
}

void index_write_tree_to(MEX_DEF_INPUT){
    //40
}


void index2(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            //01 git_index_add
            index_add(MEX_INPUT);
            break;
        case 2:
            //02 git_index_add_all
            (MEX_INPUT);
            break;
        case 3:
            //03 git_index_add_bypath
            index_add_bypath(MEX_INPUT);
            break;
        case 4:
            //04 git_index_add_frombuffer
            index_add_frombuffer(MEX_INPUT);
            break;
        case 5:
            //05 git_index_caps
            index_caps(MEX_INPUT);
            break;
        case 6:
            //06 git_index_checksum
            index_checksum(MEX_INPUT);
            break;
        case 7:
            //07 git_index_clear
            index_clear(MEX_INPUT);
            break;
        case 8:
            //08 git_index_conflict_add
            index_conflict_add(MEX_INPUT);
            break;
        case 9:
            //09 git_index_conflict_cleanup
            index_conflict_cleanup(MEX_INPUT);
            break;
        case 10:
            //10 git_index_conflict_get
            index_conflict_get(MEX_INPUT);
            break;
        case 11:
            //11 git_index_conflict_iterator_free
            index_conflict_iterator_free(MEX_INPUT);
            break;
        case 12:
            //12 git_index_conflict_iterator_new
            index_conflict_iterator_new(MEX_INPUT);
            break;
        case 13:
            //13 git_index_conflict_next
            index_conflict_next(MEX_INPUT);
            break;
        case 14:
            //14 git_index_conflict_remove
            index_conflict_remove(MEX_INPUT);
            break;
        case 15:
            //15 git_index_entry_is_conflict
            index_entry_is_conflict(MEX_INPUT);
            break;
        case 16:
            //16 git_index_entry_stage
            index_entry_stage(MEX_INPUT);
            break;
        case 17:
            //17 git_index_entrycount
            index_entrycount(MEX_INPUT);
            break;
        case 18:
            //18 git_index_find
            index_find(MEX_INPUT);
            break;
        case 19:
            //19 git_index_find_prefix
            index_find_prefix(MEX_INPUT);
            break;
        case 20:
            //20 git_index_free
            index_free(MEX_INPUT);
            break;
        case 21:
            //21 git_index_get_byindex
            index_get_byindex(MEX_INPUT);
            break;
        case 22:
            //22 git_index_get_bypath
            index_get_bypath(MEX_INPUT);
            break;
        case 23:
            //23 git_index_has_conflicts
            index_has_conflicts(MEX_INPUT);
            break;
        case 24:
            //24 git_index_new
            index_new(MEX_INPUT);
            break;
        case 25:
            //25 git_index_open
            index_open(MEX_INPUT);
            break;
        case 26:
            //26 git_index_owner
            index_owner(MEX_INPUT);
            break;
        case 27:
            //27 git_index_path
            index_path(MEX_INPUT);
            break;
        case 28:
            //28 git_index_read
            index_read(MEX_INPUT);
            break;
        case 29:
            //29 git_index_read_tree
            index_read_tree(MEX_INPUT);
            break;
        case 30:  
            //30 git_index_remove
            index_remove(MEX_INPUT);
            break;
        case 31:
            //31 git_index_remove_all
            index_remove_all(MEX_INPUT);
            break;
        case 32:
            //32 git_index_remove_bypath
            index_remove_bypath(MEX_INPUT);
            break;
        case 33:
            //33 git_index_remove_directory
            index_remove_directory(MEX_INPUT);
            break;
        case 34:
            //34 git_index_set_caps
            index_set_caps(MEX_INPUT);
            break;
        case 35:
            //35 git_index_set_version
            index_set_version(MEX_INPUT);
            break;
        case 36:
            //36 git_index_update_all
            index_update_all(MEX_INPUT);
            break;
        case 37:
            //37 git_index_version
            index_version(MEX_INPUT);
            break;
        case 38:
            //38 git_index_write
            index_write(MEX_INPUT);
            break;
        case 39:
            //39 git_index_write_tree
            index_write_tree(MEX_INPUT);
            break;
        case 40:
            //40 git_index_write_tree_to
            index_write_tree_to(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","config.h, input sub-type not recognized");
    }
}

//01 git_index_add
//02 git_index_add_all
//03 git_index_add_bypath
//04 git_index_add_frombuffer
//05 git_index_caps
//06 git_index_checksum
//07 git_index_clear
//08 git_index_conflict_add
//09 git_index_conflict_cleanup
//10 git_index_conflict_get
//11 git_index_conflict_iterator_free
//12 git_index_conflict_iterator_new
//13 git_index_conflict_next
//14 git_index_conflict_remove
//15 git_index_entry_is_conflict
//16 git_index_entry_stage
//17 git_index_entrycount
//18 git_index_find
//19 git_index_find_prefix
//20 git_index_free
//21 git_index_get_byindex
//22 git_index_get_bypath
//23 git_index_has_conflicts
//24 git_index_new
//25 git_index_open
//26 git_index_owner
//27 git_index_path
//28 git_index_read
//29 git_index_read_tree
//30 git_index_remove
//31 git_index_remove_all
//32 git_index_remove_bypath
//33 git_index_remove_directory
//34 git_index_set_caps
//35 git_index_set_version
//36 git_index_update_all
//37 git_index_version
//38 git_index_write
//39 git_index_write_tree
//40 git_index_write_tree_to

