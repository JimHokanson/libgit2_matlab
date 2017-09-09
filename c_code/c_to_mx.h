//c_to_mx.h

#include "stdint.h"

#ifdef _WIN32
#include "windows/git2.h"
#else
#include "mac_os/git2.h"
#endif


#define RETURN_POINTER \
    mxArray *output = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL); \
    int64_t *p; \
    p = (int64_t *) mxGetData(output); \
    *p = (int64_t)out; \
    return output;

//=========================================================================
mxArray* string__to_mx(const char *s){
    return mxCreateString(s);
}

mxArray* int64__to_mx(int64_t v){
    mxArray *out = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
    int64_t *data = (int64_t *)mxGetData(out);
    *data = v;
    return out;
}

mxArray* uint32__to_mx(uint32_t v){
    mxArray *out = mxCreateNumericMatrix(1,1,mxUINT32_CLASS,mxREAL);
    uint32_t *data = (uint32_t *)mxGetData(out);
    *data = v;
    return out;
}

mxArray* int32__to_mx(int v){
    mxArray *out = mxCreateNumericMatrix(1,1,mxINT32_CLASS,mxREAL);
    int *data = (int *)mxGetData(out);
    *data = v;
    return out;
}

mxArray* sizet__to_mx(size_t v2){
    return uint32__to_mx((uint32_t)v2);
}

mxArray* uint16__to_mx(uint16_t v){
    mxArray *out = mxCreateNumericMatrix(1,1,mxUINT16_CLASS,mxREAL);
    uint16_t *data = (uint16_t *)mxGetData(out);
    *data = v;
    return out;
}

//=========================================================================
mxArray* git_off_t__to_mx(git_off_t t){
    return int64__to_mx(t);
}

mxArray* git_oid__to_mx(const git_oid *oid){
    //
    //  oid is a byte array
   
    mxArray *output = mxCreateNumericMatrix(1,sizeof(*oid),mxUINT8_CLASS,mxREAL);
    uint8_t *temp = (uint8_t *)mxGetData(output);
    memcpy(temp,oid,sizeof(*oid));
    return output; 
}

mxArray* git_strarray__to_mx(git_strarray *s, int free_git){   
    //     typedef struct git_strarray {
    //          char **strings;
    //          size_t count;
    //     } git_strarray;
    
    mxArray *output = mxCreateCellMatrix(1,s->count);
    for (size_t i = 0; i < s->count; i++){
       mxSetCell(output,i,mxCreateString(s->strings[i]));
    }
    
    if (free_git){
        git_strarray_free(s);
    }
    
    return output;
}

mxArray* git_time__to_mx(git_time t){
    //
    //   git_time  => int64
    
    mxArray *mt = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
    int64_t *p;
    int64_t *p2;
    
    p2 = (int64_t *)&(t);
    
    p = (int64_t *) mxGetData(mt);
    *p = *p2; 
    
    return mt;
}

//=========================================================================



//https://stackoverflow.com/questions/45646167/use-of-undeclared-identifier-git-diff-perfdata-with-libgit2
//
// // // mxArray* git_diff_perfdata__to_mx(git_diff_perfdata *s){
// // //     //
// // //     //  plhs[0] = git_diff_perfdata__to_mx(out);
// // //     //
// // //     //typedef struct {
// // //     //      unsigned int version;
// // //     //      size_t stat_calls; /**< Number of stat() calls performed */
// // //     //      size_t oid_calculations; /**< Number of ID calculations */
// // //     // } git_diff_perfdata;
// // //     
// // //     const char *fn[3];
// // //     fn[0] = "version";
// // //     fn[1] = "stat_calls";
// // //     fn[2] = "oid_calculations";
// // //     
// // //     mxArray *output;
// // //     output = mxCreateStructMatrix(1,1,3,fn);
// // //     
// // //     //JAH TODO: At this point
// // //     
// // //     //mxSetFieldByNumber(output,0,0,mxCreateString(s->name));
// // //     //mxSetFieldByNumber(output,0,1,mxCreateString(s->email));
// // //     //mxSetFieldByNumber(output,0,2,git_time__to_mx(s->when));      
// // // }
mxArray* git_branch_iterator__to_mx(git_branch_iterator *out){
    //  plhs[0] = git_branch_iterator__to_mx(out);

    RETURN_POINTER;   
}

