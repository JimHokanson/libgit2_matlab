//Callbacks

int default_remote_callback (git_cred **out,
                    const char * UNUSED(url),
                    const char * UNUSED(username_from_url),
                    unsigned int UNUSED(allowed_types),
                    void * UNUSED(payload))
{
    //This callback is meant to handle the case where the user 
    //specifies their credentials up front.
    //
    //TODO: Document usage
    
    //https://libgit2.github.com/libgit2/#HEAD/group/cred

	int error;
    
    //TODO: Eventually allow multiple cred options.
	error = git_cred_userpass_plaintext_new(out, remote_username, remote_password);
    
    //TODO: This might be better in fetch or push. I'm not sure if this
    //callback would ever be called twice, in which case the second
    //time the variable would be freed
    mxFree((void *)remote_username);
    mxFree((void *)remote_password);
    
	return error;
}