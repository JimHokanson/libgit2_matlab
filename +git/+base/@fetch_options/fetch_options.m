classdef fetch_options
    %
    %   Class:
    %   git.base.fetch_options
    %
    %   https://libgit2.github.com/libgit2/#HEAD/type/git_fetch_options
        
    properties
        version %???
        
        callbacks
        %Callbacks to use for this fetch operation
        
        prune %git_fetch_prune_t
        %Whether to perform a prune after the fetch
        
        update_fetchhead = true %logical
        %Whether to write the results to FETCH_HEAD. Defaults to on. Leave 
        %this default in order to behave like git.
        
        download_tags %git_remote_autotag_option_t
        %Determines how to behave regarding tags on the remote, such as
        %auto-downloading tags for objects we're downloading or downloading
        %all of them. The default is to auto-follow tags.
        
        proxy_options %git_proxy_options
        %Proxy options to use, by default no proxy is used.
        
        extra_headers %git_strarray
        %Extra headers for this fetch operation
    end
    
    methods
    end
    
end

