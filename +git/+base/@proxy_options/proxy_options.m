classdef proxy_options
    %
    %   Class:
    %   git.base.proxy_options
    %
    %   https://github.com/libgit2/libgit2/blob/HEAD/include/git2/proxy.h
    
    properties
        version %unsigned int
        
        type %git_proxy_t
        %The type of proxy to use, by URL, auto-detect.
        
        url %string
        %The URL of the proxy.
        
        credentials %git_cred_acquire_cb
        %This will be called if the remote host requires authentication in
        %order to connect to it.
        %
        %Returning GIT_PASSTHROUGH will make libgit2 behave as though this
        %field isn't set.
        
        certificate_check
        %  If cert verification fails, this will be called to let the user
        %  make the final decision of whether to allow the connection to
        %  proceed. Returns 1 to allow the connection, 0 to disallow it or
        %  a negative value to indicate an error.
     
        payload %void *
        %Payload to be provided to the credentials and certificate check
        %callbacks.
    end
    
    methods
    end
    
end