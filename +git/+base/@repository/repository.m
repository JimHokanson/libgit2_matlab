classdef repository < sl.obj.display_class
    %
    %   Class:
    %   git.base.repository
    
    %{
        
        file_path = 'G:\repos\matlab_git\mat_std_lib';
        
        file_path = '/Users/jim/Documents/repos/matlab_git/matlab_standard_library';
        
        file_path = '/Users/jim/Documents/repos/matlab_git/libgit2_matlab';
        repo = git.base.repository(file_path);
    
        stat_list = git.base.status_list.fromRepo(repo);
    
        
        remote = repo.lookupRemote('origin');
        list = git.base.remote.getList(repo);
        ref = git.base.reference(repo,'HEAD');
        oid = ref.oid;
        commit = git.base.commit(repo,oid)
    
        b = git.base.branch_iterator(repo);
        
    %}
    
    properties (Hidden)
        h = 0%pointer for underlying git_repository 
    end
    
    properties
        file_path
    end
    
    methods
        function value = get.file_path(obj)
           value = libgit(0,34,obj.h); 
        end
    end
    
    %Repo creation methods
    methods (Static)
        function obj = fromHandle(h)
            %
            %   obj = git.base.repository.fromHandle(h);

            %Ideally we could get a handle copy method or track refences
            %but if we pass this to another instance of the object we
            %get 2 delete requests for 1 underlying handle and this causes
            %Matlab to crash
            
            file_path = libgit(0,34,h);
            obj = git.base.repository(file_path);
        end
    end
    
    %Constructor
    %------------------------------------------
    methods
        function obj = repository(file_path)
            %
            %   obj = git.base.repository(file_path)
            %
            
            %if ischar(file_path_or_h)
                obj.h = libgit(0,30,file_path);
            %else
            %    obj.h = file_path_or_h;
            %end
           
        end
    end
    
    
    methods
        function detatchHead(obj)
            libgit(0,5,obj.h)
        end
        function branch = getBranch(obj,branch_name,is_remote)
            branch = git.base.branch.fromName(obj,branch_name,is_remote);
        end
        function d = getCommonDir(obj)
            d = libgit(0,2,obj.h);
        end
        function c = getConfig(obj)
            c_h = libgit(0,3,obj.h);
            c = git.base.config(c_h);
        end
        function branch = getCurrentLocalBranch(obj)
            branch = [];
            %How is this best done?
        end
        function namespace = getNamespace(obj)
            %x Get the currently active namespace for this repository
            %
            %   namespace = getNamespace(obj)
            %
            %   Why is this returning empty????
            namespace = libgit(0,9,obj.h);
        end
        function index = getIndex(obj)
            index = git.base.index();
        end
        function list = getRemoteList(obj)
            %x Get list of remotes.
            %
            %   list = getRemoteList(obj)
            %
            %   Example
            %   --------------------------
            %   list = repo.getRemoteList()
            %
            %   list => {'origin'}
            
            
            %   Note: 1 is for remotes
            list = libgit(1,21,obj.h)';
        end
        function remote = getRemote(obj,remote_name)
            %x Get remote reference
            %
            %   remote = getRemote(obj,remote_name)
            %
            %   
            %
            %   See Also
            %   --------
            %   getRemoteList
            %   getReferenceList
            
            if nargin == 0
                remote_name = 'origin';
            end
            
            remote = git.base.remote.fromRepo(obj,remote_name);
        end
        function list = getReferenceList(obj)
            %x Return names of all references that can be found in a repository. 
            %
            %   list = getReferenceList(obj)
            %
            %   Outputs
            %   -------
            %   list : cellstr
            %
            %   Example
            %   -------
            %   list = repo.getReferenceList()
            %
            %   list => 
            %   'refs/heads/master'
            %   'refs/remotes/origin/HEAD'
            %   'refs/remotes/origin/master'
            
            list = libgit(3,23,obj.h)';
        end
        function ref = getReference(obj,name)
            %
            %   ref = getReference(obj,name)
            %
            %   Inputs
            %   ------
            %   name : string
            %       Reference name
            %
            %   Outputs
            %   -------
            %   ref : git.base.reference
            %   
            %   Example
            %   -------
            %   
            
            ref = git.base.reference.fromRepoAndName(obj,name);
        end
        function walker = getRevWalker(obj)
            walker = git.base.revwalk.fromRepo(obj);
        end
    end
    
    
    methods
        
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
%08  X git_repository_free
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

