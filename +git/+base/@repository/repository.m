classdef repository < sl.obj.display_class
    %
    %   Class:
    %   git.base.repository
    
    %{
        
        file_path = 'G:\repos\matlab_git\mat_std_lib';
        
        file_path = '/Users/jim/Documents/repos/matlab_git/matlab_standard_library';
        repo = git.base.repository(file_path);
        
        remote = repo.lookupRemote('origin');
        list = git.base.remote.getList(repo);
        ref = git.base.reference(repo,'HEAD');
        oid = ref.oid;
        commit = git.base.commit(repo,oid)
    %}
    
    properties (Hidden)
        h = 0%pointer for underlying git_repository 
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
            obj.h = libgit(0,30,file_path);
        end
        function getNamespace(obj)
            %x 
            %TODO
        end
        function list = getRemoteList(obj)
            %x Get list of remotes.
            list = libgit(1,21,obj.h);
        end
    end
    methods (Hidden)
        function delete(obj)
            if obj.h ~= 0
                libgit(0,8,obj.h);
            end
        end
    end
    
end

%01  git_repository__cleanup
%02  git_repository_commondir
%03  git_repository_config
%04  git_repository_config_snapshot
%05  git_repository_detach_head
%06  git_repository_discover
%07  git_repository_fetchhead_foreach
%08  git_repository_free
%09  git_repository_get_namespace
%10  git_repository_hashfile
%11  git_repository_head
%12  git_repository_head_detached
%13  git_repository_head_for_worktree
%14  git_repository_head_unborn
%15  git_repository_ident
%16  git_repository_index
%17  git_repository_init
%18  git_repository_init_ext
%19  git_repository_init_init_options
%20  git_repository_is_bare
%21  git_repository_is_empty
%22  git_repository_is_shallow
%23  git_repository_is_worktree
%24  git_repository_item_path
%25  git_repository_mergehead_foreach
%26  git_repository_message
%27  git_repository_message_remove
%28  git_repository_new
%29  git_repository_odb
%30  git_repository_open
%31  git_repository_open_bare
%32  git_repository_open_ext
%33  git_repository_open_from_worktree
%34  git_repository_path
%35  git_repository_refdb
%36  git_repository_reinit_filesystem
%37  git_repository_set_bare
%38  git_repository_set_config
%39  git_repository_set_head
%40  git_repository_set_head_detached
%41  git_repository_set_head_detached_from_annotated
%42  git_repository_set_ident
%43  git_repository_set_index
%44  git_repository_set_namespace
%45  git_repository_set_odb
%46  git_repository_set_refdb
%47  git_repository_set_workdir
%48  git_repository_state
%49  git_repository_state_cleanup
%50  git_repository_submodule_cache_all
%51  git_repository_submodule_cache_clear
%52  git_repository_workdir
%53  git_repository_wrap_odb