mxArray* git_commit__to_mx(git_commit *out){
    //  plhs[0] = git_commit__to_mx(out);
    
    RETURN_POINTER;
}

mxArray* git_index__to_mx(git_index *out){   
    //  plhs[0] = git_index__to_mx(out)
    
    RETURN_POINTER;
}

mxArray* git_object__to_mx(git_object *out){   
    //  plhs[0] = git_object__to_mx(out)
    
    RETURN_POINTER;
}

mxArray* git_reference__to_mx(git_reference *out){   
    //  plhs[0] = git_reference__to_mx(ref)
    
    RETURN_POINTER;
}

mxArray* git_repository__to_mx(git_repository *out){
    //  plhs[0] = git_repository__to_mx(ref)
    
    RETURN_POINTER;    
}

mxArray* git_status_list__to_mx(git_status_list *out){
    //
    //  plhs[0] = git_status_list__to_mx(out);
    //
    
    RETURN_POINTER;
}

mxArray* git_remote_head__to_mx(const git_remote_head **refs, size_t size){
//     int	local
//     git_oid	oid
//     git_oid	loid
//     char *	name
//     char *	symref_target
    
//     void mxSetFieldByNumber(mxArray *pm, mwIndex index, int fieldnumber, mxArray *pvalue);
    
        const git_remote_head *ref;
    
        const char *fn[5];
        fn[0] = "local";
        fn[1] = "oid";
        fn[2] = "loid";
        fn[3] = "name";
        fn[4] = "symref_target";
        
        mxArray *output;
        output = mxCreateStructMatrix(1,size,5,fn);
        
        for (size_t i = 0; i < size; i++){
            ref = refs[i];
            mxSetFieldByNumber(output,i,0,int32__to_mx(ref->local));
            mxSetFieldByNumber(output,i,1,git_oid__to_mx(&ref->oid));
            mxSetFieldByNumber(output,i,2,git_oid__to_mx(&ref->loid));
            mxSetFieldByNumber(output,i,3,mxCreateString(ref->name));
            mxSetFieldByNumber(output,i,4,mxCreateString(ref->symref_target));
        }
        
        return output;
}

mxArray* git_signature__to_mx(const git_signature *s){
//DONE
//
// /** An action signature (e.g. for committers, taggers, etc) */
// typedef struct git_signature {
// 	char *name; /**< full name of the author */
// 	char *email; /**< email of the author */
// 	git_time when; /**< time when the action happened */
// } git_signature;

    const char *fn[3];
    fn[0] = "name";
    fn[1] = "email";
    fn[2] = "when";
    
    mxArray *output;
    output = mxCreateStructMatrix(1,1,3,fn);
    
    mxSetFieldByNumber(output,0,0,mxCreateString(s->name));
    mxSetFieldByNumber(output,0,1,mxCreateString(s->email));
    mxSetFieldByNumber(output,0,2,git_time__to_mx(s->when));
    
    return output;
}

mxArray* git_diff_file__to_mx(git_diff_file *s){
// DONE
//
//  typedef struct {
// 	git_oid     id;
// 	const char *path;
// 	git_off_t   size;
// 	uint32_t    flags;
// 	uint16_t    mode;
// 	uint16_t    id_abbrev;
// } git_diff_file;
    
    const char *fn[6];
    fn[0] = "id";
    fn[1] = "path";
    fn[2] = "size";
    fn[3] = "flags";
    fn[4] = "mode";
    fn[5] = "id_abbrev";
        
    mxArray *output;
    output = mxCreateStructMatrix(1,1,6,fn);
    mxSetFieldByNumber(output,0,0,git_oid__to_mx(&s->id));
    mxSetFieldByNumber(output,0,1,string__to_mx(s->path));
    mxSetFieldByNumber(output,0,2,git_off_t__to_mx(s->size));
    mxSetFieldByNumber(output,0,3,uint32__to_mx(s->flags));
    mxSetFieldByNumber(output,0,4,uint16__to_mx(s->mode));
    mxSetFieldByNumber(output,0,5,uint16__to_mx(s->id_abbrev));
    
    return output;
        
}

