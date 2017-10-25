#include "mex.h"

//https://libgit2.github.com/libgit2/#HEAD/group/blob

//9

void blob_create_frombuffer(MEX_DEF_INPUT){
    //1 - Write an in-memory buffer to the ODB as a blob
    //
    //  libgit(9,1,...)
    //
    //int git_blob_create_frombuffer(git_oid *id, git_repository *repo, 
    //          const void *buffer, size_t len);
}

void blob_create_fromdisk(MEX_DEF_INPUT){
    //2 - Read a file from the filesystem and write its content to the 
    //Object Database as a loose blob
    //
    //int git_blob_create_fromdisk(git_oid *id, git_repository *repo, 
    //      const char *path);

}

void blob_create_fromstream(MEX_DEF_INPUT){
    //3 - Create a stream to write a new blob into the object db
    //
    //int git_blob_create_fromstream(git_writestream **out, 
    //          git_repository *repo, const char *hintpath);

}

void blob_create_fromstream_commit(MEX_DEF_INPUT){
    //4 - Close the stream and write the blob to the object db
    //
    //  libgit(9,4,...)
    //
    //  int git_blob_create_fromstream_commit(git_oid *out, 
    //          git_writestream *stream);

}

void blob_create_fromworkdir(MEX_DEF_INPUT){
    //5 - Read a file from the working folder of a repository and 
    //    write it to the Object Database as a loose blob
    //
    //  int git_blob_create_fromworkdir(git_oid *id, git_repository *repo, 
    //          const char *relative_path);

}

void git_blob_dup(MEX_DEF_INPUT){
    //6 - Create an in-memory copy of a blob. The copy must be explicitly 
    //    free'd or it will leak.
    //
    //  int git_blob_dup(git_blob **out, git_blob *source);

}

void blob_filtered_content(MEX_DEF_INPUT){
    //7 - Get a buffer with the filtered content of a blob.
    //
    //  libgit(9,7,...)
    //
    //  int git_blob_filtered_content(git_buf *out, git_blob *blob, 
    //          const char *as_path, int check_for_binary_data);

}

void blob_free(MEX_DEF_INPUT){
    //8 - Close an open blob
    //
    //   libgit(9,8,...)
    //
    //void git_blob_free(git_blob *blob);


}

void blob_id(MEX_DEF_INPUT){
    //9 - Get the id of a blob.
    //
    //const git_oid * git_blob_id(const git_blob *blob);

}

void blob_is_binary(MEX_DEF_INPUT){
    //10 - Determine if the blob content is most certainly binary or not.
    //
    //  libgit(9,10,...)
    //
    //int git_blob_is_binary(const git_blob *blob);


}

void blob_lookup(MEX_DEF_INPUT){
    //11 - Lookup a blob object from a repository.
    //
    //  libgit(9,11,...)
    //
    //int git_blob_lookup(git_blob **blob, git_repository *repo, 
    //      const git_oid *id);


}

void blob_lookup_prefix(MEX_DEF_INPUT){
    //12 - Lookup a blob object from a repository, given a prefix of 
    //     its identifier (short id).
    //
    //  int git_blob_lookup_prefix(git_blob **blob, git_repository *repo, 
    //          const git_oid *id, size_t len);

}

void blob_owner(MEX_DEF_INPUT){
    //13 - Get the repository that contains the blob.
    //
    //  libgit(9,13,...)
    //
    //git_repository * git_blob_owner(const git_blob *blob);


}

void blob_rawcontent(MEX_DEF_INPUT){
    //14 - Get a read-only buffer with the raw content of a blob.
    //
    //  libgit(9,14,...)
    //
    //const void * git_blob_rawcontent(const git_blob *blob);

}

void blob_rawsize(MEX_DEF_INPUT){
    //15 - Get the size in bytes of the contents of a blob
    //
    //git_off_t git_blob_rawsize(const git_blob *blob);

}


void blob(MEX_DEF_INPUT)
{
        
    int sub_type = (int)mxGetScalar(prhs[1]);
    switch (sub_type) {
        case 1:
            //01 git_blob_create_frombuffer
            blob_create_frombuffer(MEX_INPUT);
            break;
        case 2:
            //02 git_blob_create_fromdisk
            blob_create_fromdisk(MEX_INPUT);
            break;
        case 3:
            //03 git_blob_create_fromstream
            blob_create_fromstream(MEX_INPUT);
            break;
        case 4:
            //04 git_blob_create_fromstream_commit
            (MEX_INPUT);
            break;
        case 5:
            //05 git_blob_create_fromworkdir
            blob_create_fromworkdir(MEX_INPUT);
            break;
        case 6:
            //06 git_blob_dup
            git_blob_dup(MEX_INPUT);
            break;
        case 7:
            //07 git_blob_filtered_content
            blob_filtered_content(MEX_INPUT);
            break;
        case 8:
            //08 git_blob_free
            blob_free(MEX_INPUT);
            break;
        case 9:
            //09 git_blob_id
            blob_id(MEX_INPUT);
            break;
        case 10:
            //10 git_blob_is_binary
            blob_is_binary(MEX_INPUT);
            break;
        case 11:
            //11 git_blob_lookup
            blob_lookup(MEX_INPUT);
            break;
        case 12:
            //12 git_blob_lookup_prefix
            blob_lookup_prefix(MEX_INPUT);
            break;
        case 13:
            //13 git_blob_owner
            blob_owner(MEX_INPUT);
            break;
        case 14:
            //14 git_blob_rawcontent
            blob_rawcontent(MEX_INPUT);
            break;
        case 15:
            //15 git_blob_rawsize
            blob_rawsize(MEX_INPUT);
            break;
        default:
            mexErrMsgIdAndTxt("libgit:input_2","blob.h, input sub-type not recognized");
    }
}

//01 git_blob_create_frombuffer
//02 git_blob_create_fromdisk
//03 git_blob_create_fromstream
//04 git_blob_create_fromstream_commit
//05 git_blob_create_fromworkdir
//06 git_blob_dup
//07 git_blob_filtered_content
//08 git_blob_free
//09 git_blob_id
//10 git_blob_is_binary
//11 git_blob_lookup
//12 git_blob_lookup_prefix
//13 git_blob_owner
//14 git_blob_rawcontent
//15 git_blob_rawsize