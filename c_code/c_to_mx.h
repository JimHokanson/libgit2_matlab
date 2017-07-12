//c_to_mx.h

mxArray* int32__to_mx(int v){
    mxArray *out = mxCreateNumericMatrix(1,1,mxINT32_CLASS,mxREAL);
    int *data = (int *)mxGetData(out);
    *data = v;
    return out;
}

mxArray* uint32__to_mx(unsigned int v){
    mxArray *out = mxCreateNumericMatrix(1,1,mxUINT32_CLASS,mxREAL);
    int *data = (int *)mxGetData(out);
    *data = v;
    return out;
}

//=========================================================================
mxArray* git_oid__to_mx(const git_oid *oid){
   
    mxArray *output = mxCreateNumericMatrix(1,sizeof(*oid),mxUINT8_CLASS,mxREAL);
    uint8_t *temp = (uint8_t *)mxGetData(output);
    memcpy(temp,oid,sizeof(*oid));
    return output; 
}

mxArray* git_time__to_mx(git_time t){
    
    //git_time  => int64
    
    mxArray *mt = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);
    int64_t *p;
    int64_t *p2;
    p = (int64_t *) mxGetData(mt);
    
    p2 = (int64_t *)&(t);
    *p = *p2; 
    
    return mt;
}

//=========================================================================


// mxArray* git_remote__to_mx(const git_remote *r){
//     
// }

mxArray* get_index__to_mx(git_index *out){   
    //
    //  plhs[0] = get_index__to_mx(out)
    //
    
    mxArray *output = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);

    int64_t *p;
    p = (int64_t *) mxGetData(output);
    *p = (int64_t)out; 
    return output;
}

mxArray* git_reference__to_mx(git_reference *ref){   
    //
    //  plhs[0] = get_reference__to_mx(ref)
    //
    
    mxArray *output = mxCreateNumericMatrix(1,1,mxINT64_CLASS,mxREAL);

    int64_t *p;
    p = (int64_t *) mxGetData(output);
    *p = (int64_t)ref; 
    return output;
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

mxArray* git_strarray__to_mx(git_strarray *s,int free_git){
    
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



//=========================================================================

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