mxArray* git_diff_delta__to_mx(git_diff_delta *s){
//DONE
//
// typedef struct {
// 	git_delta_t   status;
// 	uint32_t      flags;	   /**< git_diff_flag_t values */
// 	uint16_t      similarity;  /**< for RENAMED and COPIED, value 0-100 */
// 	uint16_t      nfiles;	   /**< number of files in this delta */
// 	git_diff_file old_file;
// 	git_diff_file new_file;
// } git_diff_delta;   
    
    const char *fn[6];
    fn[0] = "status";
    fn[1] = "flags";
    fn[2] = "similarity";
    fn[3] = "nfiles";
    fn[4] = "old_file";
    fn[5] = "new_file";
    
    mxArray *output;
    output = mxCreateStructMatrix(1,1,6,fn);
    mxSetFieldByNumber(output,0,0,int32__to_mx(s->status));
    mxSetFieldByNumber(output,0,1,uint32__to_mx(s->flags));
    mxSetFieldByNumber(output,0,2,uint16__to_mx(s->similarity));
    mxSetFieldByNumber(output,0,3,uint16__to_mx(s->nfiles));
    mxSetFieldByNumber(output,0,4,git_diff_file__to_mx(&s->old_file));
    mxSetFieldByNumber(output,0,5,git_diff_file__to_mx(&s->new_file));
    return output;
}

mxArray* git_status_entry__to_mx(const git_status_entry *s){

// typedef struct {
// 	git_status_t status;
// 	git_diff_delta *head_to_index;
// 	git_diff_delta *index_to_workdir;
// } git_status_entry;
    
    const char *fn[3];
    fn[0] = "status";
    fn[1] = "head_to_index";
    fn[2] = "index_to_workdir";
    
    mxArray *output, *s1, *s2;
    output = mxCreateStructMatrix(1,1,3,fn);
    
    if (s->head_to_index){
        s1 = git_diff_delta__to_mx(s->head_to_index);
    }else{
        s1 = mxCreateStructMatrix(1,1,0,NULL);
    }
    
    if (s->index_to_workdir){
        s2 = git_diff_delta__to_mx(s->index_to_workdir);
    }else{
        s2 = mxCreateStructMatrix(1,1,0,NULL);
    }

    
    mxSetFieldByNumber(output,0,0,int32__to_mx(s->status));
    mxSetFieldByNumber(output,0,1,s1);
    mxSetFieldByNumber(output,0,1,s2);
    
    
    
    //mxSetFieldByNumber(output,0,1,mxCreateString(s->email));
    //mxSetFieldByNumber(output,0,2,git_time__to_mx(s->when));
    
    return output;
    
    
    //git_status_t
    //https://github.com/libgit2/libgit2/blob/HEAD/include/git2/status.h#L335-337
    //
    //git_diff_delta
    //https://github.com/libgit2/libgit2/blob/HEAD/include/git2/diff.h#L331-338
   
 
    
    

    
}


        
//=========================================================================
mxArray* git_status_options__to_mx(git_status_options *so){
    
    
    //0 version: unsigned int
    //1 show: git_status_show_t
    //2 flags: unsigned
    //3 pathspec: git_strarray
    
    const char *fn[4];
    fn[0] = "version";                
    fn[1] = "show";    
    fn[2] = "flags";
    fn[3] = "pathspec";
    
    mxArray *output;
    output = mxCreateStructMatrix(1,1,4,fn);
    mxSetFieldByNumber(output,0,0,uint32__to_mx(so->version));
    mxSetFieldByNumber(output,0,1,int32__to_mx(so->show));
    mxSetFieldByNumber(output,0,2,uint32__to_mx(so->flags));
    mxSetFieldByNumber(output,0,3,git_strarray__to_mx(&(so->pathspec),true));
    return output;
    
}

