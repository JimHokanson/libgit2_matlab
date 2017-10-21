classdef remote < sl.obj.display_class
    %
    %   Class:
    %   git.base.remote
    
    %{
        o = repo.getRemote('origin')
        o.fetch()
        %TODO: Now do the revwalk
    
    %}
    
    properties (Hidden)
        h
    end
    
    properties
        repo
        remote_name
    end
    
    %Properties
    %----------
    %url  - git_remote_set_url
    %name
    %pushurl  - git_remote_set_pushurl
    
    properties (Dependent)
        url
        connected
    end
    
    methods
        function value = get.url(obj)
            value = libgit(1,38,obj.h);
        end
    end
    
    %Constructors
    %----------------------------------------------------
    methods (Static)
        %fromReference()
        %
        function obj = fromRepo(repo,remote_name)
            h = libgit(1,22,repo.h,remote_name);
            obj = git.base.remote(h);
        end
    end
    
    methods
        function obj = remote(h)
            %
            %   obj = git.base.remote(h)
            
            %TODO: Build in optional parameters
            %=> particularly things related to fetching
            
            obj.h = h;
            %obj.repo = repo;
            %obj.remote_name = remote_name;
        end
    end
    
    %Other methods
    %---------------------------------------------
    methods
        function options = getFetchOptions(obj)
            options = git.base.fetch_options;
        end
        function varargout = fetch(obj,varargin)
            %
            %
            %   Optional Inputs
            %   ---------------
            %   refspecs : cellstr
            %   options : git.base.fetch_options
            %   reflog_message : 
            
            in.refspecs = {};
            in.options = [];
            in.reflog_message = '';
            in = sl.in.processVarargin(in,varargin);
            
            %TODO: Support optional inputs 
            
            %git.base.fetch_options
            %       git.base.remote_callbacks
            
            %(remote,refspecs,options,reflog_message) 
            
            libgit(1,14,obj.h);
        
            if nargout
                varargout{1} = libgit(1,34,obj.h);
            end
        
        end
        
        %We might not want to expose this, but rather do it implicitly
        %when fetching or pushing
        function connect(obj)
            %
            %   
            
            %   direction GIT_DIRECTION_FETCH or GIT_DIRECTION_PUSH
            %   callbacks
            %   proxy options
            %   custom_headers
            
        end
    end
    methods (Hidden)
        function delete(obj)
            libgit(1,10,obj.h);
        end
    end
    
end

%01 git_remote_add_fetch
%02 git_remote_add_push
%03 git_remote_autotag
%04 git_remote_connect - Open a connection to a remote
%05 git_remote_connected
%06 git_remote_create
%07 git_remote_create_anonymous
%08 git_remote_create_with_fetchspec
%09 git_remote_default_branch
%10 git_remote_delete
%11 git_remote_disconnect
%12 git_remote_download
%13 git_remote_dup
%14 git_remote_fetch
%x 15 git_remote_free
%16 git_remote_get_fetch_refspecs
%17 git_remote_get_push_refspecs
%18 git_remote_get_refspec
%19 git_remote_init_callbacks
%20 git_remote_is_valid_name
%REPO x 21 git_remote_list
%x 22 git_remote_lookup
%23 git_remote_ls
%24 git_remote_name
%25 git_remote_owner
%26 git_remote_prune
%27 git_remote_prune_refs
%28 git_remote_push
%29 git_remote_refspec_count
%30 git_remote_rename
%31 git_remote_set_autotag
%32 git_remote_set_pushurl
%33 git_remote_set_url
%34 git_remote_stats - Get the statistics structure that is filled in by the fetch operation.
%35 git_remote_stop
%36 git_remote_update_tips - update the tips to the new state
%37 git_remote_upload
%x 38 git_remote_url