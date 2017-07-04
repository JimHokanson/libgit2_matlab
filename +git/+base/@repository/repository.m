classdef repository < handle
    %
    %   Class:
    %   git.base.repository
    
    %{
        file_path = '/Users/jim/Documents/repos/matlab_git/matlab_standard_library';
        repo = git.base.repository(file_path);
        remote = repo.lookupRemote('origin');
        list = git.base.remote.getList(repo);
        ref = git.base.reference(repo,'HEAD');
    %}
    
    properties (Hidden)
        h %pointer for underlying git_repository 
    end
    
    properties
        file_path
    end
    
    %Repo creation methods
    methods (Static)
        
    end
    
    %Other methods
    methods
        function remote = lookupRemote(obj,remote_name)
            remote = git.base.remote(obj,remote_name);
        end
    end
    
    methods
        function obj = repository(file_path)
            %
            %   obj = git.base.repository(file_path)
            
            obj.file_path = file_path;
            %call git.mex.repo
            obj.h = libgit(0,26,file_path);
        end
        function getNamespace(obj)
            %TODO
        end
        function delete(obj)
            libgit(0,7,obj.h);
        end
    end
    
end

%01  git_repository__cleanup
%02  git_repository_config
%03  git_repository_config_snapshot
%04  git_repository_detach_head
%05  git_repository_discover
%06  git_repository_fetchhead_foreach
%07  git_repository_free
%08  git_repository_get_namespace
%09  git_repository_hashfile
%10  git_repository_head
%11  git_repository_head_detached
%12  git_repository_head_unborn
%13  git_repository_ident
%14  git_repository_index
%15  git_repository_init
%16  git_repository_init_ext
%17  git_repository_init_init_options
%18  git_repository_is_bare
%19  git_repository_is_empty
%20  git_repository_is_shallow
%21  git_repository_mergehead_foreach
%22  git_repository_message
%23  git_repository_message_remove
%24  git_repository_new
%25  git_repository_odb
%26  git_repository_open
%27  git_repository_open_bare
%28  git_repository_open_ext
%29  git_repository_path
%30  git_repository_refdb
%31  git_repository_reinit_filesystem
%32  git_repository_set_bare
%33  git_repository_set_config
%34  git_repository_set_head
%35  git_repository_set_head_detached
%36  git_repository_set_head_detached_from_annotated
%37  git_repository_set_ident
%38  git_repository_set_index
%39  git_repository_set_namespace
%40  git_repository_set_odb
%41  git_repository_set_refdb
%42  git_repository_set_workdir
%43  git_repository_state
%44  git_repository_state_cleanup
%45  git_repository_submodule_cache_all
%46  git_repository_submodule_cache_clear
%47  git_repository_workdir
%48  git_repository_wrap_odb