mxArray* git_proxy_options__to_mx(git_proxy_options *po){
    
    //https://github.com/libgit2/libgit2/blob/HEAD/include/git2/proxy.h
    
    //git.base.proxy_options
    
    //Parents
    //- git_fetch_options
    
    //0 version:        unsigned int
    //1 type:           git_proxy_t
    //2 url:            const char *
    //3 credentials:    git_cred_acquire_cb
    //4 certificate_check: git_transport_certificate_check_cb
    //5 payload:        void *    
    
    const char *fn[6];
    fn[0] = "version";                
    fn[1] = "type";    
    fn[2] = "url";
    fn[3] = "credentials";
    fn[4] = "certificate_check";
    fn[5] = "payload";
    
    mxArray *output;
    output = mxCreateStructMatrix(1,1,6,fn);
    return output;
    
}

mxArray* git_remote_callbacks__to_mx(git_remote_callbacks *cb){
    
    //https://github.com/libgit2/libgit2/blob/HEAD/include/git2/remote.h
    
    //git.base.remote_callbacks
    
    //Parents
    //- git_fetch_options
    //- 
    
    //0 version:              unsigned int
    //1 sideband_progress:    git_transport_message_cb  
    //2 completion:           int (*completion)(git_remote_completion_type type, void *data);
    //3 credentials:          git_cred_acquire_cb
    //4 certificate_check:    git_transport_certificate_check_cb
    //5 transfer_progress:    git_transfer_progress_cb
    //6 update_tips:          int (*update_tips)(const char *refname, const git_oid *a, const git_oid *b, void *data);
    //7 pack_progress:        git_packbuilder_progress
    //8 push_transfer_progress:   git_push_transfer_progress
    //9 push_update_reference:    int (*push_update_reference)(const char *refname, const char *status, void *data);
    //10 transport:        git_transport_cb
    //11 payload:          void *
    
    const char *fn[11];
    fn[0] = "version";                
    fn[1] = "sideband_progress";    
    fn[2] = "completion";
    fn[3] = "certificate_check";
    fn[4] = "transfer_progress";
    fn[5] = "update_tips";
    fn[6] = "pack_progress";
    fn[7] = "push_transfer_progress";
    fn[8] = "push_update_reference";
    fn[9] = "transport";
    fn[10]= "payload";
    
    mxArray *output;
    output = mxCreateStructMatrix(1,1,11,fn);
    mxSetFieldByNumber(output,0,0,uint32__to_mx(cb->version));
    
    //We won't support passing the callbacks to Matlab for now
    return output;
}

mxArray* git_fetch_options__to_mx(git_fetch_options *fo){
    
    //https://github.com/libgit2/libgit2/blob/HEAD/include/git2/remote.h
    
    //git.base.fetch_options
    
    //Fields 
    //----------------------------------------------
    //0 version:            int
    //1 callbacks:          git_remote_callbacks
    //2 prune:              git_fetch_prune_t (enum)
    //3 update_fetchhead:   int
    //4 download_tags:      git_remote_autotag_option_t (enum)
    //5 proxy_opts:         git_proxy_options
    //6 custom_headers:     git_strarray

    mxArray *output;
    mxArray *temp;
    
    const char *fn[7];
    fn[0] = "version";
    fn[1] = "callbacks";
    fn[2] = "prune";
    fn[3] = "update_fetchhead";
    fn[4] = "download_tags";
    fn[5] = "proxy_opts";
    fn[6] = "custom_headers";
    
    output = mxCreateStructMatrix(1,1,7,fn);
    
    mxSetFieldByNumber(output,0,0,int32__to_mx(fo->version));
    temp = git_remote_callbacks__to_mx(&(fo->callbacks));
    mxSetFieldByNumber(output,0,1,temp);
    mxSetFieldByNumber(output,0,2,int32__to_mx(fo->prune));
    mxSetFieldByNumber(output,0,3,int32__to_mx(fo->update_fetchhead));
    mxSetFieldByNumber(output,0,4,int32__to_mx(fo->download_tags));
    temp = git_proxy_options__to_mx(&(fo->proxy_opts));
    mxSetFieldByNumber(output,0,5,temp);
    temp = git_strarray__to_mx(&(fo->custom_headers),0);
    mxSetFieldByNumber(output,0,6,temp);
     
    return output;
}